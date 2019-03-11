#pragma once
#include "System.h"
#include "../render/Model.h"

class FrameCounter : public System {
    public:
		FrameCounter();
		int update(timesys::system_clock::duration deltaTime);
		int fixedUpdate();
		int getRenderArr(std::queue<Model> &arr);
		int cleanup();
    private:
	    Model getCell();
};