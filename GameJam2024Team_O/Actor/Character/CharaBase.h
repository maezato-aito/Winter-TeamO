#pragma once
#include"../../Collision/BoxCollision.h"
#include"../../common.h"

#define STICK_RATIO     0.2f		//スティックの傾き割合
#define MAX_SPEED		10.f		//最高速度	
#define GRAVITY			0.8f		//落下速度
#define JUMP_POWER		15.f		//ジャンプ力
#define JUMP_COOL_TIME  FPS * 0.8f  //ジャンプのクールタイム

class GameMainScene;

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
	Vector2D vec;				//移動量
	std::string animHandle;     //アニメーションハンドル

	int animState;              //アニメーション状態
	int animCnt;                //アニメーションカウント

	float jumpCoolTimeCount;    //ジャンプクールタイムのカウント

	bool isLanding;				//着地している？
	bool isAir;					//空中？
	bool isReverse;				//反転する？
public:
	//コンストラクタ
	CharaBase();

	//デストラクタ
	~CharaBase();

	//地面との当たり判定
	void GroundCollision(GameMainScene* game, int arrayNum);

	std::string GetAnimHandle() const
	{
		return animHandle;
	}

	void SetIsReverse(const bool flg)
	{
		isReverse = flg;
	}
};