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
	virtual void startup() = 0;
	virtual void shutdown() = 0;
	virtual void update(float) = 0; // update function
	virtual void draw() = 0;

	//// vertex and index buffers (for generating geometry)
	//unsigned int m_VAO;
	//unsigned int m_VBO;
	//unsigned int m_IBO;
	//unsigned int m_programID;


	GLFWwindow* m_window; // to refer to the window
	bool m_check; // check for loop statement.

};

