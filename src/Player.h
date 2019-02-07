#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/CinderMath.h"

#include "JoyController.h"
#include "Func.h"

#include <list>

class Player {
private:
	ci::Vec3f m_vPosition;
	ci::Vec3f m_vVelocity;
	ci::Quatf m_qDirection;
	float m_fSpeed;
	float m_fScale;

	float experience;
	float maxExperience;

	float m_fLimitPositoin;

public:
	Player();
	~Player();

	void Update(const ci::Quatf& q);
	void Draw();

	ci::Vec3f GetPosition() { return m_vPosition; }
	float GetScale() { return m_fScale; }

	void PulsExp(float value) { experience += value; }
	float GetExp() { return experience; }

	float NomalizedExp(){ return experience / maxExperience; }
};
