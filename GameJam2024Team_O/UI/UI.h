#pragma once
class UI
{
private:
	int Count;
	float Timer;
	float TimerCount;

public:
	UI();
	~UI();

	void Update();
	void Draw();

private:
	void Count_Change();
	void Count_Timer();
};

