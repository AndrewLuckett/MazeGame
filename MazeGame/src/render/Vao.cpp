#include "Vao.h"
#include "Renderer.h"

Model createVAO(std::vector<vec2> verts, std::vector<vec2> texCoords) {
	uint vaoId;
	glGenVertexArrays(1, &vaoId);
	glBindVertexArray(vaoId);

	std::vector<uint> indices = triangulate((uint)verts.size());
	Model out = Model(vaoId,(uint) indices.size());

	out.vbos.push_back(loadIndicesBuffer(indices));
	out.vbos.push_back(loadVertexBuffer(0, verts));
	out.vbos.push_back(loadVertexBuffer(1, texCoords));
	
	glBindVertexArray(0);
	return out;
}

int deleteVAO(Model &model) {
	glDeleteVertexArrays(1, &model.vaoID);
	for (auto const i : model.vbos) {
		glDeleteBuffers(1, &i);
	}
	return 0;
}

uint loadVertexBuffer(int attribNum, std::vector<vec2> data) {
	uint vboId;
	glGenBuffers(1, &vboId); //Create vbo
	glBindBuffer(GL_ARRAY_BUFFER, vboId); //Bind vbo

	glBufferData(GL_ARRAY_BUFFER, sizeof(vec2)*data.size(), data.data(), GL_STATIC_DRAW); //Put data in vbo
	glVertexAttribPointer(attribNum, 2, GL_FLOAT, false, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0); //Unbind vbo
	return vboId;
}

uint loadIndicesBuffer(std::vector<uint> indices) {
	uint vboId;
	glGenBuffers(1, &vboId);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboId);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint)*indices.size(), indices.data(), GL_STATIC_DRAW);
	return vboId;
}

std::vector<uint> triangulate(uint vertexCount) {
	//TODO: Find a better algo

	std::vector<uint> out;
	for (uint i = 0; i < vertexCount - 2; i++) {
		out.push_back(0);
		out.push_back(i + 1);
		out.push_back(i + 2);
	}

	return out;
}