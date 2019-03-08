#include "Poly.h"
#include <iostream>

Poly::Poly(vec2 vertices[], uint vertexcount) {
	Poly::vertices = vertices;
	Poly::vertexCount = vertexcount;
	//Poly::colour = { 0.1f,0.5f,0.5f };
}

PolySSDat Poly::getSSDat() {
	vec2* vert = new vec2[vertexCount];

	for (uint i = 0; i < vertexCount; i++) {
		vert[i] = vertices[i];
	}

	return PolySSDat(vert, vertexCount, triangulate());
}

uint* Poly::triangulate() {
	//TODO: Find a better algo
	
	uint* out = new uint[3 * (vertexCount - 2)];
	for (uint i = 0; i < vertexCount - 2; i++) {
		out[i * 3] = 0;
		out[i * 3 + 1] = i + 1;
		out[i * 3 + 2] = i + 2;
	}

	return out;
}