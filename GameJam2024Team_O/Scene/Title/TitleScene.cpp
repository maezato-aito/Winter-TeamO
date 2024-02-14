#include "TitleScene.h"
#include"../Scene/GameMain/GameMainScene.h"
#include"../Scene/End/EndScene.h"
#include"../Scene/Help/HelpScene.h"
#include"PadInput.h"
#include"KeyInput.h"
#include"../common.h"

TitleScene::TitleScene()
{
	cursorNum = 0;
	interval = 0;

	location = {};
}

TitleScene::~TitleScene()
{

}

SceneBase* TitleScene::Update()
{
	location.y = cursorNum * 50;

	if (interval < 15)
	{
		interval++;
	}

	if ((KeyInput::GetKey(KEY_INPUT_W) || PadInput::GetLStickRationY1() > 0.2) && interval >= 15)
	{
		cursorNum--;
		interval = 0;

		if (cursorNum < 0)
		{
			cursorNum = 2;
		}
	}
	else if ((KeyInput::GetKeyDown(KEY_INPUT_S) || PadInput::GetLStickRationY1() < -0.2) && interval >= 15)
	{
		cursorNum++;
		interval = 0;

		if (cursorNum > 2)
		{
			cursorNum = 0;
		}
	}

	if (cursorNum == 0)
	{
		//�Q�[�����C����
		if (PadInput::OnButton1(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			return new GameMainScene();
		}
	}
	else if (cursorNum == 1)
	{
		//�w���v��
		if (PadInput::OnButton1(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			return new HelpScene();
		}
	}
	else
	{
		//�G���h��ʂ�
		if (PadInput::OnButton1(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			return new EndScene();
		}
	}

	return this;
}

void TitleScene::Draw() const
{

	//�J�[�\��
	DrawTriangle(480, 400 + location.y, 450, 380 + location.y, 450, 420 + location.y, 0xffffff, TRUE);

	SetFontSize(36);

	DrawFormatString(SCREEN_WIDTH / 2 - 100, 180, 0xffffff, "%s", GAME_NAME);

	DrawString(SCREEN_WIDTH / 2 - 100, 380, "�X�^�[�g", 0xffffff);

	DrawString(SCREEN_WIDTH / 2 - 100, 430, "�w���v", 0xffffff);

	DrawString(SCREEN_WIDTH / 2 - 100, 480, "�I��", 0xffffff);

	SetFontSize(16);

}
