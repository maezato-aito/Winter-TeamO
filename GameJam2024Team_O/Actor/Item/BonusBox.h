#pragma once
#pragma once
#include"../../Collision/BoxCollision.h"
class BonusBox :public BoxCollision
{
	float x;
	float Vector;

public:
	BonusBox();
	~BonusBox();

	float Get_Box_x();

	void Update();
	void Draw();

private:
	void Change_Vector();
	void Move_Change();
	void Count_Box();

};


