#pragma once
#include "gl_core_4_4.h"

struct GLFWwindow; //window object
class bootApplication
{
public:
	bootApplication(); // constructor for class
	virtual ~bootApplication(); // destructor for class

	virtual void run(const char* title, unsigned int width, unsigned int height, bool fullscreen); //function for running application

protected:
	void startup();
	void shutdown();
	void update(float);
	void draw();

	GLFWwindow* m_window; // to refer to the window
	bool m_check; // check for loop statement.

};

