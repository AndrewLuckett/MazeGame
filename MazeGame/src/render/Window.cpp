#include "../global/Shorts.h"
#ifdef _DEBUG
#include <iostream>
#endif
#include "Window.h"
#include "ShaderGen.h"

GLFWwindow* window;

bool renderer::isRunning() {
	return !glfwWindowShouldClose(window);
}

int renderer::init(const char windowTitle[]) {
	/* Initialize the library */
	if (!glfwInit()) return -2;

	window = glfwCreateWindow(1280, 960, windowTitle, NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -2;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) return -3;

#ifdef _DEBUG
	std::cout << glGetString(GL_VERSION) << std::endl;
#endif

	return 0;
}

int renderer::myinit() {
	//glfwSwapInterval(0); //No vsync
	string vesh = ParseFile("res/shaders/light.vert");
	string frsh = ParseFile("res/shaders/light.frag");

	uint prog = glCreateProgram();
	glBindAttribLocation(prog, 0, "position");
	glBindAttribLocation(prog, 1, "coords");

	uint vs = CompileShader(GL_VERTEX_SHADER, vesh);
	uint fs = CompileShader(GL_FRAGMENT_SHADER, frsh);

	glAttachShader(prog, vs);
	glAttachShader(prog, fs);
	
	glLinkProgram(prog);
	
	glUseProgram(prog);
	return 0;
}

rect renderer::getWindowSize(){
	rect out;
	glfwGetWindowSize(window, &out.x, &out.y);
	return out;
}

GLFWwindow * renderer::getWindow(){
	return window;
}

int renderer::close() {
	glfwTerminate();
	return 0;
}