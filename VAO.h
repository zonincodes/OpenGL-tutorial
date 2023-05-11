#pragma once

#include <glad.h>
#include <VBO.h>

class VAO
{
    public:
        GLuint ID;
        VAO();
        void LinkVBO(VBO VBO, GLuint layout);
        void Bind();
        void Unbind();
        void Delete();
};