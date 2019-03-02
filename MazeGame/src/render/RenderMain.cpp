#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "../global/Shorts.h"
#include <iostream>

#include "ShaderGen.h"

GLFWwindow* window;


bool isRunning() {
	return !glfwWindowShouldClose(window);
}


int init() {

	/* Initialize the library */
	if (!glfwInit()) return -2;


	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(1280, 960, "Hello World", NULL, NULL);
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
	uint vertexarray;
	glGenVertexArrays(1, &vertexarray);
	glBindVertexArray(vertexarray);

	float vertices[] = {
		-0.5f,0.5f,
		0.5f, 0.5f,
		0.5f, -0.5f,
		-0.5f,-0.5f
	};

	uint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	uint elements[] = {
	0, 1, 2,
	2, 3, 0
	};

	uint elementbuffer;
	glGenBuffers(1, &elementbuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

	string vs = ParseFile("res/shaders/light.vert");
	string fs = ParseFile("res/shaders/light.frag");

	uint shad = CreateShader(vs, fs);
	glUseProgram(shad);

	return 0;
}

int renderop() {
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);

	//glDrawArrays(GL_TRIANGLES,0,3);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	/* Swap front and back buffers */
	glfwSwapBuffers(window);

	/* Poll for and process events */
	glfwPollEvents();

	return 0;
}

int close() {
	glfwTerminate();
	return 0;
}