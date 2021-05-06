#include "MazeGame.h"
#include "Engine/render/Texture.h"
#include "Engine/render/Vao.h"
#include "Engine/render/Window.h"
#include "Engine/core/input.h"
#include "Engine/render/Renderer.h"

MazeGame::MazeGame() {
	world = GameWorld({ 100,100 });

	addSubSystem(new Player(&world));
	addSubSystem(&world);
	
	world.generateNewLevel();

	zoom = 0.15f;
}

int MazeGame::update(timesys::system_clock::duration deltaTime) {
	System::update(deltaTime);
	if (!world.isLevelLoaded()) {
		levelsCompleted += 1;
		world.generateNewLevel();
	}
	return 0;
}

int MazeGame::getRenderArr(std::queue<Model> &arr) {
	rect windowSize = window::getWindowSize();
	float aspect = windowSize.x * 1.0f / windowSize.y;
	TransMatrix scale;
	scale.top = { zoom, 0.0f, 0.0f };
	scale.mid = { 0.0f, zoom*aspect , 0.0f };

	System::getRenderArr(arr);

	renderer::loadGlobalTransform(window::getProgramID(), scale);
	
	return 0;
}

Model MazeGame::scaleModel(Model in, TransMatrix scale){
	in.transform = matrixMult(scale, in.transform);
	return in;
}
