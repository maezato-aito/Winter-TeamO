#pragma once
#include"../../Collision/BoxCollision.h"
#include"../../common.h"

#define STICK_RATIO     0.2f		//�X�e�B�b�N�̌X������
#define MAX_SPEED		10.f		//�ō����x	
#define GRAVITY			0.8f		//�������x
#define JUMP_POWER		15.f		//�W�����v��

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
	CharaBase()
	{
		vec = {};

		isAir = false;
	}
	//�f�X�g���N�^
	~CharaBase()
	{

	}
};