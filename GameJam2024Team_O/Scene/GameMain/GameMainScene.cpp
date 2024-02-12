#include"../../common.h"
#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	player1 = new Player1();
}

GameMainScene::~GameMainScene()
{

}

SceneBase* GameMainScene::Update()
{
	player1->Update();
	return this;
}

void GameMainScene::Draw() const
{
	player1->Draw();
}

void GameMainScene::Ground() const
{

}
