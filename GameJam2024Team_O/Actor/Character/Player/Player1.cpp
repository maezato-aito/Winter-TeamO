#include "Player1.h"
#include "KeyInput.h"
#include "PadInput.h"
#include"../Scene/GameMain/GameMainScene.h"
#include"../common.h"

Player1::Player1()
{
	ImageManager::SetImage(IDLE);
	ImageManager::SetImage(WALK1);
	ImageManager::SetImage(WALK2);
	ImageManager::SetImage(JUMP);
	ImageManager::SetImage(STUN);

	location.x = SCREEN_WIDTH / 4;
	location.y = SCREEN_HEIGHT / 2;

	area.height = 80.f;
	area.width = 50.f;

	jumpCount = 0;

	animState = 0;
	animCnt = 0;

	stanCount = 0.f;

	isStan = false;
	isReverse = false;
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

	Animation();

 	AnimStateToAnimHandle();

	Collision(game);

	if (stanCount < 0)
	{
		isStan = false;
	}

}

void Player1::Draw() const
{
	if (!isReverse)
	{
		DrawGraphF(location.x - area.width + IMAGE_SHIFT_X, location.y - area.height + IMAGE_SHIFT_Y, ImageManager::GetHandle(GetAnimHandle().c_str()), TRUE);
	}
	else
	{
		DrawTurnGraphF(location.x - area.width + IMAGE_SHIFT_X-10, location.y - area.height + IMAGE_SHIFT_Y, ImageManager::GetHandle(GetAnimHandle().c_str()), TRUE);
	}

	if (isStan)
	{
		DrawBoxAA(location.x, location.y,
			GetMax().x, GetMax().y,
			0xff0000, FALSE, 1.2f);
	}
	else
	{
		DrawBoxAA(location.x, location.y,
			GetMax().x, GetMax().y,
			0xffff00, FALSE, 1.2f);
	}
}

void Player1::Movement()
{
	//右へ移動
	if ((KeyInput::GetKeyDown(KEY_INPUT_D) || PadInput::GetLStickRationX1() > STICK_RATIO) && !isStan)
	{
		if (vec.x < MAX_SPEED)
		{
			vec.x += 2.f;
		}
	}
	//左へ移動
	else if ((KeyInput::GetKeyDown(KEY_INPUT_A) || PadInput::GetLStickRationX1() < -STICK_RATIO) && !isStan)
	{
		if (vec.x > -MAX_SPEED)
		{
			vec.x -= 2.f;
		}
	}
	//停止
	else
	{
		vec.x = 0.f;
	}

	//ジャンプ
	if ((KeyInput::GetKey(KEY_INPUT_SPACE) || KeyInput::GetKey(KEY_INPUT_W) || PadInput::OnButton1(XINPUT_BUTTON_A)) && jumpCount < 2 && !isStan && jumpCoolTimeCount <= 0)
	{
		vec.y = -JUMP_POWER;
		isAir = true;
		jumpCount++;
		//ジャンプのクールタイム必要なら入れる
		//if (jumpCount >= 2)
		//{
		//	jumpCoolTimeCount = JUMP_COOL_TIME;
		//}
	}

	//ジャンプのクールタイム必要なら入れる
	//if (jumpCoolTimeCount > 0)
	//{
	//	jumpCoolTimeCount--;
	//}

	//重力を加算
	vec.y += GRAVITY;

	//移動量を座標に加算
	location.x += vec.x;
	location.y += vec.y;

	//画面左端を超えない
	if (GetMin().x < 0.f)
	{
		location.x = 0.f;
		vec.x = 0.f;
	}
	//画面右端を超えない
	else if (GetMax().x > SCREEN_WIDTH)
	{
		location.x = SCREEN_WIDTH - area.width;
		vec.x = 0.f;
	}

	//天井を超えない
	if (GetMin().y < 0.f)
	{
		location.y = 0.f;
		vec.y = 0.f;
	}

	//地面を超えない
	if (GetMax().y > STAGE_FLOOR)
	{
		location.y = STAGE_FLOOR - area.height;
		vec.y = 0.f;
		isAir = false;
		jumpCount = 0;
	}
}

void Player1::Animation()
{
	if (animCnt < 60)
	{
		animCnt++;
	}
	else
	{
		animCnt = 0;
	}

	if (isStan)
	{
		animState = Stun;
	}

	if (stanCount < 0)
	{
		animState = Idle;
	}

	//右へ
	if ((KeyInput::GetKeyDown(KEY_INPUT_D) || PadInput::GetLStickRationX1() > STICK_RATIO) && !isStan)
	{
		isReverse = false;

		if (!isAir)
		{
			if (animCnt % 5 == 0)
			{
				animState += 1;
				if (animState > Walk2)
				{
					animState = Walk1;
				}
			}
		}
	}
	//左へ
	else if ((KeyInput::GetKeyDown(KEY_INPUT_A) || PadInput::GetLStickRationX1() < -STICK_RATIO) && !isStan)
	{
		isReverse = true;

		if (!isAir)
		{
			if (animCnt % 5 == 0)
			{
				animState += 1;
				if (animState > Walk2)
				{
					animState = Walk1;
				}
			}
		}
	}
	//停止
	else
	{
		if (!isAir && !isStan)
		{
			animState = Idle;
		}
	}

	//ジャンプ
	if ((KeyInput::GetKey(KEY_INPUT_SPACE) || KeyInput::GetKey(KEY_INPUT_W) || PadInput::OnButton1(XINPUT_BUTTON_A)) && jumpCount < 2 && !isStan && jumpCoolTimeCount <= 0)
	{
		animState = Jump;
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
			//相手より上へ行けない
			if (GetMin().y < enemyMaxY &&
				GetMax().y>enemyMaxY)
			{
				location.y = enemyMaxY;
				vec.y = 10.f;
			}

			//相手より下へ行けない
			if (GetMax().y > enemyMinY &&
				GetMin().y < enemyMinY)
			{
				location.y = enemyMinY - enemyHeigh;
				vec.y = -10.f;
			}
		}

		if (GetMin().y<enemyMaxY - 5 && GetMax().y>enemyMinY + 5)
		{
			//相手より左へ行けない
			if (GetMin().x < enemyMaxX &&
				GetMax().x>enemyMaxX)
			{
				location.x = enemyMaxX;
				vec.x = 10.f;
			}

			//相手より右へ行けない
			if (GetMax().x > enemyMinX &&
				GetMin().x < enemyMinX)
			{
				location.x = enemyMinX - enemyWidth;
				vec.x = -10.f;
			}
		}
	}
}