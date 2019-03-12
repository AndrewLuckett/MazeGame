#include "MazeGame.h"
#include "../render/Texture.h"
#include "../render/Vao.h"

MazeGame::MazeGame() {
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
	b = Model(createVAO(a, t), m);
}

int MazeGame::update(timesys::system_clock::duration deltaTime) {
	return 0;
}

int MazeGame::fixedUpdate() {
	return 0;
}

int MazeGame::getRenderArr(std::queue<Model> &arr) {
	arr.push(b);
	return 0;
}
