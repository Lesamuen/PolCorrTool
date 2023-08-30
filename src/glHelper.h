#ifndef GL_H
#define GL_H

#define GLFW_DLL
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

/*
Initializes both GLEW (OpenGL bindings) and GLFW (windows and input)
Returns nullptr if some kind of error occurred, otherwise returns the window context for app
*/
GLFWwindow* init();

#endif