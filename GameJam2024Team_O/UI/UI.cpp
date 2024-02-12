#include "UI.h".
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

void UI::Update()
{
	if (TimerCount < 60)
	{
		TimerCount++;
	}
	else
	{
		TimerCount = 0;
		Timer --;
	}
	   Count_Change();
}

void UI::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "“ü—Í‰ñ”%d\n", Count);
	DrawFormatString(100, 0, 0xffffff, "§ŒÀŽžŠÔ%f\n", Timer);
}

void UI::Count_Change()
{
	if (KeyInput::GetKey(KEY_INPUT_SPACE)){
		Count++;
	}
}
