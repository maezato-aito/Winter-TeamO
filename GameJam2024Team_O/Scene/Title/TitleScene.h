#pragma once
#include "../SceneBase.h"

#define Title "BGM/Title.mp3"

struct Cursor
{
    int x, y;
};

class TitleScene :
    public SceneBase
{
private:
    int cursorNum;
    int interval;

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

