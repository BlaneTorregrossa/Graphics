#include "InheritanceApp.h"

#include <iostream>
//includes for information from other header files and thirdparty librarys


int main()
{
	bootApplication* app = new InheritanceApp();
	app->run("intro window", 800, 800, false);
	return 1;
}