#pragma once
#include "bootApplication.h"
//includes for information from other header files

class InheritanceApp : public bootApplication // class that this is being inherited
{
public:
	InheritanceApp();  //constructor for class
	~InheritanceApp(); //destructor for class

	virtual void run(const char* title, unsigned int width, unsigned int height, bool fullscreen); // function for the application running
};