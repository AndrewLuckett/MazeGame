#include "FrameCounter.h"
//#include <iostream>

#include "../render/RenderMain.h"

timesys::system_clock::duration sumTime;
uint frames;
int fps;

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

	//std::cout << fps << std::endl;

	frames = 0;
	sumTime = timesys::system_clock::duration();

	return 0;
}

int FrameCounter::getRenderArr(std::queue<PolySSDat> &arr) {
	//TODO: Return graphics
	rect size = renderer::getWindowSize();
	vec2 cellSize;
	cellSize.x = 40.0f / size.x;
	cellSize.y = 40.0f / size.y;

	arr.push(getCell(cellSize, 0));
	arr.push(getCell(cellSize, 2));

	return 0;
}

PolySSDat FrameCounter::getCell(vec2 &cellSize,int i) {
	std::vector<vec2> v = { {cellSize.x*i - 1.0f,1.0f},
	                        {cellSize.x*(i+1) - 1.0f,1.0f },
	                        {cellSize.x*(i+1) - 1.0f,1.0f - cellSize.y},
	                        {cellSize.x*i - 1.0f,1.0f - cellSize.y}	};
	std::vector<uint> e = { 0,1,2,0,2,3 };
	return PolySSDat(v, 4, e);
}

int FrameCounter::cleanup() {
	return 0;
}
