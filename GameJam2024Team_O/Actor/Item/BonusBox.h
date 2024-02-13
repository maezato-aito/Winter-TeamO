#pragma once
#pragma once
#include"../../Collision/BoxCollision.h"
class BonusBox :public BoxCollision
{
	float x;
	float y;
	int count;
	float CountFrame;

public:
	BonusBox();
	~BonusBox();



	void Update();
	void Draw();

private:
	void Count_Box();

};


