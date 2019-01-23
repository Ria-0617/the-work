#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder\Camera.h"
#include "cinder\gl\Light.h"
#include "cinder\gl\Material.h"

#include "SceneManager.h"
#include "BaseScene.h"
#include "Title.h"

#include "GameField.h"
#include "GameCamera.h"
#include "Player.h"
#include "UI.h"

#include "SpawnManager.h"

#include "Func.h"

#include <list>

class GameScene : public BaseScene {
	std::unique_ptr<GameField> field;
	std::unique_ptr<GameCamera> camera;
	std::unique_ptr<Player> player;
	std::unique_ptr<UI> ui;

public:
	GameScene();
	~GameScene();

	void Enter(SceneManager*);
	void ExecuteUpdate(SceneManager*);
	void Exit(SceneManager*);
	void Draw(SceneManager*);

};