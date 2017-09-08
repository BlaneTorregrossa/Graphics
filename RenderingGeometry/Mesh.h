#pragma once
#include "bootApplication.h"	//calls bootstrap header file

#include "RenderingApp.h"
#include "Shader.h"
#include "gl_core_4_4.h"

#include <stdio.h>
#include <vector>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>
// includes header files from elsewhere in the project and also from third party libraries

using namespace std;
// namespaces that remove the use of typing the namespacestd for value_ptr

struct Vertex		// struct to set up what a vertex is
{
	glm::vec4 position;
	glm::vec4 colour;
};

class Mesh
{
public:
	Mesh();
	~Mesh();

	void setRowAndCol(unsigned int rows, unsigned int cols);
	void Create_buffers();	// creates buffer for the mesh
	void initialize(vector<Vertex>&verts, vector<unsigned int>&indices);

	void bind();		//bind array and vertex buffers
	void unbind();		//unbind array and vertex buffers
	unsigned int index_Count();		// counts the indices
	unsigned int vertex_Count();	// counts the verticies
	unsigned int* auiIndices = new unsigned int[(m_rows - 1) * (m_cols - 1) * 6];
	Vertex* aoVerticies = new Vertex[m_rows * m_cols];

private:
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;
	unsigned int m_rows;		// row member variable
	unsigned int m_cols;		// column member variable

	vector<unsigned int> m_indicies;
	vector<Vertex> m_verticies;
	
};

