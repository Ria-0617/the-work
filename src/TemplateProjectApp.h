#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "SceneManager.h"

class TemplateProjectApp : public ci::app::AppNative{
	SceneManager* sceneManager;

public:
	void prepareSettings(Settings* settings);
	void setup();
	void shutdown();

	void update();
	void draw();
};
