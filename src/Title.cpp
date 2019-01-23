#include "Title.h"

using namespace ci;
using namespace ci::app;

Title::Title() {
	uiCamera = CameraOrtho(0.f, getWindowWidth(), getWindowHeight(), 0.f, -1.f, 1.f);
	uiCamera.setEyePoint(Vec3f(0.f, 0.f, 0.f));
	uiCamera.setCenterOfInterestPoint(Vec3f(0.f, 0.f, -1.f));

	//customFont = Font(loadAsset("aaa.ttf"), 48.f);
}

Title::~Title() {

}

void Title::Enter(SceneManager*) {

}

void Title::ExecuteUpdate(SceneManager*) {

}

void Title::Exit(SceneManager*) {

}

void Title::Draw(SceneManager* manager) {
	gl::color(Color(1.f, 0.f, 0.f));
	gl::setMatrices(uiCamera);

	if (joy->IsPressedButton(joy->CIRCLE) || mouseEvent.isLeft()) {
		manager->ChangeScene(new GameScene());
	}
}