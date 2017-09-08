#include "Mesh.h"
#include "Shader.h"

#include <assert.h>

using namespace std;

Mesh::Mesh()
{
}


Mesh::~Mesh()
{

}


void Mesh::setRowAndCol(unsigned int rows, unsigned int cols)
{
	m_rows = rows;
	m_cols = cols;
}

void Mesh::Create_buffers()
{
	auto windowLoad = new bootApplication();
	windowLoad->run("Rendering App", 800, 800, nullptr);

	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);

	glGenVertexArrays(1, &m_vao);

	bind();

	glBindVertexArray(0);
	
	unbind();

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(m_vao);
	vertex_Count();
	glDrawElements(GL_TRIANGLES, index_Count(), GL_UNSIGNED_INT, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	delete[] aoVerticies;
}

void Mesh::initialize(vector<Vertex>&verts, vector<unsigned int>&indices)
{
}

void Mesh::bind()
{
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, (m_rows * m_cols) * sizeof(Vertex), aoVerticies, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (m_rows - 1) * (m_cols - 1) * 6 * sizeof(unsigned int), auiIndices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int Mesh::index_Count()
{
	unsigned int indexCount = (m_rows - 1) * (m_cols - 1) * 6;
	return indexCount;
}

unsigned int Mesh::vertex_Count()
{
	unsigned int vertexCount = (m_rows * m_cols);
	return vertexCount;
}
