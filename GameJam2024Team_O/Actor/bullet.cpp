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
	isflg = false;
}
void bullet::Update(GameMainScene* game)
{
	location.x += Speed;

	if (HitBox(game->GetPlayer1()))
	{
		OffFlg();
		game->GetPlayer1()->SetIsStan(true);
	}
}

void bullet::Draw()
{
	if (isflg)
	{
 		DrawBoxAA(location.x, location.y, location.x+area.width, location.y + area.height, 0xff0000, TRUE);
	}
}

void bullet::MoveBullet(GameMainScene* game)
{
	if (game->GetPlayer2()->GetLocation().x < game->GetPlayer1()->GetLocation().x)
	{
		Speed = 15;
	}
	if (game->GetPlayer2()->GetLocation().x > game->GetPlayer1()->GetLocation().x)
	{
		Speed = -15;
	}
}

bool bullet::OnFlg()
{
	isflg = true;
	return isflg;
}
bool bullet::OffFlg()
{
	isflg = false;
	return isflg;
}