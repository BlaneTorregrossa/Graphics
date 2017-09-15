#include "bootApplication.h"

#include "RenderingApp.h"
#include "Mesh.h"
#include "Shader.h"

#include <glm.hpp>
#include <stdio.h>
#include <iostream>
// NO ADDITIONAL CODE BEYOND THIS---------------------------------


int main()
{
	bootApplication* app = new RenderingApp();
	app->run("Rendering shapes", 1280, 720, false);
	return 1;
}