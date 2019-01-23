#include "EnemyManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

EnemyManager::EnemyManager() {
	currentState = new LargeEnemy(1.f);
}

void EnemyManager::Update() {
	currentState->ExecuteUpdate(this);
}

void EnemyManager::Draw() {
	currentState->ExecuteDraw(this);
}

void EnemyManager::ChangeState(State<EnemyManager>* newState) {
	assert(currentState && newState);

	currentState->ExecuteExit(this);
	currentState = newState;
	//currentState.reset(newState);
	currentState->ExecuteEnter(this);
}