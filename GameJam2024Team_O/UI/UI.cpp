#include "UI.h"
#include "DxLib.h"
#include "KeyInput.h"
#include "PadInput.h"
#include "../common.h"

UI::UI()
{
	count = 0;
	Timer = 60;
	TimerCount = 0;
	Score = 0;
	x1 = 630.0f;
	y1 = 310.0f;
	Move_Box = 30.0f;
}

UI::~UI()
{

}

//更新処理
void UI::Update()
{
	Count_Timer();
	Count_Timer();

}

//描画処理
void UI::Draw()
{
	DrawFormatString(550, 0, 0xffffff, "制限時間%d\n", Timer); //制限時間カウント
	DrawFormatString(1000, 0, 0xffffff, "SCORE%f\n",Score); //スコアの表示
}



void UI::Count_Timer() //タイマーカウント処理
{
	if (TimerCount < 120)
	{
		TimerCount++;
	}
	else
	{
		TimerCount = 0;

		if (Timer > 0)
		{
			Timer--;
		}
		
	}
}

void UI::Count_Score(int item) //スコアカウント処理
{
	Score += item;
}

int UI::Get_Timer()
{
	return Timer;
}
