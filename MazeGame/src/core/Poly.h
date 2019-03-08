#pragma once
#include "../global/Shorts.h"

struct PolySSDat { //Screen space data for poly
	vec2* vertices;
	uint vertexcount;
	uint* elements;
};

class Poly { //Should be called block or something
	//For non moving solid objects in the world
    public:
		Poly(vec2 vertices[], uint vertexcount);
		PolySSDat getSSDat();
    private:
		vec2* vertices;
		uint vertexCount;
		vec2 location; //Based around vertex 0

		uint* triangulate();
};