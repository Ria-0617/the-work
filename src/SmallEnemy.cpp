#include "SmallEnemy.h"

using namespace ci;
using namespace ci::app;
using namespace std;

SmallEnemy::SmallEnemy(float s) {
	//position = Vec3f(30.f, 30.f, 30.f);
	position = Vec3f(randFloat(-30.f, 30.f), randFloat(-30.f, 30.f), randFloat(-30.f, 30.f));
	angle = MyFanc::ToRadians(Vec3f(randFloat(0.f, 360.f), randFloat(0.f, 360.f), randFloat(0.f, 360.f)));
	direction = Matrix44f::createRotation(angle) * Vec3f(1.f, 0.f, 0.f);
	scale = randFloat(0.5f, s);
	color = Color(0.f, 0.f, 1.f);

	viewAngleRange = toRadians(45.f);
	viewDistanceRange = 15.f;
}

bool SmallEnemy::OutOfViewRange(Vec3f& pos, float viewAngleRange, float viewDistanceRange) {
	Vec3f neighbors = (pos - position).normalized();

	if (direction.dot(neighbors) < viewAngleRange || this->position.distance(pos) > viewDistanceRange) {
		return true;
	}
	return false;
}

Vec3f SmallEnemy::Separate(list<SmallEnemy>& smallEnemys) {
	Vec3f relativePosition = Vec3f(0, 0, 0);
	Vec3f toAgent;

	for (auto itr = smallEnemys.begin(); itr != smallEnemys.end(); ++itr) {
		if (position.distance(itr->position) > viewDistanceRange) continue;

		toAgent = (position - itr->position).safeNormalized();
		relativePosition += toAgent;
	}

	return relativePosition;
}

Vec3f SmallEnemy::Alignment(list<SmallEnemy>&smallEnemys) {
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

Vec3f SmallEnemy::Cohesion(list<SmallEnemy>&smallEnemys) {
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

void SmallEnemy::ExecuteUpdate(EnemyManager*) {
	Vec3f v;
	v = position;
	v += Separate(Spowner->getEnemys());
	v += Alignment(smallEnemys);
	v += Cohesion(smallEnemys);

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