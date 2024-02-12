#pragma once
#include "../CharaBase.h"

class GameMainScene;

class Player1 :
    public CharaBase
{
private:
    short jumpCount;

public:
    //�R���X�g���N�^
    Player1();

    //�f�X�g���N�^
    ~Player1();

    //�X�V
    void Update(GameMainScene*);

    //�`��
    void Draw()const;

    //�ړ�
    void Movement();

    //�����蔻��
    void Collision(GameMainScene*);
};

