#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

class BaseGameEntity {
private:
	ci::Vec3f position;
	ci::Vec3f angle;
	ci::Vec3f direction;
	float scale;
	ci::Color color;

	float viewAngleRange;
	float viewDistanceRange;
public:
	BaseGameEntity() {};
	~BaseGameEntity() {};

	virtual void Update() = 0;
	virtual void Draw() = 0;
};