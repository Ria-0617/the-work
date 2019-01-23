#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "BaseEnemy.h"
#include "LargeEnemy.h"
#include "SmallEnemy.h"

#define Spowner SpawnManager::Instance()

class SpawnManager {

	SpawnManager() {};
	~SpawnManager() {};

	SpawnManager(const SpawnManager&);
	SpawnManager& operator=(const SpawnManager&) {};

	std::list<std::shared_ptr<SmallEnemy>> enemys;
	const int enemyMaxNum = 100;

public:
	static SpawnManager* Instance();

	std::list<std::shared_ptr<SmallEnemy>> getEnemys() { return enemys; }

	void EnemySpowner(float s);
	void EnemyDraw();
};