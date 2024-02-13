#pragma once
#include "../Collision/BoxCollision.h"
#include "Character/Player/Player2.h"
#include "Character/Player/Player1.h"

class bullet :public BoxCollision
{
private:
	float Speed;
	Player2* P2;
	Player1* P1;

public:

	bullet(float Px, float Py);
	~bullet();

	void Update();
	void Draw();
};

