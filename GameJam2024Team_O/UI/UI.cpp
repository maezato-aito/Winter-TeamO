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

//�X�V����
void UI::Update()
{
	Count_Timer();
	Count_Change();
	Count_Timer();
	Count_Score();
	Change_Box();
	Change_Vector();
}

//�`�揈��
void UI::Draw()
{
	DrawFormatString(0, 0, 0xffffff, "���͉�%d\n", Count); //���͉񐔃J�E���g
	DrawFormatString(100, 0, 0xffffff, "��������%f\n", Timer); //�������ԃJ�E���g
	DrawFormatString(1000, 0, 0xffffff, "SCORE%f\n",Score); //�X�R�A�̕\��
	DrawBoxAA(x1, y1, x1+100, y1+100, 0xfffffa, TRUE); //�{�[�i�X�{�b�N�X
}

void UI::Count_Change() //���̓J�E���g�����i�X�y�[�X�j
{
	if (KeyInput::GetKey(KEY_INPUT_SPACE)){
		Count++;
	}
}

void UI::Count_Timer() //�^�C�}�[�J�E���g����
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

void UI::Count_Score() //�X�R�A�J�E���g����
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

void UI::Change_Box() //�{�b�N�X�ړ�����
{
	x1 += Move_Box;
}

void UI::Change_Vector()//�{�b�N�X�ړ������ύX����
{
	if (x1 >= 1100 || x1 <= 100)
	{
		Move_Box *= -1;
	}
}