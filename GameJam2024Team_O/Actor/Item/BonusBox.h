#pragma once
#pragma once
#include"../../Collision/BoxCollision.h"
#include"../../UI/UI.h"

#define Bonusbox "Item/bonusbox.png"
#define Openbox "Item/openbox.png"
#define Effect "Item/effect.png"

class GameMainScene;
class BonusBox :public BoxCollision
{
	float Count;
	float CountFrame;
	bool isOpen;

public:
	BonusBox(int& i);
	~BonusBox();

	void Update(GameMainScene*);
	void Draw(int& i);

	float Get_Count();

private:
	void Count_Box(GameMainScene*);

};
