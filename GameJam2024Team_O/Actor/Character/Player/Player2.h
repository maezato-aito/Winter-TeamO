#pragma once
#include "../CharaBase.h"

class GameMainScene;

class Player2 :
    public CharaBase
{
private:

public:
    //�R���X�g���N�^
    Player2();

    //�f�X�g���N�^
    ~Player2();

    //�X�V
    void Update(GameMainScene*);

    //�`��
    void Draw()const;

    //�ړ�
    void Movement();

    //�����蔻��
    void Collision(GameMainScene*);
};

