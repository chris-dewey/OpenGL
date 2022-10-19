#pragma once

#include <iostream>         // cout, cerr
#include <cstdlib>          // EXIT_FAILURE
#include <glew.h>        // GLEW library
#include <glfw3.h>
#include <fstream>
#include <string>


// GLM Math Header inclusions
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

struct GLMesh
{
    GLuint vao[6];                                                                           // Vertex array object
    GLuint vbo[6];                                                                           // Vertex buffer objects
    GLuint nIndices[6];                                                                      // Number of indices of the mesh
};

const GLuint nVerts = 3;
const GLuint nNorms = 3;
const GLuint nUVs = 2;
const GLuint nFloats = nVerts + nNorms + nUVs;
void* distUV = (void*)(sizeof(float) * (nVerts + nNorms));
GLint stride = sizeof(float) * nFloats;

GLMesh gMesh;

class Mesh
{
private:
    GLuint meshId;
    GLuint VAO;
    GLuint VBO;
    GLuint nIndices;
    GLuint numVerts;
    GLuint nVerts = 3;
    GLuint nNorms = 3;
    GLuint nUVs = 2;
    int distUV = sizeof(float) * (nVerts + nNorms);
    GLint stride = sizeof(float) * nFloats;
    GLuint nFloats;


    void generateBuffers(GLfloat* verts)
    {
        glGenVertexArrays(1, &this->VAO);
        glGenBuffers(1, &this->VBO);
        glBindVertexArray(this->VAO);

        glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

        glVertexAttribPointer(0, nVerts, GL_FLOAT, GL_FALSE, this->stride, 0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, nVerts, GL_FLOAT, GL_FALSE, this->stride, 0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, nVerts, GL_FLOAT, GL_FALSE, this->stride, (void*)this->distUV);
        glEnableVertexAttribArray(2);
    }

public:
    Mesh() {}

    void createMesh(GLfloat* verts, int size0, int size1)
    {
        this->numVerts = size0 / (size1 * nFloats);
        this->generateBuffers(verts);
        this->nFloats = this->nVerts + this->nNorms + nUVs;
        this->stride = sizeof(float) * this->nFloats;
    }

    ~Mesh() 
    {
        glDeleteVertexArrays(3, &this->VAO);
        glDeleteBuffers(3, &this->VBO);
    }

    void bind()
    {
        glBindVertexArray(this->VAO);
    }

    GLuint getNumVerts()
    {
        return this->numVerts;
    }
};
