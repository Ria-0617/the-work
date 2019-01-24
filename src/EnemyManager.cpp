#include "EnemyManager.h"

using namespace ci;
using namespace ci::app;
using namespace std;

EnemyManager::EnemyManager(float s) :position(Vec3f(randFloat(-30.f, 30.f), randFloat(-30.f, 30.f), randFloat(-30.f, 30.f))),
angle(MyFanc::ToRadians(Vec3f(randFloat(0.f, 360.f), randFloat(0.f, 360.f), randFloat(0.f, 360.f)))),
direction(Matrix44f::createRotation(angle) * Vec3f(1.f, 0.f, 0.f)),
scale(randFloat(s - 5.f, s + 5.0f)), color(Color(1.f, 0.f, 0.f)), viewAngleRange(toRadians(45.f)), viewDistanceRange(15.f) {
	pStateMachine = make_shared<StateMachine<EnemyManager>>(this);
	pStateMachine->SetCurrentState(make_shared<LargeEnemy>(this));
}

void EnemyManager::Update() {
	pStateMachine->Update();
}

void EnemyManager::Draw() {
	pStateMachine->Draw();
}

//void EnemyManager::Update() {
//	for (auto ptr : pStateMachine)
//		ptr->ExecuteUpdate(this);
//}
//
//void EnemyManager::Draw() {
//	for (auto ptr : pStateMachine)
//		ptr->ExecuteUpdate(this);
//}
//
//void EnemyManager::ChangeState(StateMachine<EnemyManager>* newState) {
//	//assert(currentEnemy && newState);
//
//	for (auto ptr : pStateMachine) {
//		ptr->ExecuteExit(this);
//		ptr.reset(newState);
//		ptr->ExecuteEnter(this);
//	}
//}