#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "BaseGameEntitiy.h"
#include "BaseEnemy.h"

class BaseEnemy;

class SteeringBehaviors {
	BaseEnemy* m_pBaseEnemy;

	//bool ViewRange(BaseEnemy* neighbor);

public:
	SteeringBehaviors(BaseEnemy*);
	~SteeringBehaviors() { delete m_pBaseEnemy; }

	ci::Vec3f Calculate();

	ci::Vec3f Seek(ci::Vec3f targetPos);
	ci::Vec3f Separation(const std::vector<BaseEnemy*>& neighbors);
	ci::Vec3f Alignment(const std::vector<BaseEnemy*>& neighbors);
	ci::Vec3f Cohesion(const std::vector<BaseEnemy*>& neighbors);
};
