#pragma once
#include "../SceneBase.h"
#include"../../UI/UI.h"
#include"../../Actor/Character/Player/Player1.h"
#include"../../Actor/Character/Player/Player2.h"
#include "../../Skill/skill1.h"
#include"../../Actor/Item/Item.h"
#include"../../Actor/Item/BonusBox.h"
#include"../../Actor/Skyfloor/Floor.h"
#define MAX_ITEM    10

class GameMainScene :
    public SceneBase
{
private:
    Player1* player1;
    Player2* player2;
    UI* ui;
    skill1* Skill1;
    Item* item[MAX_ITEM];
    BonusBox* bonusbox[2];
    Floor* floor;
    int Time;
    int floorCount;

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

    //初期化処理
    void Initialize();

    //プレイヤー1を取得する
    Player1* GetPlayer1() { return player1; }

    //プレイヤー2を取得する
    Player2* GetPlayer2() { return player2; }
};

