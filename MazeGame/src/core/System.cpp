#include "System.h"

int System::getRenderArr(PolySSDat *& arr, uint & c){
	delete[] arr; //delete old array

	uint* curr = new uint[subsystems.size()];
	PolySSDat** dat = new PolySSDat*[subsystems.size()];

	uint count = 0;
	for (auto const& i : subsystems) {
		i->getRenderArr(dat[count], curr[count]);
		count++;
	}

	arr = new PolySSDat[count];

	count = 0;
	for (int i = 0; i < subsystems.size(); i++) {
		for (uint j = 0; j < curr[i]; j++) {
			arr[count] = dat[i][j];
			count++;
		}
		delete[] dat[i];
	}
	delete[] curr;
	delete[] dat;

	c = count;

	return 0;
}

int System::cleanup() {
	for (auto const& i : subsystems) {
		i->cleanup();
	}
	delete &subsystems;
	return 0;
}

int System::addSubSystem(System * sys) {
	subsystems.emplace_front(sys);
	return 0;
}
