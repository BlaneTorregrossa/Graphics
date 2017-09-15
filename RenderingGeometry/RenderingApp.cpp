#include "RenderingApp.h"
#include "Mesh.h"
#include "Shader.h"

RenderingApp::RenderingApp()
{
}


RenderingApp::~RenderingApp()
{
}

//*
void RenderingApp::generateGrid(unsigned int rows, unsigned int cols)
{
	unsigned int* auiIndices = new unsigned int[(rows - 1) * (cols - 1) * 6];
	Vertex* aoVerticies = new Vertex[rows * cols];

	//!!!
	for (unsigned int r = 0; r < rows; ++r)
	{
		for (unsigned int c = 0; c < cols; ++c)
		{
			aoVerticies[r * cols + c].position = glm::vec4((float)c, 0, (float)r, 1);

			glm::vec3 colour = glm::vec3(sinf((c / (float)(cols - 1)) * (r / (float)(rows - 1))));
			aoVerticies[r * cols + c].colour = glm::vec4(colour, 1);
		}
	}

	//!!!
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

void RenderingApp::startup()
{
}

void RenderingApp::shutdown()
{
}

