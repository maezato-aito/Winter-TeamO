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

//�X�V����
void UI::Update()
{
	Count_Timer();
	Count_Change();
}

//�`�揈��
void UI::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "���͉�%d\n", Count); //���͉񐔃J�E���g
	DrawFormatString(100, 0, 0xffffff, "��������%f\n", Timer); //�������ԃJ�E���g
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
