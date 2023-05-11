#ifndef VAO_CLASS_H
#define VAO_CLASS_H

#include "glad.h"
#include "VBO.h"

class VAO
{
    public:
        // ID refernece for the Vaertex Array Object
        GLuint ID;
        // Constructor that generates a VAO ID
        VAO();

        // Links  a VBO to the VAO using a certain laout
        void LinkVBO(VBO VBO, GLuint layout);
        // Binds the VAO
        void Bind();
        // Unbinds the VAO
        void Unbind();

        // DELETES THE VAO
        void Delete();
};

#endif