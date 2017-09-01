#include "RenderingApp.h"
#include "Mesh.h"
#include <iostream>

int main()
{
	Mesh* app = new Mesh();
	app->~Mesh();
	app->Create_buffers();
	return 1;
}