#include "UI.h"
#include "DxLib.h"
#include "KeyInput.h"
#include "PadInput.h"
#include "../common.h"

UI::UI()
{
	Count = 0;
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
	Count_Change();
	Count_Timer();
	Count_Score();
	Change_Box();
	Change_Vector();
}

//描画処理
void UI::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "入力回数%d\n", Count); //入力回数カウント
	DrawFormatString(100, 0, 0xffffff, "制限時間%f\n", Timer); //制限時間カウント
	DrawFormatString(1000, 0, 0xffffff, "SCORE%f\n",Score); //スコアの表示
	DrawBoxAA(x1, y1, x1+100, y1+100, 0xfffffa, TRUE); //ボーナスボックス
}

void UI::Count_Change() //入力カウント処理（スペース）
{
	if (KeyInput::GetKey(KEY_INPUT_SPACE)){
		Count++;
	}
}

void UI::Count_Timer() //タイマーカウント処理
{
	if (TimerCount < 60)
	{
		TimerCount++;
	}
	else
	{
		TimerCount = 0;

		if (Timer >= 1)
		{
			Timer--;
		}
		
	}
}

void UI::Count_Score() //スコアカウント処理
{
	if (x1 >= 700)
	{
		if (count == 1)
		{
			Score++;
		}
		count = 0;
	}
	else
	{
		count = 1;
	}
}

void UI::Change_Box() //ボックス移動処理
{
	x1 += Move_Box;
}

void UI::Change_Vector()//ボックス移動方向変更処理
{
	if (x1 >= 1100 || x1 <= 100)
	{
		Move_Box *= -1;
	}
}