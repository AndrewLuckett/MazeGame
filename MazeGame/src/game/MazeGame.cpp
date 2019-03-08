#include "MazeGame.h"
#include "../core/Poly.h"
#include "../global/Shapes.h"

Poly test = *new Poly(shapes::SQUARE, 4);

int MazeGame::update(timesys::system_clock::duration deltaTime) {
	return 0;
}

int MazeGame::fixedUpdate() {
	return 0;
}

int MazeGame::getRenderArr(std::queue<PolySSDat> &arr, uint &c) {
	arr.push(test.getSSDat());
	return 0;
}
