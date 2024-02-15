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
    //コンストラクタ
    TitleScene();

    //デストラクタ
    ~TitleScene();

    //描画に関すること以外の更新を実装する
    SceneBase* Update()override;

    //描画に関することの更新を実装する
    void Draw()const override;
};

