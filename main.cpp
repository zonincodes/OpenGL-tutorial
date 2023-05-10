#include <iostream>
#include <glad.h>
#include <GLFW/glfw3.h>

int main()
{
    // initialize GLFW
    glfwInit();

    // Tell GLFW what version of OpenGl to use
    // in this case we are using OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Tell GLFW we are using the CORE profile
    // So that means we only have the modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //create a GLFWwindow object of  800, by 800 pixels, naming it "ZoninOpenGL"
    GLFWwindow *window = glfwCreateWindow(800, 800, "ZoninOpenGL", NULL, NULL);

    // Error check if gthe window fails to create
    if(window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        
    }

    // Ingtroduce the window into the current context
    glfwMakeContextCurrent(window);

    // load OpenGl with glad
    gladLoadGL();

    // specify the viewport goes from x = y, y = 0, x = 800, y = 800
    glViewport(0, 0, 800, 800);

    //specify the color of the background
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

    //clean the backbuffer and assign the new color to it
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap the back buffer with the front buffer
    glfwSwapBuffers(window);

    while(!glfwWindowShouldClose(window))
    {
        // take care of all GLFW events
        glfwPollEvents();
    }
    // delete window pointer before ending the program
    glfwDestroyWindow(window);

    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;

}