#include "Player.h"

using namespace ci;
using namespace ci::app;

Player::Player() {
	m_vPosition.zero();
	m_vVelocity.zero();
	m_qDirection = Quatf();
	m_fScale = 1.f;

	m_fSpeed = 0.3f;

	experience = 0.f;
	maxExperience = 3.f;

	m_fLimitPositoin = 50.f;
};

Player::~Player() {

}

void Player::Update(const Quatf& q) {
	m_qDirection = q;

	// à⁄ìÆ
	if (joy->IsMove(joy->Input().dwXpos, joy->Input().dwYpos)) {
		m_vVelocity = Vec3f(joy->StickValue(joy->Input().dwXpos), 0.f, joy->StickValue(joy->Input().dwYpos));
		m_vPosition += m_qDirection *  m_vVelocity * m_fSpeed;

		MyFanc::Clamp(m_vPosition, -m_fLimitPositoin, m_fLimitPositoin);
	}


	if (experience >= maxExperience) {
		experience = 0.f;
		m_fScale += 1.f;
		maxExperience = m_fScale * 5;
	}

	
}

void Player::Draw() {
	// ÉvÉåÉCÉÑÅ[
	gl::pushModelView();
	gl::translate(m_vPosition);
	gl::rotate(m_qDirection);
	gl::color(Color(0.f, 0.f, 0.f));
	gl::drawCube(Vec3f(0.f, 0.f, 0.f), Vec3f(m_fScale, m_fScale, m_fScale));
	gl::popModelView();
}