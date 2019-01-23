#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder\Camera.h"
#include "cinder\gl\Light.h"
#include "cinder\gl\Material.h"

#include "State.h"
#include "SceneManager.h"
#include "Title.h"

#include "GameField.h"
#include "GameCamera.h"
#include "Player.h"
#include "UI.h"

#include "SpawnManager.h"

#include "Func.h"

#include <list>

class GameScene : public State<SceneManager> {
	std::unique_ptr<GameField> field;
	std::unique_ptr<GameCamera> camera;
	std::unique_ptr<Player> player;
	std::unique_ptr<UI> ui;

public:
	GameScene();
	~GameScene();

	void ExecuteEnter(SceneManager*);
	void ExecuteUpdate(SceneManager*);
	void ExecuteExit(SceneManager*);
	void ExecuteDraw(SceneManager*);

};