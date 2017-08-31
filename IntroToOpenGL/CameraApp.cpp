#include "CameraApp.h"


CameraApp::CameraApp()
{
}


CameraApp::~CameraApp()
{
}

//Application on startup Sets up camera, it's perspective view, position, and LookAt (See Camera.cpp)
//Creates with Gizmos
void CameraApp::startup()
{
	m_camera = new Camera();
	m_camera->setPerspective(70.f, 16.f/ 9.f, 1.f, 200.f);
	m_camera->setPosition(glm::vec3(0, 1, 1));
	m_camera->setLookAt(glm::vec3(10, 10, 10), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
	Gizmos::create();
}

// not used
void CameraApp::shutdown()
{
	// shutdown app
}

//Draws objects with transform, it's color, center + camera
void CameraApp::draw()
{
	auto sphere = glm::mat4(1);
	auto center = glm::vec4(0, 0, 0, 1);
	auto color = glm::vec4(0, 0, 0, 0);
	Gizmos::addSphere(sphere[3], 1, 10, 10, color); //setting center, radius, and color
	Gizmos::addTransform(sphere, 5); // Sets transform and radius
}

//update with controls to control camrea with both mouse and WASD controls
void CameraApp::update(float deltaTime)
{
	m_currentTime += deltaTime;

}

//Runs application
void CameraApp::run(const char * title, float width, float height, bool fullscreen)
{
}
