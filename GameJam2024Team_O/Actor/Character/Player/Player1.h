#pragma once
#include "../CharaBase.h"
#include<string>

#define IMAGE_SHIFT_X 30
#define IMAGE_SHIFT_Y 62

#define IDLE    "Player/Player1 Default.png"
#define WALK1    "Player/Player1 Motion1.png"
#define WALK2    "Player/player1 Motion2.png"
#define JUMP    "Player/Player1 Jump Motion1.png"
#define STUN    "Player/Player1 Motion3.png"

#define MAX_STAN_TIME   FPS * 0.85f   //スタン時間

class GameMainScene;

class Player1 :
    public CharaBase
{
private:
    short jumpCount;            //ジャンプカウント

    int animState;              //アニメーション状態
    int animCnt;                //アニメーションカウント

    float stanCount;            //スタンカウント

    bool isStan;                //スタン中？
    bool isReverse;             //反転する？

    std::string animHandle;             //アニメーションハンドル

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

    void SetIsStan(const bool flg)
    {
        isStan = flg;
        if (isStan)
        {
            stanCount = MAX_STAN_TIME;
        }
    }

    void AnimStateToAnimHandle()
    {
        if (animState == 0)
        {
            animHandle = IDLE;
        }
        else if (animState == 1)
        {
            animHandle = WALK1;
        }
        else if (animState == 2)
        {
            animHandle = WALK2;
        }
        else if (animState == 3)
        {
            animHandle = JUMP;
        }
        else if (animState == 4)
        {
            animHandle = STUN;
        }
    }

    std::string GetAnimHandle() const 
    { 
        return animHandle;

    }
};

