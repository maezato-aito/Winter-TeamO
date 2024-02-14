#pragma once
#include<map>
#include<string>

class ImageManager
{
private:
	static ImageManager* manager;				//オブジェクト

	std::map<std::string, int>image;			//連想配列image
public:
	//コンストラクタ
	ImageManager() {};

	//デストラクタ
	~ImageManager() {};

	//ImageManagerの作成
	static void CreateImageManager();

	//ImageManagerの削除
	static void DeleteImageManager();

	//連想配列に格納されたImageのサウンドハンドルを取得する
	static int GetHandle(const char* fileName) { return manager->image[fileName]; }

	//サウンドハンドルにImageを設定する
	static void SetImage(const char* fileName);
};

