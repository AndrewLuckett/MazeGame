#include "System.h"
//#include <iostream>

int System::getRenderArr(std::queue<Model> &arr){
	for (auto const& i : subsystems) {
		i->getRenderArr(arr);
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
