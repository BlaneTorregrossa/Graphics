#include "bootApplication.h"
#include "DirectLightingApp.h"

#include <glm.hpp>
#include <stdio.h>
#include <iostream>


int main()
{
	bootApplication* app = new DirectLightingApp();
	app->run("Rendering shapes", 1280, 720, false);
	delete app;
}