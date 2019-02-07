#include "GameScene.h"

using namespace ci;
using namespace ci::app;

GameScene::GameScene() {
	field = std::make_unique<GameField>();
	player = std::make_unique<Player>();
	camera = std::make_unique<GameCamera>();
	ui = std::make_unique<UI>();
	
	gl::enable(GL_COLOR_MATERIAL);
}

GameScene::~GameScene() {

}

void GameScene::ExecuteEnter(SceneManager*) {

}

void GameScene::ExecuteUpdate(SceneManager*) {
	player->Update(camera->GetQuaternion());
	camera->Update(player->GetPosition(), player->GetScale());
	ui->Update(player->NomalizedExp());
	
	//Spowner->EnemySpowner(player->GetScale());

	
	/*for (auto itr = Spowner->getEnemys().begin(); itr != Spowner->getEnemys().end(); ++itr) {
		itr->Move();

		if (MyFanc::OutCircleCollider(itr->GetPos(), itr->GetScale(), player->GetPosition(), player->GetScale())) continue;
		if (itr->GetScale() < player->GetScale()) {
			itr = enemys.erase(itr);
			ui->PlusScore(itr->GetScale() * 100);
			player->PulsExp(itr->GetScale());
		}
	}*/

	/*for (const auto& itr : Spowner->getEnemys()) {
		itr->Move();
	}*/
}

void GameScene::ExecuteExit(SceneManager*) {

}

void GameScene::ExecuteDraw(SceneManager* m) {
#pragma region enable
	gl::enableDepthRead();
	gl::enableDepthWrite();
	gl::enable(GL_CULL_FACE);
	//gl::enable(GL_LIGHTING);
#pragma endregion

	camera->Draw();
	field->Draw();
	player->Draw();

	// “G•`‰æ
	//Spowner->EnemyDraw();

#pragma region disable
	gl::disableDepthRead();
	gl::disableDepthWrite();
	gl::disable(GL_CULL_FACE);
	//gl::disable(GL_LIGHTING);
#pragma endregion

	ui->Draw();

	if (joy->IsPressedButton(joy->CROSS))
		m->GetFSM()->ChangeState(new Title());
}