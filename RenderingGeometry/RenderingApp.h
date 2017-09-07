#pragma once
#include "bootApplication.h" // from bootstrap
#include "gl_core_4_4.h"
#include "Mesh.h"
#include <stdio.h>
#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp> // This is for use of glm::value_ptr

using namespace glm;

class RenderingApp
{
public:
	RenderingApp();
	virtual ~RenderingApp();

	void generateGrid(unsigned int m_rows, unsigned int m_columns);
	void tempStartup();

protected:
	// vertex and index buffers (for generating geometry)
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;

	unsigned int m_programID;

	mat4 m_projectionViewMatrix = mat4
	{
		vec4(0, 0, 0, 0),
		vec4(0, 0, 0, 0),
		vec4(0, 0, 0, 0),
		vec4(0, 0, 0, 0)
	};

	unsigned int m_rows;
	unsigned int m_columns;
};

