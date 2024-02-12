#pragma once
#include"DxLib.h"

#define BUTTON 16
#define STICK_MAX 32767.f
#define QUARTER 32767*0.25

struct Stick
{
	short x;	//縦軸
	short y;	//横軸
};

class PadInput
{
private:
	static char now_key1[BUTTON];	//今回のキー1
	static char now_key2[BUTTON];	//今回のキー2
	static char old_key1[BUTTON];	//前回のキー1
	static char old_key2[BUTTON];	//前回のキー2
	static XINPUT_STATE input1;		//パッド情報1
	static XINPUT_STATE input2;		//パッド情報2
	static Stick l_stick1;			//左スティック1
	static Stick l_stick2;			//左スティック1
	static Stick r_stick1;			//右スティック1
	static Stick r_stick2;			//右スティック1
private:
	PadInput() = default;
public:
	//更新処理
	static void Update()
	{
		//入力キー取得
		GetJoypadXInputState(DX_INPUT_PAD1, &input1);
		GetJoypadXInputState(DX_INPUT_PAD2, &input2);

		for (int i = 0; i < BUTTON; i++)
		{
			old_key1[i] = now_key1[i];
			old_key2[i] = now_key2[i];
			now_key1[i] = input1.Buttons[i];
			now_key2[i] = input2.Buttons[i];
		}

		//左スティック
		l_stick1.x = input1.ThumbLX;
		l_stick2.x = input2.ThumbLX;
		l_stick1.y = input1.ThumbLY;
		l_stick2.y = input2.ThumbLY;

		//右スティック
		r_stick1.x = input1.ThumbRX;
		r_stick2.x = input2.ThumbRX;
		r_stick1.y = input1.ThumbRY;
		r_stick2.y = input2.ThumbRY;
	}

	//コントローラー1がボタンを押したとき
	static bool OnButton1(int button)
	{
		bool ret = (now_key1[button] == TRUE && old_key1[button] == FALSE);
		return ret;
	}

	//コントローラー2がボタンを押したとき
	static bool OnButton2(int button)
	{
		bool ret = (now_key2[button] == TRUE && old_key2[button] == FALSE);
		return ret;
	}

	//コントローラー1がボタンを押しているとき
	static bool OnPressed1(int button)
	{
		bool ret = (now_key1[button] == TRUE);
		return ret;
	}

	//コントローラー2がボタンを押しているとき
	static bool OnPressed2(int button)
	{
		bool ret = (now_key2[button] == TRUE);
		return ret;
	}

	//コントローラー1がボタンを離したとき
	static bool OnRelease1(int button)
	{
		bool ret = (now_key1[button] == FALSE && old_key1[button] == TRUE);
		return ret;
	}

	//コントローラー2がボタンを離したとき
	static bool OnRelease2(int button)
	{
		bool ret = (now_key2[button] == FALSE && old_key2[button] == TRUE);
		return ret;
	}

	//コントローラー1の右スティックの取得
	static Stick GetRStick1()
	{
		return r_stick1;
	}

	//コントローラー2の右スティックの取得
	static Stick GetRStick2()
	{
		return r_stick2;
	}

	//コントローラー1の左スティックの取得
	static Stick GetLStick1()
	{
		return l_stick1;
	}

	//コントローラー2の左スティックの取得
	static Stick GetLStick2()
	{
		return l_stick2;
	}

	//コントローラー1の右スティックのxの割合
	static float GetRStickRationX1()
	{
		return r_stick1.x / STICK_MAX;
	}

	//コントローラー2の右スティックのxの割合
	static float GetRStickRationX2()
	{
		return r_stick2.x / STICK_MAX;
	}

	//コントローラー1の右スティックのyの割合
	static float GetRStickRationY1()
	{
		return r_stick1.y / STICK_MAX;
	}

	//コントローラー2の右スティックのyの割合
	static float GetRStickRationY2()
	{
		return r_stick2.y / STICK_MAX;
	}

	//コントローラー1の左スティックのxの割合
	static float GetLStickRationX1()
	{
		return l_stick1.x / STICK_MAX;
	}

	//コントローラー2の左スティックのxの割合
	static float GetLStickRationX2()
	{
		return l_stick2.x / STICK_MAX;
	}

	//コントローラー1の左スティックのyの割合
	static float GetLStickRationY1()
	{
		return l_stick1.y / STICK_MAX;
	}

	//コントローラー2の左スティックのyの割合
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

