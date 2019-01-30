#include "LargeEnemy.h"

using namespace ci;
using namespace ci::app;
using namespace std;

LargeEnemy::LargeEnemy(BaseEnemy* m) {
	
}

bool LargeEnemy::OutOfViewRange(Vec3f& pos, float viewAngleRange, float viewDistanceRange) {
	Vec3f neighbors = (pos - position).normalized();

	if (direction.dot(neighbors) < viewAngleRange || this->position.distance(pos) > viewDistanceRange) {
		return true;
	}
	return false;
}

void LargeEnemy::ExecuteUpdate(BaseEnemy*) {
	
}

void LargeEnemy::ExecuteEnter(BaseEnemy*) {

}


void LargeEnemy::ExecuteDraw(BaseEnemy*) {
	gl::pushModelView();

	gl::color(color);
	gl::drawCube(position, Vec3f(scale, scale, scale));

	gl::popModelView();
}

void LargeEnemy::ExecuteExit(BaseEnemy*) {

}