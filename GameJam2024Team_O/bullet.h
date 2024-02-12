#pragma once

struct Location
{
	float x, y;//弾の中心座標
};

struct HitBox
{
	float x1, y1;//当たり判定左上の座標
	float x2, y2;//当たり判定右下の座標
};

class bullet
{
public:
	Location l;
	HitBox h;
	float velocity; //銃弾の移動速度

	bullet();
	~bullet();

	void Update();
	void Draw();
};

