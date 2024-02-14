#pragma once
#include<map>
#include<string>

class FontManager
{
private:
	static FontManager* manager;				//�I�u�W�F�N�g

	std::map<int, int>font;						//�A�z�z��font
public:
	//�R���X�g���N�^
	FontManager() {};

	//�f�X�g���N�^
	~FontManager() {};

	//FontManager�̍쐬
	static void CreateFontManagerr();

	//FontManager�̍폜
	static void DeleteFontManagerr();

	//�A�z�z��Ɋi�[���ꂽ�t�H���g�̃n���h�����擾����
	static int GetHandle(int size) { return manager->font[size]; }

	//�n���h���Ƀt�H���g��ݒ肷��
	static void SetFont(int size);
};

