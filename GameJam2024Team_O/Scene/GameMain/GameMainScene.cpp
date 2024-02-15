#include"../../common.h"
#include "GameMainScene.h"
#include"../Utility/FontManager.h"

GameMainScene::GameMainScene()
{
	ImageManager::SetImage(STAGE);
	ImageManager::SetImage("Stage/Main Stage1.png");

	ui = new UI();
	player1 = new Player1();
	player2 = new Player2();

	int patern = GetRand(2);

	for (int i = 0; i < MAX_ITEM; i++)
	{
		item[i] = new Item();
		if (i < 2)
		{
			bonusbox[i] = new BonusBox(i, patern);

		}
		if (i < 4)
		{
			floor[i] = new Floor();
		}
	}
	overTime = 0;

	isObstacle = false;
	isOver = false;
}

GameMainScene::~GameMainScene()
{
	delete ui;
	delete player1;
	delete player2;

	for (int i = 0; i < MAX_ITEM; i++)
	{
		delete item[i];

		if (i < 2)
		{
			delete bonusbox[i];
		}
		if (i < 4)
		{
			delete floor[i];
		}
	}
}


SceneBase* GameMainScene::Update()
{
	ui->Update();

	player1->Update(this);

	player2->Update(this);

	for (int i = 0; i < 4; i++)
	{
		floor[i]->Update(i);
		player1->GroundCollision(this, i);
		player2->GroundCollision(this, i);
	}

	for (int i = 0; i < 2; i++)
	{
		if (bonusbox[i] != nullptr)
		{
			bonusbox[i]->Update(this);
		}

	}
	
	for (int i = 0; i < MAX_ITEM; i++)
	{
		if (item[i] != nullptr)
		{
			item[i]->Update(this);
			if (item[i]->HitBox(player1) && !player1->GetIsStan())
			{
				ui->Count_Score(item[i]->GetScore());
				delete item[i];
				item[i] = nullptr;
				Initialize();
			}

			if (item[i]->GetLocation().y > SCREEN_HEIGHT)
			{
				delete item[i];
				item[i] = nullptr;
				Initialize();
			}
		}
			
	}

	if (ui->Get_Timer() <= 40)
	{
		isOver = true;
	}

	if (isOver)
	{
		overTime++;
	}

	if (overTime > FPS * 3)
	{
		return new ResultScene(ui->Get_Score(), bonusbox[0]->Get_Count() + bonusbox[1]->Get_Count());
	}

	return this;
}

void GameMainScene::Draw() const
{
	DrawGraph(0, 0, ImageManager::GetHandle(STAGE), TRUE);
	DrawGraph(0, STAGE_FLOOR, ImageManager::GetHandle("Stage/Main Stage1.png"), TRUE);
	DrawGraph(363, STAGE_FLOOR, ImageManager::GetHandle("Stage/Main Stage1.png"), TRUE);
	DrawGraph(726, STAGE_FLOOR, ImageManager::GetHandle("Stage/Main Stage1.png"), TRUE);
	DrawGraph(1089, STAGE_FLOOR, ImageManager::GetHandle("Stage/Main Stage1.png"), TRUE);

	Ground();

	for (int i = 0; i < 4; i++)
	{
		floor[i]->Draw();
	}

	for (int i = 0; i < MAX_ITEM; i++)
	{
		if (item[i] != nullptr)
		{
			item[i]->Draw();
		}
	}

	for (int i = 0; i < 2; i++)
	{
		if (bonusbox[i] != nullptr)
		{
			bonusbox[i]->Draw(i);
		}
	}

	if (isObstacle)
	{

	}

	player1->Draw();

	player2->Draw();

	ui->Draw();

	DrawFormatStringToHandle(864, 40, 0xffffff, FontManager::GetHandle(32), "ボーナス倍率:%0.f\n", bonusbox[0]->Get_Count() + bonusbox[1]->Get_Count());
	DrawFormatStringToHandle(900, 80, 0xffffff, FontManager::GetHandle(32), "目標スコア:%0.f\n", QUOTA_SCORE);
	if (isOver)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
		DrawBox(0, SCREEN_HEIGHT / 4, SCREEN_WIDTH, (SCREEN_HEIGHT / 2) + (SCREEN_HEIGHT / 4), 0x000000, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawFormatStringToHandle(SCREEN_WIDTH / 2 - 128, SCREEN_HEIGHT / 2 - 64, 0xffffff, FontManager::GetHandle(128), "終了！\n");
	}
}

void GameMainScene::Ground() const
{
	DrawLine(0, STAGE_FLOOR, SCREEN_WIDTH, STAGE_FLOOR, 0xffffff);
}

void GameMainScene::Initialize()
{
	for (int i = 0; i < MAX_ITEM; i++)
	{
		if (item[i] == nullptr)
		{
			item[i] = new Item();
			item[i]->Initialize();
			break;
		}
	}
}
