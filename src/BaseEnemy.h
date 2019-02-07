#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "Func.h"

#include "MovingEntity.h"

#include "SteeringBehaviors.h"

class SteeringBehaviors;

class BaseEnemy : public MovingEntity {
	
	SteeringBehaviors* m_pSteering;

	ci::Vec3f m_vFront;

public:

	BaseEnemy(ci::Vec3f position,
		ci::Vec3f velocity,
		ci::Vec3f angle,
		float mass,
		float scale,
		float maxSpeed,
		float turnRate);
	~BaseEnemy();

	void Update();
	void Draw();
};