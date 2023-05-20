#version 330 CORE

out vec4 FragColor;

uniform vec4 lightColor;

void main()
{
    FragColor = lightColor;
}