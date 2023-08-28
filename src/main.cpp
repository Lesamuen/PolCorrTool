#include <glm/glm.hpp>

#include <GL/glew.h>

#define GLFW_DLL
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "shaders.h"

#include <cstdio>

int main(int argc, char **argv)
{
    // init glfw lib
    if (!glfwInit())
    {
        // glfw init failed, get error
        fprintf(stderr, "Failed to init GLFW: %d\n", glfwGetError(NULL));

        return 1;
    }

    // window params
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // create window context
    GLFWwindow *window = glfwCreateWindow(1600, 900, "PolCorrTool DEV", nullptr, nullptr);
    if (!window)
    {
        // window creation failed, get error
        fprintf(stderr, "Failed to create window: %d\n", glfwGetError(NULL));

        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    // init glew lib
    glewExperimental = GL_TRUE;
    GLenum glewErr = glewInit();
    if (glewErr != GLEW_OK)
    {
        // glew init failed, get error
        fprintf(stderr, "Failed to init GLEW: %s\n", glewGetErrorString(glewErr));

        glfwTerminate();
        return 1;
    }

    // compile shaders
    GLuint shaders[] = 
    {
        glCreateShader(GL_VERTEX_SHADER),
        glCreateShader(GL_FRAGMENT_SHADER),
        glCreateShader(GL_VERTEX_SHADER),
        glCreateShader(GL_FRAGMENT_SHADER)
    };
    
    glShaderSource(shaders[0], 1, &flatVert, NULL);
    glShaderSource(shaders[1], 1, &flatFrag, NULL);
    glShaderSource(shaders[2], 1, &perspVert, NULL);
    glShaderSource(shaders[3], 1, &perspFrag, NULL);

    for (int i = 0; i < 4; i++)
    {
        glCompileShader(shaders[i]);

        GLint compiled;
        glGetShaderiv(shaders[i], GL_COMPILE_STATUS, &compiled);

        fprintf(stdout, "Shader %d compile status: %d\n", i, compiled);

        char compileLog[512];
        glGetShaderInfoLog(shaders[i], 512, NULL, compileLog);

        fprintf(stdout, "Compilation log: %s\n", compileLog);
    }

    // link shaders
    GLuint shaderPrograms[] =
    {
        glCreateProgram(),
        glCreateProgram()
    };

    glAttachShader(shaderPrograms[0], shaders[0]);
    glAttachShader(shaderPrograms[0], shaders[1]);
    glAttachShader(shaderPrograms[1], shaders[2]);
    glAttachShader(shaderPrograms[1], shaders[3]);

    for (int i = 0; i < 2; i++)
    {
        glLinkProgram(shaderPrograms[i]);

        GLint linked;
        glGetProgramiv(shaderPrograms[i], GL_LINK_STATUS, &linked);

        fprintf(stdout, "Shader program %d link status: %d\n", i, linked);

        char linkLog[512];
        glGetProgramInfoLog(shaders[i], 512, NULL, linkLog);

        fprintf(stdout, "Linking log: %s\n", linkLog);
    }

    // event loop
    while (!glfwWindowShouldClose(window))
    {
        // event handling
        glfwPollEvents();
        
        // render frame
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}