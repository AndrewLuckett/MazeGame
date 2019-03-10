#pragma once
#include "../global/Shorts.h"
#include <iostream>
#include <vector>

struct PolySSDat { //Screen space data for poly
	std::vector<vec2> vertices;
	uint vertexcount;
	std::vector<uint> elements;

	PolySSDat(std::vector<vec2> vert, uint vc, std::vector<uint> ele) {
		vertices = vert;
		vertexcount = vc;
		elements = ele;
	}
};

class Poly { //Should be called block or something
	//For non moving solid objects in the world
    public:
		Poly(vec2 vertices[], uint vertexcount);
		PolySSDat getSSDat();
    private:
		vec2* vertices;
		uint vertexCount;

		std::vector<uint> triangulate();
};