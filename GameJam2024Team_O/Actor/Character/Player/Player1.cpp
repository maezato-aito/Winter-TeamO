#include "Player1.h"
#include "../../../InputControl/Key/KeyInput.h"
#include "../../../InputControl/Pad/PadInput.h"
#include "../../../common.h"

Player1::Player1()
{
	location.x = SCREEN_WIDTH / 2;
	location.x = SCREEN_HEIGHT / 2;

	area.height = 50.f;
	area.width = 50.f;

	jumpCount = 0;
}

Player1::~Player1()
{

}

void Player1::Update()
{
	if (KeyInput::GetKeyDown(KEY_INPUT_D) || PadInput::GetLStickRationX1() > STICK_RATIO)
	{
		if (vec.x < MAX_SPEED)
		{
			vec.x += 2.f;
		}
	}
	else if (KeyInput::GetKeyDown(KEY_INPUT_A) || PadInput::GetLStickRationX1() < -STICK_RATIO)
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

	if ((KeyInput::GetKey(KEY_INPUT_SPACE) || PadInput::OnButton1(XINPUT_BUTTON_A)) && jumpCount < 2)
	{
		vec.y = -JUMP_POWER;
		isAir = true;
		jumpCount++;
	}

	vec.y += GRAVITY;

	location.x += vec.x;
	location.y += vec.y;

	if (GetMax().y > STAGE_FLOOR)
	{
		location.y = STAGE_FLOOR - area.height;
		vec.y = 0.f;
		isAir = false;
		jumpCount = 0;
	}
}

void Player1::Draw() const
{
	DrawBoxAA(location.x, location.y,
		GetMax().x, GetMax().y,
		0xffff00, FALSE, 1.2f);
}