#include "bullet.h"
#include"../common.h"
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
	ImageManager::SetImage(BULLET);

	location.x = 0;
	location.y = 0;
	area.width = 35;
	area.height = 30;

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
		DrawGraphF(location.x - BULLET_IMAGE_SHIFT_X, location.y - BULLET_IMAGE_SHIFT_Y, ImageManager::GetHandle(BULLET), TRUE);
	}
}

void bullet::MoveBullet(GameMainScene* game)
{
	if (game->GetPlayer2()->GetLocation().x < game->GetPlayer1()->GetLocation().x)
	{
		game->GetPlayer2()->SetIsReverse(false);
		Speed = 15;
	}
	if (game->GetPlayer2()->GetLocation().x > game->GetPlayer1()->GetLocation().x)
	{
		game->GetPlayer2()->SetIsReverse(true);
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