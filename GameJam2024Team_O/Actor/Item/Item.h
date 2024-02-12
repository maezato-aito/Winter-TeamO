#pragma once
class Item
{
	float x;
	float Vector;

public:
	Item();
	~Item();

	float Get_Box_x();

	void Update();
	void Draw();

private:
	void Change_Vector();
	void Move_Change();
	void Count_Box();

};

