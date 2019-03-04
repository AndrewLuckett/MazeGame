#pragma once
#include <time.h>
#include <chrono>
#include "Poly.h"

namespace timesys = std::chrono;

class game {
public:
	game();
	int update();
	int fixedUpdate();
	int getRenderArr(PolySSDat** arr, uint* c);
	int cleanup();

private:
	timesys::system_clock::time_point fuLastRun;
	timesys::system_clock::time_point suLastRun;
	timesys::system_clock::duration fuTime = std::chrono::milliseconds(200);
	timesys::system_clock::duration deltaTime;

};