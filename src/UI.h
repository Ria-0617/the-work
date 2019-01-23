#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "cinder/Camera.h"
#include "cinder/gl/Texture.h"
#include "cinder/Text.h"

class UI {
	ci::CameraOrtho uiCamera;

	ci::DataSourceRef loadFont;

	int score;
	ci::Font scoreFont;
	std::string scoreText;
	ci::gl::Texture scoreTexture;

	int timer;
	ci::Font timeFont;
	std::string timerText;
	ci::gl::Texture timerTexture;

	ci::Font expFont;
	std::string expText;
	ci::gl::Texture expTexture;
	ci::Rectf expGauge;
public:
	UI();
	~UI();

	void PlusScore(int value) { score += value; }
	void PulsTime(int value) { timer += value; }
	int GetTimer()const { return timer; }

	ci::gl::Texture TextSetUp(std::string, ci::TextBox::Alignment, ci::Font font, ci::Vec2i);
	void Update(float exp);
	void Draw();
};