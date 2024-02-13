#include "skill1.h"

skill1::skill1()
{
	ShootFlg = 0;
	BT = new bullet();
}

skill1::~skill1()
{

}

void skill1::UpDate()
{
	if (KeyInput::GetKeyDown(KEY_INPUT_SPACE))
	{
		ShootFlg = 1;
	}

	if(ShootFlg == 1)
	{
		BT->Update();
	}
	
}

void skill1::Draw()
{
	BT->Draw();
}
