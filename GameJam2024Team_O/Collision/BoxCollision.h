#pragma once

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
	Location location;
	Area area;

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
	bool HitBox(const BoxCollision* box_collider)const;

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