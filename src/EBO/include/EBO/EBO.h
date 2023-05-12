#ifndef EBO_CLASS_H
#define EBO_CLASS_H
#include "glad/glad.h"

class EBO
{
    public:
        // ID refernece of elements Buffer Object
        GLuint ID;
        // Constructor that generates a Eemengts Buffer Object and links it to indices
        EBO(GLuint *indices, GLsizeiptr size);

        // Binds the EBO
        void Bind();
        // Unbinds the EBO
        void Unbind();

        // Deletes the EBO
        void Delete();
};

#endif