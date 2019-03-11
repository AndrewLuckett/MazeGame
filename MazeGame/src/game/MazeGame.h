#include "../core/System.h"
#include "../render/Model.h"

class MazeGame : public System {
public:
	int update(timesys::system_clock::duration deltaTime);
	int fixedUpdate();
	int getRenderArr(std::queue<Model> &arr);
};