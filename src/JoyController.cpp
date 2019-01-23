#include "JoyController.h"

using namespace ci;
using namespace ci::app;

JoyController::JoyController() : minValue(0.1f) {
	joyController.dwSize = sizeof(JOYINFOEX);
	joyController.dwFlags = JOY_RETURNALL;

	for (unsigned int i = 0; i < joyGetNumDevs(); i++) {//サポートされているジョイスティックの数を返す
		if (JOYERR_NOERROR == joyGetPosEx(i, &joyController))
			printf("ジョイスティック No.%d　接続されています\n", i);
	}
}

// 正規化
float JoyController::StickValue(unsigned long value) {
	return 1.f - 2.f * (value / 65535.f);
}

bool JoyController::IsMove(float valueX, float valueY) {
	//0番のジョイスティックの情報を見る
	if (JOYERR_NOERROR != joyGetPosEx(JOYSTICKID1, &joyController)) return false;

	if (StickValue(valueX) > minValue || StickValue(valueX) < -minValue ||
		StickValue(valueY) > minValue || StickValue(valueY) < -minValue) {
		return true;
	}
	else
		return false;
}

bool JoyController::IsPressedButton(BUTTON buttonNum) {
	if (JOYERR_NOERROR != joyGetPosEx(JOYSTICKID1, &joyController)) return false;

	return joyController.dwButtons == buttonNum ? true : false;
}

JoyController* JoyController::Instance() {
	static JoyController instance;
	return &instance;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// デバッグ用
// ボタン確認
void JoyController::Debug() {
	if (JOYERR_NOERROR == joyGetPosEx(JOYSTICKID1, &joyController)) { //0番のジョイスティックの情報を見る
		console() << "L_posX = " << StickValue(joyController.dwXpos) << std::endl;
		console() << "L_posY = " << StickValue(joyController.dwYpos) << std::endl;
		console() << "R_posX = " << StickValue(joyController.dwZpos) << std::endl;     // 右スティック横
		console() << "R_posY = " << StickValue(joyController.dwRpos) << std::endl;    // 右スティック縦
		//console() << "L2 = " << joyController.dwVpos << std::endl;    // L2
		//console() << "R2 = " << joyController.dwUpos << std::endl;    // R2
		//console() << "Buttons = " << joyController.dwButtons << std::endl;
		console() << ' ' << std::endl;
	}
	else {
		console() << "エラー" << std::endl;
	}
}