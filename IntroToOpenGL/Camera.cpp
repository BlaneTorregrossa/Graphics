#include "Camera.h"

// Something in here is potentially preventing anything in the project from running properly

Camera::Camera()
{
}


Camera::~Camera()
{
}


void Camera::update(float deltaTime)
{
}

void Camera::setPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
	auto X = 1.f / (aspectRatio * tan(fieldOfView / 2.f));
	auto Y = 1.f / (aspectRatio * tan(fieldOfView / 2.f));
	auto Z = 1.f / ((far + near) / (far - near));
	auto W = 1.f / ((2.f * far * near) / (far - near));

	auto perspectiveMatrix = glm::mat4
	{
		glm::vec4(X, 0, 0, 0),
		glm::vec4(0, Y, 0, 0),
		glm::vec4(0, 0, Z, 0),
		glm::vec4(0, 0, 0, W)
	};
	/*auto perspectiveMatrixTest = setPerspective(fieldOfView, 16.f / 9.f, 0.f, 200.f);
	assert(perspectiveMatrix == perspectiveMatrixTest);*/
}

// eye must be a vector of <10, 10, 10> and center must be a vector of <0, 0, 0>
void Camera::setLookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up)
{
	assert(eye == glm::vec3(10, 10, 10));
	assert(center == glm::vec3(0, 0, 0));
	glm::vec3 x;
	glm::vec3 y;
	glm::vec3 z;
	auto c = glm::vec3(0, 0, 0);
	auto forwardVector = (eye - center);
	forwardVector = (forwardVector / (sqrt(forwardVector)));
	z = normalize(forwardVector);
	auto s = cross(up,z);
	x = (s / (sqrt(s))) = normalize(s);
	auto u = cross(z,x);
	y = (u / (sqrt(u))) = c;
	auto v = glm::mat4
	{
		glm::vec4(x[0], y[0], z[0], 0),
		glm::vec4(x[1], y[1], z[1], 0),
		glm::vec4(x[2], y[2], z[2], 0),
		glm::vec4(0, 0, 0, 1)
	};
	//fix this matrix
	auto t = glm::mat4
	{
		glm::vec4(1, 0, 0, 0),
		glm::vec4(0, 1, 0, 0),
		glm::vec4(0, 0, 1, 0),
		glm::vec4(0, 0, 0, 1)
	};
	auto invertedV = v * t;
	auto m = invertedV;
}

void Camera::setPosition(glm::vec3 position)
{

}

glm::mat4 Camera::getWorldTransform()
{
	return m_worldTransform;
}

glm::mat4 Camera::getView()
{
	return m_viewTransform;
}

glm::mat4 Camera::getProjection()
{
	return m_projectionTransform;
}

glm::mat4 Camera::getProjectionView()
{
	return m_projectionTransform;
}

void Camera::updateProjectionViewTransform()
{

}
