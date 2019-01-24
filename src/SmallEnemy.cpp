#include "SmallEnemy.h"

using namespace ci;
using namespace ci::app;
using namespace std;

SmallEnemy::SmallEnemy() {
	
}

bool SmallEnemy::OutOfViewRange(Vec3f& pos, float viewAngleRange, float viewDistanceRange) {
	Vec3f neighbors = (pos - position).normalized();

	if (direction.dot(neighbors) < viewAngleRange || this->position.distance(pos) > viewDistanceRange) {
		return true;
	}
	return false;
}

Vec3f SmallEnemy::Separate() {
	Vec3f relativePosition = Vec3f(0, 0, 0);
	Vec3f toAgent;

	//for (auto itr = Spowner->GetEnemyState()->GetCurrentEnemys().begin(); itr != Spowner->GetEnemyState()->GetCurrentEnemys().end(); ++itr) {
	for (auto itr : Spowner->GetEnemys())
	{
		if (position.distance(itr->position) > viewDistanceRange) continue;

	toAgent = (position - itr->position).safeNormalized();
	relativePosition += toAgent;
}

return relativePosition;
}

Vec3f SmallEnemy::Alignment() {
	int neiborCount = 0;
	Vec3f ralativeAngle = Vec3f(0, 0, 0);

	for (auto itr = smallEnemys.begin(); itr != smallEnemys.end(); ++itr) {
		if (OutOfViewRange(itr->position, viewAngleRange, viewDistanceRange))continue;

		ralativeAngle += itr->angle;

		++neiborCount;
	}

	if (neiborCount > 0) {
		ralativeAngle /= neiborCount;
	}

	angle = ralativeAngle;
	direction = Matrix44f::createRotation(angle) * Vec3f(1.f, 0.f, 0.f);

	return direction;
}

Vec3f SmallEnemy::Cohesion() {
	Vec3f centerPos = Vec3f(0, 0, 0);

	int neiborCount = 0;

	for (auto itr = smallEnemys.begin(); itr != smallEnemys.end(); ++itr) {
		if (OutOfViewRange(itr->position, viewAngleRange, viewDistanceRange))continue;

		centerPos += itr->position;
		++neiborCount;
	}

	if (neiborCount > 0) {
		centerPos /= neiborCount;
	}

	return (centerPos - position).safeNormalized();
}

void SmallEnemy::ExecuteEnter(EnemyManager*) {

}

void SmallEnemy::ExecuteUpdate(EnemyManager* m) {
	Vec3f v;
	v = position;
	v += Separate();
	v += Alignment();
	v += Cohesion();

	position += ((v - position) * 0.08f);

	MyFanc::MoveLimit(position,/*limitValue = */50, /*moveValue = */100);
}

void SmallEnemy::ExecuteDraw(EnemyManager*) {
	gl::pushModelView();

	gl::color(color);
	gl::drawCube(position, Vec3f(scale, scale, scale));

	gl::popModelView();
}

void SmallEnemy::ExecuteExit(EnemyManager*) {

}