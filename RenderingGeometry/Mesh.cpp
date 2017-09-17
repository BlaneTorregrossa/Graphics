#include "Mesh.h"

#include <assert.h>

Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

void Mesh::Create_buffers()
{
	glGenVertexArrays(1, &m_vao);

	glGenBuffers(1, &m_vbo);
	glGenBuffers(1, &m_ibo);

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	glBufferData(GL_ARRAY_BUFFER, vertex_Count * sizeof(Vertex), m_verticies.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, index_Count * sizeof(unsigned int), m_indicies.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));
	
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

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
}

void Mesh::bind()
{
}

void Mesh::unbind()
{
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


void Mesh::draw(int num)
{
	glBindVertexArray(m_vao); // binds
	glBindVertexArray(0); // unbinds
}
