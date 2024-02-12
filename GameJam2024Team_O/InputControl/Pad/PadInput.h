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
	static void Update()
	{
		//���̓L�[�擾
		GetJoypadXInputState(DX_INPUT_PAD1, &input1);
		GetJoypadXInputState(DX_INPUT_PAD2, &input2);

		for (int i = 0; i < BUTTON; i++)
		{
			old_key1[i] = now_key1[i];
			old_key2[i] = now_key2[i];
			now_key1[i] = input1.Buttons[i];
			now_key2[i] = input2.Buttons[i];
		}

		//���X�e�B�b�N
		l_stick1.x = input1.ThumbLX;
		l_stick2.x = input2.ThumbLX;
		l_stick1.y = input1.ThumbLY;
		l_stick2.y = input2.ThumbLY;

		//�E�X�e�B�b�N
		r_stick1.x = input1.ThumbRX;
		r_stick2.x = input2.ThumbRX;
		r_stick1.y = input1.ThumbRY;
		r_stick2.y = input2.ThumbRY;
	}

	//�R���g���[���[1���{�^�����������Ƃ�
	static bool OnButton1(int button)
	{
		bool ret = (now_key1[button] == TRUE && old_key1[button] == FALSE);
		return ret;
	}

	//�R���g���[���[2���{�^�����������Ƃ�
	static bool OnButton2(int button)
	{
		bool ret = (now_key2[button] == TRUE && old_key2[button] == FALSE);
		return ret;
	}

	//�R���g���[���[1���{�^���������Ă���Ƃ�
	static bool OnPressed1(int button)
	{
		bool ret = (now_key1[button] == TRUE);
		return ret;
	}

	//�R���g���[���[2���{�^���������Ă���Ƃ�
	static bool OnPressed2(int button)
	{
		bool ret = (now_key2[button] == TRUE);
		return ret;
	}

	//�R���g���[���[1���{�^���𗣂����Ƃ�
	static bool OnRelease1(int button)
	{
		bool ret = (now_key1[button] == FALSE && old_key1[button] == TRUE);
		return ret;
	}

	//�R���g���[���[2���{�^���𗣂����Ƃ�
	static bool OnRelease2(int button)
	{
		bool ret = (now_key2[button] == FALSE && old_key2[button] == TRUE);
		return ret;
	}

	//�R���g���[���[1�̉E�X�e�B�b�N�̎擾
	static Stick GetRStick1()
	{
		return r_stick1;
	}

	//�R���g���[���[2�̉E�X�e�B�b�N�̎擾
	static Stick GetRStick2()
	{
		return r_stick2;
	}

	//�R���g���[���[1�̍��X�e�B�b�N�̎擾
	static Stick GetLStick1()
	{
		return l_stick1;
	}

	//�R���g���[���[2�̍��X�e�B�b�N�̎擾
	static Stick GetLStick2()
	{
		return l_stick2;
	}

	//�R���g���[���[1�̉E�X�e�B�b�N��x�̊���
	static float GetRStickRationX1()
	{
		return r_stick1.x / STICK_MAX;
	}

	//�R���g���[���[2�̉E�X�e�B�b�N��x�̊���
	static float GetRStickRationX2()
	{
		return r_stick2.x / STICK_MAX;
	}

	//�R���g���[���[1�̉E�X�e�B�b�N��y�̊���
	static float GetRStickRationY1()
	{
		return r_stick1.y / STICK_MAX;
	}

	//�R���g���[���[2�̉E�X�e�B�b�N��y�̊���
	static float GetRStickRationY2()
	{
		return r_stick2.y / STICK_MAX;
	}

	//�R���g���[���[1�̍��X�e�B�b�N��x�̊���
	static float GetLStickRationX1()
	{
		return l_stick1.x / STICK_MAX;
	}

	//�R���g���[���[2�̍��X�e�B�b�N��x�̊���
	static float GetLStickRationX2()
	{
		return l_stick2.x / STICK_MAX;
	}

	//�R���g���[���[1�̍��X�e�B�b�N��y�̊���
	static float GetLStickRationY1()
	{
		return l_stick1.y / STICK_MAX;
	}

	//�R���g���[���[2�̍��X�e�B�b�N��y�̊���
	static float GetLStickRationY2()
	{
		return l_stick2.y / STICK_MAX;
	}

	static char GetOldKey(const int i)
	{
		return old_key1[i];
	}

	static char GetNowKey(const int i)
	{
		return now_key1[i];
	}
};

