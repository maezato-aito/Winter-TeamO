#include "BonusBox.h"
#include"DxLib.h"
#include"../../Scene/GameMain/GameMainScene.h"
#include"../common.h"
#include"../Utility/FontManager.h"



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

	fpsCnt = 0;
	Count = 0.55f;
	CountFrame = 0;
	effectAngle = 0.f;

	isOpen = false;
	isShow = false;
}

BonusBox::~BonusBox()
{

}

void BonusBox::Update(GameMainScene* Game)
{		
	fpsCnt++;

	if (fpsCnt % 10 == 0)
	{
		if (effectAngle < 360)
		{
			effectAngle += 1;
		}
		else
		{
			effectAngle = 0;
		}
	}

	if (Game->GetUI()->Get_Timer() <= BONUS_TIME)
	{
		isShow = true;
	}

	if (isShow)
	{
		Count_Box(Game);
		if (HitBox(Game->GetPlayer1()) && !Game->GetPlayer1()->GetIsStan())
		{
			isOpen = true;
		}
		else
		{
			isOpen = false;
		}
	}
}

void BonusBox::Draw(int& i)
{
	if (isShow)
	{
		if (isOpen)
		{
			DrawRotaGraphF(GetCenter().x, GetCenter().y, 0.07f, 0.0f, ImageManager::GetHandle(Openbox), TRUE);
			DrawRotaGraphF(GetCenter().x - 10.f, GetCenter().y - 60.f, 0.05f, effectAngle, ImageManager::GetHandle(Effect), TRUE);
		}
		else
		{
			DrawRotaGraphF(GetCenter().x, GetCenter().y, 0.07f, 0.0f, ImageManager::GetHandle(Bonusbox), TRUE);
		}
	}
}


void BonusBox::Count_Box(GameMainScene* Game)
{
	if (CountFrame < 100)
	{
		CountFrame++;
	}
	else
	{
		CountFrame = 0;
		if (HitBox(Game->GetPlayer1()) && !Game->GetPlayer1()->GetIsStan())
		{
			Count += 0.1f;
		}
	}
}

float BonusBox::Get_Count()
{
	return Count;
}
