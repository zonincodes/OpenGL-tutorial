#include <iostream>
#include <glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";
// Fragment Shader source code
const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
                                   "}\n\0";

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
            -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,  // lower left corner
            0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,   // lower right corner
            0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // upper corner
        
            -0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,           // Inner Left
            0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // inner right
            0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f     // inner down
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

    // Create Vertex Shader Object and get refence
   

    // Create reference containers for the Vertex Array Object and the Vertex Buffer Object
    GLuint VAO, VBO, EBO;

    // Generate the VAO and VBO with only 1 object each
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &EBO);
    // Make the VAO the current Vertex Array Object by binding it
    glBindVertexArray(VAO);

   
    

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Configure  the Vertex Attribute so that OpenGl knows how to read the VBO
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

    // Enable the Vertex Attribute so that OpenGL knows to use it
    glEnableVertexAttribArray(0);

    // Bind both the VBO and VAO to 0 si we do not accidentally modify the VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        // Tell OpenGL which Shader Program we want to use
        // Bind the VAO so OpenGL knows to use it
        glBindVertexArray(VAO);
        // DRaw the triangle using the GL_TRIANGLES primitive
        glDrawElements(GL_TRIANGLES,  9, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        // take care of all GLFW events
        glfwPollEvents();
    }

    // delete all objects created
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &EBO);
    // delete window pointer before ending the program
    glfwDestroyWindow(window);

    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;
}