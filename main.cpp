#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <shader/shaderClass.h>
#include <VAO/VAO.h>
#include <VBO/VBO.h>
#include <EBO/EBO.h>
#include <textures/texture.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <camera/camera.h>

const unsigned int width = 800;
const unsigned int height = 800;

// Vertices coordinates
GLfloat vertices[] =
    {
        //     COORDINATES     /        COLORS          /    TexCoord   /        NORMALS       //
        -0.5f, 0.0f, 0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,  // Bottom side
        -0.5f, 0.0f, -0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 5.0f, 0.0f, -1.0f, 0.0f, // Bottom side
        0.5f, 0.0f, -0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 5.0f, 0.0f, -1.0f, 0.0f,  // Bottom side
        0.5f, 0.0f, 0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 0.0f, 0.0f, -1.0f, 0.0f,   // Bottom side

        -0.5f, 0.0f, 0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 0.0f, -0.8f, 0.5f, 0.0f,  // Left Side
        -0.5f, 0.0f, -0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 0.0f, -0.8f, 0.5f, 0.0f, // Left Side
        0.0f, 0.8f, 0.0f, 0.92f, 0.86f, 0.76f, 2.5f, 5.0f, -0.8f, 0.5f, 0.0f,   // Left Side

        -0.5f, 0.0f, -0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 0.0f, 0.0f, 0.5f, -0.8f, // Non-facing side
        0.5f, 0.0f, -0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 0.0f, 0.0f, 0.5f, -0.8f,  // Non-facing side
        0.0f, 0.8f, 0.0f, 0.92f, 0.86f, 0.76f, 2.5f, 5.0f, 0.0f, 0.5f, -0.8f,   // Non-facing side

        0.5f, 0.0f, -0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 0.0f, 0.8f, 0.5f, 0.0f, // Right side
        0.5f, 0.0f, 0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 0.0f, 0.8f, 0.5f, 0.0f,  // Right side
        0.0f, 0.8f, 0.0f, 0.92f, 0.86f, 0.76f, 2.5f, 5.0f, 0.8f, 0.5f, 0.0f,  // Right side

        0.5f, 0.0f, 0.5f, 0.83f, 0.70f, 0.44f, 5.0f, 0.0f, 0.0f, 0.5f, 0.8f,  // Facing side
        -0.5f, 0.0f, 0.5f, 0.83f, 0.70f, 0.44f, 0.0f, 0.0f, 0.0f, 0.5f, 0.8f, // Facing side
        0.0f, 0.8f, 0.0f, 0.92f, 0.86f, 0.76f, 2.5f, 5.0f, 0.0f, 0.5f, 0.8f   // Facing side
};

// Indices for vertices order
GLuint indices[] =
    {
        0, 1, 2,    // Bottom side
        0, 2, 3,    // Bottom side
        4, 6, 5,    // Left side
        7, 9, 8,    // Non-facing side
        10, 12, 11, // Right side
        13, 15, 14  // Facing side
};

GLfloat lightVertices[] =
    { //     COORDINATES     //
        -0.1f, -0.1f, 0.1f,
        -0.1f, -0.1f, -0.1f,
        0.1f, -0.1f, -0.1f,
        0.1f, -0.1f, 0.1f,
        -0.1f, 0.1f, 0.1f,
        -0.1f, 0.1f, -0.1f,
        0.1f, 0.1f, -0.1f,
        0.1f, 0.1f, 0.1f};

GLuint lightIndices[] =
    {
        0, 1, 2,
        0, 2, 3,
        0, 4, 7,
        0, 7, 3,
        3, 7, 6,
        3, 6, 2,
        2, 6, 5,
        2, 5, 1,
        1, 5, 4,
        1, 4, 0,
        4, 5, 6,
        4, 6, 7};

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
    GLFWwindow *window = glfwCreateWindow(width, height, "ZoninOpenGL1", NULL, NULL);

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
    glViewport(0, 0, width, height);

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
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 11 * sizeof(float), (void *)(3 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 2, 2, GL_FLOAT, 11 * sizeof(float), (void *)(6 * sizeof(float)));
    VAO1.LinkAttrib(VBO1, 3, 3, GL_FLOAT, 11 * sizeof(float), (void *)(8 * sizeof(float)));

    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();


    // Texture
   Texture scoobyDoo("brick-texture.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
   scoobyDoo.texUnit(shaderProgram, "tex0", 0);

    

// Enable the depth buffer
   glEnable(GL_DEPTH_TEST);

    Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));
// Main while loop
    while (!glfwWindowShouldClose(window))
    {
        // Specify the color of the background
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

        // Clear the buffer and assign the new color to it
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Tell OpenGl which Shader program we want to use
        shaderProgram.Activate();

       camera.Matrix(shaderProgram, "camMatrix");

       // Handles  camera inputs 
       camera.Inputs(window);

       // Updagtes and exports the camera matri\x to the vertex shader

       camera.updateMatrix(45.0f, 0.1f, 100.0f);

       
        // Binds the texture so that it appears in rendering
        scoobyDoo.Bind();
        // Bind the VAO so OpenGL knows to use it
        VAO1.Bind();

        // DRaw the triangle using the GL_TRIANGLES primitive
        glDrawElements(GL_TRIANGLES, sizeof(indices)/sizeof(int), GL_UNSIGNED_INT, 0);

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