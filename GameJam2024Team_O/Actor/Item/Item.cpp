#include "Item.h"
#include"DxLib.h"

Item::Item()
{
	x = 20.0f;
	Vector = 30.0f;
}

Item::~Item()
{

}

float Item::Get_Box_x()
{
	return x;
}

void Item::Update()
{
	Move_Change();
	Change_Vector();
}

void Item::Draw()
{
	DrawBoxAA(x, 10, 60, 50, 0xfffff,TRUE);
}


void Item::Move_Change()
{
	x += Vector;
}

void Item::Change_Vector()
{
	if (x >= 600.0f || x <= 30.0f)
	{
		Vector *= -1;
	}
	
}

