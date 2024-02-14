#pragma once
class UI
{
private:
	int count;
	int Timer;
	int TimerCount;
	float Score;
	float x1;
	float y1;

public:
	UI();
	~UI();

	void Update();
	void Draw();
	void Count_Score(int item);
	int Get_Timer();
	float Get_Score();

private:
	void Count_Timer();
};

