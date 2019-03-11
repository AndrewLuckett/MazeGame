#include "ra.h"
#include "Window.h"
#include "Renderer.h"

int renderer::clearScreen() {
	int x, y;
	glfwGetWindowSize(getWindow(), &x, &y);
	glViewport(0, 0, x, y);
	//glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	return 0;
}

int renderer::pushToScreen() { //ought to go back into window?
	/* Swap front and back buffers */
	glfwSwapBuffers(getWindow());

	/* Poll for and process events */
	glfwPollEvents();
	return 0;
}

int renderer::draw(Model &model) {
	glBindVertexArray(model.vaoID);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindTexture(GL_TEXTURE_2D, model.textureId);
	glDrawElements(GL_TRIANGLES, sizeof(uint)*model.vertexCount, GL_UNSIGNED_INT, 0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glBindVertexArray(0);
	return 0;
}