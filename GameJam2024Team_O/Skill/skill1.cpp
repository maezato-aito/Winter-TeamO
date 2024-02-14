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
		ShootFlg = 1;
		BT->SetLocation({ P2x,P2y });

		if (P2x < game->GetPlayer1()->GetLocation().x)
		{
			BT->Speed = 15;
		}
		if (P2x > game->GetPlayer1()->GetLocation().x)
		{
			BT->Speed = -15;
		}
	}

	if(ShootFlg == 1)
	{
		BT->Update(game);
	}
}

void skill1::Draw()
{
	BT->Draw();
}
