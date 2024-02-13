#include "Item.h"
#include"DxLib.h"
#include"../../Scene/GameMain/GameMainScene.h"
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
	//出現させるX座標パターンを取得
	float random_x = (float)(GetRand(10) * 105 + 40);
	float random_y = (float)(GetRand(20) * 20);
	float random_speed = (float)(GetRand(2) * 2 + 2);
	//生成位置の設定
	location.x= random_x;
	location.y=-random_y;
	//当たり判定の 
	area.width = 100;
	area.height = 100;
	//速さの設定
	speed = random_speed;
}

void Item::Update(GameMainScene*game)
{
	//位置情報に移動量を加算する
	location.y += speed;
	//if (HitBox(game->GetPlayer1()))
	//{
	//	delete this;
	//}
	
}

void Item::Draw()
{
	//画像の描画
	DrawBoxAA(location.x,location.y, location.x+area.width,location.y+area.height,0x00ffff,TRUE);
}

void Item::Finalize()
{

}

//タイプを取得
int Item::GetType() const
{
	return type;
}


