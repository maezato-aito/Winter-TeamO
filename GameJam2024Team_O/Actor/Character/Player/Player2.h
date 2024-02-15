#pragma once
#include "../CharaBase.h"
#include "../Skill/skill1.h"

#define IMAGE_SHIFT_X_2 58                      //�v���C���[2�̉摜�����p
#define IMAGE_SHIFT_Y_2 62                      //�v���C���[2�̉摜�����p

#define IDLE_2    "Player/Player2 Default.png"  //�p�X
#define WALK1_2    "Player/Player2 Motion1.png" //�p�X
#define WALK2_2    "Player/Player2 Motion2.png" //�p�X
#define JUMP_2    "Player/Player2 Jump1.png"    //�p�X
#define STUN_2    "Player/Player2 Motion3.png"  //�p�X

#define MAX_SKILL_1_COOL_TIME   FPS * 1.7f      //�X�L��1�̃N�[���^�C��
#define MAX_SKILL_2_COOL_TIME   FPS * 20.f      //�X�L��2�̃N�[���^�C��

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

    skill1* SK;                     //�X�L��1

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

    //�A�j���[�V����
    void Animation();

    //�����蔻��
    void Collision(GameMainScene*);

    //�X�L��1�̎擾
    bool GetIsShotSkill1();

    //�X�L��2�̎擾
    bool GetIsShotSkill2();

    //�n���h���̕ύX
    void AnimStateToAnimHandle();

    //�X�L��
    void Skill(GameMainScene*);

};

