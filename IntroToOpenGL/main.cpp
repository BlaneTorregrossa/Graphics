#include "gl_core_4_4.h"
#include "InheritanceApp.h"
#include <glfw-3.2.1.bin.WIN32\include\GLFW\glfw3.h>
#include <stdio.h>

#include <iostream>
//includes for information from other header files and thirdparty librarys

//main function for the project.
int main()
{
	Application* app = new InheritanceApp();
	app->run("Intro To OpenGL", 800, 800, false); // run function and what it's taking in for the application currently
	return 1; // returns 1 and terminates program
}