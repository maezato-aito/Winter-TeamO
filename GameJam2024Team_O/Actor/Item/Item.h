#pragma once
#include"../../Collision/BoxCollision.h"

#define Ingot "Item/Gold Ingot.png"
#define Money "Item/money.png"

class GameMainScene;
enum
{
	common,
	rare
};
class Item:public BoxCollision 
{
private:
	int type;       //�^�C�v
	int image;      //�摜
	int score;		//�X�R�A
	float speed;    //����

public:
	Item();
	~Item();

	void Initialize();       //����������
	void Update(GameMainScene*);           //�X�V����
	void Draw();             //�`�揈��
	void Finalize();         //�I��������

	int GetType() const;     //�^�C�v�擾
	void SetType(int type)
	{
		this->type = type;
	}
	float GetScore()
	{
		return score;
	}
};

