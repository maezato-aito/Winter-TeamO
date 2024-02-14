#pragma once
#include"../../Collision/BoxCollision.h"
#include"../../common.h"

#define STICK_RATIO     0.2f		//スティックの傾き割合
#define MAX_SPEED		10.f		//最高速度	
#define GRAVITY			0.8f		//落下速度
#define JUMP_POWER		15.f		//ジャンプ力
#define JUMP_COOL_TIME  FPS * 0.8f  //ジャンプのクールタイム

enum Animation
{
	Idle = 0,
	Walk1,
	Walk2,
	Jump,
	Stun
};

struct Vector2D
{
	float x, y;
};

class CharaBase :public BoxCollision
{
private:

protected:
	Vector2D vec;		//移動量

	float jumpCoolTimeCount;    //ジャンプクールタイムのカウント

	bool isAir;			//空中？
public:
	//コンストラクタ
	CharaBase()
	{
		vec = {};

		jumpCoolTimeCount = 0.f;

		isAir = false;
	}
	//デストラクタ
	~CharaBase()
	{

	}
};