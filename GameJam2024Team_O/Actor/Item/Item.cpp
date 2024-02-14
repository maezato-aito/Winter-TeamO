#include "Item.h"
#include"DxLib.h"
#include"../../Scene/GameMain/GameMainScene.h"
#include"../common.h"

Item::Item()
{
	Initialize();
}

Item::~Item()
{

}

//����������
void Item::Initialize()
{
	ImageManager::SetImage("Item/Gold Ingot.png");
	ImageManager::SetImage("Item/money.png");
	if (GetRand(100) < 80)
	{
		SetType(common);
	}
	else
	{
		SetType(rare);
	}
	if(type==common)
		{
			scoa=500;
		}
	else if (type == rare)
	{
		scoa = 1000;
	}
	//�o��������X���W�p�^�[�����擾
	float random_x = (float)(GetRand(10) * 105 + 40);
	float random_y = (float)(GetRand(20) * 20);
	float random_speed = (float)(GetRand(2) * 2 + 2);
	//�����ʒu�̐ݒ�
	location.x= random_x;
	location.y=-random_y;
	//�����蔻��� 
	area.width = 100;
	area.height = 100;
	//�����̐ݒ�
	speed = random_speed;
}

void Item::Update(GameMainScene*game)
{
	//�ʒu���Ɉړ��ʂ����Z����
	location.y += speed;
}

void Item::Draw()
{
	//�摜�̕`��
	DrawBoxAA(location.x,location.y, location.x+area.width,location.y+area.height,0x00ffff,TRUE);
}

void Item::Finalize()
{

}

//�^�C�v���擾
int Item::GetType() const
{
	return type;
}


