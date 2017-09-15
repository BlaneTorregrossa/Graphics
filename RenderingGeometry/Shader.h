#pragma once
#include "bootApplication.h" // Calls bootstrap header file

#include "RenderingApp.h"
#include "Mesh.h"
#include "gl_core_4_4.h"

#include <stdio.h>
#include <vector>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
// includes from elsewhere in the project and third party libraries


class Shader
{
public:
	Shader();
	~Shader();
	void startup();		
	void shutdown();
	void bind();		
	void unbind();
	void defaultLoad();
	void load(const char * filename, unsigned int type);
	void attach();		//attatchment of the shaders to the program

	unsigned int getUniform(const char *);
	unsigned int m_program;
	const char* vsSource;	//Vertex Shader
	const char* fsSource;	//Fragment Shader

private:
	unsigned int success;			// a check for a loop
	unsigned int vertexShader;		// vertexShader 
	unsigned int fragmentShader;	// fragmentShader
};

