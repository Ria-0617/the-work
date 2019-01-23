#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include <list>
#include "Func.h"
#include "BaseEnemy.h"

class LargeEnemy :BaseEnemy {
public:
	LargeEnemy(float s);
	~LargeEnemy();

	void Move();

	void Draw() override;
};