#include "Player2.h"
#include"../Scene/GameMain/GameMainScene.h"

Player2::Player2()
{

	ImageManager::SetImage(IDLE_2);
	ImageManager::SetImage(WALK1_2);
	ImageManager::SetImage(WALK2_2);
	ImageManager::SetImage(JUMP_2);
	ImageManager::SetImage(STUN_2);

	location.x = (SCREEN_WIDTH / 2) + (SCREEN_WIDTH / 4);
	location.y = SCREEN_HEIGHT / 2 + 10.f;

	area.height = 80.f;
	area.width = 70.f;

	skill1Count = MAX_SKILL_1_COOL_TIME;
	skill2Count = 0.f;

	isShotSkill1 = false;
	isShotSkill2 = false;

	isReverse = true;


	SK = new skill1();
}

Player2::~Player2()
{

}

void Player2::Update(GameMainScene* game)
{
	Movement();

	Animation();

	AnimStateToAnimHandle();

	Skill(game);

	Collision(game);
}

void Player2::Draw() const
{
	if (!isReverse)
	{
		DrawGraphF(location.x - area.width + IMAGE_SHIFT_X_2, location.y - area.height + IMAGE_SHIFT_Y_2, ImageManager::GetHandle(GetAnimHandle().c_str()), TRUE);
	}
	else
	{
		DrawTurnGraphF(location.x - area.width + IMAGE_SHIFT_X_2 - 5, location.y - area.height + IMAGE_SHIFT_Y_2, ImageManager::GetHandle(GetAnimHandle().c_str()), TRUE);
	}

	SK->Draw();
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
	if ((KeyInput::GetKey(KEY_INPUT_UP) || PadInput::OnButton2(XINPUT_BUTTON_A)) && !isAir && jumpCoolTimeCount <= 0)
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

void Player2::Animation()
{
	if (animCnt < 60)
	{
		animCnt++;
	}
	else
	{
		animCnt = 0;
	}

	if (!isShotSkill1)
	{
		animState = Stun;
	}

	//�E��
	if (KeyInput::GetKeyDown(KEY_INPUT_RIGHT) || PadInput::GetLStickRationX2() > STICK_RATIO)
	{
		isReverse = false;

		if (!isAir)
		{
			if (animCnt % 10 == 0)
			{
				animState += 1;
				if (animState > Walk2)
				{
					animState = Walk1;
				}
			}
		}
	}
	//����
	else if (KeyInput::GetKeyDown(KEY_INPUT_LEFT) || PadInput::GetLStickRationX2() < -STICK_RATIO)
	{
		isReverse = true;

		if (!isAir)
		{
			if (animCnt % 10 == 0)
			{
				animState += 1;
				if (animState > Walk2)
				{
					animState = Walk1;
				}
			}
		}
	}
	//��~
	else
	{
		if (!isAir && isShotSkill1)
		{
			animState = Idle;
		}
	}

	//�W�����v
	if (isAir)
	{
		animState = Jump;
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
				vec.x = 10.f;
			}

			//������E�֍s���Ȃ�
			if (GetMax().x > enemyMinX &&
				GetMin().x < enemyMinX)
			{
				location.x = enemyMinX - enemyWidth;
				vec.x = -10.f;
			}
		}
	}
}

bool Player2::GetIsShotSkill1()
{
	if (MAX_SKILL_1_COOL_TIME <= skill1Count)
	{
		isShotSkill1 = true;
	}

	return isShotSkill1;
}

bool Player2::GetIsShotSkill2()
{
	if (MAX_SKILL_2_COOL_TIME <= skill2Count)
	{
		isShotSkill2 = true;
	}

	return isShotSkill2;
}

void Player2::AnimStateToAnimHandle()
{
	if (animState == 0)
	{
		animHandle = IDLE_2;
	}
	else if (animState == 1)
	{
		animHandle = WALK1_2;
	}
	else if (animState == 2)
	{
		animHandle = WALK2_2;
	}
	else if (animState == 3)
	{
		animHandle = JUMP_2;
	}
	else if (animState == 4)
	{
		animHandle = STUN_2;
	}
}

void Player2::Skill(GameMainScene* game)
{
	skill1Count++;
	skill2Count++;

	if (GetIsShotSkill1() == true)
	{
		if (PadInput::OnButton2(XINPUT_BUTTON_B) || KeyInput::GetKey(KEY_INPUT_RSHIFT))
		{
			SK->SKshoot(game);
			skill1Count = 0;
			isShotSkill1 = false;
		}
	}

	SK->UpDate(game);

	if (GetIsShotSkill2())
	{
		if (PadInput::OnButton2(XINPUT_BUTTON_Y) || KeyInput::GetKey(KEY_INPUT_END))
		{
			skill2Count = 0;
			isShotSkill2 = false;
			game->SetIsObstacle(true);
		}
	}

}