#pragma once
#include "../global/Shorts.h"
#include "../global/DataTypes.h"

struct PolySSDat { //Screen space data for poly
	vec2* vertices;
	uint vertexcount;
	uint* elements;
	float* colour;
};

class Poly { //Should be called block or something
	//For non moving solid objects in the world
    public:
		Poly(vec2* vertices, uint vertexcount);
		PolySSDat getSSDat(vec2(*normalizingfcnptr)(vec2));
		float* Poly::getColour();
    private:
		vec2* vertices;
		int vertexCount;
		vec2 location; //Based around vertex 0
		vec3 colour;

		uint* triangulate();
};