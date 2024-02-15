#pragma once
#include "../Collision/BoxCollision.h"
#include "../common.h"
class Floor:public BoxCollision
{
private:
	int type;
public:
	Floor();
	~Floor();

	void Update(int a);
	void Draw();
};

