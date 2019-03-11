#version 400 core

in vec2 position;
in vec2 coords;

out vec2 texCo;

void main() {
    gl_Position = vec4(position, 0.0, 1.0);
	texCo = coords;
};
