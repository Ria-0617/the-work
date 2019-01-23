#include "Init.h"

using namespace ci;
using namespace ci::app;

Init::Init() {
	joyController = new JoyController();
}

Init::~Init() {
	delete joyController;
}