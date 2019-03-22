#pragma once
#include "../global/Shorts.h"
#include "../global/Matrix.h"
#include <vector>

typedef struct Model {
	uint vaoID;
	uint vertexCount;
	uint vertexVBO;
	uint indicesVBO;
	uint textureCoordsVBO;

	TransMatrix transform;

	uint textureId;

	Model() {
	}

	Model(uint vi) {
		vaoID = vi;
	}

} Model;

/*
* VAO
* Element buffer : IndicesArray
* 0 : VertexArray
* 1 : TextureCoordinateArray
*/