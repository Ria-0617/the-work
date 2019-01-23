#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "State.h"
#include "LargeEnemy.h"

class EnemyManager {
	//std::unique_ptr<State<EnemyManager>> currentState;
	State<EnemyManager>* currentState;
public:

	EnemyManager();
	~EnemyManager() { delete currentState; }

	void Update();
	void Draw();
	void ChangeState(State<EnemyManager>* newState);
};