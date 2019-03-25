#include "Sprite.h"
#include "../render/Vao.h"
#include "../render/Texture.h"

Model gen;
bool created = false;

Model getGenericModel() {
	if (!created) {
		createGenericModel();
	}
	return gen;
}
void createGenericModel() {
	std::vector<vec2> a = { {-0.5f, 0.5f },
						   { 0.5f, 0.5f },
						   { 0.5f,-0.5f },
						   {-0.5f,-0.5f } };
	std::vector<vec2> t = { { 0.0f, 0.0f }, { 1.0f, 0.0f },{ 1.0f,1.0f }, { 0.0f,1.0f } };

	gen = createVAO(); //Create base model
	loadVertexData(gen, a); //Load vertex data in base model
	loadTextureCoordinates(gen, t); //Load texture coords into base model

	gen.textureId = loadTexture("res/textures/white.png");// , GL_NEAREST);
}