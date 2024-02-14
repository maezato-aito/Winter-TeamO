#pragma once
#include<map>
#include<string>

class ImageManager
{
private:
	static ImageManager* manager;				//�I�u�W�F�N�g

	std::map<std::string, int>image;			//�A�z�z��image
public:
	//�R���X�g���N�^
	ImageManager() {};

	//�f�X�g���N�^
	~ImageManager() {};

	//ImageManager�̍쐬
	static void CreateImageManager();

	//ImageManager�̍폜
	static void DeleteImageManager();

	//�A�z�z��Ɋi�[���ꂽImage�̃T�E���h�n���h�����擾����
	static int GetHandle(const char* fileName) { return manager->image[fileName]; }

	//�T�E���h�n���h����Image��ݒ肷��
	static void SetImage(const char* fileName);
};

