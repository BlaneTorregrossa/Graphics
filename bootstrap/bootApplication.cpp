#include "bootApplication.h"
#include "gl_core_4_4.h"
#include <GLFW\include\GLFW\glfw3.h>

#include <iostream>
//includes for information from other header files and thirdparty librarys

//constructor
bootApplication::bootApplication()
{
}

//desstructor
bootApplication::~bootApplication()
{
}

//Run function that takes in a title, width, height, and if the application will be fullscreen
//Defines how the application runs on startup.
void bootApplication::run(const char * title, unsigned int width, unsigned int height, bool fullscreen)
{
	//GLFW function for initialization. if initialization fails terminates program
	if (glfwInit() == GL_FALSE)
	{
		return; // Terminate program
	}

	GLFWmonitor* monitor = (fullscreen) ? glfwGetPrimaryMonitor() : nullptr;
	m_window = glfwCreateWindow(width, height, title, monitor, nullptr); // Creates the application window

	glfwMakeContextCurrent(m_window); // Gives/Makes the context of m_window current for calling

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) //Load OpenGL functions and if it can't the program is terminated.
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return; //Terminate program
	}

	glClearColor(0.12f, 0.12f, 0.30f, 1.0f); // Sets a "Background" color

	double prevTime = glfwGetTime(); // Sets prevTime to return the value of the GLFW timer
	double currTime = 0;
	double deltaTime = 0;

	while (!m_check) // loop could be set better
	{
		//glEnable(GL_DEPTH_TEST);

		glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT); // Clears the window

		currTime = glfwGetTime();  // Sets currTime to return the value of the GLFW timer
		deltaTime = currTime - prevTime;  // deltaTime set to equal the change of time between current time and the previous time
		prevTime = currTime; // Updates prevTime

		glfwPollEvents(); // processes all events
		glfwSwapBuffers(m_window); // Swaps the front and back buffers of the window
	}
	//glfwDestroyWindow(m_window);
	//glfwTerminate();
	//return;
}
