#include "Mesh.h"
#include "Shader.h"

#include <assert.h>

using namespace glm;
using namespace std;

Mesh::Mesh()
{
}


Mesh::~Mesh()
{

}

// nah...
void Mesh::generateGrid(unsigned int rows, unsigned int cols)
{
	m_rows = rows;
	m_cols = cols;

	for (unsigned int r = 0; r < rows; ++r)
	{
		for (unsigned int c = 0; c < cols; ++c)
		{
			aoVerticies[r * cols + c].position = vec4((float)c, 0, (float)r, 1);

			vec3 colour = vec3(sinf((c / (float)(cols - 1)) * (r / (float)(rows - 1))));
			aoVerticies[r * cols + c].colour = vec4(colour, 1);
		}
	}

	unsigned int index = 0;
	for (unsigned int r = 0; r < (rows - 1); ++r)
	{
		for (unsigned int c = 0; c < (cols - 1); ++c)
		{
			auiIndices[index++] = r * cols + c;
			auiIndices[index++] = (r + 1) * cols + c;
			auiIndices[index++] = (r + 1) * cols + (c + 1);

			auiIndices[index++] = r * cols + c;
			auiIndices[index++] = (r + 1) * cols + (c + 1);
			auiIndices[index++] = r * cols + (c + 1);
		}
	}
	Create_buffers();
	bind();
	unbind();
}

void Mesh::Create_buffers()
{
	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);
}

void Mesh::initialize(vector<Vertex>&verts, vector<unsigned int>&indices)
{
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(vec4)));

	glDrawElements(GL_TRIANGLES, index_Count(), GL_UNSIGNED_INT, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	delete[] aoVerticies;
}

vector<vec4> Mesh::genHalfCircle(unsigned int radius, unsigned int np)
{
	assert(radius > 0);
	assert(np >= 3);
	return vector<vec4>();
}

vector<vec4> Mesh::rotatePoints(vector<vec4> points, unsigned int nm)
{
	return vector<vec4>();
}

void Mesh::bind()
{
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, (m_rows * m_cols) * sizeof(Vertex), aoVerticies, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (m_rows - 1) * (m_cols - 1) * 6 * sizeof(unsigned int), auiIndices, GL_STATIC_DRAW);
}

void Mesh::unbind()
{
	glBindVertexArray(0);
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
