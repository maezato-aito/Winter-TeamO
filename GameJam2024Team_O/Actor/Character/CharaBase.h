#pragma once
#include"../../Collision/BoxCollision.h"

#define MAX_ACC		10.f
#define GRAVITY		9.8f

struct Vector2D
{
	float x, y;
};

class CharaBase :public BoxCollision
{
private:

protected:
	Vector2D vec;		//�ړ���

	bool isAir;			//�󒆁H
public:
	//�R���X�g���N�^
	CharaBase();
	//�f�X�g���N�^
	~CharaBase();
};