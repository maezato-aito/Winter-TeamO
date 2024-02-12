#pragma once
#include"../../Collision/BoxCollision.h"

#define MAX_ACC		10.f
#define GRAVITY		9.8f

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
	CharaBase();
	//デストラクタ
	~CharaBase();
};