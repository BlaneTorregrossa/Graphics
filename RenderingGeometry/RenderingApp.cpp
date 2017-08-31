#include "RenderingApp.h"
#include "gl_core_4_4.h"
#include <stdio.h>
#include <glm\glm.hpp>

using namespace glm;

RenderingApp::RenderingApp()
{
}


RenderingApp::~RenderingApp()
{
}

// accepts rows and columns as arguments to generate and then delete a grid
void RenderingApp::generateGrid(unsigned int rows, unsigned int columns)
{
	Vertex* aoVertices = new Vertex[rows * columns];
	for (unsigned int r = 0; r < rows; ++r)
	{
		for (unsigned int c = 0; c < columns; ++c)
		{
			aoVertices[r * columns + c].position = glm::vec4((float)c, 0, (float)r, 1);

			//creates colour
			glm::vec3 colour = glm::vec3(sinf((c / (float)(columns - 1)) * (r / (float)(rows - 1))));
			aoVertices[r * columns + c].colour = glm::vec4(colour, 1);
		}
	}

#pragma region Defining Index
	//defining index
	unsigned int* auiIndices = new unsigned int[(rows - 1) * (columns - 1) * 6];

	unsigned int index = 0;
	for (unsigned int r = 0; r < (rows - 1); ++r)
	{
		for (unsigned int c = 0; c < (columns - 1); ++c)
		{
			// triangle 1
			auiIndices[index++] = r * columns + c;
			auiIndices[index++] = (r + 1) * columns + c;
			auiIndices[index++] = (r + 1) * columns + (c + 1);

			//tirangle 2
			auiIndices[index++] = r * columns + c;
			auiIndices[index++] = (r + 1) * columns + (c + 1);
			auiIndices[index++] = r * columns + (c + 1);
		}
	}
#pragma endregion

	glGenBuffers(1, &m_VBO);
	glGenBuffers(1, &m_IBO);

	glGenVertexArrays(1, &m_VAO);

	glBindVertexArray(m_VAO);

	// create and bind (VBO) buffers to a vertex array object
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, (rows * columns) * sizeof(Vertex), aoVertices, GL_STATIC_DRAW);

	// create and bind (IBO) buffers to a vertex array object
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (rows - 1) * (columns - 1) * 6 * sizeof(unsigned int), auiIndices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	//set up how vertex structure is made
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glUseProgram(m_programID);
	unsigned int projectionViewUniform = glGetUniformLocation(m_programID, "projectionViewWorldMatrix");
	glUniformMatrix4fv(projectionViewUniform, 1, false, glm::value_ptr(m_projectionViewMatrix)); // i don't like this line

	glBindVertexArray(m_VAO);
	unsigned int indexCount = (rows - 1) * (columns - 1) * 6;
	glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	delete[] aoVertices;
}

void RenderingApp::tempStartup()
{
	//creates Shaders
	const char* vsSource = "#version 410\n \
							layout(location=0) in vec4 position; \
							layout(location=0) in vec4 colour; \
							out vec4 vColour; \
							uniform mat4 projectionViewWorldMatrix; \
							void main() { vColour = colour; gl_Position = projectionViewWorldMatrix * position; }";

	const char* fsSource = "#version 410\n \
							in vec4 vColour; \
							out vec4 fragColor; \
							void main() { fragColor = vColour; }";

	// compiles shaders
	int success = GL_FALSE;
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0);
	glCompileShader(vertexShader);
	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0);
	glCompileShader(fragmentShader);

	m_programID = glCreateProgram();
	glAttachShader(m_programID, vertexShader);
	glAttachShader(m_programID, fragmentShader);
	glLinkProgram(m_programID);

	glGetProgramiv(m_programID, GL_LINK_STATUS, &success);
	if (success == GL_FALSE)
	{
		int infoLogLength = 0;
		glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* infoLog = new char[infoLogLength];

		glGetProgramInfoLog(m_programID, infoLogLength, 0, infoLog);
		printf("Error: Failed to link shader program! \n");
		printf("%s\n", infoLog);
		delete[] infoLog;
	}

	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
}


