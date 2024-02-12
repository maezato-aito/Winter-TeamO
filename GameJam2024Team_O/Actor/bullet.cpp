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
	l.x += velocity;
	h.x1 = l.x - 50;
	h.x2 = l.x + 50;
	h.y1 = l.y - 50;
	h.y2 = l.y + 50;
}

void bullet::Draw()
{
	DrawBox(h.x1, h.y1, h.x2, h.y2, 0xffffff, TRUE);
}