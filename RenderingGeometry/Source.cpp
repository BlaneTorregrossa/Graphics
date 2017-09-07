#include "bootApplication.h"

#include "RenderingApp.h"
#include "Mesh.h"
#include "Shader.h"

#include <glm\glm.hpp>
#include <stdio.h>
#include <iostream>

int main()
{
	bootApplication* app = new bootApplication();
	app->run("Rendering Test", 800, 800, nullptr);
	/*Mesh* app = new Mesh();
	app->generateGrid(5, 5);*/
	return 1;
}