#include <iostream>
#include "glad.h"
#include <GLFW/glfw3.h>
#include <cmath>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
// Entry point

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

// Indices for verices order
GLuint indices[] =
    {
        0, 3, 5, // lower left triangle
        3, 2, 4, // lower right triangle
        5, 4, 1  // Upper triangle
};

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

    // create a GLFWwindow object of  800, by 800 pixels, naming it "ZoninOpenGL"
    GLFWwindow *window = glfwCreateWindow(800, 800, "ZoninOpenGL1", NULL, NULL);

    // Error check if gthe window fails to create
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Ingtroduce the window into the current context
    glfwMakeContextCurrent(window);

    // load OpenGl with glad
    gladLoadGL();

    // specify the viewport goes from x = y, y = 0, x = 800, y = 800
    glViewport(0, 0, 800, 800);

    // Generate Shder object using shader default.vert and default.frag
    Shader shaderProgram("default.vert", "default.frag");

    //  Generates Vertex Array Object and binds it
    VAO VAO1;
    VAO1.Bind();

    // Generates Vertex Buffer and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    // Generates Element Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));

    // links VBO to VAO
    VAO1.LinkVBO(VBO1, 0);

    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    while (!glfwWindowShouldClose(window))
    {
        // Specify the color of the background
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

        // Clear the buffer and assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT);

        // Tell OpenGl which Shader program we want to use
        shaderProgram.Activate();
        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();

        // DRaw the triangle using the GL_TRIANGLES primitive
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

        // swap the back buffer with the front buffer
        glfwSwapBuffers(window);
        // take care of all GLFW events
        glfwPollEvents();
    }

    // delete all the objects we've create
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();
    // delete window pointer before ending the program
    glfwDestroyWindow(window);
    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;
}