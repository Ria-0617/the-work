#include "SpawnManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

SpawnManager* SpawnManager::Instance() {
	static SpawnManager instance;

	return &instance;
}

void SpawnManager::EnemySpowner() {
	if (enemys.size() > enemyMaxNum) return;
	//enemys.push_back(new BaseEnemy());
}

void SpawnManager::EnemyUpdate() {
	for (auto itr : enemys)
		itr->Update();
}

void SpawnManager::EnemyDraw() {
	for (auto itr : enemys)
		itr->Draw();
}