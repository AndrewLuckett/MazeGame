#include "../global/Shorts.h"
#include <iostream>

#include "../render/RenderMain.h"
#include "../core/Poly.h"
#include "../core/GameMain.h"
#include "../core/FrameCounter.h"

int printPolySSDat(PolySSDat p) {
	std::cout << p.vertexcount << std::endl;
	for (uint i = 0; i < p.vertexcount; i++) {
		std::cout << p.vertices[i].x << "," << p.vertices[i].y << std::endl;
	}
	return 0;
}

int main() {
	renderer::init("Maze Game - Andrew Luckett 2019");
	renderer::myinit();

	GameMain gameInst = *new GameMain();

	//gameInst.addSubSystem(new MazeGame());
	gameInst.addSubSytem(new FrameCounter());

	PolySSDat* renderArrP = new PolySSDat();
	uint renderArrC = 0;

	/* Loop until the user closes the window */
	while (renderer::isRunning()) {

		//Get inputs here or in game update?

		gameInst.update(std::chrono::system_clock::duration());

		gameInst.getRenderArr(&renderArrP, &renderArrC);

		renderer::clearScreen();

		for (uint i = 0; i < renderArrC; i++) {
			renderer::loadPoly(renderArrP[i]);
			renderer::draw();
		}
		
		//renderer::draw();
		
		renderer::pushToScreen();
	}

	renderer::close();
	return 0;
}