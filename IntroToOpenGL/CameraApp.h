#pragma once
#include "Application.h"
#include "Gizmos.h"
#include "gl_core_4_4.h"
#include <glfw-3.2.1.bin.WIN32\include\GLFW\glfw3.h>
#include <cstdio>
//Third party libraries and the application header made previously

//Startup, Shutdown, drawing, update, and running function as well as setting a "camera"
class CameraApp
{
public:
	CameraApp();
	~CameraApp();

	void startup();
	void shutdown();
	void draw();
	void update(float deltaTime);
	void run(const char* title, float width, float height, bool fullscreen);
	Camera* m_camera;

private:
	double m_currentTime = 0;

};

