#pragma once
#include "bootApplication.h"	//calls bootstrap header file

#include "RenderingApp.h"
#include "gl_core_4_4.h"

#include <stdio.h>
#include <vector>
#include <glm.hpp>
#include <gtc\type_ptr.hpp>
// includes header files from elsewhere in the project and also from third party libraries

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
	void Create_buffers();	// creates buffer for the mesh
	void initialize(std::vector<Vertex>&verts, std::vector<unsigned int>&indices);
	void bind();		//bind array and vertex buffers
	void unbind();		//unbind array and vertex buffers
	void startup();
	void shutdown();
	void update(float);
	void draw(int);
	unsigned int index_Count;		
	unsigned int vertex_Count;	

private:
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;


	std::vector<unsigned int> m_indicies;
	std::vector<Vertex> m_verticies;
	
};

