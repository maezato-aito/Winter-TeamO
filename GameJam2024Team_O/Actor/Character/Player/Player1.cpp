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
				vec.y = 0.f;
			}

			//相手より下へ行けない
			if (GetMax().y > enemyMinY &&
				GetMin().y < enemyMinY)
			{
				location.y = enemyMinY - enemyHeigh;
				vec.y = 0.f;
			}
		}

		if (GetMin().y<enemyMaxY - 5 && GetMax().y>enemyMinY + 5)
		{
			//相手より左へ行けない
			if (GetMin().x < enemyMaxX &&
				GetMax().x>enemyMaxX)
			{
				location.x = enemyMaxX;
				vec.x = 0.f;
			}

			//相手より右へ行けない
			if (GetMax().x > enemyMinX &&
				GetMin().x < enemyMinX)
			{
				location.x = enemyMinX - enemyWidth;
				vec.x = 0.f;
			}
		}
	}
}