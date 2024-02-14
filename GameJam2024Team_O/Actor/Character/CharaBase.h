#pragma once
#include"../../Collision/BoxCollision.h"
#include"../../common.h"

#define STICK_RATIO     0.2f		//�X�e�B�b�N�̌X������
#define MAX_SPEED		10.f		//�ō����x	
#define GRAVITY			0.8f		//�������x
#define JUMP_POWER		15.f		//�W�����v��
#define JUMP_COOL_TIME  FPS * 0.8f  //�W�����v�̃N�[���^�C��

enum Animation
{
	Idle = 0,
	Walk1,
	Walk2,
	Jump,
	Stun
};

struct Vector2D
{
	float x, y;
};

class CharaBase :public BoxCollision
{
private:

protected:
	Vector2D vec;		//�ړ���

	float jumpCoolTimeCount;    //�W�����v�N�[���^�C���̃J�E���g

	bool isAir;			//�󒆁H
public:
	//�R���X�g���N�^
	CharaBase()
	{
		vec = {};

		jumpCoolTimeCount = 0.f;

		isAir = false;
	}
	//�f�X�g���N�^
	~CharaBase()
	{

	}
};