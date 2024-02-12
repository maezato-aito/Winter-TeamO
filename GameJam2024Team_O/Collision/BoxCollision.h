#pragma once

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
	Location location;
	Area area;

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
	bool HitBox(const BoxCollision* box_collider)const;

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