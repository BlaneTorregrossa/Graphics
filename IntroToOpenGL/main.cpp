#include "gl_core_4_4.h"
#include "InheritanceApp.h"
#include "Camera.h"
#include <glfw-3.2.1.bin.WIN32\include\GLFW\glfw3.h>
#include <stdio.h>

#include <iostream>
//includes for information from other header files and thirdparty librarys


int main()
{
	/*Application* app = new InheritanceApp();
	app->run("Windwo Title", 800, 800, nullptr);*/
	Camera* camApp = new Camera();
	camApp->run();
	return 1; // returns 1 and terminates program
}