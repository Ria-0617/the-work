#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "StateMachine.h"
#include "Title.h"

class SceneManager {
	StateMachine<SceneManager>* m_pStateMachine;

public:

	SceneManager();
	~SceneManager() {}
	
	void Update();
	void Draw();

	StateMachine<SceneManager>* GetFSM() const{ return m_pStateMachine; }
};