#pragma once
#include "../SceneBase.h"
#include "../common.h"
#include "../UI/UI.h"
#include "../Actor/Item/BonusBox.h"

class ResultScene :
    public SceneBase
{
private:
    UI* ui;
    BonusBox* BCount;

    float DrawScore;
    float DrawBoxCount;

public:
    //コンストラクタ
    ResultScene();

    //デストラクタ
    ~ResultScene();

    //描画に関すること以外の更新を実装する
    SceneBase* Update()override;

    //描画に関することの更新を実装する
    void Draw()const override;
};

