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
	player1->Update();
	player2->Update();
	/*item->Update();*/
	bonusbox->Update();

	return this;
}

void GameMainScene::Draw() const
{
	ui->Draw();
	player1->Draw();
	player2->Draw();
	/*item->Draw();*/
	bonusbox->Draw();
}

void GameMainScene::Ground() const
{

}
