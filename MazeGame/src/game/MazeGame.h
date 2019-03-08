#include "../core/System.h"

class MazeGame : public System {
public:
	int update(timesys::system_clock::duration deltaTime);
	int fixedUpdate();
	int getRenderArr(std::queue<PolySSDat> &arr, uint &c);
};