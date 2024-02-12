#include "Player1.h"
#include"../../common.h"

Player1::Player1()
{
	location.x = SCREEN_WIDTH / 2;
	location.x = SCREEN_HEIGHT / 2;

	area.height = 100.f;
	area.width = 100.f;
}

Player1::~Player1()
{

}

void Player1::Update()
{
	if (KeyInput::GetKeyDown(KEY_INPUT_D) || PadInput::GetLStickRationX() > STICK_RATIO)
	{
		if (vec.x < MAX_ACC)
		{
			vec.x += 2.f;
		}
	}
	else if (KeyInput::GetKeyDown(KEY_INPUT_A) || PadInput::GetLStickRationX() < -STICK_RATIO)
	{
		if (vec.x > -MAX_ACC)
		{
			vec.x -= 2.f;
		}
	}
	else
	{
		vec.x = 0.f;
	}

	vec.y = GRAVITY;

	location.x += vec.x;
	location.y += vec.y;

	if (GetMax().y > STAGE_FLOOR)
	{
		location.y = STAGE_FLOOR - area.height;
		vec.y = 0.f;
	}
}

void Player1::Draw() const
{
	DrawBoxAA(location.x, location.y,
		GetMax().x, GetMax().y,
		0xffff00, FALSE, 1.2f);
}