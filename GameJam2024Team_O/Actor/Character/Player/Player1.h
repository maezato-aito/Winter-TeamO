#pragma once
#include "../CharaBase.h"

class Player1 :
    public CharaBase
{
private:
    short jumpCount;

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

