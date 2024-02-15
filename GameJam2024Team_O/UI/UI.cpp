#include "UI.h"
#include "DxLib.h"
#include "../common.h"
#include"../Utility/FontManager.h"

UI::UI()
{
	count = 0;
	Timer = 60;
	TimerCount = 0;
	Score = 0;
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
	if (Timer >= BONUS_TIME)
	{
		DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 32, 0, 0xffffff, FontManager::GetHandle(64), "%d\n", Timer);
	}
	else
	{
		DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 10, 0, 0xff0000, FontManager::GetHandle(64), "%d\n", Timer);
	}
	DrawFormatStringToHandle(974, 0, 0xffffff, FontManager::GetHandle(32), "�X�R�A:%0.f", Score);
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

float UI::Get_Score()
{
	return Score;
}



