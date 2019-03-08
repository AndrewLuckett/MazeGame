#include "../core/Poly.h"

namespace renderer {
	bool isRunning();
	int init(const char windowTitle[]);
	int myinit();
	int pushToScreen();
	int draw();
	int close();
	int clearScreen();
	int loadPoly(PolySSDat dat);
}