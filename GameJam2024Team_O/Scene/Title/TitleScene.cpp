#include "TitleScene.h"
#include"../Scene/GameMain/GameMainScene.h"
#include"../Scene/End/EndScene.h"
#include"../Scene/Help/HelpScene.h"
#include"../common.h"
#include"../Utility/FontManager.h"

TitleScene::TitleScene()
{
	SoundManager::SetBGM("Title.mp3");
	ImageManager::SetImage("Stage/Start Stage.png");
	ImageManager::SetImage("Stage/Start Stage1.png");
	ImageManager::SetImage("Stage/Start Stage2.png");
	ImageManager::SetImage("UI/Pin.png");

	fpsCnt = 0;
	imageCnt = 0;
	cursorNum = 0;
	interval = 0;

	location = {};

	isSelect = false;
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

	if (isSelect)
	{
		if (fpsCnt < 30)
		{
			fpsCnt++;
		}
		else
		{
			fpsCnt = 0;
			imageCnt++;
		}
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
			isSelect = true;
		}
		if (imageCnt > 2)
		{
			return new GameMainScene();
		}
	}
	else if (cursorNum == 1)
	{
		//ヘルプへ
		if (PadInput::OnButton1(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			isSelect = true;
		}
		if (imageCnt > 2)
		{
			return new HelpScene();
		}
	}
	else
	{
		//エンド画面へ
		if (PadInput::OnButton1(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			isSelect = true;
		}
		if (imageCnt > 2)
		{
			return new EndScene();
		}
	}

	return this;
}

void TitleScene::Draw() const
{
	if (imageCnt == 0)
	{
		DrawGraph(0, 0, ImageManager::GetHandle("Stage/Start Stage.png"), TRUE);
	}
	else if (imageCnt == 1)
	{
		DrawGraph(0, 0, ImageManager::GetHandle("Stage/Start Stage1.png"), TRUE);
	}
	else if (imageCnt == 2)
	{
		DrawGraph(0, 0, ImageManager::GetHandle("Stage/Start Stage2.png"), TRUE);
	}
	//カーソル
	DrawRotaGraph(480, 400 + location.y, 0.2, 0.78, ImageManager::GetHandle("UI/Pin.png"), TRUE);

	DrawStringToHandle(SCREEN_WIDTH / 2 - 100, 380, "スタート", 0xffffff, FontManager::GetHandle(32), 0x000000);

	DrawStringToHandle(SCREEN_WIDTH / 2 - 100, 430, "ヘルプ", 0xffffff, FontManager::GetHandle(32), 0x000000);

	DrawStringToHandle(SCREEN_WIDTH / 2 - 100, 480, "エンド", 0xffffff, FontManager::GetHandle(32), 0x000000);
}
