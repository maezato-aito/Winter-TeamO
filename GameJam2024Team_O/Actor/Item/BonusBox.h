#pragma once
#pragma once
#include"../../Collision/BoxCollision.h"
#include"../../UI/UI.h"
class GameMainScene;
class BonusBox :public BoxCollision
{
	int count;
	float CountFrame;


public:
	BonusBox(int & i);
	~BonusBox();

	void Update(GameMainScene*);
	void Draw(int & i);

private:
	void Count_Box(GameMainScene*);

};


