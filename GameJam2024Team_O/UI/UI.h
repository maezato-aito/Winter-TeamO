#pragma once
class UI
{
private:
	int Count;
	int count;
	float Timer;
	float TimerCount;
	float Score;
	float x1;
	float y1;
	float Move_Box;

public:
	UI();
	~UI();

	void Update();
	void Draw();

private:
	void Count_Change();
	void Count_Timer();
	void Count_Score();
	void Change_Box();
	void Change_Vector();
};

