#include "GameField.h"

using namespace ci;
using namespace ci::app;

GameField::GameField() {
	json = JsonTree(loadAsset("field.json"));

	for (int i = 0; i < json["CubePosition"].getNumChildren(); ++i) {
		JsonTree pos = json["CubePosition"][i];
		cubePosition[i].x = pos.getValueAtIndex<int>(0);
		cubePosition[i].y = pos.getValueAtIndex<int>(1);
		cubePosition[i].z = pos.getValueAtIndex<int>(2);
	}
	size = json.getValueForKey<float>("CubeSize");

	for (int i = 0; i < json["LinePosition"].getNumChildren(); ++i)
	{
		JsonTree pos = json["LinePosition"][i];
		linePosition[i].x = pos.getValueAtIndex<int>(0);
		linePosition[i].y = pos.getValueAtIndex<int>(1);
		linePosition[i].z = pos.getValueAtIndex<int>(2);

		JsonTree size = json["LineSize"][i];
		lineSize[i].x = size.getValueAtIndex<int>(0);
		lineSize[i].y = size.getValueAtIndex<int>(1);
		lineSize[i].z = size.getValueAtIndex<int>(2);
	}

	color.r = json["Color"].getValueAtIndex<float>(0);
	color.g = json["Color"].getValueAtIndex<float>(1);
	color.b = json["Color"].getValueAtIndex<float>(2);
}

GameField::~GameField() {

}

void GameField::Draw() {

	gl::color(color);

	for (int i = 0; i < json["CubePosition"].getNumChildren(); ++i)
		gl::drawCube(cubePosition[i], Vec3f(size, size, size));

	for (int i = 0; i < json["LinePosition"].getNumChildren(); ++i) {

		gl::drawCube(linePosition[i], lineSize[i]);
	}

}