#include <VAO/VAO.h>


// constrctor that generates a VAO ID
VAO::VAO()
{
    glGenVertexArrays(1, &ID);
}


// links a VBO to the VAO using a certain Layout
void VAO::LinkAttrib(VBO &VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void *offset)
{
    VBO.Bind();
    // Configure  the Vertex Attribute so that OpenGl knows how to read the VBO
    glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
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