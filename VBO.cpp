#include <VBO.h>

VBO::VBO(GLfloat *vertices, GLsizeiptr size)
{
    glGenBuffers(1, &ID);
    // Bind the VBO specifying it's a GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, ID);

    // Introduce the vertices to the VBO
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void VBO::Bind()
{
    // Bind the VBO specifying it's a GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Delete()
{
    glDeleteBuffers(1, &VBO);
}

