#include "GameMain.h"
//#include <iostream>



game::game() { //perform once
	suLastRun = timesys::system_clock::now();
	fuLastRun = timesys::system_clock::time_point::time_point();
}

int game::update() { //Perform every frame
	auto now = std::chrono::system_clock::now();
	deltaTime = now - suLastRun;
	suLastRun = now;
	if (now - fuLastRun > fuTime) {
		fuLastRun = now;
		fixedUpdate();
	}
	//Game code below

	return 0;
}

int game::fixedUpdate() { //Perform every fixed amount of time
	//std::cout << "Beep" << std::endl;
	return 0;
}

vec2 norm(vec2 in) { //Test normalisation function
	//vec2 out = in;
	//out.x = out.x * -1;
	return in;
}

int game::getRenderArr(PolySSDat** arr,uint* c) { //Gets SSDat for elements and returns them
	delete *arr; //Delete old array

	//Hard coded for now

	vec2 pent[5] = { { 0.1f, 0.1f },
					        { 0.0f, 0.6f },
					        { 0.4f, 0.8f },
					        { 0.8f, 0.6f },
					        { 0.6f, 0.1f } };

	vec2 square[4] = { {-0.1f,-0.1f},
	                          {-0.1f,-0.3f},
	                          {-0.3f,-0.3f},
	                          {-0.3f,-0.1f} };

	Poly test = Poly(pent, 5);
	PolySSDat d = test.getSSDat(norm);
	
	PolySSDat* out = new PolySSDat[2];
	out[0] = d;

	test = Poly(square, 4);
	d = test.getSSDat(norm);
	out[1] = d;

	*arr = out;
	*c = 2;
	return 0;
}

int game::cleanup() {
	
	return 0;
}
