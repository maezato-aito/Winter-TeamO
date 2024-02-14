#include "ResultScene.h"


ResultScene::ResultScene()
{
	ui = new UI();
	/*BCount = new BonusBox() ;*/
}

ResultScene::~ResultScene()
{

}

SceneBase* ResultScene::Update()
{
	DrawScore = ui->Get_Score();
	/*DrawBoxCount = BCount->Get_Count();*/

	if (PadInput::OnButton1(XINPUT_BUTTON_A))
	{
		return new TitleScene();
	}

	return this;
}

void ResultScene::Draw() const
{
	DrawFormatString(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0xffffff, "%d", DrawScore);
	/*DrawFormatString(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 50, 0xffffff, "%f", DrawBoxCount);
	DrawFormatString(SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 100, 0xffffff, "%f", DrawBoxCount);*/
}
