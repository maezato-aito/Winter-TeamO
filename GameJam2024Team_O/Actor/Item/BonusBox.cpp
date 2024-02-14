#include "BonusBox.h"
#include"DxLib.h"
#include"../../Scene/GameMain/GameMainScene.h"
#include"../common.h"



BonusBox::BonusBox(int& i, int patern)
{
	//画像の読み込む
	ImageManager::SetImage("Item/bonusbox.png");
	ImageManager::SetImage("Item/openbox.png");
	ImageManager::SetImage("Item/effect.png");

	int random = patern;

	if (random == 0)
	{
		location.x = 100.0f * (i * 10 + 1);
		location.y = STAGE_FLOOR - 100;
	}
	else if (random == 1)
	{
		location.x = 300.0f * (i * 2 + 1);
		location.y = STAGE_FLOOR - 100;
	}
	else if (random == 2)
	{
		location.x = SCREEN_WIDTH / 2 - 50;
		if (i == 0)
		{
			location.y = 150.0f;
		}
		else
		{
			location.y = STAGE_FLOOR - 100;
		}
	}

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
	DrawFormatString(750 * (i + 1), 0, 0xffffff, "カウント%f%%\n", Count);
	//DrawBoxAA(location.x, location.y, location.x + area.width, location.y + area.height, 0xffffff, TRUE);
	if (isOpen)
	{
		DrawRotaGraph(GetCenter().x, GetCenter().y, 0.07f, 0.0f, ImageManager::GetHandle(Openbox), TRUE);
		DrawRotaGraph(GetCenter().x,-100.f, GetCenter().y-40.f, 1.f, 0.0f, ImageManager::GetHandle(Effect), TRUE);
	}
	else
	{
		DrawRotaGraph(GetCenter().x, GetCenter().y, 0.07f, 0.0f, ImageManager::GetHandle(Bonusbox), TRUE);
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
