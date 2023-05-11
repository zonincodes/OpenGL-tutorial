#include "VAO.h"


// constrctor that generates a VAO ID
VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}


// links a VBO to the VAO using a certain Layout
void VAO::LinkVBO(VBO &VBO, GLuint layout)
{
    VBO.Bind();
    // Configure  the Vertex Attribute so that OpenGl knows how to read the VBO
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
    // Enable the Vertex Attribute so that OpenGL knows to use it
    glEnableVertexAttribArray(layout);
    VBO.Unbind();
}

// Binds the VAO
void VAO::Bind()
{
    // Make the VAO the current Vertex Array Object by binding it
    glBindVertexArray(ID);
}

// Unbinds the VAO
void VAO::Unbind()
{
    glBindVertexArray(0);
}

// Deletes the VAO
void VAO::Delete()
{
    glDeleteVertexArrays(1, &ID);
}