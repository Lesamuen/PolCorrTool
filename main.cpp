#include <GL/glew.h>

#define GLFW_DLL
#include <GLFW/glfw3.h>

#include <iostream>

int main(int argc, char **argv)
{
    // init glfw lib
    if (!glfwInit())
    {
        // glfw init failed, get error
        std::cout << "Failed to init GLFW: " << glfwGetError(NULL) << std::endl;

        return 1;
    }

    // window params
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // create window context
    GLFWwindow *window = glfwCreateWindow(1600, 900, "PolCorrTool DEV", nullptr, nullptr);
    if (!window)
    {
        // window creation failed, get error
        std::cout << "Failed to create window: " << glfwGetError(NULL) << std::endl;

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
        std::cout << "Failed to init GLEW: " << glewGetErrorString(glewErr) << std::endl;

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