#include "Item.h"
#include"DxLib.h"
#include"../../Scene/GameMain/GameMainScene.h"
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
	//�o��������X���W�p�^�[�����擾
	float random_x = (float)(GetRand(4) * 105 + 40);
	//�����ʒu�̐ݒ�
	location.x= random_x;
	location.y=0;
	//�����蔻��� 
	area.width = 100;
	area.height = 100;
	//�����̐ݒ�
	speed = 1;
}

void Item::Update(GameMainScene*game)
{
	//�ʒu���Ɉړ��ʂ����Z����
	location.y += speed;
	if (HitBox(game->GetPlayer1()))
	{
		delete this;
	}
	
}

void Item::Draw()
{
	//�摜�̕`��
	DrawBox(location.x,location.y, location.x+area.width,location.y+area.height,0xffffff,TRUE);
}

void Item::Finalize()
{

}

//�^�C�v���擾
int Item::GetType() const
{
	return type;
}


