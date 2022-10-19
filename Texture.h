#pragma once

#include<iostream>
#include<string>
#include<glew.h>
#include<glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "common/stb_image.h"


class Texture
{
private:
	GLuint textureId;
    int width, height, channels;
    GLenum type;
    GLint textureUnit;

public:
    Texture() {}

	void createTexture(const char* filePath, GLint textureUnit, GLenum type = GL_TEXTURE_2D)
	{
        if (this->textureId)
        {
            glDeleteTextures(1, &this->textureId);
        }
        
        unsigned char* image = stbi_load(filePath, &this->width, &this->height, &this->channels, 0);

        this->type = type;
        this->textureUnit = textureUnit;

        if (image)
        {
            glGenTextures(1, &this->textureId);                                          // Generate and bind texture
            glBindTexture(type, this->textureId);

            // Set wrapping and filtering parameters
            glTexParameteri(type, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(type, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(type, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(type, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);


            if (this->channels == 3)  // No Alpha                                        // Adjust channels if transparent layers exist in the original image
                glTexImage2D(type, 0, GL_RGB8, this->width, this->height, 0, GL_RGB,
                    GL_UNSIGNED_BYTE, image);
            else if (this->channels == 4)  // Alpha
                glTexImage2D(type, 0, GL_RGBA8, this->width, this->height, 0,
                    GL_RGBA, GL_UNSIGNED_BYTE, image);


            glGenerateMipmap(type);                                       // Generate mipmap

            stbi_image_free(image);
            glBindTexture(type, 0);                                       // Unbind texture
        }
        else
        {
            std::cout << "[ERROR::TEXTURE] Failed to load texture: " << filePath << std::endl;
        }
        
	}

	~Texture()
	{
		glDeleteTextures(1, &this->textureId);
	}

    GLuint getId() const
    {
        return this->textureId;
    }

    void bind()                              // texture unit allows multiple textures
    {
        glActiveTexture(GL_TEXTURE0 + this->textureUnit);
        glBindTexture(this->type, this->textureId);
    }

    void unbind(GLenum type = GL_TEXTURE_2D)
    {
        glActiveTexture(0);
        glBindTexture(type, 0);
    }

    GLint getTextureUnit()
    {
        return this->textureUnit;
    }

    GLint getId()
    {
        return this->textureId;
    }
};