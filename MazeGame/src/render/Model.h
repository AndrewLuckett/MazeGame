#pragma once
#include "../global/Shorts.h"
#include <vector>

typedef struct Model {
	uint vaoID;
	uint vertexCount;
	uint vertexVBO;
	uint indicesVBO;
	uint textureCoordsVBO;

	vec3 matrixa = { 1.0f, 0.0f, 0.0f }; //Top row of the transform matrix
	vec3 matrixb = { 0.0f, 1.0f, 0.0f }; //Second row of the transform matrix
	//The third row is ommited because it is const as { 0.0f , 0.0f , 1.0f }
	uint textureId;

	Model() {
	}

	Model(uint vi) {
		vaoID = vi;
	}

} Model;

/*
* VAO
* Element buffer : Indices
* 0 : VertexArray
* 1 : TextureCoordinateArray


*/