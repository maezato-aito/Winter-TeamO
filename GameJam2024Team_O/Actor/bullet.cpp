#include "bullet.h"
#include"DxLib.h"
#include "../Scene/GameMain/GameMainScene.h"

bullet::bullet()
{
	initialize();
}

bullet::~bullet()
{

}
void bullet::initialize()
{
	location.x = 0;
	location.y = 0;
	area.width = 10;
	area.height = 10;

	Speed = 10;
}
void bullet::Update(GameMainScene* game)
{
	location.x += Speed;
}

void bullet::Draw()
{
 	DrawBoxAA(location.x, location.y, location.x+area.width, location.y + area.height, 0xff0000, TRUE);
}