#include "UI.h"

using namespace ci;
using namespace ci::app;
using namespace std;

UI::UI() {
	score = 0;
	timer = 3600;

	uiCamera = CameraOrtho(0.f, getWindowWidth(), getWindowHeight(), 0.f, -1.f, 1.f);
	uiCamera.setEyePoint(Vec3f(0.f, 0.f, 0.f));
	uiCamera.setCenterOfInterestPoint(Vec3f(0.f, 0.f, -1.f));

	loadFont = loadAsset("AndrewsQueen.ttf");
	scoreFont = Font(loadFont, 48.f);
	timeFont = Font(loadFont, 48.f);

	expFont = Font(loadFont, 24.f);
	expGauge = Rectf(0.f, getWindowHeight() - 30.f, 0.f, getWindowHeight());
}

UI::~UI() {

}

gl::Texture UI::TextSetUp(string txt, TextBox::Alignment centerPos, Font font, Vec2i size) {
	TextBox tBox = TextBox().alignment(centerPos).font(font).size(Vec2i(size)).text(txt).
		color(Color(1.f, 1.f, 1.f)).backgroundColor(ColorA(0.f, 0.f, 0.f, 0.f));

	return gl::Texture(tBox.render());
}

void UI::Update(float exp) {
	scoreText = "SCORE : " + std::to_string(score);
	scoreTexture = TextSetUp(scoreText, TextBox::LEFT, scoreFont, /*size = */Vec2i(getWindowWidth(), 100));

	if (timer > 0) timer -= 1;

	timerText = std::to_string(timer / 60);
	timerTexture = TextSetUp(timerText, TextBox::CENTER, timeFont, /*size = */Vec2i(getWindowWidth(), 100));

	expText = "EXP";
	expTexture = TextSetUp(expText, TextBox::LEFT, expFont, /*size = */Vec2i(200, 100));
	expGauge = Rectf(0.f, getWindowHeight() - 30.f, exp * getWindowWidth(), getWindowHeight());

}

void UI::Draw() {
	gl::enableAlphaBlending();

	gl::color(Color(0.f, 0.f, 0.f));
	gl::setMatrices(uiCamera);

	gl::draw(scoreTexture, /*pos = */Vec2i(0, 0));

	gl::draw(timerTexture, /*pos = */Vec2i(0, 0));

	gl::draw(expTexture, /*pos = */Vec2i(0, getWindowHeight() - 60));
	gl::color(Color(1.f, 1.f, 0.f));
	gl::drawSolidRect(expGauge);

	gl::disableAlphaBlending();
}