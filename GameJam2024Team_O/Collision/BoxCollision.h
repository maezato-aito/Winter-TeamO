#pragma once
#include"DxLib.h"

struct Location
{
	float x, y;
};

struct Area
{
	float width, height;
};

class BoxCollision
{
protected:
	Location location;		//���W
	Area area;				//�傫��

public:
	//�R���X�g���N�^
	BoxCollision(Location location = Location{}, Area area = Area{})
	{
		this->location = location;	//0�ŏ�����
		this->area = area;			//0�ŏ�����
	}

	//�f�X�g���N�^
	~BoxCollision() {};

	//BoxCollider�Ƃ̓����蔻��
	bool HitBox(const BoxCollision* collision)const
	{
		bool ret = false;		//�Ԃ�l

		//�����̓����蔻��͈̔�
		float myX[2];
		float myY[2];

		//����̓����蔻��͈̔�
		float subX[2];
		float subY[2];

		//�����̓����蔻��͈̔͂̌v�Z
		myX[0] = location.x;
		myY[0] = location.y;
		myX[1] = myX[0] + area.width;
		myY[1] = myY[0] + area.height;

		//����̓����蔻��͈̔͂̌v�Z
		subX[0] = collision->GetLocation().x;
		subY[0] = collision->GetLocation().y;
		subX[1] = subX[0] + collision->GetArea().width;
		subY[1] = subY[0] + collision->GetArea().height;

		if ((myX[0] <= subX[1]) &&
			(subX[0] <= myX[1]) &&
			(myY[0] <= subY[1]) &&
			(subY[0] <= myY[1])) //�����蔻��
		{
			ret = true;
		}
		return ret;
	}

	//����̍��W���擾
	Location GetMin()const
	{
		return Location{ location.x,location.y };
	}
	//�E���̍��W���擾
	Location GetMax()const
	{
		return Location{ location.x + area.width,location.y + area.height };
	}
	//���S���W���擾
	Location GetCenter()const
	{
		return Location{ location.x + area.width / 2,location.y + area.height / 2 };
	}

	//location�̎擾
	Location GetLocation()const { return location; }

	//area�̎擾
	Area GetArea()const { return area; }

	//���P�[�V�����ݒ�
	void SetLocation(Location location)
	{
		this->location = location;
	}
};