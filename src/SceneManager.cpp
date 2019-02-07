#include "SceneManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

SceneManager::SceneManager() {
	m_pStateMachine = new StateMachine<SceneManager>(this);
	m_pStateMachine->SetCurrentState(new Title());
}

void SceneManager::Update() {
	m_pStateMachine->Update();
}

void SceneManager::Draw() {
	m_pStateMachine->Draw();
}