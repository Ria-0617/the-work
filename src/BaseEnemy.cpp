#include "BaseEnemy.h"

using namespace ci;
using namespace ci::app;

bool BaseEnemy::OutOfViewRange(Vec3f& pos, float viewAngleRange, float viewDistanceRange) {
	Vec3f neighbors = (pos - position).normalized();

	if (direction.dot(neighbors) < viewAngleRange || this->position.distance(pos) > viewDistanceRange) {
		return true;
	}
	return false;
}