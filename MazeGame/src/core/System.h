#pragma once
#include "Poly.h"
#include <list>
#include <chrono>
#include <iostream>

namespace timesys = std::chrono;

class System {
    public:
	    virtual int update(timesys::system_clock::duration deltaTime) = 0;
	    virtual int fixedUpdate() = 0;

	    virtual int getRenderArr(PolySSDat* &arr, uint &c) { //Gets SSDat for elements and returns them
			std::cout << arr << std::endl;
			std::cout << &c << std::endl;

			delete[] arr;

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
			delete[] dat;

			c = count;

			return 0;
		}

	    virtual int cleanup() {
			for (auto const& i : subsystems) {
				i->cleanup();
			}
			delete &subsystems;
			return 0;
		}

		virtual int addSubSystem(System* sys) {
			subsystems.emplace_front(sys);
			return 0;
		}
    protected:
	    std::list<System*> subsystems;
};