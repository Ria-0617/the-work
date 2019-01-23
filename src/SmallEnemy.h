#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include <list>
#include "Func.h"
#include "BaseEnemy.h"

class SmallEnemy : public BaseEnemy {

	ci::Vec3f Separate(std::list<SmallEnemy>&);
	ci::Vec3f Alignment(std::list<SmallEnemy>&);
	ci::Vec3f Cohesion(std::list<SmallEnemy>&);

public:
	SmallEnemy(float s);
	~SmallEnemy();

	void Move();
	void Draw() override;
};


