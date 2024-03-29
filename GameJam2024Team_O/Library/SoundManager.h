#pragma once
#include<DxLib.h>
#include<map>
#include<string>

class SoundManager
{
private:
	static SoundManager* manager;			//オブジェクト

	std::string directoryPathBGM;			//BGMのディレクトリ
	std::string directoryPathSE;			//SEのディレクトリ

	std::map<std::string, int>bgm;			//連想配列bgm
	std::map<std::string, int>se;			//連想配列se
public:
	//コンストラクタ
	SoundManager() :directoryPathBGM("Resource/Sounds/BGM/"), directoryPathSE("Resource/Sounds/SE/") {};

	//デストラクタ
	~SoundManager() {};

	//SoundManagerの作成
	static void CreateSoundManager();

	//SoundManagerの削除
	static void DeleteSoundManager();

	//BGMのディレクトリを設定する
	//＊デフォルトは"Resource/Sounds/BGM/"
	static void SetDirectoryPathBGM(const char fileName);

	//SEのディレクトリを設定する
	//＊デフォルトは"Resource/Sounds/SE/"
	static void SetDirectoryPathSE(const char fileName);

	//連想配列に格納されたBGMのサウンドハンドルを取得する
	static int GetBGMHandle(const char* fileName) { return manager->bgm[fileName]; }

	//連想配列に格納されたSEのサウンドハンドルを取得する
	static int GetSEHandle(const char* fileName) { return manager->se[fileName]; }

	//サウンドハンドルにBGMを設定する
	static void SetBGM(const char* fileName);

	//サウンドハンドルにSEを設定する
	static void SetSE(const char* fileName);

	//BGMの音量を設定する
	static void SetVolumeBGM(const char* fileName, const int volume);

	//SEの音量を設定する
	static void SetVolumeSE(const char* fileName, const int volume);

	//すべてのBGMの音量を設定する
	static void SetVolumeBGMs(const int volume);

	//すべてのSEの音量を設定する
	static void SetVolumeSEs(const int volume);

	//BGMの再生位置を設定する
	//＊再生位置をミリ秒単位で変更する
	static void SetSoundBGMPosition(LONGLONG time, const char* fileName);

	//すべてのBGMの再生位置を設定する
	//＊再生位置をミリ秒単位で変更する
	static void SetSoundBGMsPosition(LONGLONG time);

	//SEの再生位置を設定する
	//＊再生位置をミリ秒単位で変更する
	static void SetSoundSEPosition(LONGLONG time, const char* fileName);

	//すべてのSEの再生位置を設定する
	//＊再生位置をミリ秒単位で変更する
	static void SetSoundSEsPosition(LONGLONG time);

	//BGMを再生する
	//＊isSingleUnitはtrueなら音を重ねない、falseなら音を重ねる、デフォルトはtrue
	//＊デフォルトの再生形式はループ、再生位置は最後に止めたところか、再生位置を指定したところから
	static void PlaySoundBGM(const char* fileName, bool isSingleUnit = true, int playType = DX_PLAYTYPE_LOOP, int topPositionFlag = FALSE);

	//SEを再生する
	//＊isSingleUnitはtrueなら音を重ねない、falseなら音を重ねる、デフォルトはtrue
	//＊デフォルトの再生形式はバック、再生位置は先頭から
	static void PlaySoundSE(const char* fileName, bool isSingleUnit = true, int playType = DX_PLAYTYPE_BACK, int topPositionFlag = TRUE);

	//BGMを停止する
	static void StopSoundBGM(const char* fileName);

	//すべてのBGMを停止する
	static void StopSoundBGMs();

	//SEを停止する
	static void StopSoundSE(const char* fileName);

	//すべてのSEを停止する
	static void StopSoundSEs();
};