#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Json.h"

class GameField {
private:
	ci::JsonTree json;

	ci::Color color;
	
	ci::Vec3i cubePosition[8];
	float size;

	ci::Vec3i linePosition[12];
	ci::Vec3i lineSize[12];

public:
	GameField();
	~GameField();

	void Draw();
};