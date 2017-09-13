#include "InheritanceApp.h"
//includes for information from other header files


InheritanceApp::InheritanceApp()
{
}


InheritanceApp::~InheritanceApp()
{
}

void InheritanceApp::run(const char * title, unsigned int width, unsigned int height, bool fullscreen)
{
	bootApplication::run(title, width, height, fullscreen);
}
