#pragma once
#include "../CharaBase.h"
#include "../Skill/skill1.h"

#define MAX_SKILL_1_COOL_TIME   FPS * 3.f     //�X�L��1�̃N�[���^�C��
#define MAX_SKILL_2_COOL_TIME   FPS * 20.f    //�X�L��2�̃N�[���^�C��

class GameMainScene;
class skill1;

class Player2 :
    public CharaBase
{
private:
    float skill1Count;              //�X�L��1�̃J�E���g
    float skill2Count;              //�X�L��2�̃J�E���g

    bool isShotSkill1;              //�X�L��1�͌��Ă�H
    bool isShotSkill2;              //�X�L��2�͌��Ă�H

public:

    skill1* SK;

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

    //�X�L���m�F
    bool IsShotSkill1();
};

