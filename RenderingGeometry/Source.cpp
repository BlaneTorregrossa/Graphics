#include "RenderingApp.h"
#include <iostream>

int main()
{
	RenderingApp* app = new RenderingApp();
	app->generateGrid(5, 5);
	return 1;
}