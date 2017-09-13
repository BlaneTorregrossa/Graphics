#include "InheritanceApp.h"
//#include "Camera.h"

#include <iostream>
//includes for information from other header files and thirdparty librarys


int main()
{
	//Application* app = new InheritanceApp();
	//app->run("Windwo Title", 800, 800, nullptr);
	//Application* app = new CameraApp();					// does not work
	//app->run("Window Title", 800, 800, nullptr);		// Would set up window for the application
	bootApplication* app = new bootApplication();
	app->run("intro window", 800, 800, false);
	delete app; // delete app
}