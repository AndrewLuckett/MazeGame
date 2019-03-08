#include "../global/Shorts.h"
#include "../render/RenderMain.h"
#include "../core/Poly.h"
#include "../core/GameMain.h"
#include "../core/FrameCounter.h"
#include "../game/MazeGame.h"

int main() {
	renderer::init("Maze Game - Andrew Luckett 2019");
	renderer::myinit();

	GameMain gameInst = *new GameMain();

	gameInst.addSubSystem(new MazeGame());
	//gameInst.addSubSystem(new FrameCounter());

	PolySSDat* renderArrP = new PolySSDat[1]();
	uint renderArrC = 0;

	/* Loop until the user closes the window */
	while (renderer::isRunning()) {

		//Get inputs here or in game update?

		gameInst.update(std::chrono::system_clock::duration());

		gameInst.getRenderArr(renderArrP, renderArrC);

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