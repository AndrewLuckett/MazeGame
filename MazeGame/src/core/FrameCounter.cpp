#include "FrameCounter.h"
#include <iostream>
#include <sstream>

#include "../render/Window.h"
#include "../render/Texture.h"
#include "../render/Vao.h"

FrameCounter::FrameCounter() {
	out = getCell();
	for (int i = 0; i < 10; i++) {
		std::stringstream ss;
		ss << "res/textures/num/" << i << ".png";
		textures[i] = loadTexture(ss.str(),GL_NEAREST);
	}
}

int FrameCounter::update(timesys::system_clock::duration deltaTime) {
	sumTime += deltaTime;
	frames ++;
	return 0;
}

int FrameCounter::fixedUpdate() {
	int ms = (int) timesys::duration_cast<timesys::milliseconds>(sumTime).count();
	if (ms != 0) {
		fps = (frames * 1000) / ms;
	}

	std::cout << fps << std::endl;

	frames = 0;
	sumTime = timesys::system_clock::duration();

	return 0;
}

int FrameCounter::getRenderArr(std::queue<Model> &arr) {
	//fps to string
	//for each digit of the string
	out.textureId = textures[fps % 10];
	//out.transform = blah
	arr.push(out);
	
	return 0;
}

Model FrameCounter::getCell() {
	Model out = createVAO();
	std::vector<vec2> v = { {-1.0f,1.0f},
	                        {-0.9f,1.0f},
	                        {-0.9f,0.9f},
							{-1.0f,0.9f} };
	std::vector<vec2> t = { {0.0f,0.0f},{1.0f,0.0f},{1.0f,1.0f},{0.0f,1.0f} };
	loadVertexData(out, v);
	loadTextureCoordinates(out, t);
	return out;
}

int FrameCounter::cleanup() {
	return 0;
}
