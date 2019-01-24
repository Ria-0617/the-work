#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include <list>
#include "Func.h"
#include "EnemyManager.h"

class LargeEnemy : public State<EnemyManager> {
	ci::Vec3f position;
	ci::Vec3f angle;
	ci::Vec3f direction;
	float scale;
	ci::Color color;

	float viewAngleRange;
	float viewDistanceRange;

	bool OutOfViewRange(ci::Vec3f&, float, float);
public:
	LargeEnemy(EnemyManager*);
	~LargeEnemy() {};

	ci::Vec3f GetPos() { return position; }
	float GetScale() { return scale; }

	void ExecuteEnter(EnemyManager*);
	void ExecuteUpdate(EnemyManager*);
	void ExecuteDraw(EnemyManager*);
	void ExecuteExit(EnemyManager*);
};