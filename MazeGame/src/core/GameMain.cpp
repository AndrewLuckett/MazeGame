#include "GameMain.h"
//#include <iostream>

GameMain::GameMain() { //perform once
	suLastRun = timesys::system_clock::now();
	fuLastRun = timesys::system_clock::time_point::time_point();
}

int GameMain::update(timesys::system_clock::duration deltaTime) { //Perform every frame
	auto now = std::chrono::system_clock::now();
	deltaTime = now - suLastRun;
	suLastRun = now;
	if (now - fuLastRun > fuTime) {
		fuLastRun = now;
		fixedUpdate();
	}
	
	for (auto const& i : subsystems) {
		i->update(deltaTime);
	}

	return 0;
}

int GameMain::fixedUpdate() { //Perform every fixed amount of time
	//std::cout << "Beep" << std::endl;
	for (auto const& i : subsystems) {
		i->fixedUpdate();
	}
	return 0;
}

