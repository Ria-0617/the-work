#include "TemplateProjectApp.h"

using namespace ci;
using namespace ci::app;

void TemplateProjectApp::prepareSettings(Settings* settings) {
	settings->setWindowSize(800, 600);
}

void TemplateProjectApp::setup()
{
	sceneManager = std::make_unique<SceneManager>();
}

void TemplateProjectApp::shutdown() {

}

void TemplateProjectApp::update()
{
	sceneManager->Update();
}

void TemplateProjectApp::draw()
{
	gl::clear(Color(1.0f, 1.0f, 1.0f));

	sceneManager->Draw();
}

CINDER_APP_NATIVE(TemplateProjectApp, RendererGl)