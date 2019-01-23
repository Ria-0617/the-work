#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "State.h"
#include "Title.h"

class SceneManager {
	//std::unique_ptr<State<SceneManager>> currentScene;
	State<SceneManager>* currentScene;
public:

	SceneManager();
	~SceneManager() { delete currentScene; }
	
	void Update();
	void Draw();
	void ChangeScene(State<SceneManager>* newScene);
};