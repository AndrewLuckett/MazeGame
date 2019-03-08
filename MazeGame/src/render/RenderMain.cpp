#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "../global/Shorts.h"
#include <iostream>

#include "RenderMain.h"
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
	string vs = ParseFile("res/shaders/light.vert");
	string fs = ParseFile("res/shaders/light.frag");

	uint shad = CreateShader(vs, fs);
	glUseProgram(shad);

	uint vertexarray;
	glGenVertexArrays(1, &vertexarray);
	glBindVertexArray(vertexarray);
	uint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	uint elementbuffer;
	glGenBuffers(1, &elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, 0);
	return 0;
}

int renderer::pushToScreen() {
	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();
	return 0;
}

int renderer::clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT);
	return 0;
}

uint loadedElementCount = 3;

int renderer::draw() {
	glDrawElements(GL_TRIANGLES, loadedElementCount, GL_UNSIGNED_INT, 0);
	return 0;
}

int renderer::loadPoly(PolySSDat &dat) {
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*dat.vertexcount*2, dat.vertices, GL_STATIC_DRAW);

	loadedElementCount = sizeof(uint) * 3 * (dat.vertexcount - 2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, loadedElementCount, dat.elements, GL_STATIC_DRAW);

	return 0;
}

int renderer::close() {
	glfwTerminate();
	return 0;
}