#include "TitleScene.h"
#include"../Scene/GameMain/GameMainScene.h"
#include"../Scene/End/EndScene.h"
#include"../Scene/Help/HelpScene.h"
#include"../common.h"
#include"../Utility/FontManager.h"

TitleScene::TitleScene()
{
	SoundManager::SetBGM("Title.mp3");
	cursorNum = 0;
	interval = 0;

	location = {};
}

TitleScene::~TitleScene()
{

}

SceneBase* TitleScene::Update()
{
	SoundManager::PlaySoundBGM(Title);

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
		//ゲームメインへ
		if (PadInput::OnButton1(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			return new GameMainScene();
		}
	}
	else if (cursorNum == 1)
	{
		//ヘルプへ
		if (PadInput::OnButton1(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			return new HelpScene();
		}
	}
	else
	{
		//エンド画面へ
		if (PadInput::OnButton1(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			return new EndScene();
		}
	}

	return this;
}

void TitleScene::Draw() const
{
	//カーソル
	DrawTriangle(480, 400 + location.y, 450, 380 + location.y, 450, 420 + location.y, 0xffffff, TRUE);

	DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 200, 180, 0xffffff, FontManager::GetHandle(64), "%s\n", GAME_NAME);

	DrawStringToHandle(SCREEN_WIDTH / 2 - 100, 380, "スタート", 0xffffff, FontManager::GetHandle(32), 0x000000);

	DrawStringToHandle(SCREEN_WIDTH / 2 - 100, 430, "ヘルプ", 0xffffff, FontManager::GetHandle(32), 0x000000);

	DrawStringToHandle(SCREEN_WIDTH / 2 - 100, 480, "エンド", 0xffffff, FontManager::GetHandle(32), 0x000000);
}
