#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "../global/Shorts.h"
#include <iostream>

#include "RenderMain.h"
#include "ShaderGen.h"

GLFWwindow* window;


bool isRunning() {
	return !glfwWindowShouldClose(window);
}


int init(const char* windowTitle) {
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

int myinit() {
	string vs = ParseFile("res/shaders/light.vert");
	string fs = ParseFile("res/shaders/light.frag");

	uint shad = CreateShader(vs, fs);
	glUseProgram(shad);

	return 0;
}

int pushToScreen() {
	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();
	return 0;
}

int clearScreen() {
	glClear(GL_COLOR_BUFFER_BIT);
	return 0;
}

int draw() {
	//glDrawArrays(GL_TRIANGLES,0,3);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	return 0;
}

int loadPoly(PolySSDat dat) {
	uint vertexarray;
	glGenVertexArrays(1, &vertexarray);
	glBindVertexArray(vertexarray);

	uint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float)*dat.vertexcount*2, dat.vertices, GL_STATIC_DRAW);

	uint elementbuffer;
	glGenBuffers(1, &elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint)*3*(dat.vertexcount-2), dat.elements, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

	return 0;
}

int close() {
	glfwTerminate();
	return 0;
}