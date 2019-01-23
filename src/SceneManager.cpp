#include "SceneManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

SceneManager::SceneManager() {
	currentScene = std::make_unique<Title>();
}

void SceneManager::Update() {
	currentScene->ExecuteUpdate(this);
}

void SceneManager::Draw() {
	currentScene->Draw(this);
}

void SceneManager::ChangeScene(BaseScene* newScene) {
	assert(currentScene && newScene);

	currentScene->Exit(this);
	currentScene.reset(newScene);
	currentScene->Enter(this);
}