#pragma once
#include "../CharaBase.h"

#define STICK_RATIO     0.2f

class Player1 :
    public CharaBase
{
private:

public:
    //�R���X�g���N�^
    Player1();

    //�f�X�g���N�^
    ~Player1();

    //�X�V
    void Update();

    //�`��
    void Draw()const;
};

