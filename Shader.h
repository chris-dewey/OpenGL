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


class Shader
{
private:
	// Member variables
	GLuint programId;																// Store program ID

	// Private methods
	std::string loadShaderSource(std::string filePath)								// Read shaders from source file
	{
		std::string temp = "";
		std::string shaderSource = "";

		std::ifstream in_file;

		in_file.open(filePath);

		if (in_file.is_open())
		{
			while (std::getline(in_file, temp))
				shaderSource += temp + "\n";
		}
		else
			std::cout << "[ERROR::SHADER] Could not open shader file: " << filePath << std::endl;

		in_file.close();

		return shaderSource;
	}

	GLuint loadShader(GLenum type, std::string filePath)								// Create and load shader
	{
		int success = 0;
		char infoLog[512];

		GLuint shader = glCreateShader(type);											// Create Shader
		std::string str_src = this->loadShaderSource(filePath);							// Load shader source file

		const GLchar* src = str_src.c_str();											// Convert shader source from string to c_str
		glShaderSource(shader, 1, &src, NULL);											// Retrive Source
		glCompileShader(shader);														// Compile

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);								// Error Handling
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			std::cout << "[ERROR::SHADER] " << filePath << " COMPILATION FAILED\n" << infoLog << std::endl;
		}

		return shader;
	}

	void linkProgram(GLuint vertexShader, GLuint geometryShader, GLuint fragmentShader)
	{
		int success = 0;
		char infoLog[512];
		this->programId = glCreateProgram();
		glAttachShader(this->programId, vertexShader);									// Attach vertex shader

		if (geometryShader)
			glAttachShader(this->programId, geometryShader);							// Attach geometry shader (if passed)

		glAttachShader(this->programId, fragmentShader);								// Attach fragment Shader

		glLinkProgram(this->programId);													// Link shader program

		glGetProgramiv(this->programId, GL_LINK_STATUS, &success);						// Error Handling
		if (!success)
		{
			glGetProgramInfoLog(this->programId, 512, NULL, infoLog);
			std::cout << "[ERROR::SHADER] Could not link shader program.\n" << infoLog << std::endl;
		}
	}

public:
	// Constructor
	Shader() {}																		// Empty constructor for global instantiation

	void createShaders(std::string vertexFilePath, std::string fragmentFilePath, std::string geometryFilePath = "")
	{
		GLuint vertexShader = 0;
		GLuint geometryShader = 0;
		GLuint fragmentShader = 0;

		vertexShader = loadShader(GL_VERTEX_SHADER, vertexFilePath);				// Load vertex shader

		if (geometryFilePath != "")
			geometryShader = loadShader(GL_GEOMETRY_SHADER, geometryFilePath);		// Load geometry shader if used


		fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragmentFilePath);			// Load fragment shader

		this->linkProgram(vertexShader, geometryShader, fragmentShader);			// Link shader program

		
		glDeleteShader(vertexShader);												// Free vertex shader from memory
		glDeleteShader(geometryShader);												// Free geometry shader from memory
		glDeleteShader(fragmentShader);												// Free fragment shader from memory
		glUseProgram(0);														    // Deactivate shader program
	}

	// Uniform functions
	void use()
	{
		glUseProgram(this-> programId);
	}

	void unuse()
	{
		glUseProgram(0);
	}

	void set1i(GLint value, const GLchar* name)
	{
		glUniform1i(glGetUniformLocation(this->programId, name), value);
	}

	void set1f(GLfloat value, const GLchar* name)
	{
		glUniform1f(glGetUniformLocation(this->programId, name), value);
	}

	void setVec2fv(glm::fvec2 value, const GLchar* name)
	{
		glUniform2fv(glGetUniformLocation(this->programId, name), 1, glm::value_ptr(value));
	}

	void setVec4fv(glm::fvec4 value, const GLchar* name)
	{
		glUniform4fv(glGetUniformLocation(this->programId, name), 1, glm::value_ptr(value));
	}

	void setVec3(glm::fvec3 value, const GLchar* name)
	{
		glUniform3fv(glGetUniformLocation(this->programId, name), 1, glm::value_ptr(value));
	}

	void setMat3fv(glm::mat3 value, const GLchar* name, GLboolean transpose = GL_FALSE)
	{
		glUniformMatrix3fv(glGetUniformLocation(this->programId, name), 1, transpose, glm::value_ptr(value));
	}

	void setMat4(glm::mat4 value, const GLchar* name, GLboolean transpose = GL_FALSE)
	{
		glUniformMatrix4fv(glGetUniformLocation(this->programId, name), 1, transpose, glm::value_ptr(value));
	}

	// Destructor
	~Shader()
	{
		glDeleteProgram(this->programId);
	}
};