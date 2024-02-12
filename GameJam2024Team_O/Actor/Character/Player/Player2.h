#pragma once
#include "../CharaBase.h"

#define MAX_SKILL_1_COOL_TIME   FPS * 3.f     //スキル1のクールタイム
#define MAX_SKILL_2_COOL_TIME   FPS * 20.f    //スキル2のクールタイム

class GameMainScene;

class Player2 :
    public CharaBase
{
private:
    float skill1Count;              //スキル1のカウント
    float skill2Count;              //スキル2のカウント

    bool isShotSkill1;              //スキル1は撃てる？
    bool isShotSkill2;              //スキル2は撃てる？

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

