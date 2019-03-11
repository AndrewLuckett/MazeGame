#include "FrameCounter.h"
#include <iostream>

#include "../render/Window.h"
#include "../render/Texture.h"
#include "../render/Vao.h"

timesys::system_clock::duration sumTime;
uint frames;
int fps;
Model out;
uint test;
const std::string textpaths[10] = { "res/textures/notes.png" };

FrameCounter::FrameCounter() {
	out = getCell();
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
	//TODO: Return graphics
	rect size = renderer::getWindowSize();
	vec2 cellSize;
	cellSize.x = 40.0f / size.x;
	cellSize.y = 40.0f / size.y;

	
	arr.push(out);
	
	return 0;
}

Model FrameCounter::getCell() {
	std::vector<vec2> v = { {-1.0f,1.0f},
	                        {-0.9f,1.0f},
	                        {-0.9f,0.9f},
							{-1.0f,0.9f} };
	std::vector<vec2> t = { {0.0f,0.0f},{1.0f,0.0f},{1.0f,1.0f},{0.0f,1.0f} };
	return Model(createVAO(v,t), loadTexture(textpaths[0]));
}

int FrameCounter::cleanup() {
	return 0;
}
