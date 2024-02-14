#include "Floor.h"

#define FLOOR		0
#define SKYFLOOR1	1
#define SKYFLOOR2	2 
#define SKYFLOOR3	3 

Floor::Floor()
{

}

Floor::~Floor()
{

}

void Floor::Update(int type)
{
	switch (type)
	{
	case FLOOR:
		location.x = 0;
		location.y = STAGE_FLOOR;
		area.width = SCREEN_WIDTH;
		area.height = SCREEN_HEIGHT;
		break;

	case SKYFLOOR1:
		location.x = 0;
		location.y = 450;
		area.width = location.x + (SCREEN_WIDTH / 4);
		area.height = location.y + 50;
		break;

	case SKYFLOOR2:
		location.x = SCREEN_WIDTH - (SCREEN_WIDTH / 4);
		location.y = 450;
		area.width = SCREEN_WIDTH;
		area.height = location.y + 50;
		break;

	case SKYFLOOR3:
		location.x = SCREEN_WIDTH / 4;
		location.y = 250;
		area.width = SCREEN_WIDTH - (SCREEN_WIDTH / 4);
		area.height = location.y + 50;
		break;
	}
}

void Floor::Draw()
{
	DrawBox((int)location.x, (int)location.y, (int)area.width, (int)area.height, 0xffffff, false);
}