#include "Poly.h"
#include <iostream>

Poly::Poly(vec2 vertices[], uint vertexcount) {
	Poly::vertices = vertices;
	Poly::vertexCount = vertexcount;
	//Poly::colour = { 0.1f,0.5f,0.5f };
}

PolySSDat Poly::getSSDat() {
	std::vector<vec2> vert;;

	for (uint i = 0; i < vertexCount; i++) {
		vert.push_back( vertices[i]);
	}

	return PolySSDat(vert, vertexCount, triangulate());
}

std::vector<uint> Poly::triangulate() {
	//TODO: Find a better algo
	
	std::vector<uint> out;
	for (uint i = 0; i < vertexCount - 2; i++) {
		out.push_back(0);
		out.push_back(i + 1);
		out.push_back(i + 2);
	}

	return out;
}