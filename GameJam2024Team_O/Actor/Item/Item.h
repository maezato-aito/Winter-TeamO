#pragma once
#include"../../Collision/BoxCollision.h"
class Item:public BoxCollision 
{

public:
	Item();
	~Item();

	void Update();
	void Draw();
};

