#include "FontManager.h"
#include"DxLib.h"

FontManager* FontManager::manager = nullptr;

void FontManager::CreateFontManagerr()
{
	//オブジェクトが作成されていないならオブジェクトを作成する
	if (manager == nullptr)
	{
		manager = new FontManager();
	}

	std::string path = "Resource/Fonts/mihiPixelmoji_v1.1.ttf";

	if (AddFontResourceEx(path.c_str(), FR_PRIVATE, NULL) < 0)
	{
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	};

	SetFont(128);
	SetFont(64);
	SetFont(32);
	SetFont(16);
}

void FontManager::DeleteFontManagerr()
{
	InitFontToHandle();
	delete manager;
	manager = nullptr;
}

void FontManager::SetFont(int size)
{
	//ローカル変数iteratorにsizeキーの検索結果を代入
	auto iterator = manager->font.find(size);

	//設定されていない場合
	if (iterator == manager->font.end())
	{
		//キーに読みこむ
		manager->font[size] = CreateFontToHandle("みひらめフォント", size, 10, DX_FONTTYPE_EDGE);
	}
}
