#pragma once
#include "../SceneBase.h"

class HelpScene :
    public SceneBase
{
private:

public:
    //�R���X�g���N�^
    HelpScene();

    //�f�X�g���N�^
    ~HelpScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;
};

