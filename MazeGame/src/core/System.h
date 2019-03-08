#pragma once
#include "Poly.h"
#include <list>
#include <chrono>
#include <queue>

namespace timesys = std::chrono;

class System {
    public:
	    virtual int update(timesys::system_clock::duration deltaTime) = 0;
	    virtual int fixedUpdate() = 0;

		virtual int getRenderArr(std::queue<PolySSDat> &arr, uint &c); //Gets SSDat for elements and returns them
			
		int cleanup();

		int addSubSystem(System* sys);
    protected:
	    std::list<System*> subsystems;
};