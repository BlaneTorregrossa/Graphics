#pragma once
#include "bootApplication.h" // from bootstrap
#include "gl_core_4_4.h"
#include "Mesh.h"
#include <stdio.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp> // This is for use of glm::value_ptr

class RenderingApp : public bootApplication
{
public:
	RenderingApp();
	virtual ~RenderingApp();

	void generateGrid(unsigned int m_rows, unsigned int m_columns);
	void genPlane();
	void genCube();
	/*
	///Causing problems
	std::vector<glm::vec4> genHalfCircle(unsigned int radius, unsigned int np);
	std::vector<glm::vec4> rotatePoints(unsigned int points, std::vector<glm::vec4> nm);
	*/
protected:
	// vertex and index buffers (for generating geometry)
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;

	unsigned int m_programID;

	glm::mat4 m_projectionViewMatrix = glm::mat4
	{
		glm::vec4(0, 0, 0, 0),
		glm::vec4(0, 0, 0, 0),
		glm::vec4(0, 0, 0, 0),
		glm::vec4(0, 0, 0, 0)
	};

	unsigned int m_rows;
	unsigned int m_columns;
};

