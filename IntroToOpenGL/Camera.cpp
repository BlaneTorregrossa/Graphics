#include "Camera.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

// not used
void Camera::update(float deltaTime)
{

}

//Sets the perspective view for the cameras (Could not do without GLM)
void Camera::setPerspective(float fieldOfView, float aspectRatio, float near, float far)
{
	// The following variables are set for the specific purpose of seeting the perspective 
	// view in the matrix by modifying the aspectRatio, Field of View (X and Y),
	// near and far points (Z and W)
	auto X = 1.f / (aspectRatio * tanf(fieldOfView / 2.f));
	auto Y = 1.f / (tanf(fieldOfView / 2.f));
	auto Z = -1.f * ((far + near) / (far - near));
	auto W = -1.f * ((2.f * far * near) / (far - near));

	//Matrix setup for perspective view with each vec set
	glm::mat4 perspectiveMatrix = glm::mat4
	{
		glm::vec4(X, 0, 0, 0),
		glm::vec4(0, Y, 0, 0),
		glm::vec4(0, 0, Z, -1),
		glm::vec4(0, 0, W, 0)
	};
	auto perspectiveTest = glm::perspective(fieldOfView, aspectRatio, near, far);
	assert(perspectiveMatrix == perspectiveTest);
	//if assert passes then all is good with this function


}

//sets the orthographic view for the cameras (could not be done without GLM)
void Camera::setOrthographic(float left, float right, float bottom, float top, float near, float far)
{
	// Setting up specific vcaribles that deal with sutracting the values of specific dimensons
	auto X = 2 / (right - left);
	auto Y = 2 / (top - bottom);
	auto Z = 2 / (far - near);

	// sets values for variables on the W column using math that is based of off the high and low 
	// value of the specific dimenson
	auto Xa = ((right + left) / (right - left));
	auto Ya = ((top + bottom) / (top - bottom));
	auto Za = ((far + near) / (far - near));

	//Matrix for orthographic view. Previous varibles placed accordinglly 
	glm::mat4 orthographicMatrix = glm::mat4
	{
		glm::vec4(X, 0, 0, 0),
		glm::vec4(0, Y, 0, 0),
		glm::vec4(0, 0, Z, 0),
		glm::vec4(Xa, Ya, Za, 1)
	};

	auto orthographicTest = glm::ortho(left, right, bottom, top, near, far);
	assert(orthographicMatrix == orthographicTest);
	// if assert passes this function is good as is else it needs adjustment
}

// Sets LookAt with the "eye", center, and up variables to determine what the camera is looking at
// eye must be a vector of <10, 10, 10> and center must be a vector of <0, 0, 0>
void Camera::setLookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up)
{
	// quick test to see if arguments are st correctlly
	assert(eye == glm::vec3(10, 10, 10));
	assert(center == glm::vec3(0, 0, 0));

	// Sets XYZ varibles to be used in the view and translation matrix below
	glm::vec3 X;
	glm::vec3 Y;
	glm::vec3 Z;
	glm::vec3 C;
	auto forwardVector = (eye - center);
	auto test = forwardVector;
	forwardVector = (forwardVector / (sqrt(forwardVector)));
	Z = normalize(eye - center);
	auto S = cross(up, Z);
	X = normalize(S);
	Y = cross(Z, X);
	//float Xx = X[0]; float Yx = Y[0]; float Zx = Z[0];
	//float Xy = X[1]; float Yy = Y[1]; float Zy = Z[1];
	//float Xz = X[2]; float Yz = Y[2]; float Zz = Z[2];

	// View Matrix using varibles from above
	auto V = glm::mat4
	{
		glm::vec4(X.x, Y.x, Z.x, 0),
		glm::vec4(X.y, Y.y, Z.y, 0),
		glm::vec4(X.z, Y.z, Z.z, 0),
		glm::vec4(0, 0, 0, 1)
	};

	//Translate Matrix using eye argument 
	auto T = glm::mat4
	{
		glm::vec4(1, 0, 0 , 0),
		glm::vec4(0, 1, 0, 0),
		glm::vec4(0, 0, 1, 0),
		glm::vec4(-eye.x, -eye.y, -eye.z, 1)
	};

	// math with both matricies before testing
	V = V * T;
	m_viewTransform = V;
	
	auto lookAtTest = glm::lookAt(eye, center, up);
	assert(V == lookAtTest);
	// if assert works then evreything went well

	m_worldTransform = glm::inverse(V);
	m_projectionViewTransform =  V * m_projectionTransform;

}

// Sets a given position to whatever applied to
void Camera::setPosition(glm::vec3 position)
{
	auto positionMatrix = glm::mat4
	{
		glm::vec4(1, 0, 0 ,0),
		glm::vec4(0, 1, 0, 0),
		glm::vec4(0, 0, 1, 0),
		glm::vec4(position.x, position.y, position.z, 1)
	};

	m_viewTransform = positionMatrix;
	m_worldTransform = glm::inverse(m_viewTransform);
}


void Camera::run()
{
	
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
	return m_projectionViewTransform;
}


