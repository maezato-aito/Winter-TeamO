#pragma once
#include<map>
#include<string>

class FontManager
{
private:
	static FontManager* manager;				//オブジェクト

	std::map<int, int>font;						//連想配列font
public:
	//コンストラクタ
	FontManager() {};

	//デストラクタ
	~FontManager() {};

	//FontManagerの作成
	static void CreateFontManagerr();

	//FontManagerの削除
	static void DeleteFontManagerr();

	//連想配列に格納されたフォントのハンドルを取得する
	static int GetHandle(int size) { return manager->font[size]; }

	//ハンドルにフォントを設定する
	static void SetFont(int size);
};

