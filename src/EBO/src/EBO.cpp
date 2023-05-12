#include <EBO/EBO.h>


// Constructor that generates Elemnts Buffer Object and links it to indices
EBO::EBO(GLuint *indices, GLsizeiptr size)
{
    glGenBuffers(1, &ID);
    // Bind the EBO specifying it's a GL_ARRAY_BUFFER
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);

    // Introduce the indices to the EBO
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

// Bind the EBO
void EBO::Bind()
{
    // Bind the EBO specifying it's a GL_ARRAY_BUFFER
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete()
{
    glDeleteBuffers(1, &ID);
}
