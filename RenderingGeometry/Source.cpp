#include "bootApplication.h"

#include "RenderingApp.h"
#include "Mesh.h"
#include "Shader.h"

#include <glm.hpp>
#include <stdio.h>
#include <iostream>

int main()
{
	bootApplication* app = new RenderingApp();
	app->run("Rendering shapes", 800, 800, false);
	return 1;
}