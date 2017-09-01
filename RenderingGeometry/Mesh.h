#pragma once
#include "RenderingApp.h"
#include "gl_core_4_4.h"
#include <stdio.h>
#include <vector>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

using namespace glm;
using namespace std;

struct Vertex
{
	vec4 position;
	vec4 colour;
};

class Mesh
{
public:
	Mesh();
	~Mesh();

	void Create_buffers();
	void initialize(vector<Vertex>&verts, vector<unsigned int>&indices);

	void bind();
	void unbind();
	unsigned int index_Count();
	unsigned int vertex_Count();

protected:

private:
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;

	vector<unsigned int> m_indicies;
	vector<Vertex> m_verticies;
	
};

