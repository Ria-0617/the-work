#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Camera.h"
#include "cinder/Text.h"

#include "SceneManager.h"
#include "BaseScene.h"
#include "GameScene.h"

class Title : public BaseScene {
	ci::CameraOrtho uiCamera;

	//ci::Font customFont;

	// �f�o�b�O�p
	ci::app::MouseEvent mouseEvent;
	
public:
	Title();
	~Title();
	
	void Enter(SceneManager*);
	void ExecuteUpdate(SceneManager*);
	void Exit(SceneManager*);
	void Draw(SceneManager*);

};