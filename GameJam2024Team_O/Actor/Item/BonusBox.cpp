#include "BonusBox.h"
#include"DxLib.h"

BonusBox::BonusBox()
{
	x = 300.0f;
	y = 100.0f;
	count = 0;
	CountFrame = 0;
}

BonusBox::~BonusBox()
{

}

void BonusBox::Update()
{
	Count_Box();
}

void BonusBox::Draw()
{
	DrawBoxAA(x, y, x + 100, y + 100, 0xfffff, TRUE);
	DrawBoxAA(x + 300, y + 300, x + 400, y + 400, 0xfffff, TRUE);
	DrawFormatString(750, 0, 0xffffff, "ƒJƒEƒ“ƒg%d\n", count);
	
}


void BonusBox::Count_Box()
{
	if (CountFrame <= 60) 
	{
		CountFrame++;
	}
	else
	{
		CountFrame == 0;
		if()
	}
}