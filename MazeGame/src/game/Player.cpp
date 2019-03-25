#include "Player.h"
#include "../core/input.h"
#include "Sprite.h"
#include "../render/Texture.h"
#include <iostream>

Player::Player(GameWorld* world){
	this->world = world;
	base = getGenericModel();
	base.textureId = loadTexture("res/textures/player.png");// , GL_NEAREST);
}

int Player::update(timesys::system_clock::duration deltaTime){
	auto mousePos = getCursorLocation();
	if (mousePos.y > 0) {
		facingAngle = -atan(mousePos.x / mousePos.y);
	}
	else if (mousePos.y < 0) {
		facingAngle = 3.141f - atan(mousePos.x / mousePos.y);
	}
	
	vec2 dir = { 0.0f,0.0f };
	if (isKeyDown(GLFW_KEY_W)) {
		dir.y += 0.1f;
	}
	if (isKeyDown(GLFW_KEY_S)) {
		dir.y -= 0.1f;
	}
	if (isKeyDown(GLFW_KEY_D)) {
		dir.x += 0.1f;
	}
	if (isKeyDown(GLFW_KEY_A)) {
		dir.x -= 0.1f;
	}
	dir.x *= (int)timesys::duration_cast<timesys::milliseconds>(deltaTime).count() * velocity;
	dir.y *= (int)timesys::duration_cast<timesys::milliseconds>(deltaTime).count() * velocity;
	world->trymovePlayer(dir);

	world->setPlayerAngle(facingAngle);

	return 0;
}

int Player::fixedUpdate(){
	return 0;
}

int Player::getRenderArr(std::queue<Model>& arr){
	base.transform.top = { cos(facingAngle)*spriteScale, -sin(facingAngle)*spriteScale, 0.0f };
	base.transform.mid = { sin(facingAngle)*spriteScale, cos(facingAngle)*spriteScale, 0.0f };
	arr.push(base);
	return 0;
}
