#pragma once
#include "../SceneBase.h"

class ResultScene :
    public SceneBase
{
private:

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

