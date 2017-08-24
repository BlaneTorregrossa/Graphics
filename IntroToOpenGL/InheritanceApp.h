#pragma once
#include "Application.h"
//includes for information from other header files

class InheritanceApp : public Application // class that this is being inherited
{
public:
	InheritanceApp();  //constructor for class
	~InheritanceApp(); //destructor for class


private: 

	virtual void update(float) override; // update function
	virtual void run(const char* title, unsigned int width, unsigned int height, bool fullscreen); // function for the application running
};

