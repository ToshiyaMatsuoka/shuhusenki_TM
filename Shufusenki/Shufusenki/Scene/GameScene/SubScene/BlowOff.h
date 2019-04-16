#ifndef BLOWOFF_H
#define BLOWOFF_H
/**
* @file BlowOff.h
* @brief コマンド入力シーン処理
* @author Toshiya Matsuoka
*/

#include "Scene/GameScene/SubScene/SubScene.h"

class BlowOff :
	public SubScene
{
public:
	BlowOff(DirectX * pDirectX, SoundOperater * pSoundOperater, int turn, Yasuko* pYasuko);
	~BlowOff();
	int Update();
	void KeyOperation();
	void LoadResouce();
	void Render();
	/**
	* @brief 入力ボタンを文字列で返す
	*/
	char ComandButton(int comand);
	/*
	* @brief 提示コマンドの抽選
	*/
	void ComandMake();
	/*
	* @brief 入力コマンドと提示コマンドの照合
	*/
	int ComandCheck();
private:
	int m_ComandInput[5];
	int m_ComandPresentment[5];
	int m_ComandCount = 0;
	int m_CheckedComand;
	bool m_isBlowOff = false;
	CUSTOMVERTEX m_EffectExplosion[4];
	CENTRAL_STATE m_EffectExplosionCentral;
	std::string m_MobTexKey;
	int m_TurningAnimetion = 0;
	const float MOB_HEIGHT = 550.f;
};

#endif