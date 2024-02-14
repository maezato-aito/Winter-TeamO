#pragma once
#include "../SceneBase.h"

struct Cursor
{
    int x, y;
};

class TitleScene :
    public SceneBase
{
private:
    int cursorNum;

    Cursor location;
public:
    //�R���X�g���N�^
    TitleScene();

    //�f�X�g���N�^
    ~TitleScene();

    //�`��Ɋւ��邱�ƈȊO�̍X�V����������
    SceneBase* Update()override;

    //�`��Ɋւ��邱�Ƃ̍X�V����������
    void Draw()const override;
};

