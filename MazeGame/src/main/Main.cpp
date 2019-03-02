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


/*
* Termination codes:
* 0 : Normal exit
* -1 : Standard Err
* -2 : GLFW Err
* -3 : GLEW Err
*/
int main() {

	vec2 square[4] = {{-0.8f, 0.5f },
					  { 0.5f, 0.5f },
                      { 0.5f, -0.4f},
			          {-0.8f,-0.7f}};
	
	Poly test = Poly(square, 4);
	PolySSDat d = test.getSSDat(temp);

	init("Maze Game - Andrew Luckett 2019");
	myinit();

	loadPoly(d);

	/* Loop until the user closes the window */
	while (isRunning()) {

		//Handle inputs

		//Other per frame game ops

		clearScreen();

		//Render stuff
		draw();
		pushToScreen();
	}

	close();
	return 0;
}