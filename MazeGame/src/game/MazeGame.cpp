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

int MazeGame::getRenderArr(PolySSDat* &arr, uint &c) {
	arr = new PolySSDat[1];
	arr[0] = test.getSSDat();
	c = 1;
	return 0;
}
