#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

#include "State.h"

#include "BaseGameEntitiy.h"
#include "BaseEnemy.h"

#define Spowner SpawnManager::Instance()

class SpawnManager {

	SpawnManager() = default;
	~SpawnManager() = default;

	std::list<BaseEnemy*> enemys;
	const int enemyMaxNum = 100;

public:
	SpawnManager(const SpawnManager&) = delete;
	SpawnManager& operator=(const SpawnManager&) = delete;
	SpawnManager(SpawnManager&&) = delete;
	SpawnManager& operator=(SpawnManager&&) = delete;

	static SpawnManager* Instance();

	std::list<BaseEnemy*> GetEnemys() { return enemys; }

	void EnemySpowner();

	void EnemyUpdate();
	void EnemyDraw();
};