#include "BonusBox.h"
#include"DxLib.h"

BonusBox::BonusBox()
{
	x = 20.0f;
	Vector = 30.0f;
	count = 0;
}

BonusBox::~BonusBox()
{

}

float BonusBox::Get_Box_x()
{
	return x;
}

void BonusBox::Update()
{
	Move_Change();
	Change_Vector();
	Count_Box();
}

void BonusBox::Draw()
{
	DrawBoxAA(x, 30, 60, 70, 0xfffff, TRUE);
	DrawFormatString(750, 0, 0xffffff, "ƒJƒEƒ“ƒg%d\n", count);
}


void BonusBox::Move_Change()
{
	x += Vector;
}

void BonusBox::Change_Vector()
{
	if (x >= 1000.0f || x <= 30.0f)
	{
		Vector *= -1;
	}

}

void BonusBox::Count_Box()
{
	if (x >= 600.0f) 
	{
		count++;
	}
}