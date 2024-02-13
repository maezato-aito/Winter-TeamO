#include "BonusBox.h"
#include"DxLib.h"

BonusBox::BonusBox()
{
	x = 20.0f;
	Vector = 30.0f;
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
}

void BonusBox::Draw()
{
	DrawBoxAA(x, 30, 60, 70, 0xfffff, TRUE);
}


void BonusBox::Move_Change()
{
	x += Vector;
}

void BonusBox::Change_Vector()
{
	if (x >= 600.0f || x <= 30.0f)
	{
		Vector *= -1;
	}

}
