#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "SceneManager.h"
#include "Title.h"
#include "GameScene.h"

class TemplateProjectApp : public ci::app::AppNative{
	std::unique_ptr<SceneManager> sceneManager;

public:
	void prepareSettings(Settings* settings);
	void setup();
	void shutdown();

	void update();
	void draw();
};
