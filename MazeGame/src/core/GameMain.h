#pragma once
//#include <time.h>
#include <chrono>
#include "Poly.h"
#include "System.h"

class GameMain : public System {
    public:
		GameMain();
	    int update(timesys::system_clock::duration deltaTime);
	    int fixedUpdate();
	    int getRenderArr(PolySSDat** arr, uint* c);
	    int cleanup();
    private:
	    timesys::system_clock::time_point fuLastRun;
	    timesys::system_clock::time_point suLastRun;
	    timesys::system_clock::duration fuTime = timesys::milliseconds(200);
	    timesys::system_clock::duration deltaTime;
};