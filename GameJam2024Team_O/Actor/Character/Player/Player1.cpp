#include "Player1.h"
#include "KeyInput.h"
#include "PadInput.h"
#include"../Scene/GameMain/GameMainScene.h"

Player1::Player1()
{
	location.x = SCREEN_WIDTH / 4;
	location.y = SCREEN_HEIGHT / 2;

	area.height = 50.f;
	area.width = 50.f;

	jumpCount = 0;

	stanCount = 0.f;

	isStan = false;
}

Player1::~Player1()
{

}

void Player1::Update(GameMainScene* game)
{
	if (isStan)
	{
		stanCount--;
	}

	Movement();

	Collision(game);

	if (KeyInput::GetKey(KEY_INPUT_1) || PadInput::OnButton1(PAD_INPUT_START))
	{
		isStan = true;
		stanCount = MAX_STAN_TIME;
	}

	if (stanCount < 0)
	{
		isStan = false;
	}

}

void Player1::Draw() const
{
	if (isStan)
	{
		DrawBoxAA(location.x, location.y,
			GetMax().x, GetMax().y,
			0xff0000, FALSE, 1.2f);
		DrawFormatStringF(GetCenter().x, GetCenter().y, 0xff0000, "1");
	}
	else
	{
		DrawBoxAA(location.x, location.y,
			GetMax().x, GetMax().y,
			0xffff00, FALSE, 1.2f);
		DrawFormatStringF(GetCenter().x, GetCenter().y, 0xffff00, "1");
	}
}

void Player1::Movement()
{
	//�E�ֈړ�
	if ((KeyInput::GetKeyDown(KEY_INPUT_D) || PadInput::GetLStickRationX1() > STICK_RATIO) && !isStan)
	{
		if (vec.x < MAX_SPEED)
		{
			vec.x += 2.f;
		}
	}
	//���ֈړ�
	else if ((KeyInput::GetKeyDown(KEY_INPUT_A) || PadInput::GetLStickRationX1() < -STICK_RATIO) && !isStan)
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
	if ((KeyInput::GetKey(KEY_INPUT_SPACE) || KeyInput::GetKey(KEY_INPUT_W) || PadInput::OnButton1(XINPUT_BUTTON_A)) && jumpCount < 2 && !isStan && jumpCoolTimeCount <= 0)
	{
		vec.y = -JUMP_POWER;
		isAir = true;
		jumpCount++;
		//�W�����v�̃N�[���^�C���K�v�Ȃ�����
		//if (jumpCount >= 2)
		//{
		//	jumpCoolTimeCount = JUMP_COOL_TIME;
		//}
	}

	//�W�����v�̃N�[���^�C���K�v�Ȃ�����
	//if (jumpCoolTimeCount > 0)
	//{
	//	jumpCoolTimeCount--;
	//}

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
		jumpCount = 0;
	}
}

void Player1::Collision(GameMainScene* game)
{
	if (HitBox(game->GetPlayer2()))
	{
		float enemyMaxX = game->GetPlayer2()->GetMax().x;
		float enemyMaxY = game->GetPlayer2()->GetMax().y;
		float enemyMinX = game->GetPlayer2()->GetMin().x;
		float enemyMinY = game->GetPlayer2()->GetMin().y;

		float enemyHeigh = game->GetPlayer2()->GetArea().height;
		float enemyWidth = game->GetPlayer2()->GetArea().width;

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