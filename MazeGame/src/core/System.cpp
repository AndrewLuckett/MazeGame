#include "System.h"
#include <iostream>

int System::getRenderArr(std::queue<PolySSDat> &arr, uint & c){
	//arr = std::queue<PolySSDat>();

	for (auto const& i : subsystems) {
		i->getRenderArr(arr, c);
	}

	return 0;
}

int System::cleanup() {
	for (auto const& i : subsystems) {
		i->cleanup();
	}
	return 0;
}

int System::addSubSystem(System * sys) {
	subsystems.emplace_front(sys);
	return 0;
}
