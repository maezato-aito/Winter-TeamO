#pragma once
#pragma once
#include"../../Collision/BoxCollision.h"
#include"../../UI/UI.h"
class GameMainScene;
class BonusBox :public BoxCollision
{
	float Count;
	float CountFrame;

public:
	BonusBox(int& i);
	~BonusBox();

	void Update(GameMainScene*);
	void Draw(int& i);

	float Get_Count();

private:
	void Count_Box(GameMainScene*);

};
