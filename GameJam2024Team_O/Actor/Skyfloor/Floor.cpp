#include "Floor.h"
#include"../common.h"

#define FLOOR		0
#define SKYFLOOR1	1
#define SKYFLOOR2	2 
#define SKYFLOOR3	3 

Floor::Floor()
{
	ImageManager::SetImage("Stage/Main Floor1.png");
	ImageManager::SetImage("Stage/Main Floor2.png");
	type = 0;
}

Floor::~Floor()
{

}

void Floor::Update(int type)
{
	this->type = type;
	switch (type)
	{
	case FLOOR:
		location.x = 0;
		location.y = STAGE_FLOOR;
		area.width = SCREEN_WIDTH;
		area.height = SCREEN_HEIGHT - STAGE_FLOOR;
		break;

	case SKYFLOOR1:
		location.x = 0;
		location.y = 450;
		area.width = (SCREEN_WIDTH / 4);
		area.height = 50;
		break;

	case SKYFLOOR2:
		location.x = SCREEN_WIDTH - (SCREEN_WIDTH / 4);
		location.y = 450;
		area.width = SCREEN_WIDTH / 4;
		area.height = 50;
		break;

	case SKYFLOOR3:
		location.x = SCREEN_WIDTH / 4;
		location.y = 250;
		area.width = SCREEN_WIDTH / 2;
		area.height = 51;
		break;
	}
}

void Floor::Draw()
{
	switch (type)
	{
	case FLOOR:
		break;

	case SKYFLOOR1:
		DrawGraphF(-306, location.y, ImageManager::GetHandle("Stage/Main Floor1.png"), TRUE);
		break;

	case SKYFLOOR2:
		DrawGraphF(location.x, location.y, ImageManager::GetHandle("Stage/Main Floor1.png"), TRUE);
		break;

	case SKYFLOOR3:
		DrawGraphF(location.x, location.y, ImageManager::GetHandle("Stage/Main Floor2.png"), TRUE);
		break;
	}
	//DrawBoxAA(location.x, location.y, location.x + area.width, location.y + area.height, 0xffffff, FALSE);
}