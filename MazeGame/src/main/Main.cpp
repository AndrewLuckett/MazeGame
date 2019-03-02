#include "../global/Shorts.h"
#include <iostream>

#include "../render/RenderMain.h"

/*
* Termination codes:
* 0 : Normal exit
* -1 : Standard Err
* -2 : GLFW Err
* -3 : GLEW Err
*/
int main() {
	

	init();
	myinit();
	
	/* Loop until the user closes the window */
	while (isRunning()) {

		//Handle inputs

		//Other per frame game ops

		//Render stuff

		//flip frame

		renderop();
	}

	close();
	return 0;
}