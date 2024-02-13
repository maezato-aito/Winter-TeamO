#include "bullet.h"
#include"DxLib.h"
#include "../Scene/GameMain/GameMainScene.h"

bullet::bullet(float Px, float Py)
{
	P1 = new Player1();
	P2 = new Player2();

	location.x = P2->GetLocation().x ;
	location.y = P2->GetLocation().y;

	area.width = 50;
	area.height = 50;

	Speed = 10;
}

bullet::~bullet()
{

}

void bullet::Update()
{
	if (P2->GetLocation().x < P1->GetLocation().x)
	{
		location.x += Speed;
	}
	if (P2->GetLocation().x > P1->GetLocation().x)
	{
		location.x -= Speed;
	}
}

void bullet::Draw()
{
 	DrawBox(location.x, location.y, location.x+area.width, location.y + area.height, 0xff0000, TRUE);
}