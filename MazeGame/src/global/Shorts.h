#pragma once
//Shorter versions of stuff

#include <string>

typedef unsigned int uint;
typedef unsigned char uchar;
typedef std::string string;

typedef struct vec2 {
	float x;
	float y;
} vec2;

typedef struct vec3 : vec2 {
	float z;
} vec3;

typedef struct rect {
	int x;
	int y;
} rect;