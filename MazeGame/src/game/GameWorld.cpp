#include "GameWorld.h"
#include <iostream>
#include "Sprite.h"
#include "../render/Texture.h"

GameWorld::GameWorld(){
	GameWorld({ 20,20 });
}

GameWorld::GameWorld(rect scale){
	worldSize = scale;
	playerPosition = { worldSize.x/2.0f, worldSize.y/2.0f };

	lightModel = getGenericModel();
	blockModel = getGenericModel();
	blockModel.textureId = loadTexture("res/textures/t.png");// , GL_NEAREST);
}


int GameWorld::update(timesys::system_clock::duration deltaTime) {
	return 0;
}

int GameWorld::fixedUpdate() {
	return 0;
}

int GameWorld::getRenderArr(std::queue<Model> &arr) {
	lightModel.transform.top = { cos(playerAngle)*playerLightDist, -sin(playerAngle)*playerLightDist, 0.0f };
	lightModel.transform.mid = { sin(playerAngle)*playerLightDist, cos(playerAngle)*playerLightDist, 0.0f };
	arr.push(lightModel);
	return 0;
}

void GameWorld::generateNewLevel(){
	playerPosition = { worldSize.x / 2.0f, worldSize.y / 2.0f };
	
}

void GameWorld::setPlayerAngle(float angle){
	playerAngle = angle;
}

void GameWorld::trymovePlayer(vec2 dist){
	playerPosition.x += dist.x;
	playerPosition.y += dist.y;
}
