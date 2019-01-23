#pragma once

#pragma comment(lib,"winmm.lib")

#include "cinder/app/AppNative.h"

#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#define joy JoyController::Instance()

class JoyController {
private:
	const float minValue;

	JOYINFOEX joyController;

	JoyController();
	~JoyController() {};
	
public:
	
	const enum BUTTON {
		RECT = 1,
		CROSS = 2,
		CIRCLE = 4,
		TRIANGLE = 8,
		L1 = 16,
		R1 = 32
	};

	JOYINFOEX Input() { return joyController; }

	float StickValue(unsigned long value);
	bool IsMove(float valueX, float valueY);
	bool IsPressedButton(BUTTON buttonNum);

	static JoyController* Instance();

	void Debug();
};
