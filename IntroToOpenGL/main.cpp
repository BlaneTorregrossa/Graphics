#include "gl_core_4_4.h"
#include "InheritanceApp.h"
#include "Camera.h"
#include <glfw-3.2.1.bin.WIN32\include\GLFW\glfw3.h>
#include <stdio.h>

#include <iostream>
//includes for information from other header files and thirdparty librarys

/*
problem:
app won't launch because of this error from gl_core_4_4.h:
#error Attempt to include auto-generated header after including gl.h

*/

//main function for the project applications, such as the inheritance and camera app, to be run from here.
int main()
{
	Camera* app = new Camera();
	app->setLookAt(glm::vec3(10, 10, 10), glm::vec3(0, 0, 0), glm::vec3(3, 3, 3));
	//Application* app = new InheritanceApp();
	//app->run("Intro To OpenGL", 800, 800, false); // run function and what it's taking in for the application currently
	return 1; // returns 1 and terminates program
}