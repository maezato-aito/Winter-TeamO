#include"../../common.h"
#include "GameMainScene.h"
#include"../Utility/FontManager.h"

GameMainScene::GameMainScene()
{
	ImageManager::SetImage(STAGE);

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
	Time = 0;

	isObstacle = false;
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

	floorCount++;

	if (5 <= floorCount)
	{
		floorCount = 1;
	}

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

	Time++;
	
	for (int i = 0; i < MAX_ITEM; i++)
	{
		if (item[i] != nullptr)
		{
			item[i]->Update(this);
			if (item[i]->HitBox(player1) && !player1->GetIsStan())
			{
				ui->Count_Score(item[i]->GetScoa());
				delete item[i];
				item[i] = nullptr;
				Initialize();
			}

			if (item[i]->GetLocation().y > SCREEN_HEIGHT)
			{
				//item[i]->SetLocation({ item[i]->GetLocation().x, -3 });
				delete item[i];
				item[i] = nullptr;
				Initialize();
			}
		}
			
	}

	if (ui->Get_Timer() <= BONUS_TIME)
	{
		/*return new ResultScene(ui->Count_Score(), );*/
	}

	return this;
}

void GameMainScene::Draw() const
{
	DrawGraph(0, 0, ImageManager::GetHandle(STAGE), TRUE);

	Ground();

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

	for (int i = 0; i < 4; i++)
	{
		floor[i]->Draw();
	}

	ui->Draw();

	DrawFormatStringToHandle(900, 40, 0xffffff, FontManager::GetHandle(32), "ボーナス倍率:%0.f\n", bonusbox[0]->Get_Count() + bonusbox[1]->Get_Count());
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
