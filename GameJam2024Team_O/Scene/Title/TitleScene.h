#pragma once
#include "../SceneBase.h"

#define Title "Title.mp3"
#define Cursormove "CursorMove.mp3"
#define Button "Button.mp3"

struct Cursor
{
    int x, y;
};

class TitleScene :
    public SceneBase
{
private:
    int fpsCnt;
    int imageCnt;
    int cursorNum;
    int interval;

    bool isSelect;

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

