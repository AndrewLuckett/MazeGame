#include "MazeGame.h"
#include "../render/Texture.h"
#include "../render/Vao.h"
#include "../render/Window.h"
#include "../core/input.h"
#include <iostream>

MazeGame::MazeGame() {
	
	world = GameWorld({ 100,100 });
	player = Player(&world);

	world.generateNewLevel();

	zoom = 0.15f;
}

int MazeGame::update(timesys::system_clock::duration deltaTime) {
	player.update(deltaTime);
	
	return 0;
}

int MazeGame::fixedUpdate() {
	player.fixedUpdate();
	return 0;
}

int MazeGame::getRenderArr(std::queue<Model> &arr) {
	rect windowSize = window::getWindowSize();
	float aspect = windowSize.x * 1.0f / windowSize.y;
	TransMatrix scale;
	scale.top = { zoom, 0.0f, 0.0f };
	scale.mid = { 0.0f, zoom*aspect , 0.0f };

	std::queue<Model> sub;

	world.getRenderArr(sub);

	player.getRenderArr(sub);

	while (!sub.empty()) {
		arr.push(scaleModel(sub.front(), scale));
		sub.pop();
	}
	
	return 0;
}

Model MazeGame::scaleModel(Model in, TransMatrix scale){
	in.transform = matrixMult(scale, in.transform);
	return in;
}
