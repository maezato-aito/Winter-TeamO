#pragma once
#include "../SceneBase.h"
#include"../../UI/UI.h"
#include"../../Actor/Character/Player/Player1.h"
#include"../../Actor/Character/Player/Player2.h"
#include "../../Skill/skill1.h"
#include"../../Actor/Item/Item.h"
#include"../../Actor/Item/BonusBox.h"
#include"../../Actor/Skyfloor/Floor.h"
#define MAX_ITEM    10

class GameMainScene :
    public SceneBase
{
private:
    Player1* player1;
    Player2* player2;
    UI* ui;
    skill1* Skill1;
    Item* item[MAX_ITEM];
    BonusBox* bonusbox[2];
    Floor* floor;
    int Time;
    int floorCount;

public:
    //�R���X�g���N�^
    GameMainScene();

    //�f�X�g���N�^
    ~GameMainScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;

    //�n�ʂ̕`��
    void Ground()const;

    //����������
    void Initialize();

    //�v���C���[1���擾����
    Player1* GetPlayer1() { return player1; }

    //�v���C���[2���擾����
    Player2* GetPlayer2() { return player2; }
};

