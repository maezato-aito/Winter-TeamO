#pragma once
#include "../Collision/BoxCollision.h"

class GameMainScene;

class bullet :public BoxCollision
{
private:
	float Speed;


	float StartBulletx;
	float StartBullety;

public:

	bullet();
	~bullet();

	void initialize();

	void Update(GameMainScene* game);
	void Draw();
};

