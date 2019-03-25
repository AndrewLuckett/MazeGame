#include "../core/System.h"
#include "../render/Model.h"
#include "Sprite.h"
#include <vector>
#include "GameWorld.h"
#include "Player.h"

class MazeGame : public System {
    public:
	    MazeGame();
	    int update(timesys::system_clock::duration deltaTime);
	    int fixedUpdate();
	    int getRenderArr(std::queue<Model> &arr);
    private:
		Model scaleModel(Model in, TransMatrix scale);
		Player player = Player(nullptr);
		float zoom = 1.0f;
		GameWorld world;
};
//No objects contained by mazeGame can use mouse positions