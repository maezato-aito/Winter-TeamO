#pragma once
#include "../SceneBase.h"
#include"../../UI/UI.h"

class GameMainScene :
    public SceneBase
{
private:
    UI* ui;
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
};

