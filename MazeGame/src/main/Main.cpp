#include "../global/Shorts.h"
#include "../render/Window.h"
#include "../render/Renderer.h"
#include "../core/GameMain.h"
#include "../core/FrameCounter.h"
#include "../game/MazeGame.h"
#include "../render/Texture.h"
#include "../render/Vao.h"
#include <queue>

int main() {
	renderer::init("Maze Game - Andrew Luckett 2019");
	renderer::myinit();

	GameMain gameInst = *new GameMain();
	gameInst.addSubSystem(new MazeGame());
	gameInst.addSubSystem(new FrameCounter());

	std::queue<Model> renderArr;	

	/* Loop until the user closes the window */
	while (renderer::isRunning()) {
		gameInst.update(std::chrono::system_clock::duration());
		gameInst.getRenderArr(renderArr);
		
		renderer::clearScreen();

		while(renderArr.empty() == false){
			renderer::draw(renderArr.front());
			renderArr.pop();
		}
		
		renderer::pushToScreen();
		
	}

	gameInst.cleanup();
	renderer::close();

	return 0;
}