#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder\Camera.h"
#include "Func.h"
#include "JoyController.h"

class GameCamera {
private:
	ci::CameraPersp camera;

	float fov;

	ci::Vec3f offset;
	ci::Vec3f position;
	float rotationSpeed;

	ci::Vec3f upVector;

	ci::Quatf quat;

public:
	GameCamera();
	~GameCamera();

	void Update(ci::Vec3f targetPos, float scale);
	void Draw();

	ci::Vec3f GetPosition() { return position; }
	ci::Quatf GetQuaternion() { return quat; }

};