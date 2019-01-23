#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "SpawnManager.h"

class BaseEnemy {
protected:
	ci::Vec3f position;
	ci::Vec3f angle;
	ci::Vec3f direction;
	float scale;
	ci::Color color;

	float viewAngleRange;
	float viewDistanceRange;

	bool OutOfViewRange(ci::Vec3f&, float, float);

public:
	//virtual void Move(std::list<std::shared_ptr<SmallEnemy>>&) = 0;


	virtual void Draw() = 0;

	ci::Vec3f GetPos() { return position; }
	float GetScale() { return scale; }
};
