#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder//Rand.h"

#include "Func.h"
#include "StateMachine.h"

#include "LargeEnemy.h"

class EnemyManager {
	ci::Vec3f position;
	ci::Vec3f angle;
	ci::Vec3f direction;
	float scale;
	ci::Color color;

	float viewAngleRange;
	float viewDistanceRange;

	std::shared_ptr<StateMachine<EnemyManager>> pStateMachine;

	//std::list<std::shared_ptr<StateMachine<EnemyManager>>> pStateMachine;
public:

	EnemyManager(float s);
	~EnemyManager() {};

	//std::list<std::shared_ptr<StateMachine<EnemyManager>>> GetCurrentEnemys() { return pStateMachine; }

	void Update();
	void Draw();
	//void ChangeState(StateMachine<EnemyManager>* newState);
};