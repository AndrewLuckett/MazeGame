#pragma once
#include "../global/Shorts.h"

class WorldObject {
    public:
	    WorldObject(vec2 pos, int type);
    private:
	    vec2 location;
	    int type;
		float msuntilexpires;
};