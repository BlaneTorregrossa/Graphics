#pragma once
#include "bootApplication.h" // from bootstrap
#include "gl_core_4_4.h"
#include "Mesh.h"
#include <stdio.h>
#include <glm.hpp>
#include <gtc\type_ptr.hpp> // This is for use of glm::value_ptr

struct Vertex		// struct to set up what a vertex is
{
	glm::vec4 position;
	glm::vec4 colour;
};
class RenderingApp : public bootApplication
{
public:
	RenderingApp();
	virtual ~RenderingApp();

	virtual void startup() override;
	virtual void shutdown() override;
	virtual void update(float) override;
	virtual void draw() override;

	void generateGrid(unsigned int m_rows, unsigned int m_columns);
	void generatePlane();
	void generateCube();

	Vertex* vertices;

protected:
	// vertex and index buffers (for generating geometry)
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;

	unsigned int m_programID;

	unsigned int m_rows;
	unsigned int m_columns;

	glm::mat4 m_view;
	glm::mat4 m_projection;

};

