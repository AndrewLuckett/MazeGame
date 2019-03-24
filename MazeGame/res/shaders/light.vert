#version 400 core

in vec2 position;
in vec2 coords;

uniform vec3 trana;
uniform vec3 tranb;

out vec2 texCo;

void main() {
    gl_Position = vec4(position.x*trana.x + position.y*trana.y + trana.z,
					   position.x*tranb.x + position.y*tranb.y + tranb.z,
					   0.0,
					   1.0);
	texCo = coords;
};
