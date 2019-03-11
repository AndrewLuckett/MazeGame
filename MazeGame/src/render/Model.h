#pragma once
#include "../global/Shorts.h"
#include <vector>

typedef struct Model {
	uint vaoID;
	uint vertexCount;
	std::vector<uint> vbos;
	uint textureId;

	Model() {
	}

	Model(uint vi, uint vc) {
		vaoID = vi;
		vertexCount = vc;
	}

	Model(Model m, uint t) {
		vaoID = m.vaoID;
		vertexCount = m.vertexCount;
		vbos = m.vbos;
		textureId = t;
	}

} Model;