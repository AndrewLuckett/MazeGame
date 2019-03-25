#include "Player.h"
#include "../core/input.h"
#include "Sprite.h"
#include "../render/Texture.h"

Player::Player(GameWorld* world){
	this->world = world;
	velocity = 0.5f;
	radius = 0.1f;
	facingAngle = 0.0f;


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
	//And get keyboard input

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
