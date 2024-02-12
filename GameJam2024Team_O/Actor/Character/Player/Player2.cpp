#include "Player2.h"
#include "../../../InputControl/Key/KeyInput.h"
#include "../../../InputControl/Pad/PadInput.h"
#include "../../../common.h"

Player2::Player2()
{
	location.x = SCREEN_WIDTH / 2;
	location.x = SCREEN_HEIGHT / 2;

	area.height = 50.f;
	area.width = 50.f;
}

Player2::~Player2()
{

}

void Player2::Update()
{
	if (KeyInput::GetKeyDown(KEY_INPUT_D) || PadInput::GetLStickRationX2() > STICK_RATIO)
	{
		if (vec.x < MAX_SPEED)
		{
			vec.x += 2.f;
		}
	}
	else if (KeyInput::GetKeyDown(KEY_INPUT_A) || PadInput::GetLStickRationX2() < -STICK_RATIO)
	{
		if (vec.x > -MAX_SPEED)
		{
			vec.x -= 2.f;
		}
	}
	else
	{
		vec.x = 0.f;
	}

	if ((KeyInput::GetKey(KEY_INPUT_SPACE) || PadInput::OnButton2(XINPUT_BUTTON_A)) && !isAir)
	{
		vec.y = -JUMP_POWER;
		isAir = true;
	}

	vec.y += GRAVITY;

	location.x += vec.x;
	location.y += vec.y;

	if (GetMax().y > STAGE_FLOOR)
	{
		location.y = STAGE_FLOOR - area.height;
		vec.y = 0.f;
		isAir = false;
	}

}

void Player2::Draw() const
{
	DrawBoxAA(location.x, location.y,
		GetMax().x, GetMax().y,
		0x00ffff, FALSE, 1.2f);
}
