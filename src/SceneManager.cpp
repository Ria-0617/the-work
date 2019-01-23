#include "SceneManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

SceneManager::SceneManager() {
	//currentScene = std::make_unique<Title>();
	currentScene = new Title();
}

void SceneManager::Update() {
	currentScene->ExecuteUpdate(this);
}

void SceneManager::Draw() {
	currentScene->ExecuteDraw(this);
}

void SceneManager::ChangeScene(State<SceneManager>* newScene) {
	assert(currentScene && newScene);

	currentScene->ExecuteExit(this);
	//currentScene.reset(newScene);
	currentScene = newScene;
	currentScene->ExecuteEnter(this);
}