#pragma once
#include"../../Collision/BoxCollision.h"
class GameMainScene;
class Item:public BoxCollision 
{
private:
	int type;        //�^�C�v
	int image;       //�摜
	float speed;     //����

public:
	Item();
	~Item();

	void Initialize();       //����������
	void Update(GameMainScene*);           //�X�V����
	void Draw();             //�`�揈��
	void Finalize();         //�I��������

	int GetType() const;     //�^�C�v�擾
};

