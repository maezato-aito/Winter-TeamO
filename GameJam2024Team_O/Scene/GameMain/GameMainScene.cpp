#include"../../common.h"
#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	ui = new UI();
	player1 = new Player1();
	player2 = new Player2();
	/*item = new Item();*/
	bonusbox = new BonusBox();
}

GameMainScene::~GameMainScene()
{
	delete ui;
	delete player1;
	delete player2;
	/*delete item;*/
	delete bonusbox;
}

SceneBase* GameMainScene::Update()
{
	ui->Update();

	player1->Update(this);

	player2->Update(this);

	/*item->Update();*/

	bonusbox->Update();

	return this;
}

void GameMainScene::Draw() const
{
	Ground();

	ui->Draw();

	player1->Draw();

	player2->Draw();

	/*item->Draw();*/

	bonusbox->Draw();

}

void GameMainScene::Ground() const
{
	DrawLine(0, STAGE_FLOOR, SCREEN_WIDTH, STAGE_FLOOR, 0xffffff);
}
