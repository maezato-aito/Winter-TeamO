#include "Player1.h"
#include"../Scene/GameMain/GameMainScene.h"

Player1::Player1()
{
	ImageManager::SetImage(IDLE_1);
	ImageManager::SetImage(WALK1_1);
	ImageManager::SetImage(WALK2_1);
	ImageManager::SetImage(JUMP_1);
	ImageManager::SetImage(STUN_1);
	SoundManager::SetSE("Damage.mp3");
	SoundManager::SetSE("Jump.mp3");

	SoundManager::SetVolumeSE(Damage, 255);
	SoundManager::SetVolumeSE(Jump, 255);

	location.x = SCREEN_WIDTH / 4;
	location.y = STAGE_FLOOR - 80.f;

	area.height = 80.f;
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
		DrawGraphF(location.x - area.width + IMAGE_SHIFT_X_1, location.y - area.height + IMAGE_SHIFT_Y_1, ImageManager::GetHandle(GetAnimHandle().c_str()), TRUE);
	}
	else
	{
		DrawTurnGraphF(location.x - area.width + IMAGE_SHIFT_X_1 - 10, location.y - area.height + IMAGE_SHIFT_Y_1, ImageManager::GetHandle(GetAnimHandle().c_str()), TRUE);
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
		SoundManager::PlaySoundSE(Jump,false);
		vec.y = -JUMP_POWER;
		isAir = true;
		isLanding = false;
		jumpCount++;
		//�W�����v�̃N�[���^�C���K�v�Ȃ�����
		if (jumpCount >= 2)
		{
			jumpCoolTimeCount = JUMP_COOL_TIME;
		}
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
		isLanding = true;
		jumpCount = 0;
	}

	if (isLanding)
	{
		jumpCount = 0;
		//�W�����v�̃N�[���^�C���K�v�Ȃ�����
		if (jumpCoolTimeCount > 0)
		{
			jumpCoolTimeCount--;
		}
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
		animState = PlayerAnim::Stun;
	}

	if (stanCount < 0)
	{
		animState = PlayerAnim::Idle;
	}

	//�E��
	if ((KeyInput::GetKeyDown(KEY_INPUT_D) || PadInput::GetLStickRationX1() > STICK_RATIO) && !isStan)
	{
		isReverse = false;

		if (!isAir)
		{
			if (animCnt % 10 == 0)
			{
				animState += 1;
				if (animState > PlayerAnim::Walk2)
				{
					animState = PlayerAnim::Walk1;
				}
			}
		}
	}
	//����
	else if ((KeyInput::GetKeyDown(KEY_INPUT_A) || PadInput::GetLStickRationX1() < -STICK_RATIO) && !isStan)
	{
		isReverse = true;

		if (!isAir)
		{
			if (animCnt % 10 == 0)
			{
				animState += 1;
				if (animState > PlayerAnim::Walk2)
				{
					animState = PlayerAnim::Walk1;
				}
			}
		}
	}
	//��~
	else
	{
		if (!isAir && !isStan && isLanding)
		{
			animState = PlayerAnim::Idle;
		}
	}

	//�W�����v
	if (!isLanding && !isStan)
	{
		animState = 3;
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
				location.y = enemyMinY - enemyHeigh;
				vec.y = -10.f;
				isLanding = true;
				isAir = false;
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

void Player1::SetIsStan(const bool flg)
{
	isStan = flg;
	if (isStan)
	{
		SoundManager::PlaySoundSE(Damage);
		stanCount = MAX_STAN_TIME;
	}
}

void Player1::AnimStateToAnimHandle()
{
	if (animState == 0)
	{
		animHandle = IDLE_1;
	}
	else if (animState == 1)
	{
		animHandle = WALK1_1;
	}
	else if (animState == 2)
	{
		animHandle = WALK2_1;
	}
	else if (animState == 3)
	{
		animHandle = JUMP_1;
	}
	else if (animState == 4)
	{
		animHandle = STUN_1;
	}
}