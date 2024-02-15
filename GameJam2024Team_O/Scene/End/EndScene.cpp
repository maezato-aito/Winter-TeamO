#include "../common.h"
#include "EndScene.h"

EndScene::EndScene()
{
	
	ImageManager::SetImage("Scene/Credit.png");

}

EndScene::~EndScene()
{

}

SceneBase* EndScene::Update()
{
	return nullptr;
}

void EndScene::Draw() const
{
	DrawRotaGraph(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1, 0, ImageManager::GetHandle("Scene/Credit.png"), TRUE);
}
