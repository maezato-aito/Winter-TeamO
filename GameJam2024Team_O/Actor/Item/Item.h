#pragma once
#include"../../Collision/BoxCollision.h"
class GameMainScene;
enum
{
	common,
	rare
};
class Item:public BoxCollision 
{
private:
	int type;        //タイプ
	int image;       //画像
	float speed;     //速さ
	float scoa;      //

public:
	Item();
	~Item();

	void Initialize();       //初期化処理
	void Update(GameMainScene*);           //更新処理
	void Draw();             //描画処理
	void Finalize();         //終了時処理

	int GetType() const;     //タイプ取得
	void SetType(int type)
	{
		this->type = type;
	}
	float GetScoa()
	{
		return scoa;
	}
};

