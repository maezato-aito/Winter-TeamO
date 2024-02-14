#include "skill1.h"
#include "../Scene/GameMain/GameMainScene.h"
skill1::skill1()
{
	ShootFlg = 0;
	BT = new bullet();
}

skill1::~skill1()
{

}

void skill1::UpDate(GameMainScene* game)
{
	P2x = game->GetPlayer2()->GetCenter().x;
	P2y = game->GetPlayer2()->GetCenter().y;


	if (PadInput::OnButton2(XINPUT_BUTTON_B))
	{
		flg();
		BT->SetLocation({ P2x,P2y });
		BT->MoveBullet(game);
	}

	if(flg() == true)
	{
		BT->Update(game);
	}
}

void skill1::Draw()
{
	BT->Draw();
}

bool skill1::flg()
{
	return true;
}
