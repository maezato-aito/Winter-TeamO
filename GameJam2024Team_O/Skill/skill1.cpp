#include "skill1.h"

skill1::skill1()
{
	b = new bullet;
	
}

skill1::~skill1()
{

}

void skill1::UpDate()
{
	if(KeyInput::GetKeyDown(KEY_INPUT_SPACE))
	b->Update();
}

void skill1::Draw()
{
	b->Draw();
}
