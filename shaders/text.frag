#version 330

in vec2 TexCoords; 
out vec4 color;

uniform sampler2D text;
uniform vec3 Color;

void main()
{    
    vec4 sampled = vec4(1.0, 1.0, 1.0, texture(text, TexCoords).r);
    color = vec4(Color, 1.0) * sampled;
}

