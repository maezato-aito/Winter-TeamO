#pragma once
#include "../CharaBase.h"

#define STICK_RATIO     0.2f

class Player1 :
    public CharaBase
{
private:

public:
    //コンストラクタ
    Player1();

    //デストラクタ
    ~Player1();

    //更新
    void Update();

    //描画
    void Draw()const;
};

