#include "HelpScene.h"
#include "../Scene/Title/TitleScene.h"
#include "../common.h"
#include "PadInput.h"


HelpScene::HelpScene()
{
	ImageManager::SetImage("Scene/helpimg/スライド1.PNG");
	ImageManager::SetImage("Scene/helpimg/スライド2.PNG");
}

HelpScene::~HelpScene()
{

}

SceneBase* HelpScene::Update()
{
	if (PadInput::OnButton1(XINPUT_BUTTON_A))
	{
		return new TitleScene();
	}
	return this;
}

void HelpScene::Draw() const
{
	DrawRotaGraph(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, 1, 0, ImageManager::GetHandle("Scene/helpimg/スライド1.PNG"), TRUE);
}
