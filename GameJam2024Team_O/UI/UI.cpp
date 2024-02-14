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

//�X�V����
void UI::Update()
{
	Count_Timer();
	Count_Timer();

}

//�`�揈��
void UI::Draw()
{
	DrawFormatString(550, 0, 0xffffff, "��������%d\n", Timer); //�������ԃJ�E���g
	DrawFormatString(1000, 0, 0xffffff, "SCORE%f\n",Score); //�X�R�A�̕\��
}



void UI::Count_Timer() //�^�C�}�[�J�E���g����
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

void UI::Count_Score(int item) //�X�R�A�J�E���g����
{
	Score += item;
}

int UI::Get_Timer()
{
	return Timer;
}
