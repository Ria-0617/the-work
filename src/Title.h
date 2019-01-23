#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Camera.h"
#include "cinder/Text.h"

#include "State.h"
#include "SceneManager.h"
#include "GameScene.h"

class Title : public State<SceneManager> {
	ci::CameraOrtho uiCamera;

	//ci::Font customFont;

	// デバッグ用
	ci::app::MouseEvent mouseEvent;
	
public:
	Title();
	~Title();
	
	void ExecuteEnter(SceneManager*);
	void ExecuteUpdate(SceneManager*);
	void ExecuteExit(SceneManager*);
	void ExecuteDraw(SceneManager*);

};