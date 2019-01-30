#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder//Rand.h"

#include "Func.h"
#include "StateMachine.h"

#include "LargeEnemy.h"

class BaseEnemy {
	ci::Vec3f position;
	ci::Vec3f angle;
	ci::Vec3f direction;
	float scale;
	ci::Color color;

	float viewAngleRange;
	float viewDistanceRange;

	std::shared_ptr<StateMachine<BaseEnemy>> pStateMachine;

public:

	BaseEnemy(float s);
	~BaseEnemy() {};

	void Update();
	void Draw();
};