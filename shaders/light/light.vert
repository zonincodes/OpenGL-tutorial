#version 330 CORE

layout (location = 0) in vec3 aPos;

uniform mat4 model;
uniform mat4 camMatrix;

void main()
{
    gl_position = camMatrix * model * vec4 (aPos, 1.0f);
}