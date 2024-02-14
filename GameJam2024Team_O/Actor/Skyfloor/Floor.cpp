#include "Floor.h"
#define FLOOR 1; 
#define SKYFLOOR1 2; 
#define SKYFLOOR2 3; 
Floor::Floor()
{

}

Floor::~Floor()
{

}

void Floor::Update()
{
	switch (type)
	{
	FlOOR:
		location.x = 0;
		location.y = 650;
		area.width = SCREEN_WIDTH;
		area.height = location.y + 50;
		break;

	SKYFlOOR1:
		location.x = 0;
		location.y = 550;
		area.width = location.x + (SCREEN_WIDTH / 4);
		area.height = location.y + 50;
		break;

	SKYFlOOR2:
		location.x = SCREEN_WIDTH - (SCREEN_WIDTH / 4);
		location.y = 550;
		area.width = SCREEN_WIDTH;
		area.height = location.y + 50;
		break;
	}
}

void Floor::Draw()
{
	
}