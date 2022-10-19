#pragma once

#include <glew.h>

GLfloat planeVerts[] = {                                                                // Plane mesh data (hard coded vertices, indices, and texture coords)
    //Position				Normal Coords				Texture Coords
    -0.5f, -0.5f, -0.5f,        0.0f, 1.0f, 0.0f,        0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,        0.0f, 1.0f, 0.0f,        1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,        0.0f, 1.0f, 0.0f,        1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,        0.0f, 1.0f, 0.0f,        1.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,        0.0f, 1.0f, 0.0f,        0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,        0.0f, 1.0f, 0.0f,        0.0f, 0.0f,
};