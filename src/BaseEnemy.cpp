#include "BaseEnemy.h"

using namespace ci;
using namespace ci::app;
using namespace std;

BaseEnemy::BaseEnemy(float s) :position(Vec3f(randFloat(-30.f, 30.f), randFloat(-30.f, 30.f), randFloat(-30.f, 30.f))),
angle(MyFanc::ToRadians(Vec3f(randFloat(0.f, 360.f), randFloat(0.f, 360.f), randFloat(0.f, 360.f)))),
direction(Matrix44f::createRotation(angle) * Vec3f(1.f, 0.f, 0.f)),
scale(randFloat(s - 5.f, s + 5.0f)), color(Color(1.f, 0.f, 0.f)), viewAngleRange(toRadians(45.f)), viewDistanceRange(15.f) {
	pStateMachine = make_shared<StateMachine<BaseEnemy>>(this);
	pStateMachine->SetCurrentState(make_shared<LargeEnemy>(this));
}

void BaseEnemy::Update() {
	pStateMachine->Update();
}

void BaseEnemy::Draw() {
	pStateMachine->Draw();
}