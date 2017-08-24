#pragma once
#include "Camera.h"

struct GLFWwindow; //window object
class Application
{
public:
	Application(); // constructor for class
	virtual ~Application(); // destructor for class

	virtual void run(const char* title, unsigned int width, unsigned int height, bool fullscreen); //function for running application

protected:
	virtual void startup();
	virtual void shutdown();
	virtual void update(float) = 0; // update function
	GLFWwindow* m_window; // to refer to the window
	bool m_check; // check for loop statement.

};

