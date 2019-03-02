#include <GLEW/glew.h>
#include <GLFW/glfw3.h>
#include "../global/Shorts.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>



static string ParseFile(const string &filepath) {
	std::ifstream filestream(filepath);

	string text;
	text.assign((std::istreambuf_iterator<char>(filestream)),(std::istreambuf_iterator<char>()));
	return text;
}

static uint CompileShader(uint type,const string &source) {
	uint id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr); //Null terminated is assumed from nullptr
	glCompileShader(id);

	//std::cout << src << std::endl;

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result = GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile :" << type << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
	}
	return id;
}

static uint CreateShader(const string &vertexShader, const string &fragmentShader) {
	uint prog = glCreateProgram();
	uint vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	uint fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	glAttachShader(prog, vs);
	glAttachShader(prog, fs);
	glLinkProgram(prog);
	glValidateProgram(prog);

	return prog;
}


/*
* Termination codes:
* 0 : Normal exit
* -1 : Standard Err
* -2 : GLFW Err
* -3 : GLEW Err
*/
int main() {
	GLFWwindow* window;

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
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		//glDrawArrays(GL_TRIANGLES,0,3);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
