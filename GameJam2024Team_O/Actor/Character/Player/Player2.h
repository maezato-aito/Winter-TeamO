#pragma once
#include "../CharaBase.h"

class GameMainScene;

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
    void Update(GameMainScene*);

    //描画
    void Draw()const;

    //移動
    void Movement();

    //当たり判定
    void Collision(GameMainScene*);
};

