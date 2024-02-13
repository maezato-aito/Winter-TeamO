#include "BonusBox.h"
#include"DxLib.h"
#include"../../Scene/GameMain/GameMainScene.h"

BonusBox::BonusBox(int & i)
{
	location.x = 300.0f * (i + 1);
	location.y = 550.0f;

	area.width = 100;
	area.height = 100;

	count = 0;
	CountFrame = 0;
}

BonusBox::~BonusBox()
{

}

void BonusBox::Update(GameMainScene*Game)
{
	Count_Box(Game);
}

void BonusBox::Draw(int & i)
{
	
	DrawFormatString(750*(i + 1), 0, 0xffffff, "ƒJƒEƒ“ƒg%d%%\n", count);
	DrawBoxAA(location.x, location.y, location.x + area.width, location.y + area.height, 0xffffff, TRUE);
	
}


void BonusBox::Count_Box(GameMainScene*Game)
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
			count++;
		}
	}
}