#include "BaseEnemy.h"

using namespace ci;
using namespace ci::app;
using namespace std;

BaseEnemy::BaseEnemy(ci::Vec3f position,
	ci::Vec3f velocity,
	ci::Vec3f angle,
	float mass,
	float scale,
	float maxSpeed,
	float turnRate) :
	MovingEntity(position,
		velocity,
		angle,
		mass,
		Vec3f(scale, scale, scale),
		maxSpeed,
		turnRate)
{
	m_pSteering = new SteeringBehaviors(this);

	m_vFront = Vec3f(0.f, 0.f, 1.f);
}

BaseEnemy::~BaseEnemy() {
	delete m_pSteering;
}

void BaseEnemy::Update() {
	Vec3f SteeringForce = m_pSteering->Calculate();

	Vec3f acceleration = SteeringForce / m_fMass;

	m_vVelocity += acceleration;
	MyFanc::Clamp(m_vVelocity, 0.f, m_fMaxSpeed);

	m_vPosition += m_vVelocity;

	if (m_vVelocity.lengthSquared() > 0.0001f) {
		m_qDirection *= Quatf(m_vFront, m_vVelocity.normalized());
		m_vFront = m_vVelocity.normalized();
	}
}

void BaseEnemy::Draw() {
	gl::pushModelView();
	gl::translate(m_vPosition);
	gl::rotate(m_qDirection);
	gl::color(m_color);
	gl::drawCube(Vec3f(0.f, 0.f, 0.f), m_vScale);
	gl::popModelView();
}