#pragma once
#include "../CharaBase.h"
#include "../Skill/skill1.h"

#define IMAGE_SHIFT_X_2 58                      //プレイヤー2の画像調整用
#define IMAGE_SHIFT_Y_2 62                      //プレイヤー2の画像調整用

#define IDLE_2    "Player/Player2 Default.png"  //パス
#define WALK1_2    "Player/Player2 Motion1.png" //パス
#define WALK2_2    "Player/Player2 Motion2.png" //パス
#define JUMP_2    "Player/Player2 Jump1.png"    //パス
#define STUN_2    "Player/Player2 Motion3.png"  //パス

#define MAX_SKILL_1_COOL_TIME   FPS * 1.7f      //スキル1のクールタイム
#define MAX_SKILL_2_COOL_TIME   FPS * 20.f      //スキル2のクールタイム

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

    skill1* SK;                     //スキル1

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

    //アニメーション
    void Animation();

    //当たり判定
    void Collision(GameMainScene*);

    //スキル1の取得
    bool GetIsShotSkill1();

    //スキル2の取得
    bool GetIsShotSkill2();

    //ハンドルの変更
    void AnimStateToAnimHandle();

    //スキル
    void Skill(GameMainScene*);

};

