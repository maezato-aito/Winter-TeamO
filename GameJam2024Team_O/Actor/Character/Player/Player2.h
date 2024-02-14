#pragma once
#include "../CharaBase.h"
#include "../Skill/skill1.h"

#define IMAGE_SHIFT_X_2 28
#define IMAGE_SHIFT_Y_2 62

#define IDLE_2    "Player/Player2 Default.png"
#define WALK1_2    "Player/Player2 Motion1.png"
#define WALK2_2    "Player/Player2 Motion2.png"
#define JUMP_2    "Player/Player2 Jump1.png"
#define STUN_2    "Player/Player2 Motion3.png"

#define MAX_SKILL_1_COOL_TIME   FPS * 1.5f    //スキル1のクールタイム
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

    //アニメーション
    void Animation();

    //当たり判定
    void Collision(GameMainScene*);

    //スキル確認
    bool IsShotSkill1();

    void AnimStateToAnimHandle();

};

