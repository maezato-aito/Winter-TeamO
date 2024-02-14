#pragma once
#include "../Collision/BoxCollision.h"
#include "Character/Player/Player2.h"

#define BULLET_IMAGE_SHIFT_X	25
#define BULLET_IMAGE_SHIFT_Y	35

#define BULLET "Player/Player2 Skill.png"

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

