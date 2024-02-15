#pragma once
#include "../CharaBase.h"
#include<string>

#define IMAGE_SHIFT_X_1 30
#define IMAGE_SHIFT_Y_1 62

#define IDLE_1    "Player/Player1 Default.png"
#define WALK1_1    "Player/Player1 Motion1.png"
#define WALK2_1    "Player/player1 Motion2.png"
#define JUMP_1    "Player/Player1 Jump Motion1.png"
#define STUN_1    "Player/Player1 Motion3.png"

#define MAX_STAN_TIME   FPS * 0.85f   //スタン時間

#define Damage "Damage.mp3"
#define Jump "Jump.mp3"

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

    //アニメーション
    void Animation();

    //当たり判定
    void Collision(GameMainScene*);

    //スタン中かどうか取得する
    bool GetIsStan()const { return isStan; }

    void SetIsStan(const bool flg);

    void AnimStateToAnimHandle();
};

