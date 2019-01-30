#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include <list>
#include "Func.h"
#include "BaseEnemy.h"

class LargeEnemy : public State<BaseEnemy> {
	ci::Vec3f position;
	ci::Vec3f angle;
	ci::Vec3f direction;
	float scale;
	ci::Color color;

	float viewAngleRange;
	float viewDistanceRange;

	bool OutOfViewRange(ci::Vec3f&, float, float);
public:
	LargeEnemy(BaseEnemy*);
	~LargeEnemy() {};

	ci::Vec3f GetPos() { return position; }
	float GetScale() { return scale; }

	void ExecuteEnter(BaseEnemy*);
	void ExecuteUpdate(BaseEnemy*);
	void ExecuteDraw(BaseEnemy*);
	void ExecuteExit(BaseEnemy*);
};