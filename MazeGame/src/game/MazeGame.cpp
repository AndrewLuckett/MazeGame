#include "MazeGame.h"
#include "../core/Poly.h"
#include "../global/Shapes.h"

Poly test = Poly(shapes::SQUARE, 4);
Poly t2 = Poly(shapes::PENTAGON, 5);

int MazeGame::update(timesys::system_clock::duration deltaTime) {
	return 0;
}

int MazeGame::fixedUpdate() {
	return 0;
}

int MazeGame::getRenderArr(std::queue<PolySSDat> &arr, uint &c) {
	arr.push(test.getSSDat());
	arr.push(t2.getSSDat());
	return 0;
}
