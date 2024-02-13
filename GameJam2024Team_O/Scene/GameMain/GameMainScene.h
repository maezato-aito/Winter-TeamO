#pragma once
#include "../SceneBase.h"
#include"../../UI/UI.h"
#include"../../Actor/Character/Player/Player1.h"
#include"../../Actor/Character/Player/Player2.h"
#include "../../Skill/skill1.h"
#include"../../Actor/Item/Item.h"
#include"../../Actor/Item/BonusBox.h"

class GameMainScene :
    public SceneBase
{
private:
    Player1* player1;
    Player2* player2;
    UI* ui;
    skill1* Skill1;
    Item* item;
    BonusBox* bonusbox;

public:
    //コンストラクタ
    GameMainScene();

    //デストラクタ
    ~GameMainScene();

    //描画に関すること以外の更新を実装する
    SceneBase* Update()override;

    //描画に関することの更新を実装する
    void Draw()const override;

    //地面の描画
    void Ground()const;

    //プレイヤー1を取得する
    Player1* GetPlayer1() { return player1; }

    //プレイヤー2を取得する
    Player2* GetPlayer2() { return player2; }
};

