#include "../common.h"
#include "EndScene.h"
#include"../../Scene/GameMain/GameMainScene.h"

EndScene::EndScene()
{
	
	ImageManager::SetImage("Scene/Credit.png");
	Timer = 5;
	TimerCount = 0;
	

}

EndScene::~EndScene()
{

}

SceneBase* EndScene::Update()
{

	if (TimerCount < 60)
	{
		TimerCount++;
	}
	else
	{
		TimerCount = 0;

		if (Timer > 0)
		{
			Timer--;
		}

	}
	
	if (Timer == 0)
	{
		return nullptr;
	}
	else
	{
		return this;
	}
}

void EndScene::Draw() const
{
	DrawRotaGraph(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 1, 0, ImageManager::GetHandle("Scene/Credit.png"), TRUE);
}
