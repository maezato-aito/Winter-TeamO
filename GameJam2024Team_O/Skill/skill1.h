#pragma once
#include "../Actor/bullet.h"
#include "KeyInput.h"
#include "PadInput.h"
#include"DxLib.h"

class skill1
{
private:
	bullet* b;
public:
	skill1();
	~skill1();

	void UpDate();
	void Draw();
};

