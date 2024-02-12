#pragma once
#include "../CharaBase.h"

class Player2 :
    public CharaBase
{
private:

public:
    //コンストラクタ
    Player2();

    //デストラクタ
    ~Player2();

    //更新
    void Update();

    //描画
    void Draw()const;

};

