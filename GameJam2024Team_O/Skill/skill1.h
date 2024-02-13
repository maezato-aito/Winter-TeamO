#pragma once
#include "../Actor/bullet.h"
#include "KeyInput.h"
#include "PadInput.h"
#include"DxLib.h"

class GameMainScene;

class bullet;

class skill1
{
private:
	bool ShootFlg;
	bullet* BT;
	float P2x;
	float P2y;

public:
	skill1();
	~skill1();

	void UpDate(GameMainScene* game);
	void Draw();
};

