#pragma once
#include "../Collision/BoxCollision.h"

class GameMainScene;

class bullet :public BoxCollision
{
private:

public:

	bullet();
	~bullet();

	void initialize();

	void Update(GameMainScene* game);
	void Draw();
	
	float Speed;
};

