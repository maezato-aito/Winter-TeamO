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
	//�摜�̓ǂݍ���
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
		score = 950;

		//�����̓����蔻��̊m�F
		area.width = 54;
		area.height = 62;
	}
	else if (type == rare)
	{
		score = 1350;

		//����̓����蔻��̊m�F
		area.width = 54;
		area.height = 60;
	}

	//�o��������X���W�p�^�[�����擾
	float random_x = (float)(GetRand(10) * 105 + 40);
	float random_y = (float)(GetRand(20) * 20);
	float random_speed = (float)(GetRand(2) * 2 + 2);
	//�����ʒu�̐ݒ�
	location.x= random_x;
	location.y=-random_y;
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
	//DrawBoxAA(location.x, location.y, location.x + area.width, location.y + area.height, 0x00ffff, TRUE);

	if (type == common)
	{
		DrawRotaGraphF(GetCenter().x ,GetCenter().y, 0.11f, 0.0f, ImageManager::GetHandle(Money), TRUE);
	}
	else
	{
		DrawRotaGraphF(GetCenter().x, GetCenter().y, 0.11f, 0.0f, ImageManager::GetHandle(Ingot), TRUE);
	}
}

void Item::Finalize()
{

}

//�^�C�v���擾
int Item::GetType() const
{
	return type;
}


