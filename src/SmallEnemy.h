#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include <list>
#include "Func.h"
#include "SpawnManager.h"
#include "EnemyManager.h"

class SmallEnemy : public State<EnemyManager> {

	ci::Vec3f position;
	ci::Vec3f angle;
	ci::Vec3f direction;
	float scale;
	ci::Color color;

	float viewAngleRange;
	float viewDistanceRange;

	bool OutOfViewRange(ci::Vec3f&, float, float);

	ci::Vec3f Separate();
	ci::Vec3f Alignment();
	ci::Vec3f Cohesion();

public:
	SmallEnemy();
	~SmallEnemy() {};

	void ExecuteEnter(EnemyManager*);
	void ExecuteUpdate(EnemyManager*);
	void ExecuteDraw(EnemyManager*);
	void ExecuteExit(EnemyManager*);
};


