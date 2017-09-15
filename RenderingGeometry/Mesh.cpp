#include "Mesh.h"

#include <assert.h>

Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

//this is fine
void Mesh::Create_buffers()
{
	glGenVertexArrays(1, &m_vao);

	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, m_verticies.size() * sizeof(Vertex), m_verticies.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indicies.size() * sizeof(unsigned int), m_indicies.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));
	
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// this is fine
void Mesh::initialize(std::vector<Vertex>&verts, std::vector<unsigned int>&indices)
{
	for (auto v : verts)
	{
		m_verticies.push_back(v);
	}

	for (auto i : indices)
	{
		m_indicies.push_back(i);
	}

	index_Count = m_indicies.size();
	vertex_Count = m_verticies.size();

	Create_buffers();
}

// this is fine
void Mesh::bind()
{
	glBindVertexArray(m_vao);
}

// this is fine
void Mesh::unbind()
{
	glBindVertexArray(0);
}

void Mesh::startup()
{
}

void Mesh::shutdown()
{
}

void Mesh::update(float)
{
}

//*
void Mesh::draw(GLuint num)
{
	bind();
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glDrawElements(num, index_Count, GL_UNSIGNED_INT, 0);
	unbind();
}
