#pragma once
#include "../CharaBase.h"

class GameMainScene;

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
    void Update(GameMainScene*);

    //描画
    void Draw()const;

    //移動
    void Movement();

    //当たり判定
    void Collision(GameMainScene*);
};

