#include"../../common.h"
#include "GameMainScene.h"

GameMainScene::GameMainScene()
{
	ui = new UI();
	player1 = new Player1();
	player2 = new Player2();
	floor = new Floor();
	for (int i = 0; i < MAX_ITEM; i++)
	{
		item[i] = new Item();
		if (i < 2)
		{
			bonusbox[i] = new BonusBox(i);

		}
	}
	Time = 0;

}

GameMainScene::~GameMainScene()
{
	delete ui;
	delete player1;
	delete player2;
	delete floor;

	for (int i = 0; i < MAX_ITEM; i++)
	{
		delete item[i];

		if (i < 2)
		{
			delete bonusbox[i];
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
	floor->Update(floorCount);
	

	if (ui->Get_Timer() < 50)
	{
		for (int i = 0; i < 2; i++)
		{
			if (bonusbox[i] != nullptr)
			{
				bonusbox[i]->Update(this);

			}

		}
	}
	if (ui->Get_Timer() <= 50)
	{
		/*return new ResultScene(ui->Count_Score(), );*/
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

	return this;
}

void GameMainScene::Draw() const
{
	Ground();

	
	for (int i = 0; i < MAX_ITEM; i++)
	{
		if (item[i] != nullptr)
		{
			item[i]->Draw();
			DrawFormatStringF(item[i]->GetCenter().x, item[i]->GetCenter().y, 0xffffff, "%d", i);
		}
	}

	if (ui->Get_Timer() < 50)
	{
		for (int i = 0; i < 2; i++)
		{
			if (bonusbox[i] != nullptr)
			{
				bonusbox[i]->Draw(i);

			}

		}
	}

	player1->Draw();

	player2->Draw();

	ui->Draw();

	floor->Draw();

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
