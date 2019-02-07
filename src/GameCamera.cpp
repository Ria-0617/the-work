#include "GameCamera.h"

using namespace ci;
using namespace ci::app;

GameCamera::GameCamera() {
	offset = Vec3f(0.f, 2.f, -8.f);
	fov = 35.f;
	rotationSpeed = 0.05f;
	m_vUp = Vec3f(0.f, 1.f, 0.f);

	quat = Quatf();

	camera = CameraPersp(getWindowWidth(), getWindowHeight(), fov, /*nearClip = */0.1f, /*farClip = */1000.f);
	camera.lookAt(offset, Vec3f(0.f, 0.f, 0.f), m_vUp);
};

GameCamera::~GameCamera() {

}

void GameCamera::Update(Vec3f targetPos, float scale) {

	if (joy->IsMove(joy->Input().dwRpos, joy->Input().dwZpos)) {
		Vec3f c = (targetPos - position).normalized().cross(m_vUp.normalized());
		quat *= Quatf(m_vUp, joy->StickValue(joy->Input().dwZpos)*rotationSpeed) * Quatf(c, joy->StickValue(joy->Input().dwRpos)*rotationSpeed);
		m_vUp = Vec3f(0.f, 1.f, 0.f) * quat;
	}

	// プレイヤーのスケールに比例して遠くなる
	offset.y = scale + 2 / tan(toRadians(fov) / 2);
	offset.z = -(scale + 8) / tan(toRadians(fov) / 2);

	position = targetPos + quat * offset;
	Vec3f target = targetPos + quat * Vec3f(0.f, 1.f, 0.f);

	camera.lookAt(position, target, m_vUp);
}

void GameCamera::Draw() {
	gl::setMatrices(camera);
}