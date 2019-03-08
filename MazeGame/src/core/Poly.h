#pragma once
#include "../global/Shorts.h"
#include <iostream>

struct PolySSDat { //Screen space data for poly
	vec2* vertices;
	uint vertexcount;
	uint* elements;

	PolySSDat(vec2* vert, uint vc, uint* ele) {
		vertices = vert;
		vertexcount = vc;
		elements = ele;
	}

	~PolySSDat() {
		//???? Errors if I delete anything here or dont have the destructor at all
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
		vec2 location; //Based around vertex 0

		uint* triangulate();
};