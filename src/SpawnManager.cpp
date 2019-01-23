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
	auto p = make_shared<SmallEnemy>(s);
	enemys.push_back(p);
}

//void SpawnManager::EnemyDraw() {
//	for (const auto& itr : enemys) { 
//		itr->ExecuteDraw();
//	}
//}