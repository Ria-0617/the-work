#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

class BaseGameEntity {
	bool m_bTag;

protected:
	ci::Vec3f m_vPosition;
	ci::Vec3f m_vScale;

	BaseGameEntity(ci::Vec3f pos) :
		m_bTag(false),
		m_vPosition(pos),
		m_vScale(ci::Vec3f(3.f,3.f,3.f)) {}
	virtual ~BaseGameEntity() {}

	virtual void Update() {};

public:
	bool IsTagged() { return m_bTag; }
	void Tag() { m_bTag = true; }
	void UnTag() { m_bTag = false; }

	ci::Vec3f GetPos() { return m_vPosition; }
	ci::Vec3f GetScale() { return m_vScale; }
};