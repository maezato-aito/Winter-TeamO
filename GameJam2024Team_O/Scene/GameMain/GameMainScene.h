#pragma once
#include "../SceneBase.h"
#include"../../UI/UI.h"

class GameMainScene :
    public SceneBase
{
private:
    UI* ui;
public:
    //コンストラクタ
    GameMainScene();

    //デストラクタ
    ~GameMainScene();

    //描画に関すること以外の更新を実装する
    SceneBase* Update()override;

    //描画に関することの更新を実装する
    void Draw()const override;

    //地面の描画
    void Ground()const;
};

