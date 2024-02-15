#include "ResultScene.h"
#include"../Utility/FontManager.h"
#include"../common.h"

ResultScene::ResultScene(float score, float count)
{
	SoundManager::SetBGM("Result.mp3");
	num = 0;

	fpsCnt = 0.f;
	this->score = score;
	this->bonusCount = count;
}

ResultScene::~ResultScene()
{

}

SceneBase* ResultScene::Update()
{
	SoundManager::PlaySoundBGM(Result);
	if (num == 4)
	{
		SoundManager::PlaySoundBGM(Player,false);
	}
	if (fpsCnt < FPS * 1.5)
	{
		fpsCnt++;
	}
	else
	{
		fpsCnt = 0.f;
		if (num < 4)
		{
			num++;
		}
	}

	if (num >= 4)
	{
		if (PadInput::OnButton1(XINPUT_BUTTON_A) || PadInput::OnButton2(XINPUT_BUTTON_A) || KeyInput::GetKey(KEY_INPUT_SPACE))
		{
			SoundManager::StopSoundBGMs();
			return new TitleScene();
		}
	}

	return this;
}

void ResultScene::Draw() const
{
	DrawGraph(0, 0, ImageManager::GetHandle("Stage/Main Stage.png"), TRUE);

	DrawBox(100, 100,1180, 620, 0x888888, TRUE);
	DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 128, 100, 0xffffff, FontManager::GetHandle(64), "リザルト");
	if (num == 1)
	{
		DrawFormatStringToHandle(SCREEN_WIDTH / 2-200, 200, 0xffffff, FontManager::GetHandle(32), "獲得したスコア:%0.f", score);
	}
	if (num == 2)
	{
		DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 200, 200, 0xffffff, FontManager::GetHandle(32), "獲得したスコア:%0.f", score);

		DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 164, 300, 0xffffff, FontManager::GetHandle(32), "ボーナス倍率:%0.f", bonusCount);
	}
	if (num == 3)
	{
		DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 200, 200, 0xffffff, FontManager::GetHandle(32), "獲得したスコア:%0.f", score);

		DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 164, 300, 0xffffff, FontManager::GetHandle(32), "ボーナス倍率:%0.f", bonusCount);

		DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 131, 500, 0xffffff, FontManager::GetHandle(32), "合計スコア:%0.f", score * bonusCount);
	}
	if (num == 4)
	{
		DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 200, 200, 0xffffff, FontManager::GetHandle(32), "獲得したスコア:%0.f", score);

		DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 164, 300, 0xffffff, FontManager::GetHandle(32), "ボーナス倍率:%0.f", bonusCount);

		DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 131, 500, 0xffffff, FontManager::GetHandle(32), "合計スコア:%0.f", score * bonusCount);
		
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
		DrawBox(0, SCREEN_HEIGHT / 4, SCREEN_WIDTH, (SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 4), 0x000000, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		if (QUOTA_SCORE < score * bonusCount)
		{
			DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 300, SCREEN_HEIGHT / 2 - 32, 0xffffff, FontManager::GetHandle(64), "プレイヤー1の勝利！\n");
		}
		else
		{
			DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 300, SCREEN_HEIGHT / 2 - 32, 0xffffff, FontManager::GetHandle(64), "プレイヤー2の勝利！\n");
		}
	}
}
