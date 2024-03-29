#version 330

layout (location = 0) in vec3 v3Position;
layout (location = 1) in vec2 v2TexPosition;

uniform mat4 matCamera;
uniform mat4 matPosition;
uniform mat4 matRotation;
uniform mat4 matScale;

out vec2 TexCoord;

void main()
{
	gl_Position = matCamera * matPosition * matRotation
                            * matScale * vec4(v3Position, 1.0f);
	TexCoord = v2TexPosition;
}

