#include "../global/Shorts.h"
#include "../render/RenderMain.h"
#include "../core/Poly.h"
#include "../core/GameMain.h"
#include "../core/FrameCounter.h"
#include "../game/MazeGame.h"

#include <queue>

int main() {
	renderer::init("Maze Game - Andrew Luckett 2019");
	renderer::myinit();

	GameMain gameInst = *new GameMain();

	gameInst.addSubSystem(new MazeGame());
	//gameInst.addSubSystem(new FrameCounter());

	std::queue<PolySSDat> renderArr;
	uint renderArrC = 0;

	/* Loop until the user closes the window */
	while (renderer::isRunning()) {

		//Get inputs here or in game update?
		
		gameInst.update(std::chrono::system_clock::duration());
		
		gameInst.getRenderArr(renderArr, renderArrC);
		
		renderer::clearScreen();

		while(renderArr.empty() == false){
			renderer::loadPoly(renderArr.front());
			renderArr.pop();
			renderer::draw();
		}

		renderer::pushToScreen();
		
	}
	gameInst.cleanup();
	renderer::close();

	return 0;
}