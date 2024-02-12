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
	b->Update();
}

void skill1::Draw()
{
	b->Draw();
}
