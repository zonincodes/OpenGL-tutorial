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

    GLfloat vertices[] =
        {
            -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
            0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,
            0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f

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

    // shaders 
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // wrap up the shader
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // vertex buffer objects
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    // specify the color of the background
    glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

    // clean the backbuffer and assign the new color to it
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap the back buffer with the front buffer
    glfwSwapBuffers(window);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        // take care of all GLFW events
        glfwPollEvents();
    }

    // delete all objects created
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    // delete window pointer before ending the program
    glfwDestroyWindow(window);

    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;
}