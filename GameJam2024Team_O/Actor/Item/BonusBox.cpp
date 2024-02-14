#include "BonusBox.h"
#include"DxLib.h"
#include"../../Scene/GameMain/GameMainScene.h"
#include"../common.h"



BonusBox::BonusBox(int& i)
{
	//画像の読み込む
	ImageManager::SetImage("Item/bonusbox.png");
	ImageManager::SetImage("Item/openbox.png");
	location.x = 300.0f * (i + 1);
	location.y = 550.0f;

	area.width = 100;
	area.height = 100;

	Count = 0.0f;
	CountFrame = 0;

	isOpen = false;
}

BonusBox::~BonusBox()
{

}

void BonusBox::Update(GameMainScene* Game)
{
	Count_Box(Game);
	if (HitBox(Game->GetPlayer1()))
	{
		isOpen = true;
	}
	else
	{
		isOpen = false;
	}
}

void BonusBox::Draw(int& i)
{
	DrawFormatString(750 * (i + 1), 0, 0xffffff, "カウント%d%%\n", Count);
	DrawBoxAA(location.x, location.y, location.x + area.width, location.y + area.height, 0xffffff, TRUE);
	if (isOpen)
	{
		DrawRotaGraph(GetCenter().x, GetCenter().y, 0.07f, 0.0f, ImageManager::GetHandle(Openbox), FALSE);
	}
	else
	{
		DrawRotaGraph(GetCenter().x, GetCenter().y, 0.07f, 0.0f, ImageManager::GetHandle(Bonusbox), FALSE);
	}
}


void BonusBox::Count_Box(GameMainScene* Game)
{
	if (CountFrame < 30)
	{
		CountFrame++;
	}
	else
	{
		CountFrame = 0;
		if (HitBox(Game->GetPlayer1()))
		{
			Count++;
		}
	}
}

float BonusBox::Get_Count()
{
	return Count;
}
