#pragma once

#include "bootApplication.h"
#include <mat4x4.hpp>

class DirectLightingApp
{
public:
	DirectLightingApp();
	virtual ~DirectLightingApp();

	virtual void startup() /*override*/;
	virtual void shutdown() /*override*/;
	virtual void update(float) /*override*/;
	virtual void draw() /*override*/;

protected:
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;
};

