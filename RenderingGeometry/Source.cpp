#include "bootApplication.h"

#include "RenderingApp.h"
#include "Mesh.h"
#include "Shader.h"

#include <glm\glm.hpp>
#include <stdio.h>
#include <iostream>

int main()
{
	auto app = new Mesh();
	app->Create_buffers();
	return 1;
}