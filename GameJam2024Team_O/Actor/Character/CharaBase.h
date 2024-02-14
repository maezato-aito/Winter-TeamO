#pragma once
#include"../../Collision/BoxCollision.h"
#include"../../common.h"

#define STICK_RATIO     0.2f		//�X�e�B�b�N�̌X������
#define MAX_SPEED		10.f		//�ō����x	
#define GRAVITY			0.8f		//�������x
#define JUMP_POWER		15.f		//�W�����v��
#define JUMP_COOL_TIME  FPS * 0.8f  //�W�����v�̃N�[���^�C��

class GameMainScene;

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
	Vector2D vec;				//�ړ���
	std::string animHandle;     //�A�j���[�V�����n���h��

	int animState;              //�A�j���[�V�������
	int animCnt;                //�A�j���[�V�����J�E���g

	float jumpCoolTimeCount;    //�W�����v�N�[���^�C���̃J�E���g

	bool isLanding;				//���n���Ă���H
	bool isAir;					//�󒆁H
	bool isReverse;				//���]����H
public:
	//�R���X�g���N�^
	CharaBase();

	//�f�X�g���N�^
	~CharaBase();

	//�n�ʂƂ̓����蔻��
	void GroundCollision(GameMainScene* game, int arrayNum);

	std::string GetAnimHandle() const
	{
		return animHandle;
	}

	void SetIsReverse(const bool flg)
	{
		isReverse = flg;
	}
};