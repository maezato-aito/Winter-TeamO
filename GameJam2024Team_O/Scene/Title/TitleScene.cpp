#include "TitleScene.h"

TitleScene::TitleScene()
{
	cursorNum = 0;

	location = {};
}

TitleScene::~TitleScene()
{

}

SceneBase* TitleScene::Update()
{
	location.x = cursorNum * 200;

	//if (cursorNum < 3)
	//{
	//	cursorNum++;
	//	if(cursorNum)
	//}

	return this;
}

void TitleScene::Draw() const
{

}
