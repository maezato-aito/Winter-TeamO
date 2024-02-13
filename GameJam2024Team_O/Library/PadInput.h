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
	static void Update();

	//コントローラー1がボタンを押したとき
	static bool OnButton1(int button);

	//コントローラー2がボタンを押したとき
	static bool OnButton2(int button);

	//コントローラー1がボタンを押しているとき
	static bool OnPressed1(int button);

	//コントローラー2がボタンを押しているとき
	static bool OnPressed2(int button);

	//コントローラー1がボタンを離したとき
	static bool OnRelease1(int button);

	//コントローラー2がボタンを離したとき
	static bool OnRelease2(int button);

	//コントローラー1の右スティックの取得
	static Stick GetRStick1();

	//コントローラー2の右スティックの取得
	static Stick GetRStick2();

	//コントローラー1の左スティックの取得
	static Stick GetLStick1();

	//コントローラー2の左スティックの取得
	static Stick GetLStick2();

	//コントローラー1の右スティックのxの割合
	static float GetRStickRationX1();

	//コントローラー2の右スティックのxの割合
	static float GetRStickRationX2();

	//コントローラー1の右スティックのyの割合
	static float GetRStickRationY1();

	//コントローラー2の右スティックのyの割合
	static float GetRStickRationY2();

	//コントローラー1の左スティックのxの割合
	static float GetLStickRationX1();

	//コントローラー2の左スティックのxの割合
	static float GetLStickRationX2();

	//コントローラー1の左スティックのyの割合
	static float GetLStickRationY1();

	//コントローラー2の左スティックのyの割合
	static float GetLStickRationY2();

	//前回のキーを取得
	static char GetOldKey(const int i);

	//現在のキーを取得
	static char GetNowKey(const int i);
};
