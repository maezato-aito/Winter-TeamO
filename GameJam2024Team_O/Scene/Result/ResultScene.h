#pragma once
#include "../SceneBase.h"
#include "../common.h"

#include "../Scene/Title/TitleScene.h"

class ResultScene :
    public SceneBase
{
private:
    int num;

    float fpsCnt;
    float score;
    float bonusCount;

public:
    //�R���X�g���N�^
    ResultScene(float score, float bonusCnt);

    //�f�X�g���N�^
    ~ResultScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;
};

