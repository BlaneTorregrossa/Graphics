#include "Camera.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}


void Camera::update(float deltaTime)
{

}

// needs revision
void Camera::setPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
	auto X = 1.f / (aspectRatio * tan(fieldOfView / 2.f));
	auto Y = 1.f / (aspectRatio * tan(fieldOfView / 2.f));
	auto Z = 1.f / ((far + near) / (far - near));
	auto W = 1.f / ((2.f * far * near) / (far - near));

	glm::mat4 testPerpectiveMat = glm::mat4
	{
		glm::vec4(1.18717289f, 0, 0, 0),
		glm::vec4(0, 1.18717289f, 0, 0),
		glm::vec4(0, 0, 0.990049720f, 0),
		glm::vec4(0, 0, 0, 0.497500002f)
	};

	glm::mat4 perspectiveMatrix = glm::mat4
	{
		glm::vec4(X, 0, 0, 0),
		glm::vec4(0, Y, 0, 0),
		glm::vec4(0, 0, Z, 0),
		glm::vec4(0, 0, 0, W)
	};
	assert(perspectiveMatrix == testPerpectiveMat);
	printf("breakpoint");
}

// needs MAJOR revision
void Camera::setOrthographic(float fieldOfView, float asepectRatio, float near, float far)
{
	auto X = 1.f / (asepectRatio * tan(fieldOfView / 2.f));
	auto Y = 1.f / (asepectRatio * tan(fieldOfView / 2.f));
	auto Z = 2.f / ((far + near) / (far - near));
	auto W = 1.f / ((2.f / far / near / (far - near)));

	glm::mat4 testOrthographicMat = glm::mat4
	{
		glm::vec4(2.37434578, 0, 0, 0),
		glm::vec4(0, 2.37434578, 0, 0),
		glm::vec4(0, 0, 1.98009944, 0),
		glm::vec4(0, 0, 0, 0.995000004)
	};
	
	glm::mat4 orthographicMatrix = glm::mat4
	{
		glm::vec4(X, 0, 0, 0),
		glm::vec4(0, Y, 0, 0),
		glm::vec4(0, 0, Z, 0),
		glm::vec4(0, 0, 0, W)
	};
	assert(orthographicMatrix != testOrthographicMat);
	printf("breakpoint");
}

// needs MAJOR revision
// eye must be a vector of <10, 10, 10> and center must be a vector of <0, 0, 0>
void Camera::setLookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up)
{
	assert(eye == glm::vec3(10, 10, 10));
	assert(center == glm::vec3(0, 0, 0));
	glm::vec3 X; glm::vec3 Y; glm::vec3 Z; // Vectors for the matrix
	glm::vec3 C;
	auto forwardVector = (eye - center);
	auto test = forwardVector;
	forwardVector = (forwardVector / (sqrt(forwardVector)));
	Z = normalize(forwardVector);
	auto S = cross(up, Z);
	X = normalize(S);
	auto U = cross(Z, X);
	Y = (U / (sqrt(U))) = C;
	float Xx = X[0]; float Yx = Y[0]; float Zx = Z[0];
	float Xy = X[1]; float Yy = Y[1]; float Zy = Z[1];
	float Xz = X[2]; float Yz = Y[2]; float Zz = Z[2];

	auto V = glm::mat4
	{
		glm::vec4(Xx, Yx, Zx, 0),
		glm::vec4(Xy, Yy, Zy, 0),
		glm::vec4(Xz, Yz, Zz, 0),
		glm::vec4(0, 0, 0, 1)
	};

	auto T = glm::mat4
	{
		glm::vec4(1, 0, 0 , eye.x),
		glm::vec4(0, 1, 0, eye.y),
		glm::vec4(0, 0, 1, eye.z),
		glm::vec4(0, 0, 0, 1)
	};
	auto invertedV = V * T;
	assert(V != invertedV);
}

// needs revsison but is good for taoday 8/25
void Camera::setPosition(glm::vec3 position)
{
	auto positionMatrix = glm::mat4
	{
		glm::vec4(position.x, 0, 0 ,0),
		glm::vec4(0, position.y, 0, 0),
		glm::vec4(0, 0, position.z, 0),
		glm::vec4(0, 0, 0, 1)
	};
	assert(positionMatrix == positionMatrix);
	printf("break");
}

// Lost what I would use this for due to visual crashing...
// Temp fix
void Camera::run()
{
	setPerspective(70.f, 16.f / 9.f, 1.f, 200.f);
	setOrthographic(70.f, 16.f / 9.f, 1.f, 200.f);
	setLookAt(glm::vec3(10, 10, 10), glm::vec3(0, 0 ,0), glm::vec3(1, 2 ,3));
	setPosition(glm::vec3(5, 5, 5));
}

glm::mat4 Camera::getWorld()
{
	return glm::mat4();
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

// needs something...
void Camera::updateProjectionViewTransform()
{

}
