#include "Player2.h"
#include "KeyInput.h"
#include "PadInput.h"
#include"../Scene/GameMain/GameMainScene.h"


Player2::Player2()
{
	location.x = (SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 4);
	location.y = SCREEN_HEIGHT / 2;

	area.height = 50.f;
	area.width = 50.f;

	skill1Count = 0.f;
	skill2Count = 0.f;

	isShotSkill1 = false;
	isShotSkill2 = false;
}

Player2::~Player2()
{

}

void Player2::Update(GameMainScene* game)
{
	Movement();

	Collision(game);
}

void Player2::Draw() const
{
	DrawBoxAA(location.x, location.y,
		GetMax().x, GetMax().y,
		0x00ffff, FALSE, 1.2f);
	DrawFormatStringF(GetCenter().x, GetCenter().y, 0x00ffff, "2");
}

void Player2::Movement()
{
	//�E�ֈړ�
	if (KeyInput::GetKeyDown(KEY_INPUT_RIGHT) || PadInput::GetLStickRationX2() > STICK_RATIO)
	{
		if (vec.x < MAX_SPEED)
		{
			vec.x += 2.f;
		}
	}
	//���ֈړ�
	else if (KeyInput::GetKeyDown(KEY_INPUT_LEFT) || PadInput::GetLStickRationX2() < -STICK_RATIO)
	{
		if (vec.x > -MAX_SPEED)
		{
			vec.x -= 2.f;
		}
	}
	//��~
	else
	{
		vec.x = 0.f;
	}

	//�W�����v
	if ((KeyInput::GetKey(KEY_INPUT_UP) || PadInput::OnButton2(XINPUT_BUTTON_A)) && !isAir)
	{
		vec.y = -JUMP_POWER - (JUMP_POWER * GRAVITY) / 2.f;
		isAir = true;
	}

	//�d�͂����Z
	vec.y += GRAVITY;

	//�ړ��ʂ����W�ɉ��Z
	location.x += vec.x;
	location.y += vec.y;

	//��ʍ��[�𒴂��Ȃ�
	if (GetMin().x < 0.f)
	{
		location.x = 0.f;
		vec.x = 0.f;
	}
	//��ʉE�[�𒴂��Ȃ�
	else if (GetMax().x > SCREEN_WIDTH)
	{
		location.x = SCREEN_WIDTH - area.width;
		vec.x = 0.f;
	}

	//�V��𒴂��Ȃ�
	if (GetMin().y < 0.f)
	{
		location.y = 0.f;
		vec.y = 0.f;
	}

	//�n�ʂ𒴂��Ȃ�
	if (GetMax().y > STAGE_FLOOR)
	{
		location.y = STAGE_FLOOR - area.height;
		vec.y = 0.f;
		isAir = false;
	}
}

void Player2::Collision(GameMainScene* game)
{
	if (HitBox(game->GetPlayer1()))
	{
		float enemyMaxX = game->GetPlayer1()->GetMax().x;
		float enemyMaxY = game->GetPlayer1()->GetMax().y;
		float enemyMinX = game->GetPlayer1()->GetMin().x;
		float enemyMinY = game->GetPlayer1()->GetMin().y;

		float enemyHeigh = game->GetPlayer1()->GetArea().height;
		float enemyWidth = game->GetPlayer1()->GetArea().width;

		if (GetMin().x<enemyMaxX - 5 && GetMax().x>enemyMinX + 5)
		{
			//�������֍s���Ȃ�
			if (GetMin().y < enemyMaxY &&
				GetMax().y>enemyMaxY)
			{
				location.y = enemyMaxY;
				vec.y = 0.f;
			}

			//�����艺�֍s���Ȃ�
			if (GetMax().y > enemyMinY &&
				GetMin().y < enemyMinY)
			{
				location.y = enemyMinY - enemyHeigh;
				vec.y = 0.f;
			}
		}

		if (GetMin().y<enemyMaxY - 5 && GetMax().y>enemyMinY + 5)
		{
			//�����荶�֍s���Ȃ�
			if (GetMin().x < enemyMaxX &&
				GetMax().x>enemyMaxX)
			{
				location.x = enemyMaxX;
				vec.x = 0.f;
			}

			//������E�֍s���Ȃ�
			if (GetMax().x > enemyMinX &&
				GetMin().x < enemyMinX)
			{
				location.x = enemyMinX - enemyWidth;
				vec.x = 0.f;
			}
		}
	}
}
