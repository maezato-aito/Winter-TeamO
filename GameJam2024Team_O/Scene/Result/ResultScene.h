#pragma once
#include "../SceneBase.h"
#include "../common.h"

#include "../Scene/Title/TitleScene.h"

class ResultScene :
    public SceneBase
{
private:
    int num;

    float fpsCnt;
    float score;
    float bonusCount;

public:
    //コンストラクタ
    ResultScene(float score, float bonusCnt);

    //デストラクタ
    ~ResultScene();

    //描画に関すること以外の更新を実装する
    SceneBase* Update()override;

    //描画に関することの更新を実装する
    void Draw()const override;
};

