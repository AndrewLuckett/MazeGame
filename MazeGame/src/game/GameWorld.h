#pragma once
#include <vector>
#include "Engine/global/Shorts.h"
#include "Engine/core/System.h"

class GameWorld : public System {
    public:
		GameWorld() : GameWorld({ 20,20 }) {}
	    GameWorld(rect scale);
		int update(timesys::system_clock::duration deltaTime);
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
		rect exitLocation;

		Model lightModel;
		Model blockModel;
		Model exitModel;
};