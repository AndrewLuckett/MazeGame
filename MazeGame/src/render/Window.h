#pragma once

#include "ra.h"
#include "../global/Shorts.h"

namespace renderer {
	

	bool isRunning();
	int init(const char windowTitle[]);
	int myinit();
	int close();
	rect getWindowSize();
	GLFWwindow* getWindow();
}