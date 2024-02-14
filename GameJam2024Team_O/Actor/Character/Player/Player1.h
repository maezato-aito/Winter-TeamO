#pragma once
#include "../CharaBase.h"

#define MAX_STAN_TIME   FPS * 2.f   //�X�^������

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

    //�����蔻��
    void Collision(GameMainScene*);

    //�X�^�������ǂ����擾����
    bool GetIsStan() { return isStan; }
};

