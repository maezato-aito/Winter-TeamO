#pragma once
#include"DxLib.h"

struct Location
{
	float x, y;
};

struct Area
{
	float width, height;
};

class BoxCollision
{
protected:
	Location location;		//座標
	Area area;				//大きさ

public:
	//コンストラクタ
	BoxCollision(Location location = Location{}, Area area = Area{})
	{
		this->location = location;	//0で初期化
		this->area = area;			//0で初期化
	}

	//デストラクタ
	~BoxCollision() {};

	//BoxColliderとの当たり判定
	bool HitBox(const BoxCollision* collision)const
	{
		bool ret = false;		//返り値

		//自分の当たり判定の範囲
		float myX[2];
		float myY[2];

		//相手の当たり判定の範囲
		float subX[2];
		float subY[2];

		//自分の当たり判定の範囲の計算
		myX[0] = location.x;
		myY[0] = location.y;
		myX[1] = myX[0] + area.width;
		myY[1] = myY[0] + area.height;

		//相手の当たり判定の範囲の計算
		subX[0] = collision->GetLocation().x;
		subY[0] = collision->GetLocation().y;
		subX[1] = subX[0] + collision->GetArea().width;
		subY[1] = subY[0] + collision->GetArea().height;

		if ((myX[0] <= subX[1]) &&
			(subX[0] <= myX[1]) &&
			(myY[0] <= subY[1]) &&
			(subY[0] <= myY[1])) //当たり判定
		{
			ret = true;
		}
		return ret;
	}

	//左上の座標を取得
	Location GetMin()const
	{
		return Location{ location.x,location.y };
	}
	//右下の座標を取得
	Location GetMax()const
	{
		return Location{ location.x + area.width,location.y + area.height };
	}
	//中心座標を取得
	Location GetCenter()const
	{
		return Location{ location.x + area.width / 2,location.y + area.height / 2 };
	}

	//locationの取得
	Location GetLocation()const { return location; }

	//areaの取得
	Area GetArea()const { return area; }

	//ロケーション設定
	void SetLocation(Location location)
	{
		this->location = location;
	}
};