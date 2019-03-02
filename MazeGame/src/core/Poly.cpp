#include "Poly.h"


Poly::Poly(vec2* vertices, uint vertexcount) {
	Poly::vertices = vertices;
	Poly::vertexCount = vertexcount;
	Poly::colour = { 0.1f,0.5f,0.5f };
}


PolySSDat Poly::getSSDat(vec2 (*normalizingfcnptr)(vec2)) {
	vec2* vert = vertices;
	for (int i = 0; i < vertexCount; i++) {
		vert[i] = (normalizingfcnptr)(vertices[i]);

	}
	PolySSDat dat = {vert,vertexCount,triangulate(),getColour()};
	return dat;
}

uint* Poly::triangulate() {
	//TODO: Find an algo for this
	//Hardcoded for now
	
	static uint e[6] = { 0, 1, 2,
	                     2, 3, 0 };
	return e;
}

float* Poly::getColour() {
	static float c[3] = { colour.x,
		                  colour.y,
		                  colour.z };
	return c;
}
