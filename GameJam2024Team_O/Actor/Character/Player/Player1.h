#pragma once
#include "../CharaBase.h"
#include<string>

#define IMAGE_SHIFT_X 30
#define IMAGE_SHIFT_Y 62

#define IDLE    "Player/Player1 Default.png"
#define WALK1    "Player/Player1 Motion1.png"
#define WALK2    "Player/player1 Motion2.png"
#define JUMP    "Player/Player1 Jump Motion1.png"
#define STUN    "Player/Player1 Motion3.png"

#define MAX_STAN_TIME   FPS * 0.85f   //�X�^������

class GameMainScene;

class Player1 :
    public CharaBase
{
private:
    short jumpCount;            //�W�����v�J�E���g

    int animState;              //�A�j���[�V�������
    int animCnt;                //�A�j���[�V�����J�E���g

    float stanCount;            //�X�^���J�E���g

    bool isStan;                //�X�^�����H
    bool isReverse;             //���]����H

    std::string animHandle;             //�A�j���[�V�����n���h��

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

    //�A�j���[�V����
    void Animation();

    //�����蔻��
    void Collision(GameMainScene*);

    //�X�^�������ǂ����擾����
    bool GetIsStan()const { return isStan; }

    void SetIsStan(const bool flg)
    {
        isStan = flg;
        if (isStan)
        {
            stanCount = MAX_STAN_TIME;
        }
    }

    void AnimStateToAnimHandle()
    {
        if (animState == 0)
        {
            animHandle = IDLE;
        }
        else if (animState == 1)
        {
            animHandle = WALK1;
        }
        else if (animState == 2)
        {
            animHandle = WALK2;
        }
        else if (animState == 3)
        {
            animHandle = JUMP;
        }
        else if (animState == 4)
        {
            animHandle = STUN;
        }
    }

    std::string GetAnimHandle() const 
    { 
        return animHandle;

    }
};

