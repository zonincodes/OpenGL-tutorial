#ifndef TEXTURE_CLASS_H
#define TEXTURE_ClASS_H

#include <glad/glad.h>
#include <stb_image/stb_image.h>

#include <shader/shaderClass.h>

class Texture
{
    public:
        GLuint ID;
        GLenum type;
        Texture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);

        // Assign a tgexture unit to a Texture
        void texUnit(Shader& shader, const char* uniform, GLuint unit);

        // Binds the texture 
        void Bind();
        // Unbinds the texture

        void Unbind();

        // Deletes a texture
        void Delete();
};

#endif