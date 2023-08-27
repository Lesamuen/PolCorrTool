#include <GL/glew.h>

#define GLFW_DLL
#include <GLFW/glfw3.h>

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

    // event loop
    while (!glfwWindowShouldClose(window))
    {
        // event handling
        {
            glfwPollEvents();
        }
        
        // render frame
        {
            glfwSwapBuffers(window);
        }
    }

    glfwTerminate();
    return 0;
}