#include "../global/Shorts.h"
#include "../global/DataTypes.h"
#include <iostream>

#include "../render/RenderMain.h"
#include "../core/Poly.h"

vec2 temp(vec2 in) { //Test normalisation function
	vec2 out = in;
	out.x = out.x * -1;
	return out;
}

int main() {

	vec2 pent[5] = {{-0.8f, 0.5f },
					  { 0.5f, 0.5f },
                      { 0.5f,-0.4f },
					  {-0.6f,-0.7f },
					  {-0.99f, 0.0f } };
	
	Poly test = Poly(pent, 5);
	PolySSDat d = test.getSSDat(temp);

	renderer::init("Maze Game - Andrew Luckett 2019");
	renderer::myinit();

	renderer::loadPoly(d);



	/* Loop until the user closes the window */
	while (renderer::isRunning()) {

		//Handle inputs

		//Other per frame game ops

		renderer::clearScreen();

		//Render stuff
		renderer::draw();
		renderer::pushToScreen();
	}

	renderer::close();
	return 0;
}