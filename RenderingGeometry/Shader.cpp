#include "Shader.h"

// 

Shader::Shader()
{
}


Shader::~Shader()
{
}

//*
void Shader::startup()
{
	//success = GL_FALSE;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	m_program = glCreateProgram();
}

void Shader::shutdown()
{
	glDeleteShader(fragmentShader);
	glDeleteShader(vertexShader);
}

void Shader::bind()
{
	glLinkProgram(m_program);
}

void Shader::unbind()
{
	glLinkProgram(0);
}

//*
void Shader::defaultLoad()
{
	vsSource = "#version 410\n \
				layout(location=0) in vec4 position; \
				layout(location=0) in vec4 colour \
				out vec4 vColour; \
				uniform mat4 projectionViewWorldMatrix; \
				void main() { vColour = colour; gl_Position = projectionViewWorldMatrix * position; }";

	fsSource = "#version 410\n \
				in vec4 vColour; \
				out vec4 fragColor; \
				void main() { fragColor = vColour; }";
}

//*
void Shader::load(const char * filename, unsigned int type)
{
	glShaderSource(vertexShader, 1, (const char**)&vsSource, 0);
	glCompileShader(vertexShader);
	glShaderSource(fragmentShader, 1, (const char**)&fsSource, 0);
	glCompileShader(fragmentShader);
}

//*
void Shader::attach()
{
	glAttachShader(m_program, vertexShader);
	glAttachShader(m_program, fragmentShader);
}

//*
unsigned int Shader::getUniform(const char *)
{
	return 0;
}
