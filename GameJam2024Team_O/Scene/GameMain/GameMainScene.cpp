#include"../../common.h"
#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	ui = new UI();
}

GameMainScene::~GameMainScene()
{

}

SceneBase* GameMainScene::Update()
{
	ui->Update();
	return this;
}

void GameMainScene::Draw() const
{
	ui->Draw();
}

void GameMainScene::Ground() const
{

}
