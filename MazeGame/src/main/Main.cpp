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

	std::vector<vec2> a;
	a.push_back({ -0.5f, 0.5f });
	a.push_back({ 0.5f, 0.5f });
	a.push_back({ 0.5f,-0.5f });
	a.push_back({ -0.5f,-0.5f });
	std::vector<vec2> t;
	t.push_back({ 0.0f, 0.0f });
	t.push_back({ 1.0f,0.0f });
	t.push_back({ 1.0f,1.0f });
	t.push_back({ 0.0f,1.0f });
	uint m = loadTexture("res/textures/t.png");
	Model b = Model(createVAO(a,t),m);

	/* Loop until the user closes the window */
	while (renderer::isRunning()) {

		//Get inputs here or in game update?
		
		gameInst.update(std::chrono::system_clock::duration());
		
		gameInst.getRenderArr(renderArr);
		
		renderArr.push(b);
		
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