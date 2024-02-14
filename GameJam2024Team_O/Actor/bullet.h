#pragma once
#include "../Collision/BoxCollision.h"
#include "Character/Player/Player2.h"

class GameMainScene;

class bullet :public BoxCollision
{
private:
	float Speed;
	bool isflg;

public:

	bullet();
	~bullet();

	void initialize();

	void Update(GameMainScene* game);
	void Draw();

	void MoveBullet(GameMainScene* game);
	bool OnFlg();
	bool OffFlg();
};

