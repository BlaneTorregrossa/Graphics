#include "RenderingApp.h"
#include "Mesh.h"
#include "Shader.h"

RenderingApp::RenderingApp()
{
}


RenderingApp::~RenderingApp()
{
}


void RenderingApp::generateGrid(unsigned int rows, unsigned int cols)
{
}

void RenderingApp::generatePlane()
{
	Vertex a = { glm::vec4(0, 0, 0, 1), glm::vec4(.1, .1, .1, 1) };
	Vertex b = { glm::vec4(3, 0, 0, 1), glm::vec4(.1, .1, .1, 1) };
	Vertex c = { glm::vec4(3, 0, 0, 1), glm::vec4(.1, .1, .1, 1) };
	Vertex d = { glm::vec4(0, 0, 0, 1), glm::vec4(.1, .1, .1, 1) };

	vertices = new Vertex[4];
	vertices[0] = a;
	vertices[1] = b;
	vertices[2] = c;
	vertices[3] = d;

	unsigned int indices[6] = { 0, 1, 2, 0, 2, 3};
	unsigned int vertAmount = 4;
	unsigned int indicesAmount = 6;

	Mesh* createPlane = new Mesh();
	createPlane->Create_buffers();
}

void RenderingApp::generateCube()
{
	Vertex a = { glm::vec4(-1, 0, 0, 1), glm::vec4(.20, .20, .20, 1) }; 
	Vertex b = { glm::vec4(0, 0, 0, 1), glm::vec4(.20, .20, .20, 1) };	
	Vertex c = { glm::vec4(0, 1, 0, 1), glm::vec4(.20, .20, .20, 1) };	
	Vertex d = { glm::vec4(-1, 1, 0, 1), glm::vec4(.20, .20, .20, 1) };	

	Vertex e = { glm::vec4(-1, 0, -1, 1), glm::vec4(.20, .20, .20, 1) }; 
	Vertex f = { glm::vec4(0, 0, -1, 1), glm::vec4(.20, .20, .20, 1) };	
	Vertex g = { glm::vec4(0, 1, -1, 1), glm::vec4(.20, .20, .20, 1) };	
	Vertex h = { glm::vec4(-1, 1, -1, 1), glm::vec4(.20, .20, .20, 1) }; 

	vertices = new Vertex[8];
	vertices[0] = a;
	vertices[1] = b;
	vertices[2] = c;
	vertices[3] = d;
	vertices[4] = e;
	vertices[5] = f;
	vertices[6] = g;
	vertices[7] = h;

	unsigned int indices[36] = { 
									
	};
	unsigned int vertAmount = 8;
	unsigned int indicesAmount = 36;

	Mesh* createCube = new Mesh();
	createCube->Create_buffers();
}

void RenderingApp::startup()
{
}

void RenderingApp::shutdown()
{
}

void RenderingApp::update(float)
{
}

void RenderingApp::draw()
{
}

