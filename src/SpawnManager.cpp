#include "SpawnManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

SpawnManager* SpawnManager::Instance() {
	static SpawnManager instance;

	return &instance;
}

void SpawnManager::EnemySpowner(float s) {
	if (enemys.size() > enemyMaxNum) return;
	auto p = make_shared<BaseEnemy>(1.f);
	enemys.push_back(p);
}

void SpawnManager::EnemyUpdate() {
	for (auto itr : enemys)
		itr->Update();
}

void SpawnManager::EnemyDraw() {
	for (auto itr : enemys)
		itr->Draw();
}