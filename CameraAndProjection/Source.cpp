#include "bootApplication.h"
#include "CamApp.h"

int main()
{
	bootApplication* app = new CamApp();
	app->run("application name", 800, 800, false);
	delete app;
}