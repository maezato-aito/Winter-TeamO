#include "Item.h"
#include"DxLib.h"
#include"../../Scene/GameMain/GameMainScene.h"
#include"../common.h"

Item::Item()
{
	Initialize();
}

Item::~Item()
{

}

//初期化処理
void Item::Initialize()
{
	//画像の読み込む
	ImageManager::SetImage("Item/Gold Ingot.png");
	ImageManager::SetImage("Item/money.png");

	if (GetRand(100) < 80)
	{
		SetType(common);
	}
	else
	{
		SetType(rare);
	}

	if(type==common)
	{
		score = 950;

		//お金の当たり判定の確認
		area.width = 54;
		area.height = 62;
	}
	else if (type == rare)
	{
		score = 1350;

		//金塊の当たり判定の確認
		area.width = 54;
		area.height = 60;
	}

	//出現させるX座標パターンを取得
	float random_x = (float)(GetRand(10) * 105 + 40);
	float random_y = (float)(GetRand(20) * 20);
	float random_speed = (float)(GetRand(2) * 2 + 2);
	//生成位置の設定
	location.x= random_x;
	location.y=-random_y;
	//速さの設定
	speed = random_speed;
}

void Item::Update(GameMainScene*game)
{
	//位置情報に移動量を加算する
	location.y += speed;
}

void Item::Draw()
{
	//画像の描画
	//DrawBoxAA(location.x, location.y, location.x + area.width, location.y + area.height, 0x00ffff, TRUE);

	if (type == common)
	{
		DrawRotaGraphF(GetCenter().x ,GetCenter().y, 0.11f, 0.0f, ImageManager::GetHandle(Money), TRUE);
	}
	else
	{
		DrawRotaGraphF(GetCenter().x, GetCenter().y, 0.11f, 0.0f, ImageManager::GetHandle(Ingot), TRUE);
	}
}

void Item::Finalize()
{

}

//タイプを取得
int Item::GetType() const
{
	return type;
}


