#include "Application.h"
#include "gl_core_4_4.h"
#include <include\GLFW\glfw3.h>
#include <glm.hpp>


#include <iostream>
//includes for information from other header files and thirdparty librarys

//constructor
Application::Application()
{
}

//desstructor
Application::~Application()
{
}

//Run function that takes in a title, width, height, and if the application will be fullscreen
//Defines how the application runs on startup.
void Application::run(const char * title, unsigned int width, unsigned int height, bool fullscreen)
{
	//GLFW function for initialization. if initialization fails terminates program
	if (glfwInit() == GL_FALSE)
	{
		return; // Terminate program
	}

	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr); // Creates the application window

	glfwMakeContextCurrent(m_window); // Gives/Makes the context of m_window current for calling

	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) //Load OpenGL functions and if it can't the program is terminated.
	{
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return; //Terminate program
	}

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.12f, 0.12f, 0.30f, 1.0f); // Sets a "Background" color

	// Setup definitions for calculating time
	double prevTime = glfwGetTime(); // Sets prevTime to return the value of the GLFW timer
	double currTime = 0;
	double deltaTime = 0;

	while (!m_check) // loop could be set better
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clears the window

		currTime = glfwGetTime();  // Sets currTime to return the value of the GLFW timer
		deltaTime = currTime - prevTime;  // deltaTime set to equal the change of time between current time and the previous time
		prevTime = currTime; // Updates prevTime
		
		update(deltaTime);
		draw();

		glfwPollEvents(); // processes all events
		glfwSwapBuffers(m_window); // Swaps the front and back buffers of the window
	}

	glfwDestroyWindow(m_window);
	glfwTerminate();
}

void Application::startup()
{
}

void Application::shutdown()
{
}

