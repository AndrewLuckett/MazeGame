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

int GameMain::getRenderArr(PolySSDat** arr, uint* c) { //Gets SSDat for elements and returns them
	delete *arr; //Delete old array

	uint* curr = new uint[subsystems.size()];
	PolySSDat** dat = new PolySSDat*[subsystems.size()];

	uint j = 0;
	for (auto const& i : subsystems) {
		i->getRenderArr(&dat[j],&curr[j]);
		j++;
	}

	PolySSDat* out = new PolySSDat[j];

	uint count = 0;
	for (int i = 0; i < subsystems.size(); i++) {
		for (uint j = 0; j < curr[i]; j++) {
			out[count] = dat[i][j];
			count++;
		}
	}
	*arr = out;
	*c = count;

	return 0;
}

int GameMain::cleanup() {
	for (auto const& i : subsystems) {
		i->cleanup();
	}
	delete &subsystems;
	return 0;
}
