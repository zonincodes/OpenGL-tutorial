#include <iostream>
#include <glad.h>
#include <GLFW/glfw3.h>
#include <cmath>


// Entry point
int main(int argc, char **argv)
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

    // vertices coordinates
    GLfloat vertices[] =
        {
            -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,   // lower left corner
            0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,    // lower right corner
            0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // upper corner

            -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner Left
            0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,  // inner right
            0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f      // inner down
        };

    GLuint indices[] =
        {
            0, 3, 5, // lower left triangle
            3, 2, 4, // lower right triangle
            5, 4, 1  // Upper triangle
        };

    // create a GLFWwindow object of  800, by 800 pixels, naming it "ZoninOpenGL"
    GLFWwindow *window = glfwCreateWindow(800, 800, "ZoninOpenGL1", NULL, NULL);

    // Error check if gthe window fails to create
    if (window == NULL)
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


    // Create reference containers for the Vertex Array Object and the Vertex Buffer Object
    GLuint VAO, VBO, EBO;

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // Tell OpenGL which Shader Program we want to use
        // Bind the VAO so OpenGL knows to use it
        glBindVertexArray(VAO);
        // DRaw the triangle using the GL_TRIANGLES primitive
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        // take care of all GLFW events
        glfwPollEvents();
    }

    // delete window pointer before ending the program
    glfwDestroyWindow(window);

    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;
}