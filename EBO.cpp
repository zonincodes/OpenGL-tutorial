#include <EBO.h>


EBO::EBO(GLfloat *indices, GLsizeiptr size)
{
    glGenBuffers(1, &ID);
    // Bind the EBO specifying it's a GL_ARRAY_BUFFER
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);

    // Introduce the indices to the EBO
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void EBO::Bind()
{
    // Bind the EBO specifying it's a GL_ARRAY_BUFFER
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void EBO::Delete()
{
    glDeleteBuffers(1, &ID);
}
