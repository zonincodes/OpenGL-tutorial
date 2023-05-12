#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H

#include "glad.h"
#include <string>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <iostream>
#include <cinttypes>
std::string get_file_contents(const char* filename);

class Shader
{
    public:
        // Reference ID of the Shader Program
        GLuint ID;

        // Constructor that builld the SHader Program from 2 differnt shaders
        Shader(const char* vertexFile, const char* fragmentFile);
        // Activate the shader Progrema
        void Activate();

        // Deletes the Shader Progrma
        void Delete();
    
    private:
        void compileErrors(u_int shader, const char *type);
};
#endif