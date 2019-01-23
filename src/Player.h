#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderMath.h"

#include "JoyController.h"
#include "Func.h"

#include <list>

class Player {
private:
	ci::Vec3f position;
	ci::Quatf direction;
	float speed;
	float scale;

	float experience;
	float maxExperience;

	float limitPositoin;

public:
	Player();
	~Player();

	void Update(const ci::Quatf& q);
	void Draw();

	ci::Vec3f GetPosition() { return position; }
	float GetScale() { return scale; }

	void PulsExp(float value) { experience += value; }
	float GetExp() { return experience; }

	float NomalizedExp(){ return experience / maxExperience; }
};
