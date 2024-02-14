#pragma once
#include "../SceneBase.h"
#include "../common.h"
#include "../UI/UI.h"
#include "../Actor/Item/BonusBox.h"

class ResultScene :
    public SceneBase
{
private:
    UI* ui;
    BonusBox* BCount;

    float DrawScore;
    float DrawBoxCount;

public:
    //�R���X�g���N�^
    ResultScene();

    //�f�X�g���N�^
    ~ResultScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;
};

