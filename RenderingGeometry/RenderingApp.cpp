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
	unsigned int* auiIndices = new unsigned int[(rows - 1) * (cols - 1) * 6];
	Vertex* aoVerticies = new Vertex[rows * cols];

	for (unsigned int r = 0; r < rows; ++r)
	{
		for (unsigned int c = 0; c < cols; ++c)
		{
			aoVerticies[r * cols + c].position = glm::vec4((float)c, 0, (float)r, 1);

			glm::vec3 colour = glm::vec3(sinf((c / (float)(cols - 1)) * (r / (float)(rows - 1))));
			aoVerticies[r * cols + c].colour = glm::vec4(colour, 1);
		}
	}

	unsigned int index = 0;
	for (unsigned int r = 0; r < (rows - 1); ++r)
	{
		for (unsigned int c = 0; c < (cols - 1); ++c)
		{
			auiIndices[index++] = r * cols + c;
			auiIndices[index++] = (r + 1) * cols + c;
			auiIndices[index++] = (r + 1) * cols + (c + 1);

			auiIndices[index++] = r * cols + c;
			auiIndices[index++] = (r + 1) * cols + (c + 1);
			auiIndices[index++] = r * cols + (c + 1);
		}
	}
}

void RenderingApp::genPlane()
{
	Vertex A = { glm::vec4(-1, 0, 0, 1), glm::vec4(.5f, .5f, .5f, 1) };
	Vertex B = { glm::vec4(0, 0, 0, 1), glm::vec4(.5f, .5f, .5f, 1) };
	Vertex C = { glm::vec4(-1, 1, 0, 1), glm::vec4(.5f, .5f, .5f, 1) };
	Vertex D = { glm::vec4(0, 1, 0, 1), glm::vec4(.5f, .5f, .5f, 1) };

	std::vector<Vertex> verticies{ A, B, C, D };
	std::vector<unsigned int> indicies{ 0, 1, 2, 0, 2, 3 };
}

void RenderingApp::genCube()
{
	Vertex A = { glm::vec4(-1, 0, 0, 1), glm::vec4(.5f, .5f, .5f, 1) };
	Vertex B = { glm::vec4(0, 0, 0, 1), glm::vec4(.5f, .5f, .5f, 1) };
	Vertex C = { glm::vec4(-1, 1, 0, 1), glm::vec4(.5f, .5f, .5f, 1) };
	Vertex D = { glm::vec4(0, 1, 0, 1), glm::vec4(.5f, .5f, .5f, 1) };
	Vertex E = { glm::vec4(-1, 0, -1, 1), glm::vec4(.5f, .5f, .5f, 1) };
	Vertex F = { glm::vec4(0, 0, -1, 1), glm::vec4(.5f, .5f, .5f, .5f) };
	Vertex G = { glm::vec4(-1, 1, -1, 1), glm::vec4(.5f, .5f, .5f, 1) };
	Vertex H = { glm::vec4(0, 1, -1, 1), glm::vec4(.5f, .5f, .5f, 1) };

	std::vector<Vertex> verticies{ A, B, C, D, E, F, G, H };
	std::vector<unsigned int> indicies{ 0, 1, 2, 0, 2, 3, /*resets starting index ,*/ 
										0, 1, 4, 0, 4, 5, /*resets starting index ,*/ 
										4, 5, 6, 4, 6, 7, /*resets starting index ,*/ 
										6, 7, 2, 6, 2, 3, /*resets starting index ,*/ 
										6, 2, 0, 6, 0, 7, /*resets starting index ,*/ 
										5, 1, 3, 5, 3, 7};
}




