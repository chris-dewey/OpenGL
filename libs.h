#pragma once

#include <iostream>																			 // cout, cerr
#include <cstdlib>																			 // EXIT_FAILURE
#include <glew.h>																			 // GLEW library
#include <glfw3.h>																			 // GLFW library
																							 
#include <glm.hpp>																			 // OpenGL vectors and matrices
#include <gtx/transform.hpp>																 // Vector and matrix transformations
#include <gtc/type_ptr.hpp>																	 // Pointer interactions

#include "Texture.h"																		 // Class: Texture creation and binding
#include "Shader.h"																			 // Class: Shader creation, binding, and uniform passers
#include "Mesh.h"																			 // Class: Mesh creation, binding, and buffer assignments
																							 
#include "objects/TapeMeasure.h"															 // Tape measure vertices
#include "objects/Plane.h"																	 // Plane vertices
#include "objects/Screw.h"																	 // Screw vertices
#include "objects/Screwdriver.h"															 // Screwdriver vertices
#include "objects/Light.h"																	 // Light vertices
#include "objects/Caliper.h"																 // Caliper vertices


/*     Prototypes     */
void Render();                                                                               // Render graphics
void CreateMesh(GLMesh& mesh);                                                               // Create meshes in memory
void DestroyMesh(GLMesh& mesh);                                                              // Destroy mesh from memory
void KeyHoldHandler(GLFWwindow* window);                                                     // React to user actions
void KeyPressHandler(GLFWwindow* window, int key, int scancode, int action, int mods);       // React to user actions via keyboard P key
void MousePositionHandler(GLFWwindow* window, double xpos, double ypos);                     // React to user actions via mouse movement
void MouseScrollHandler(GLFWwindow* window, double xoffset, double yoffset);                 // React to user actions via mouse scroll wheel
void MouseButtonHandler(GLFWwindow* window, int button, int action, int mods);				 // React to user actions via mouse button presses
void ResizeCallback(GLFWwindow* window, int fbw, int fbh);                                   // Set window size
