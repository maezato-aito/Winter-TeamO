#include "bullet.h"
#include"DxLib.h"

bullet::bullet()
{
	velocity = 10;
}

bullet::~bullet()
{

}

void bullet::Update()
{
	LocationX += velocity;
	HitBoxX1 = LocationX - 50;
	HitBoxX2 = LocationX + 50;
	HitBoxY1 = LocationY - 50;
	HitBoxY2 = LocationY + 50;
}

void bullet::Draw()
{
 	DrawBox(HitBoxX1, HitBoxY1, HitBoxX2, HitBoxY2, 0xffffff, TRUE);
}