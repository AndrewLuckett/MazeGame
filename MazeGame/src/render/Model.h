#pragma once
#include "../global/Shorts.h"
#include <vector>

typedef struct Model {
	uint vaoID;
	uint vertexCount;
	uint vertexVBO;
	uint indicesVBO;
	uint textureCoordsVBO;
	vec3 matrixaVBO = { 1.0f, 0.0f, 0.0f };
	vec3 matrixbVBO = { 0.0f, 1.0f, 0.0f };
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
* 2 : MatrixTopRow
* 3 : MatrixBottomRow



*/