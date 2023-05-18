#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <shader/shaderClass.h>
#include <VAO/VAO.h>
#include <VBO/VBO.h>
#include <EBO/EBO.h>
#include <textures/texture.h>

// Entry point
// vertices coordinates
GLfloat vertices[] =
    {
        //     COORDINATES      /       COLORS
        -0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 0.0f,       0.0f, 0.0f, // lower left corner
        -0.5f, 0.5f, 0.0f,      0.0f, 1.0f, 0.0f,       0.0f, 1.0f,  // lower right corner
        0.5f, 0.5f, 0.0f,       0.0f, 0.0f, 1.0f,       1.0f, 1.0f,   // upper right corner
        0.5f, -0.5f, 0.0f,      1.0f, 1.0f, 1.0f,       1.0f, 0.0f   // lower left corner
};

// Indices for verices order
GLuint indices[] =
    {
        0, 2, 1, // Uper triangle
        0, 3, 2, // lower triangle
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
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 8 * sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *)(3 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 8 * sizeof(float), (void *)(6 * sizeof(float)));

    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

    // Texture
   Texture scoobyDoo("scooby-doo.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGB, GL_UNSIGNED_BYTE);
   scoobyDoo.texUnit(shaderProgram, "tex0", 0);

    while (!glfwWindowShouldClose(window))
    {
        // Specify the color of the background
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

        // Clear the buffer and assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT);

        // Tell OpenGl which Shader program we want to use
        shaderProgram.Activate();
        // Assigns a value to the uniform; NOTE: Must always be done after activating the Shader Program
        glUniform1f(uniID, 0.0f);
        // Binds the texture so that it appears in rendering
        scoobyDoo.Bind();
        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();

        // DRaw the triangle using the GL_TRIANGLES primitive
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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
    scoobyDoo.Delete();
    // delete window pointer before ending the program
    glfwDestroyWindow(window);
    
    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;
}