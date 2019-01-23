#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

class SceneManager;
class EnemyManager;

template<class T>
class State {
public:
	virtual void ExecuteEnter(T*) = 0;
	virtual void ExecuteUpdate(T*) = 0;
	virtual void ExecuteExit(T*) = 0;
	virtual void ExecuteDraw(T*) = 0;

	virtual ~State() {};
};