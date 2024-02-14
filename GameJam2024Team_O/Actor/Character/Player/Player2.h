#pragma once
#include "../CharaBase.h"
#include "../Skill/skill1.h"

#define MAX_SKILL_1_COOL_TIME   FPS * 3.f     //スキル1のクールタイム
#define MAX_SKILL_2_COOL_TIME   FPS * 20.f    //スキル2のクールタイム

class GameMainScene;
class skill1;

class Player2 :
    public CharaBase
{
private:
    float skill1Count;              //スキル1のカウント
    float skill2Count;              //スキル2のカウント

    bool isShotSkill1;              //スキル1は撃てる？
    bool isShotSkill2;              //スキル2は撃てる？

public:

    skill1* SK;

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

    //スキル確認
    bool IsShotSkill1();
};

