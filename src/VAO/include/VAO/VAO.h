#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include "glad/glad.h"
#include <VBO/VBO.h>

class VAO
{
    public:
        // ID refernece for the Vaertex Array Object
        GLuint ID;
        // Constructor that generates a VAO ID
        VAO();

        // Links  a VBO to the VAO using a certain laout
        void LinkAttrib(VBO &VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void *offset);
        // Binds the VAO
        void Bind();
        // Unbinds the VAO
        void Unbind();

        // DELETES THE VAO
        void Delete();
};

#endif