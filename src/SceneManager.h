#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "BaseScene.h"
#include "Title.h"

class SceneManager {
	std::unique_ptr<BaseScene> currentScene;
public:

	SceneManager();
	~SceneManager() {};
	
	void Update();
	void Draw();
	void ChangeScene(BaseScene* newScene);
};