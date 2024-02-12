#include "UI.h"
#include "DxLib.h"
#include "../InputControl/Key/KeyInput.h"
#include "../InputControl/Pad/PadInput.h"
#include "../common.h"

UI::UI()
{
	Count = 0;
	Timer = 60;
	TimerCount = 0;
}

UI::~UI()
{

}

//更新処理
void UI::Update()
{
	Count_Timer();
	Count_Change();
}

//描画処理
void UI::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "入力回数%d\n", Count); //入力回数カウント
	DrawFormatString(100, 0, 0xffffff, "制限時間%f\n", Timer); //制限時間カウント
}

void UI::Count_Change()
{
	if (KeyInput::GetKey(KEY_INPUT_SPACE)){
		Count++;
	}
}

void UI::Count_Timer()
{
	if (TimerCount < 60)
	{
		TimerCount++;
	}
	else
	{
		TimerCount = 0;
		Timer--;
	}
}
