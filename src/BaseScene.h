#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "SceneManager.h"

// zŠÂQÆ‰ñ”ğ—p
class SceneManager;

class BaseScene {
public:
	virtual void Enter(SceneManager*) = 0;
	virtual void ExecuteUpdate(SceneManager*) = 0;
	virtual void Exit(SceneManager*) = 0;
	virtual void Draw(SceneManager*) = 0;
};