#pragma once

#include "ra.h"
#include "../global/Shorts.h"
#include <vector>
#include "Model.h"

Model createVAO(std::vector<vec2> verts, std::vector<vec2> texCoords);

uint loadVertexBuffer(int attribNum, std::vector<vec2> data);
uint loadIndicesBuffer(std::vector<uint> indices);

int deleteVAO(Model &model);

std::vector<uint> triangulate(uint vertexCount);

