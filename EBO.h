#pragma once
#include <glad.h>

class EBO
{
    public:
        GLuint ID;

        EBO(GLfloat *indices, GLsizeiptr size);

        void Bind();
        void Unbind();
        void Delete();
        
};