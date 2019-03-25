#pragma once
#include <vector>
#include "../global/Shorts.h"
#include "WorldObject.h"
#include "../core/System.h"

class GameWorld : public System {
    public:
		GameWorld();
	    GameWorld(rect scale);
		int update(timesys::system_clock::duration deltaTime);
		int fixedUpdate();
		int getRenderArr(std::queue<Model> &arr);

		bool isLevelLoaded() { return levelLoaded; }
		void generateNewLevel();
		void setPlayerAngle(float angle);
		void trymovePlayer(vec2 dist);
		void forcemovePlayer(vec2 dist);

    private:
		float playerAngle;
		vec2 playerPosition;
		float playerLightDist = 5.0f;
		rect worldSize;
		bool levelLoaded = false;
	    std::vector<std::vector<int>> world;
		std::vector<WorldObject> items;

		Model lightModel;
		Model blockModel;
};