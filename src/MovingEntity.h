#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "Func.h"
#include "BaseGameEntitiy.h"

class MovingEntity :public BaseGameEntity{

protected:
	ci::Vec3f m_vVelocity;
	ci::Vec3f m_vAngle;
	ci::Quatf m_qDirection;
	float m_fMass;
	ci::Vec3f m_vUp;

	float m_fViewAngleRange;
	float m_fViewDistanceRange;

	float m_fMaxSpeed;
	float m_fMaxTurnRate;

	ci::Color m_color;
public:
	MovingEntity(
		ci::Vec3f position,
		ci::Vec3f velocity,
		ci::Vec3f angle,
		float mass,
		ci::Vec3f scale,
		float maxSpeed,
		float turnRate) :BaseGameEntity(position),
		m_vVelocity(velocity),
		m_vAngle(angle),
		m_qDirection(ci::Quatf()),
		m_fMass(mass),
		m_vUp(ci::Vec3f(0.f,1.f,0.f)),
		m_fMaxSpeed(maxSpeed),
		m_fMaxTurnRate(turnRate) {
		m_vScale = scale;
	}

	virtual ~MovingEntity() {};

	// accesser
	ci::Vec3f GetVelocity() { return m_vVelocity; }

	ci::Vec3f GetAngle() { return m_vAngle; }

	ci::Quatf GetDirection() { return m_qDirection; }

	float GetMaxSpeed() { return m_fMaxSpeed; }
};
