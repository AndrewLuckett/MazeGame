#version 400 core

out vec4 colour;

in vec2 texCo;

uniform sampler2D texSampler;

void main() {
    colour = texture(texSampler,texCo);
    //colour = vec4(1.0,0.0,1.0,1.0);
};
