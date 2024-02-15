#include "CharaBase.h"
#include"../../Scene/GameMain/GameMainScene.h"

CharaBase::CharaBase()
{
	vec = {};

	animState = 0;
	animCnt = 0;

	jumpCoolTimeCount = 0.f;

	isLanding = false;
	isAir = false;
	isReverse = false;
}

CharaBase::~CharaBase()
{

}

void CharaBase::GroundCollision(GameMainScene* game, int arrayNum)

{
	if (HitBox(game->GetFloor(arrayNum)))
	{
		float enemyMaxX = game->GetFloor(arrayNum)->GetMax().x;
		float enemyMaxY = game->GetFloor(arrayNum)->GetMax().y;
		float enemyMinX = game->GetFloor(arrayNum)->GetMin().x;
		float enemyMinY = game->GetFloor(arrayNum)->GetMin().y;

		float enemyHeigh = game->GetFloor(arrayNum)->GetArea().height;
		float enemyWidth = game->GetFloor(arrayNum)->GetArea().width;

		if (GetMin().x<enemyMaxX - 10 && GetMax().x>enemyMinX + 10)
		{
			//�������֍s���Ȃ�
			if (GetMin().y < enemyMaxY &&
				GetMax().y>enemyMaxY)
			{
				location.y = enemyMaxY;
				vec.y = 10.f;
			}

			//�����艺�֍s���Ȃ�
			if (GetMax().y > enemyMinY &&
				GetMin().y < enemyMinY)
			{
				location.y = enemyMinY - area.height;
				vec.y = 0.f;
				isLanding = true;
				isAir = false;
			}
		}

		if (GetMin().y<enemyMaxY && GetMax().y>enemyMinY)
		{
			//�����荶�֍s���Ȃ�
			if (GetMin().x < enemyMaxX &&
				GetMax().x>enemyMaxX)
			{
				location.x = enemyMaxX;
			}

			//������E�֍s���Ȃ�
			if (GetMax().x > enemyMinX &&
				GetMin().x < enemyMinX)
			{
				location.x = enemyMinX - area.width;
			}
		}
	}
}