#pragma once
#include "System.h"

class FrameCounter : public System {
    public:
		int update(timesys::system_clock::duration deltaTime);
		int fixedUpdate();
		int getRenderArr(std::queue<PolySSDat> &arr);
		int cleanup();
    private:
	    PolySSDat getCell(vec2 &cellSize, int i);
};