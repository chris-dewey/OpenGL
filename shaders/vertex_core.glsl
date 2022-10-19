#version 440

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoords;

out vec3 Normal;
out vec3 FragPos;
out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
    gl_Position = proj * view * model * vec4(aPos, 1.0f);

    FragPos = vec3(model * vec4(aPos, 1.0f));

    Normal = mat3(transpose(inverse(model))) * aNormal;

    TexCoords = vec2(aTexCoords.x * -1.0f, aTexCoords.y * -1.0f);  // Flip image without implementing another method
}
