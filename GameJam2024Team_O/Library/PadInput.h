#pragma once
#include"DxLib.h"

#define BUTTON 16
#define STICK_MAX 32767.f
#define QUARTER 32767*0.25

struct Stick
{
	short x;	//�c��
	short y;	//����
};

class PadInput
{
private:
	static char now_key1[BUTTON];	//����̃L�[1
	static char now_key2[BUTTON];	//����̃L�[2
	static char old_key1[BUTTON];	//�O��̃L�[1
	static char old_key2[BUTTON];	//�O��̃L�[2
	static XINPUT_STATE input1;		//�p�b�h���1
	static XINPUT_STATE input2;		//�p�b�h���2
	static Stick l_stick1;			//���X�e�B�b�N1
	static Stick l_stick2;			//���X�e�B�b�N1
	static Stick r_stick1;			//�E�X�e�B�b�N1
	static Stick r_stick2;			//�E�X�e�B�b�N1
private:
	PadInput() = default;
public:
	//�X�V����
	static void Update();

	//�R���g���[���[1���{�^�����������Ƃ�
	static bool OnButton1(int button);

	//�R���g���[���[2���{�^�����������Ƃ�
	static bool OnButton2(int button);

	//�R���g���[���[1���{�^���������Ă���Ƃ�
	static bool OnPressed1(int button);

	//�R���g���[���[2���{�^���������Ă���Ƃ�
	static bool OnPressed2(int button);

	//�R���g���[���[1���{�^���𗣂����Ƃ�
	static bool OnRelease1(int button);

	//�R���g���[���[2���{�^���𗣂����Ƃ�
	static bool OnRelease2(int button);

	//�R���g���[���[1�̉E�X�e�B�b�N�̎擾
	static Stick GetRStick1();

	//�R���g���[���[2�̉E�X�e�B�b�N�̎擾
	static Stick GetRStick2();

	//�R���g���[���[1�̍��X�e�B�b�N�̎擾
	static Stick GetLStick1();

	//�R���g���[���[2�̍��X�e�B�b�N�̎擾
	static Stick GetLStick2();

	//�R���g���[���[1�̉E�X�e�B�b�N��x�̊���
	static float GetRStickRationX1();

	//�R���g���[���[2�̉E�X�e�B�b�N��x�̊���
	static float GetRStickRationX2();

	//�R���g���[���[1�̉E�X�e�B�b�N��y�̊���
	static float GetRStickRationY1();

	//�R���g���[���[2�̉E�X�e�B�b�N��y�̊���
	static float GetRStickRationY2();

	//�R���g���[���[1�̍��X�e�B�b�N��x�̊���
	static float GetLStickRationX1();

	//�R���g���[���[2�̍��X�e�B�b�N��x�̊���
	static float GetLStickRationX2();

	//�R���g���[���[1�̍��X�e�B�b�N��y�̊���
	static float GetLStickRationY1();

	//�R���g���[���[2�̍��X�e�B�b�N��y�̊���
	static float GetLStickRationY2();

	//�O��̃L�[���擾
	static char GetOldKey(const int i);

	//���݂̃L�[���擾
	static char GetNowKey(const int i);
};
