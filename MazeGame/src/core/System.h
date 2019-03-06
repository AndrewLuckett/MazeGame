#pragma once
#include "Poly.h"
#include <list>
#include <chrono>

namespace timesys = std::chrono;

class System {
    public:
	    virtual int update(timesys::system_clock::duration deltaTime) = 0;
	    virtual int fixedUpdate() = 0;
	    virtual int getRenderArr(PolySSDat** arr, uint* c) = 0;
	    virtual int cleanup() = 0;
		virtual int addSubSytem(System* sys) {
			subsystems.emplace_front(sys);
			return 0;
		}
    protected:
	    std::list<System*> subsystems;
};