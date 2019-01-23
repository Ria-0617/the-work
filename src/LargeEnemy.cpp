#include "LargeEnemy.h"

using namespace ci;
using namespace ci::app;
using namespace std;

LargeEnemy::LargeEnemy(float s) {
	position = Vec3f(-30.f, -30.f, -30.f);
	angle = MyFanc::ToRadians(Vec3f(randFloat(0.f, 360.f), randFloat(0.f, 360.f), randFloat(0.f, 360.f)));
	direction = Matrix44f::createRotation(angle) * Vec3f(1.f, 0.f, 0.f);
	scale = randFloat(s, s + 3.0f);
	color = Color(1.f, 0.f, 0.f);

	viewAngleRange = toRadians(45.f);
	viewDistanceRange = 15.f;
}

bool LargeEnemy::OutOfViewRange(Vec3f& pos, float viewAngleRange, float viewDistanceRange) {
	Vec3f neighbors = (pos - position).normalized();

	if (direction.dot(neighbors) < viewAngleRange || this->position.distance(pos) > viewDistanceRange) {
		return true;
	}
	return false;
}

void LargeEnemy::ExecuteUpdate(EnemyManager*) {
	//OutOfViewRange(viewAngleRange, viewDistanceRange) {

	//}

	//MyFanc::MoveLimit(position,/*limitValue = */50, /*moveValue = */100);
}

void LargeEnemy::ExecuteEnter(EnemyManager*) {

}


void LargeEnemy::ExecuteDraw(EnemyManager*) {
	gl::pushModelView();

	gl::color(color);
	gl::drawCube(position, Vec3f(scale, scale, scale));

	gl::popModelView();
}

void LargeEnemy::ExecuteExit(EnemyManager*) {

}