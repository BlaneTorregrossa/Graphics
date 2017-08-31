#pragma once
#include <glm\glm.hpp>

struct Vertex
{
	glm::vec4 position;
	glm::vec4 colour;
	// will contain vec4 UV later on and other variables
};

class RenderingApp
{
public:
	RenderingApp();
	virtual ~RenderingApp();

	void generateGrid(unsigned int m_rows, unsigned int m_columns);
	void tempStartup();

protected:
	// vertex and index buffers (for generating geometry)
	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_IBO;

	unsigned int m_programID;

	unsigned int m_projectionViewMatrix;

	unsigned int m_rows;
	unsigned int m_columns;
};

