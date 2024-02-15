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
    //コンストラクタ
    TitleScene();

    //デストラクタ
    ~TitleScene();

    //描画に関すること以外の更新を実装する
    SceneBase* Update()override;

    //描画に関することの更新を実装する
    void Draw()const override;
};

