#pragma once
#include "../SceneBase.h"
#include"../../UI/UI.h"
#include"../../Actor/Character/Player/Player1.h"
#include"../../Actor/Character/Player/Player2.h"
#include "../../Skill/skill1.h"
#include"../../Actor/Item/Item.h"
#include"../../Actor/Item/BonusBox.h"
#include"../../Actor/Skyfloor/Floor.h"

#include "../Scene/Result/ResultScene.h"

#define STAGE "Stage/Main Stage.png"

#define MAX_ITEM    10

class GameMainScene :
    public SceneBase
{
private:
    Player1* player1;
    Player2* player2;
    UI* ui;
    Item* item[MAX_ITEM];
    BonusBox* bonusbox[2];
    Floor* floor[4];

    int Time;

    bool isObstacle;            //���ז��摜��\������H

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

    //�t���A���擾
    Floor* GetFloor(int arrayNum) { return floor[arrayNum]; }

    //UI���擾
    UI* GetUI() { return ui; }

    //isObstacle��ݒ�
    void SetIsObstacle(const bool flg)
    {
        isObstacle = flg;
    }
};

