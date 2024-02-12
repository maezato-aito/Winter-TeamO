#include"../../common.h"
#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	ui = new UI();
	player1 = new Player1();
	Skill1 = new skill1();
}

GameMainScene::~GameMainScene()
{

}

SceneBase* GameMainScene::Update()
{
	ui->Update();
	player1->Update();
	Skill1->UpDate();
	return this;
}

void GameMainScene::Draw() const
{
	ui->Draw();
	player1->Draw();
	Skill1->Draw();
}

void GameMainScene::Ground() const
{

}
