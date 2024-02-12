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
		float my_x[2];
		float my_y[2];

		//����̓����蔻��͈̔�
		float sub_x[2];
		float sub_y[2];

		//�����̓����蔻��͈̔͂̌v�Z
		my_x[0] = location.x;
		my_y[0] = location.y;
		my_x[1] = my_x[0] + area.width;
		my_y[1] = my_y[0] + area.height;

		//����̓����蔻��͈̔͂̌v�Z
		sub_x[0] = collision->GetLocation().x;
		sub_y[0] = collision->GetLocation().y;
		sub_x[1] = sub_x[0] + collision->GetArea().width;
		sub_y[1] = sub_y[0] + collision->GetArea().height;

		if ((my_x[0] <= sub_x[1]) &&
			(sub_x[0] <= my_x[1]) &&
			(my_y[0] <= sub_y[1]) &&
			(sub_y[0] <= my_y[1])) //�����蔻��
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
};