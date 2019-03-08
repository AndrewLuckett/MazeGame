#include "FrameCounter.h"
#include <iostream>

timesys::system_clock::duration sumTime;
uint frames;

//TODO: render to screen

int FrameCounter::update(timesys::system_clock::duration deltaTime) {
	sumTime += deltaTime;
	frames ++;
	return 0;
}

int FrameCounter::fixedUpdate() {
	auto ms = timesys::duration_cast<timesys::milliseconds>(sumTime);
	if (ms.count() != 0) {
		std::cout << (frames*1000.0) / ms.count() << std::endl;
	}

	frames = 0;
	sumTime = timesys::system_clock::duration();

	return 0;
}

int FrameCounter::getRenderArr(PolySSDat* &arr, uint &c) {
	arr = new PolySSDat[0];
	c = 0;
	return 0;
}

int FrameCounter::cleanup() {
	return 0;
}
