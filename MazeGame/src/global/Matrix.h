#pragma once
#include "Shorts.h"

typedef struct TransMatrix {
	vec3 top;
	vec3 mid;
} TransMatrix;

TransMatrix matrixMult(TransMatrix& a, TransMatrix& b);
TransMatrix matrixAdd(TransMatrix& a, TransMatrix& b);