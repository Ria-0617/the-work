#include "Player.h"

using namespace ci;
using namespace ci::app;

Player::Player() {
	position = Vec3f(0.f, 0.f, 0.f);
	direction = Quatf();
	scale = 1.f;

	speed = 0.3f;

	experience = 0.f;
	maxExperience = 3.f;

	limitPositoin = 50.f;
};

Player::~Player() {

}

void Player::Update(const Quatf& q) {
	direction = q;

	// à⁄ìÆ
	if (joy->IsMove(joy->Input().dwXpos, joy->Input().dwYpos)) {
		position += direction * Vec3f(joy->StickValue(joy->Input().dwXpos), 0.f, joy->StickValue(joy->Input().dwYpos))  * speed;

		MyFanc::Clamp(position, -limitPositoin, limitPositoin);
	}


	if (experience >= maxExperience) {
		experience = 0.f;
		scale += 1.f;
		//scale = MyFanc::EaseInOutBack()
		maxExperience = scale * 5;
	}

	
}

void Player::Draw() {
	// ÉvÉåÉCÉÑÅ[
	gl::pushModelView();
	gl::translate(position);
	gl::rotate(direction);
	gl::color(Color(0.f, 0.f, 0.f));
	gl::drawCube(Vec3f(0.f, 0.f, 0.f), Vec3f(scale, scale, scale));
	gl::popModelView();
}