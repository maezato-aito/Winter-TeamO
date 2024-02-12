#include"../../common.h"
#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	ui = new UI();
	player1 = new Player1();
	player2 = new Player2();
}

GameMainScene::~GameMainScene()
{
	delete ui;
	delete player1;
	delete player2;
}

SceneBase* GameMainScene::Update()
{
	ui->Update();
	player1->Update();
	player2->Update();
	return this;
}

void GameMainScene::Draw() const
{
	ui->Draw();
	player1->Draw();
	player2->Draw();
}

void GameMainScene::Ground() const
{

}
