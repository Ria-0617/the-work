#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "JoyController.h"

class Init {
private:
	JoyController* joyController;


public:
	Init();
	~Init();

	JoyController* GetJoy() {
		return joyController;
	}
};