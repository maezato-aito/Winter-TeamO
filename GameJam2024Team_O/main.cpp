#include"SceneManager/SceneManager.h"
#include"Scene/GameMain/GameMainScene.h"
#include"common.h"
#include "KeyInput.h"
#include "PadInput.h"
#include"SoundManager.h"
/************************************************
* プログラムの開始
*************************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	double nextTime = GetNowCount();	//システム時間の取得

	//Log.txtを出力しない
	SetOutApplicationLogValidFlag(FALSE);

	//タイトル
	SetMainWindowText(GAME_NAME);

	//他の DxLib と競合しないようにウィンドウクラスを設定
	SetMainWindowClassName(GAME_NAME);

	//ウィンドウモードで起動
	ChangeWindowMode(TRUE);

	//常にアクティブ状態にする
	//SetAlwaysRunFlag(TRUE);	

	//画面サイズの設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);

	//DXライブラリの初期化処理
	if (DxLib_Init() == -1)return -1;

	//描画先を裏にする
	SetDrawScreen(DX_SCREEN_BACK);

	try
	{
		SceenManager* sceenManager = new SceenManager(dynamic_cast<SceneBase*>(new GameMainScene()));
		SoundManager::CreateSoundManager();
		//ゲームループ
		while ((ProcessMessage() == 0) &&
			sceenManager->Update() != nullptr &&
			!(CheckHitKey(KEY_INPUT_ESCAPE)))

		{	//画面の初期化
			ClearDrawScreen();

			KeyInput::Update();

			PadInput::Update();

			sceenManager->Draw();

			nextTime += 1.0 / FPS * 1000.0;		//フレームレートの設定＋ミリ単位に合わせる

			if (nextTime > GetNowCount())
			{
				WaitTimer((int)nextTime - GetNowCount());
			}
			//現在のシステム時間を取得
			else
			{
				nextTime = GetNowCount();
			}

			//裏画面の内容を表画面に反映
			ScreenFlip();

		}
	}
	catch (const char* errorLog)
	{
		OutputDebugString(_T(errorLog));

		return -1;
	}

	//DXライブラリ使用の終了処理
	DxLib_End();

	return 0;

}