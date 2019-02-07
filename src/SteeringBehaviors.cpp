#include "SteeringBehaviors.h"

using namespace ci;
using namespace ci::app;
using namespace std;

SteeringBehaviors::SteeringBehaviors(BaseEnemy* agent) :
	m_pBaseEnemy(agent)
{

}

//bool SteeringBehaviors::ViewRange(BaseEnemy* neighbor) {
//	Vec3f value = (neighbor->GetPos() - m_pBaseEnemy->GetPos()).normalized();
//
//	if (m_pBaseEnemy->GetDirection().dot(value) > m_pBaseEnemy->GetViewAngleRange() && 
//		m_pBaseEnemy->GetPos().distance(neighbor->GetPos()) < m_pBaseEnemy->GetViewDistanceRange()) {
//		return true;
//	}
//	return false;
//}

Vec3f SteeringBehaviors::Calculate() {
	return Vec3f(0.f, 0.f, 0.f);
}

Vec3f SteeringBehaviors::Seek(Vec3f targetPos) {
	Vec3f desiredVelocity = (targetPos - m_pBaseEnemy->GetPos()).normalized() * m_pBaseEnemy->GetMaxSpeed();
	return desiredVelocity - m_pBaseEnemy->GetVelocity();
}

Vec3f SteeringBehaviors::Separation(const std::vector<BaseEnemy*>& neighbors) {
	Vec3f SteeringForce = Vec3f(0.f, 0.f, 0.f);

	for (int i = 0; i < neighbors.size(); ++i) {
		if (neighbors[i] != m_pBaseEnemy /*&&
			m_pBaseEnemy->GetPos().distance(neighbors[i]->GetPos()) < m_pBaseEnemy->GetViewDistanceRange()*/) {
			Vec3f toAgent = m_pBaseEnemy->GetPos() - neighbors[i]->GetPos();
			SteeringForce += toAgent.normalized() / toAgent.length();
		}
	}

	return SteeringForce;
}

Vec3f SteeringBehaviors::Alignment(const std::vector<BaseEnemy*>& neighbors) {
	Vec3f averageAngle = Vec3f(0.f, 0.f, 0.f);
	int neighborCount = 0;

	for (int i = 0; i < neighbors.size(); ++i) {
		if (neighbors[i] != m_pBaseEnemy /*&& ViewRange(neighbors[i])*/) {
			averageAngle += neighbors[i]->GetAngle();

			++neighborCount;
		}
	}

	if (neighborCount > 0) {
		averageAngle /= neighborCount;
		averageAngle -= m_pBaseEnemy->GetAngle();
	}
	return averageAngle;
}

Vec3f SteeringBehaviors::Cohesion(const std::vector<BaseEnemy*>& neighbors) {
	Vec3f centerPos = Vec3f(0.f, 0.f, 0.f);
	Vec3f steeringForce = Vec3f(0.f, 0.f, 0.f);
	int neighborCount = 0;

	for (int i = 0; i < neighbors.size(); ++i) {
		if (neighbors[i] != m_pBaseEnemy /*&& ViewRange(neighbors[i])*/) {
			centerPos += neighbors[i]->GetPos();
			++neighborCount;
		}
	}

	if (neighborCount > 0) {
		centerPos /= neighborCount;
		steeringForce = Seek(centerPos);
	}
	return steeringForce;
}