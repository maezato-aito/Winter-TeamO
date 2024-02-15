#pragma once
#include "../CharaBase.h"
#include<string>

#define IMAGE_SHIFT_X_1 30
#define IMAGE_SHIFT_Y_1 62

#define IDLE_1    "Player/Player1 Default.png"
#define WALK1_1    "Player/Player1 Motion1.png"
#define WALK2_1    "Player/player1 Motion2.png"
#define JUMP_1    "Player/Player1 Jump Motion1.png"
#define STUN_1    "Player/Player1 Motion3.png"

#define MAX_STAN_TIME   FPS * 0.85f   //�X�^������

#define Damage "Damage.mp3"
#define Jump "Jump.mp3"

class GameMainScene;

class Player1 :
    public CharaBase
{
private:
    short jumpCount;            //�W�����v�J�E���g

    float stanCount;            //�X�^���J�E���g

    bool isStan;                //�X�^�����H

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

    void SetIsStan(const bool flg);

    void AnimStateToAnimHandle();
};

