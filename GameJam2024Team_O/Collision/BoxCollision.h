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
		float my_x[2];
		float my_y[2];

		//相手の当たり判定の範囲
		float sub_x[2];
		float sub_y[2];

		//自分の当たり判定の範囲の計算
		my_x[0] = location.x;
		my_y[0] = location.y;
		my_x[1] = my_x[0] + area.width;
		my_y[1] = my_y[0] + area.height;

		//相手の当たり判定の範囲の計算
		sub_x[0] = collision->GetLocation().x;
		sub_y[0] = collision->GetLocation().y;
		sub_x[1] = sub_x[0] + collision->GetArea().width;
		sub_y[1] = sub_y[0] + collision->GetArea().height;

		if ((my_x[0] <= sub_x[1]) &&
			(sub_x[0] <= my_x[1]) &&
			(my_y[0] <= sub_y[1]) &&
			(sub_y[0] <= my_y[1])) //当たり判定
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
};