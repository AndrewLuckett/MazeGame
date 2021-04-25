#pragma once
#include "../core/System.h"
#include "GameWorld.h"

class Player : public System {
    public:
	    Player(GameWorld* world);
	    int update(timesys::system_clock::duration deltaTime);
	    int getRenderArr(std::queue<Model> &arr);
    private:
	    Model base;
	    GameWorld* world;
	    float facingAngle = 0;
	    float velocity = 0.05f;
	    float radius = 0.1f;
		float spriteScale = 0.8f;
};