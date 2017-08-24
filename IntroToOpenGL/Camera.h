#pragma once
#include <glm\glm\glm.hpp>
#include <assert.h>
#include<stdio.h>

// Something in here is potentially preventing anything in the project from running properly

class Camera
{
public:
	Camera();
	virtual ~Camera();

	void update(float deltaTime);
	void setPerspective(float fieldOfView, float aspectRatio, float near, float far);
	void setLookAt(glm::vec3 from, glm::vec3 to, glm::vec3 up);
	void setPosition(glm::vec3 position);
	
	glm::mat4 getWorldTransform();
	glm::mat4 getView();
	glm::mat4 getProjection();
	glm::mat4 getProjectionView();

private:
	glm::mat4 m_worldTransform;
	glm::mat4 m_viewTransform;
	glm::mat4 m_projectionTransform;
	glm::mat4 m_projectionViewTransform;

	void updateProjectionViewTransform();
};

