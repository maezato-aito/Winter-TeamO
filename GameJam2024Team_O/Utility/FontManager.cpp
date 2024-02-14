#include "FontManager.h"
#include"DxLib.h"

FontManager* FontManager::manager = nullptr;

void FontManager::CreateFontManagerr()
{
	//�I�u�W�F�N�g���쐬����Ă��Ȃ��Ȃ�I�u�W�F�N�g���쐬����
	if (manager == nullptr)
	{
		manager = new FontManager();
	}

	std::string path = "Resource/Fonts/mihiPixelmoji_v1.1.ttf";

	if (AddFontResourceEx(path.c_str(), FR_PRIVATE, NULL) < 0)
	{
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	};

	SetFont(128);
	SetFont(64);
	SetFont(32);
	SetFont(16);
}

void FontManager::DeleteFontManagerr()
{
	InitFontToHandle();
	delete manager;
	manager = nullptr;
}

void FontManager::SetFont(int size)
{
	//���[�J���ϐ�iterator��size�L�[�̌������ʂ���
	auto iterator = manager->font.find(size);

	//�ݒ肳��Ă��Ȃ��ꍇ
	if (iterator == manager->font.end())
	{
		//�L�[�ɓǂ݂���
		manager->font[size] = CreateFontToHandle("�݂Ђ�߃t�H���g", size, 10, DX_FONTTYPE_EDGE);
	}
}
