#include "GameWorld.h"
#ifdef _DEBUG
#include <iostream>
#endif
#include "Sprite.h"
#include "../render/Texture.h"
#include "../render/Vao.h"
#include "MazeGenerator.h"
#include <cmath>

GameWorld::GameWorld(){
	GameWorld({ 20,20 });
}

GameWorld::GameWorld(rect scale){
	worldSize = scale;
	playerPosition = { worldSize.x/2.0f, worldSize.y/2.0f };

	lightModel = getGenericModel();
	loadVertexData(lightModel, { {-0.9f,0.9f},{0.9f,0.9f},{0.2f,0.0f},{-0.2f,0.0f} });
	blockModel = getGenericModel();
	blockModel.textureId = loadTexture("res/textures/black.png" , GL_NEAREST);
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

	float dist = playerLightDist + 1;

	for (float i = -dist; i < dist + 1; i++) {
		for (float j = -dist; j < dist + 1; j++) {
			float x = i + playerPosition.x;
			float y = j + playerPosition.y;

			if (x > 0 && y > 0 && x < worldSize.x && y < worldSize.y) {
				if (world[(int) x][(int) y] == 1) {
					blockModel.transform.top = { 1.0f, 0.0f, i - playerPosition.x + (int) playerPosition.x };
					blockModel.transform.mid = { 0.0f, 1.0f, j - playerPosition.y + (int) playerPosition.y };
					arr.push(blockModel);
				}
			}
		}
	}


	return 0;
}

void GameWorld::generateNewLevel(){
	playerPosition = { worldSize.x / 2.0f, worldSize.y / 2.0f };
	generateMaze(world, worldSize);
}

void GameWorld::setPlayerAngle(float angle){
	playerAngle = angle;
}

void GameWorld::trymovePlayer(vec2 dist) {

	int end = (int)dist.x + 1;
	for (int i = 0; i < end; i++) {
		playerPosition.x += dist.x / end;
		if (world[round(playerPosition.x)][round(playerPosition.y)] == 1) {
			playerPosition.x -= dist.x / end;
		}
	}

	end = (int)dist.y + 1;
	for (int i = 0; i < end; i++) {
		playerPosition.y += dist.y / end;
		if (world[round(playerPosition.x)][round(playerPosition.y)] == 1) {
			playerPosition.y -= dist.y / end;
		}
	}
}

void GameWorld::forcemovePlayer(vec2 dist) {
	playerPosition.x += dist.x;
	if (playerPosition.x < 0 || playerPosition.x > worldSize.x - 1) {
		playerPosition.x -= dist.x;
	}
	playerPosition.y += dist.y;
	if (playerPosition.y < 0 || playerPosition.y > worldSize.y - 1) {
		playerPosition.y -= dist.y;
	}
}
