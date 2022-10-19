#include "libs.h"                                                                            // Includes & Prototypes
                                                                                             
                                                                                             
/*     Global Variables     */                                                               
namespace {                                                                                  
    const char* const WINDOW_TITLE = "Module Six Milestone";                                 // Main window title
    const int w_height = 600, w_width = 800;                                                 // Initial window width & height (px)
    int fbw = 0, fbh = 0;                                                                    // Framebuffer width & height
    GLFWwindow* gWindow = nullptr;                                                           // Window ID                             
                                                                                             
    glm::vec3 camPosition(0.0f, 0.0f, 3.0f);                                                 // Initial camera position
    glm::vec3 camFront(0.0f, 0.0f, -1.0f);                                                   // Camera front direction (inverted)
    glm::vec3 worldUp(0.0f, 1.0f, 0.0f);                                                     // World up direction
    glm::vec3 direction;                                                                     // Camera direction
    
    float cameraSpeed = 2.0f, cameraSpeedOffset = 2.5f;                                      // Camera multipliers
    float pitch = 0.0f, yaw = -90.0f;                                                        // Camera pitch and yaw (mouse position)
    float lastX = 400, lastY = 300;                                                          // Last view angles
    float currentFrame = glfwGetTime(), lastFrame = 0.0f, deltaTime = 0.0f;                  // Frame timing
    float fov = 90.0f;                                                                       // Field of view
    float nearPlane = 0.1f, farPlane = 1000.0f;                                              // View distances
                                                                                             
    bool autoOrbit = false;                                                                  // Toggles camera automatic orbit
    bool viewToggle = true;                                                                  // Projection & Orthographic Perspective toggle
    bool firstMouse = true;                                                                  // Initializes first mouse cursor position
                                                                                             
    glm::mat4 model(1.0f);                                                                   // Model identity matrix
    glm::mat4 view(1.0f);                                                                    // View identity matrix                                                     
    glm::mat4 proj(1.0f);                                                                    // Projection identity matrix
                                                                                             
    Texture planeTexture, tapeTexture, steelTexture, caliperTexture;                         // Texture diffuse maps
    Texture planeSpecMap, tapeSpecMap, steelSpecMap, caliperSpecMap;                         // Texture specular maps
    Shader coreProgram, lightProgram;                                                        // Shader Programs
};

                                                                                            
/*     Initialization     */
bool Initialize(int argc, char* argv[], GLFWwindow** window)
// Initialize features and functionality
{
    // GLFW: initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    // GLFW: window creation
    *window = glfwCreateWindow(w_width, w_height, WINDOW_TITLE, NULL, NULL);
    if (*window == NULL)
    {
        std::cout << "[ERROR:MAIN] Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glViewport(0, 0, fbw, fbh);

    glfwSetInputMode(*window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);                              // Disable cursor
    glfwMakeContextCurrent(*window);                                                           // Set window active
    glfwGetFramebufferSize(*window, &fbw, &fbh);                                               
    glfwSetFramebufferSizeCallback(*window, ResizeCallback);                                   // Enables resizing (Note: resizing is not available while glfwSetInputMode has the cursor disabled.
    glfwSetCursorPosCallback(*window, MousePositionHandler);                                   // Enable cursor position inputs
    glfwSetScrollCallback(*window, MouseScrollHandler);                                        // Enables mouse scroll wheel inputs
    glfwSetKeyCallback(*window, KeyPressHandler);                                              // Enable P key toggle without risk of repeating characters
    glfwSetMouseButtonCallback(*window, MouseButtonHandler);                                   // Enable mouse button responses
    // GLEW: initialize
    GLenum GlewInitResult = glewInit();
    if (GLEW_OK != GlewInitResult)
    {
        std::cerr << "[ERROR::MAIN] GLEW INIT FAILURE: " << glewGetErrorString(GlewInitResult) << std::endl;
        return false;
    }

    // OpenGL Options
    glEnable(GL_DEPTH_TEST);

    CreateMesh(gMesh);

    coreProgram.createShaders(                                                                 // Create core shader program
        "shaders/vertex_core.glsl", "shaders/fragment_core.glsl");

    lightProgram.createShaders(                                                                // Create lighting shader program
        "shaders/vertex_light.glsl", "shaders/fragment_light.glsl");

    planeTexture.createTexture("textures/countertop.png", 0);                                  // Create plane diffuse map
    tapeTexture.createTexture("textures/tape_front.png", 0);                                   // Create tape diffuse map
    steelTexture.createTexture("textures/steel.png", 0);                                       // Create steel diffuse map
    caliperTexture.createTexture("textures/caliper.png", 0);                                   // Create caliper diffuse map

    planeSpecMap.createTexture("textures/countertop_specular.png", 1);                         // Create plane specular map
    tapeSpecMap.createTexture("textures/tape_front_specular.png", 1);                          // Create tape specular map
    steelSpecMap.createTexture("textures/steel_specular.png", 1);                              // Create steel specular map
    caliperSpecMap.createTexture("textures/caliper_specular.png", 1);                          // Create caliper specular map
    
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);                                                      // Set window background color to black
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

    return true;
}

/*     Main Loop     */
int main(int argc, char* argv[])                                                             
{                                                                                            
    if (!Initialize(argc, argv, &gWindow))                                                  
        return EXIT_FAILURE;                                                                 
                                                                                      
    while (!glfwWindowShouldClose(gWindow))                                                  
        // Keep open until closed                                                                       
    {   
        KeyHoldHandler(gWindow);                                                              // Exit if ESC is pressed
        Render();                                                                           // Render next frame                                                                                 
        glfwPollEvents();                                                                    // Window event handler - keeps window responsive
    }                                                                                        
    DestroyMesh(gMesh);
    exit(EXIT_SUCCESS);                                                                      // Terminates the program successfully
}


/*     Rendering     */
void Render()
// Set MVP attributes, draw, set buffers, swap frames
{
#pragma region BeginRendering
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);               // Clear z buffers
    coreProgram.use();                                                                        // Activate core shader program
    
    glm::vec3 lightCubeScale(0.3f, 0.3f, 0.3f);                                               // Scale for both light sources
    glm::vec3 lightPos0(-1.0f, 1.0f, 0.0f);                                                   // Point Light 0 position (x, y, z)
    glm::vec3 lightPos1(1.0f, 1.0f, 0.0f);                                                    // Point Light 1 position (x, y, z)
    glm::vec3 specular(1.0f, 1.0f, 1.0f);                                                     // Point light specular strength (r, g, b)
    glm::vec3 ambient(0.3f, 0.3f, 0.3f);                                                      // Point Light ambient color (r, g, b)
    glm::vec3 diffuse(0.5f, 0.5f, 0.5f);                                                      // Point light diffuse color (r, g, b)

    float lightConst = 1.0f;
    float lightLinear[] = { 0.14f, 0.09f };
    float lightQuad[] = { 0.07, 0.032f };
    
    if (autoOrbit)
    {
        camPosition.x = sin(glfwGetTime()) * 10.0f;
        camPosition.z = cos(glfwGetTime()) * 10.0f;
        view = glm::lookAt(camPosition, glm::vec3(0.0f, 0.0f, 0.0f), worldUp);
    }
    else
    {
        view = glm::lookAt(camPosition, camPosition + camFront, worldUp);                      // Standard Camera view
    }

    coreProgram.setVec3(camPosition, "viewPos");                                               // Pass view (camera) position uniform
    coreProgram.set1i(0, "material.diffuse");                                                  // Set shader program to handle diffuse maps
    coreProgram.set1i(1, "material.specular");                                                 // Set shader program to handle specular maps
    coreProgram.setVec3(lightPos0, "pointLights[0].position");                                 // Pass point light positions
    coreProgram.setVec3(lightPos1, "pointLights[1].position");
    coreProgram.set1f(lightConst, "pointLights[0].constant");                                  // Pass point light constant values
    coreProgram.set1f(lightConst, "pointLights[1].constant");
    coreProgram.set1f(lightLinear[0], "pointLights[0].linear");                                // Pass point light linear values
    coreProgram.set1f(lightLinear[1], "pointLights[1].linear");
    coreProgram.set1f(lightQuad[0], "pointLights[0].quadratic");                               // Pass point light quadratic values
    coreProgram.set1f(lightQuad[1], "pointLights[1].quadratic");
    coreProgram.setVec3(ambient, "pointLights[0].ambient");                                    // Pass point light ambient values
    coreProgram.setVec3(ambient, "pointLights[1].ambient");
    coreProgram.setVec3(diffuse, "pointLights[0].diffuse");                                    // Pass point light diffuse values
    coreProgram.setVec3(diffuse, "pointLights[1].diffuse");
    coreProgram.setVec3(specular, "pointLights[0].specular");                                  // Pass point light specular values
    coreProgram.setVec3(specular, "pointLights[1].specular");

    if (viewToggle)                                                                            // Set perspective or orthographic projection
        proj = glm::perspective(glm::radians(fov),                                             
            static_cast<float>(fbw) / fbh, nearPlane, farPlane);                               
    else                                                                                       
        proj = glm::ortho(-6.0f, 6.0f, -6.0f, 6.0f, -6.0f, 6.0f);                              // Orthographic projection encompasses points within -6 and 6 on x, y, and z axes
#pragma endregion   
#pragma region Plane
    planeTexture.bind();                                                                       // Bind plane diffuse map
    planeSpecMap.bind();                                                                       // Bind plane specular map
    model = glm::mat4(1.0f);                                                                   // Revert model matrix to identity
    
    glm::vec3 planePosition(0.0f, 0.5f, 0.0f);                                                 // Plane position (x, y, z)
    glm::vec3 planeScale(3.0f, 3.0f, 3.0f);                                                    // Plane scale (x, y, z)
    float planeShininess = 9.8f;

    model = glm::translate(model, planePosition);                                              // Position plane model
    model = glm::scale(model, planeScale);                                                     // Scale plane model
    
    coreProgram.setMat4(model, "model");                                                       // Pass model matrix uniform
    coreProgram.setMat4(view, "view");                                                         // Pass view matrix uniform
    coreProgram.setMat4(proj, "proj");                                                         // Pass projection matrix uniform
    coreProgram.set1f(planeShininess, "material.shininess");

    glBindVertexArray(gMesh.vao[0]);                                                           // Bind plane mesh
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nIndices[0]);                                          // Draw plane
    planeTexture.unbind();                                                                     // Unbind plane texture
#pragma endregion
#pragma region TapeMeasure
    tapeTexture.bind();                                                                        // Bind tape diffuse map
    tapeSpecMap.bind();                                                                        // Bind tape specular map
    model = glm::mat4(1.0f);                                                                   // Revert model matrix to identity
    
    glm::vec3 tapePosition(0.4f, -0.59f, -0.8f);                                               // Tape position (x, y, z)
    glm::vec3 tapeRotation(0.0f, -10.0f, 0.0f);                                                // Tape rotation (x, y, z)
    glm::vec3 tapeScale(0.45f);                                                                // Tape scale (x, y, z)
    float tapeShininess = 32.0f;

    model = glm::translate(model, tapePosition);                                               // Position tape model
    model = glm::rotate(model, glm::radians(tapeRotation.x), glm::vec3(1.0f, 0.0f, 0.0f));     // Rotate tape model on x axis
    model = glm::rotate(model, glm::radians(tapeRotation.y), glm::vec3(0.0f, 1.0f, 0.0f));     // Rotate tape model on y axis
    model = glm::scale(model, tapeScale);                                                      // Scale tape model
    

    coreProgram.setMat4(model, "model");                                                       // Pass model matrix uniform
    coreProgram.setMat4(view, "view");                                                         // Pass view matrix uniform
    coreProgram.setMat4(proj, "proj");                                                         // Pass projection matrix uniform
    coreProgram.set1f(tapeShininess, "material.shininess");

    glBindVertexArray(gMesh.vao[1]);                                                           // Bind tape measure mesh
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nIndices[1]);                                          // Draw tape measure
#pragma endregion 
#pragma region Screw
    steelTexture.bind();                                                                       // Bind screw diffuse map
    steelSpecMap.bind();                                                                       // Bind screw specular map
    model = glm::mat4(1.0f);                                                                   // Revert model matrix to identity

    glm::vec3 screwPosition(0.0f, -0.95f, -0.28f);                                             // Screw position (x, y, z)
    glm::vec3 screwRotation(0.0f, -25.0f, -18.0f);                                             // Screw rotation (x, y, z)
    glm::vec3 screwScale(0.1f, 0.1f, 0.1f);                                                    // Screw scale (x, y, z)
    float screwShininess = 76.8f;

    model = glm::translate(model, screwPosition);                                              // Position screw model
    model = glm::rotate(model, glm::radians(screwRotation.y), glm::vec3(0.0f, 1.0f, 0.0f));    // Rotate screw model on y axis
    model = glm::rotate(model, glm::radians(screwRotation.z), glm::vec3(0.0f, 0.0f, 1.0f));    // Rotate screw model on z axis
    model = glm::scale(model, screwScale);                                                     // Scale screw model
    
    coreProgram.setMat4(model, "model");                                                       // Pass model matrix uniform
    coreProgram.setMat4(view, "view");                                                         // Pass view matrix uniform
    coreProgram.setMat4(proj, "proj");                                                         // Pass projection matrix uniform
    coreProgram.set1f(screwShininess, "material.shininess");

    glBindVertexArray(gMesh.vao[4]);                                                           // Bind screw mesh
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nIndices[4]);                                          // Draw screw
#pragma endregion
#pragma region Caliper
    caliperTexture.bind();                                                                     // Bind caliper diffuse map
    caliperSpecMap.bind();                                                                     // Bind caliper specular map
    model = glm::mat4(1.0f);                                                                   // Revert model matrix to identity

    glm::vec3 caliperPosition(-0.25f, -0.99f, -0.08f);                                         // Screw position (x, y, z)
    glm::vec3 caliperRotation(90.0f, 0.0f, 55.0f);                                             // Screw rotation (x, y, z)
    glm::vec3 caliperScale(1.8f, 1.8f, 1.8f);                                                  // Screw scale (x, y, z)
    float caliperShininess = 32.0f;

    model = glm::translate(model, caliperPosition);                                            // Position screw model
    model = glm::rotate(model, glm::radians(caliperRotation.x), glm::vec3(1.0f, 0.0f, 0.0f));  // Rotate screw model on x axis
    model = glm::rotate(model, glm::radians(caliperRotation.z), glm::vec3(0.0f, 0.0f, 1.0f));  // Rotate screw model on z axis
    model = glm::scale(model, caliperScale);                                                   // Scale screw model

    coreProgram.setMat4(model, "model");                                                       // Pass model matrix uniform
    coreProgram.setMat4(view, "view");                                                         // Pass view matrix uniform
    coreProgram.setMat4(proj, "proj");                                                         // Pass projection matrix uniform
    coreProgram.set1f(caliperShininess, "material.shininess");

    glBindVertexArray(gMesh.vao[5]);                                                           // Bind screw mesh
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nIndices[5]);                                          // Draw screw
#pragma endregion
#pragma region Screwdriver
    model = glm::mat4(1.0f);                                                                   // Revert model matrix to identity

    glm::vec3 sdriverPosition(-0.80f, -0.87f, 0.00f);                                           // Screwdriver position (x, y, z)
    glm::vec3 sdriverRotation(0.00f, 90.0f, 0.0f);                                             // Screwdriver rotation (x, y, z)
    glm::vec3 sdriverScale(0.9f, 0.9f, 0.9f);                                                  // Screwdriver scale (x, y, z)
    float sdriverShininess = 25.6f;

    model = glm::translate(model, sdriverPosition);                                            // Position screwdriver model
    model = glm::rotate(model, glm::radians(sdriverRotation.y), glm::vec3(0.0f, 1.0f, 0.0f));  // Rotate screwdriver model on y axis
    model = glm::scale(model, sdriverScale);                                                   // Scale screwdriver model

    coreProgram.setMat4(model, "model");                                                       // Pass model matrix uniform
    coreProgram.setMat4(view, "view");                                                         // Pass view matrix uniform
    coreProgram.setMat4(proj, "proj");                                                         // Pass projection matrix uniform
    coreProgram.set1f(sdriverShininess, "material.shininess");

    glBindVertexArray(gMesh.vao[3]);                                                           // Bind screwdriver mesh
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nIndices[3]);                                          // Draw screwdriver
#pragma endregion
#pragma region Light2
    lightProgram.use();                                                                        // Activate light shader program
    model = glm::mat4(1.0f);
    
    model = glm::translate(model, lightPos0);                                                  // Position light 0 model
    model = glm::scale(model, lightCubeScale);                                                 // Scale light 0 model

    lightProgram.setMat4(model, "model");                                                      // Pass light 0 model uniform
    lightProgram.setMat4(view, "view");                                                        // Pass view uniform
    lightProgram.setMat4(proj, "proj");                                                        // Pass projection uniform

    glBindVertexArray(gMesh.vao[2]);                                                           // Bind cube mesh for light
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nIndices[2]);                                          // Draw light cube
#pragma endregion
#pragma region Light1
    model = glm::mat4(1.0f);                                                                   // Activate light cube shader program

    model = glm::translate(model, lightPos1);                                                  // Position light 1 model
    model = glm::scale(model, lightCubeScale);                                                 // Scale light 1 model

    lightProgram.setMat4(model, "model");                                                      // Pass light 1 model uniform

    glBindVertexArray(gMesh.vao[2]);                                                           // Bind cube mesh for light
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nIndices[2]);                                          // Draw light cube
#pragma endregion
#pragma region EndRendering
    lightProgram.unuse();                                                                      // Deactivate shader program
    glBindVertexArray(0);                                                                      // Deactivate VAO
    glfwSwapBuffers(gWindow);                                                                  // Bring new frame forward
    glFlush();                                                                                 // Flush buffers
#pragma endregion
}
void CreateMesh(GLMesh& mesh)
// Mesh binding, data, and buffer assignments
{
#pragma region Sizes
    const GLuint nVerts = 3;                                                                // Number of vertex floats in VAOs
    const GLuint nNorms = 3;                                                                // Number of normal floats in VAOs
    const GLuint nUVs = 2;                                                                  // Number of texture coordinates in VAOs
    const GLuint nFloats = nVerts + nNorms + nUVs;                                          // Number of floats
    void* distUV = (void*)(sizeof(float) * (nVerts + nNorms));                              // Distance to texture coordinates
    void* distNorms = (void*)(sizeof(float) * (nVerts));                                    // Distance to norms
    GLint stride = sizeof(float) * nFloats;                                                 // Distance between vertex positions

    mesh.nIndices[0] = sizeof(planeVerts) / (sizeof(planeVerts[0]) * nFloats);              // Number of vertices in plane verts array  
    mesh.nIndices[1] = sizeof(tapeVerts) / (sizeof(tapeVerts[0]) * nFloats);                // Number of vertices in tape verts array
    mesh.nIndices[2] = sizeof(lightVerts) / (sizeof(lightVerts[0]) * nFloats);              // Number of vertices in light verts array
    mesh.nIndices[3] = sizeof(sdriverVerts) / (sizeof(sdriverVerts[0]) * nFloats);          // Number of vertices in screwdriver verts array
    mesh.nIndices[4] = sizeof(screwVerts) / (sizeof(screwVerts[0]) * nFloats);              // Number of vertices in screw verts array
    mesh.nIndices[5] = sizeof(caliperVerts) / (sizeof(caliperVerts[0]) * nFloats);          // Number of vertices in caliper verts array
#pragma endregion
#pragma region Plane
    glGenVertexArrays(1, &mesh.vao[0]);
    glBindVertexArray(mesh.vao[0]);

    glGenBuffers(1, &mesh.vbo[0]);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(planeVerts), planeVerts, GL_STATIC_DRAW);

    glVertexAttribPointer(0, nVerts, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, nNorms, GL_FLOAT, GL_FALSE, stride, distNorms);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, nUVs, GL_FLOAT, GL_FALSE, stride, distUV);
    glEnableVertexAttribArray(2);
#pragma endregion
#pragma region TapeMeasure
    glGenVertexArrays(1, &mesh.vao[1]);
    glBindVertexArray(mesh.vao[1]);

    glGenBuffers(1, &mesh.vbo[1]);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(tapeVerts), tapeVerts, GL_STATIC_DRAW);

    glVertexAttribPointer(0, nVerts, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, nNorms, GL_FLOAT, GL_FALSE, stride, distNorms);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, nUVs, GL_FLOAT, GL_FALSE, stride, distUV);
    glEnableVertexAttribArray(2);
#pragma endregion
#pragma region Screw
    glGenVertexArrays(1, &mesh.vao[4]);
    glBindVertexArray(mesh.vao[4]);

    glGenBuffers(1, &mesh.vbo[4]);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo[4]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(screwVerts), screwVerts, GL_STATIC_DRAW);

    glVertexAttribPointer(0, nVerts, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, nNorms, GL_FLOAT, GL_FALSE, stride, distNorms);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, nUVs, GL_FLOAT, GL_FALSE, stride, distUV);
    glEnableVertexAttribArray(2);
#pragma endregion
#pragma region Caliper
    glGenVertexArrays(1, &mesh.vao[5]);
    glBindVertexArray(mesh.vao[5]);

    glGenBuffers(1, &mesh.vbo[5]);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo[5]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(caliperVerts), caliperVerts, GL_STATIC_DRAW);

    glVertexAttribPointer(0, nVerts, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, nNorms, GL_FLOAT, GL_FALSE, stride, distNorms);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, nUVs, GL_FLOAT, GL_FALSE, stride, distUV);
    glEnableVertexAttribArray(2);
#pragma endregion
#pragma region Screwdriver
    glGenVertexArrays(1, &mesh.vao[3]);
    glBindVertexArray(mesh.vao[3]);

    glGenBuffers(1, &mesh.vbo[3]);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(sdriverVerts), sdriverVerts, GL_STATIC_DRAW);

    glVertexAttribPointer(0, nVerts, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, nNorms, GL_FLOAT, GL_FALSE, stride, distNorms);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, nUVs, GL_FLOAT, GL_FALSE, stride, distUV);
    glEnableVertexAttribArray(2);
#pragma endregion
#pragma region Light Cube
    glGenVertexArrays(1, &mesh.vao[2]);
    glBindVertexArray(mesh.vao[2]);

    glGenBuffers(1, &mesh.vbo[2]);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.vbo[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(lightVerts), lightVerts, GL_STATIC_DRAW);

    glVertexAttribPointer(0, nVerts, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, nVerts, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, nUVs, GL_FLOAT, GL_FALSE, stride, distUV);
    glEnableVertexAttribArray(2);
#pragma endregion
}
void DestroyMesh(GLMesh& mesh)
// Free mesh data from memory
{
    glDeleteVertexArrays(3, mesh.vao);
    glDeleteBuffers(3, mesh.vbo);
}

/*     Mouse & Keyboard Handlers     */
void KeyHoldHandler(GLFWwindow* window)
// Keyboard Input Handler (allows for held key movement)
{
    // Store frame data to assist movement speed keeping framerate independent
    currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    cameraSpeed = cameraSpeedOffset * deltaTime;

    // Close window is ESC pressed
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    // W key - move forward (Positive Z axis)
    else if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camPosition += cameraSpeed * camFront;
    
    // A Key - pan left (Negative X axis)
    else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camPosition -= glm::normalize(glm::cross(camFront, worldUp)) * cameraSpeed;
    
    // S key - move backward (Negative Z axis)
    else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camPosition -= cameraSpeed * camFront;
    
    // D key - pan right (Positive X axis)
    else if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camPosition += glm::normalize(glm::cross(camFront, worldUp)) * cameraSpeed;
    
    // Q key - move up (Y axis)
    else if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        camPosition += cameraSpeed * worldUp;

    // E key - move down (Y axis)
    else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        camPosition -= cameraSpeed * worldUp;
    
}
void KeyPressHandler(GLFWwindow* window, int key, int scancode, int action, int mods)
//Keyboard Input Handler (single key press/toggle)
{
    // P key - toggle orthographic and perspective views
    if (key == GLFW_KEY_P && action == GLFW_PRESS)
    {
        // Invert boolean value
        viewToggle = !viewToggle;

        std::string currentProjection;

        if (viewToggle)
            currentProjection = "Perspective (3D)";
        else
            currentProjection = "Orthographic (2D)";

        std::cout << "[Changing Projection] -> " << currentProjection << std::endl;
    }
}
void MousePositionHandler(GLFWwindow* window, double xpos, double ypos)
// Mouse Input Handler: Cursor movement callback
{
    // Set to true upon first detection of mouse. (initializer)
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    // Local scope variables to store offsets and adjust sensitivity for camera movement
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    // Prevent maximum/minimum pitch overflow
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    // Adjust the camera direction based on yaw and pitch received by mouse position
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    camFront = glm::normalize(direction);
}
void MouseScrollHandler(GLFWwindow* window, double xoffset, double yoffset)
// Mouse Input Handler: Wheel movement callback
{
    // Adjust camera movement speed
    cameraSpeedOffset += yoffset;
    if (cameraSpeedOffset < 1.0)
        cameraSpeedOffset = 1.0;

    // Output camera speed to console
    std::cout << "[Camera Speed Adjusted] -> " << cameraSpeedOffset << ", " << yoffset << ")" << std::endl;
}
void MouseButtonHandler(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_MIDDLE && action == GLFW_PRESS)
        autoOrbit = !autoOrbit;
}
void ResizeCallback(GLFWwindow* window, int fbufferW, int fbufferH)
// Resize handler - adjust GLFW display window to user resize actions
{
    glfwGetFramebufferSize(gWindow, &fbw, &fbh);                  // Allow resizing of window without losing aspect ratio
    glViewport(0, 0, fbw, fbh);
}