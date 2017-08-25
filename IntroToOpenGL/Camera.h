#pragma once
#include <glm\glm\glm.hpp>
#include <assert.h>
#include<stdio.h>



class Camera
{
public:
	Camera();
	virtual ~Camera();

	void update(float deltaTime);
	void setPerspective(float fieldOfView, float aspectRatio, float near, float far);
	void setOrthographic(float fieldOfView, float asepectRatio, float near, float far);
	void setLookAt(glm::vec3 eye, glm::vec3 center, glm::vec3 up);
	void setPosition(glm::vec3 position);
	void run();
	
	glm::mat4 getWorld();
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

