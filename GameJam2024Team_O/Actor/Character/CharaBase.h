#pragma once
#include"../../Collision/BoxCollision.h"

#define MAX_SPEED		10.f		//最高速度	
#define GRAVITY			0.8f		//落下速度
#define JUMP_POWER		10.f			//ジャンプ力

struct Vector2D
{
	float x, y;
};

class CharaBase :public BoxCollision
{
private:

protected:
	Vector2D vec;		//移動量

	bool isAir;			//空中？
public:
	//コンストラクタ
	CharaBase()
	{
		vec = {};

		isAir = false;
	}
	//デストラクタ
	~CharaBase()
	{

	}
};