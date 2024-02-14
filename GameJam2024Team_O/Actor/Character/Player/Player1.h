#pragma once
#include "../CharaBase.h"

#define MAX_STAN_TIME   FPS * 2.f   //スタン時間

class GameMainScene;

class Player1 :
    public CharaBase
{
private:
    short jumpCount;            //ジャンプカウント

    float stanCount;            //スタンカウント

    bool isStan;                //スタン中？

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

    //スタン中かどうか取得する
    bool GetIsStan() { return isStan; }
};

