#include <textures/texture.h>

Texture::Texture(const char *image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType){

    // Assign the type of the texture on the texturre object
    type = texType;

    // Stores the width, height, and the number of color channels of the image
    int widthImg, heightImg, numColCh;

    // Flips image so it appears righ side up
    stbi_set_flip_vertically_on_load(true);

    // Reads the image from a file and stores it in bytes
    unsigned char *bytes = stbi_load(image, &widthImg, &heightImg, &numColCh, 0);

    // Generates an OpenGl texture object
    
    glGenTextures(1, &ID);
    // Assigns the texture to a Texture unit
    glActiveTexture(slot);
    glBindTexture(texType, ID);

    // Configure the type of algorithm thar is used to make the image smaller or bigger
    glTexParameteri(texType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(texType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // configure the way the texture repeats (if it does at all)
    glTexParameteri(texType, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(texType, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // Extra lines in case you choose to use GL_ClAMP_TO_BORDER
    // float flatColor[] = {1.0f, 1.0f, 1.0f, 1.0f};
    // glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, flatColor);

    // Assigns the image to the OpenGL Texture object
    glTexImage2D(texType, 0, GL_RGBA, widthImg, heightImg, 0, format, pixelType, bytes);

    // Generates MipMaps
    glGenerateMipmap(texType);

    // Deletes the image data as it is alread in the OpenGL Texture objext

    stbi_image_free(bytes);

    // Unbinds the OpenGL texture object so that it can't accidantally be modified
    glBindTexture(texType, 0);
}

void Texture::texUnit(Shader &shader, const char *uniform, GLuint unit)
{
    // Gets the Loacation of the uniform
    GLuint texUni = glGetUniformLocation(shader.ID, uniform);

    // Shader needs to be activated before changing the value of a uniform
    shader.Activate();

    // Sets the value of the uniform
    glUniform1i(texUni, unit);
}

void Texture::Bind()
{
    glBindTexture(type, ID);
}

void Texture::Unbind()
{
    glBindTexture(type, 0);
}

void Texture::Delete()
{
    glDeleteTextures(1, &ID);
}
