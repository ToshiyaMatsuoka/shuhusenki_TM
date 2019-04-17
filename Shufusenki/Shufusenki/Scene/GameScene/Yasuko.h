#ifndef YASUKO_H
#define YASUKO_H
/**
* @file Yasuko.h
* @brief 主人公処理
* @author Toshiya Matsuoka
*/

#include "Object.h"

class Yasuko :
	public Object
{
public:
	Yasuko(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~Yasuko();
	void mobToPCContact(CENTRAL_STATE * mobCentralFloa);
	//! フロア移動時の更新
	void FloaUpdate();
	//! コマンド入力時の更新
	void BlowOffUpdate(bool isAttack);
	//! フロア移動時の描画
	void FloaRender();
	//! コマンド入力時の描画
	void BlowOffRender();
	//! コマンド入力時の初期化
	void InitBlowoff();
	void KeyOperation(KeyInput key);
	void TurnTheAnimation(int AnimationPage);
	//! フロア移動時の移動処理
	void FloaMoveUpdate();

	void FloaMoveLeft();

	void FloaMoveRight();

	void FloaMoveUp();

	void FloaMoveDown();

	void  Initialize();
	//! Aボタンの表示
	void ShowA();
private:
	CUSTOMVERTEX m_EffectVertex[4];
	CENTRAL_STATE m_EffectCentral;
	const float CHARCTOR_BLOWOFF_SCALE = 150.f;
	CENTRAL_STATE m_BOCenter = { 200, 550, (CHARCTOR_BLOWOFF_SCALE - 50.f), CHARCTOR_BLOWOFF_SCALE };

	const float MOVE_SPEED = 2.f;
	bool m_isRight = false;
	int m_AnimeCount = 0;
	int salesChoice;
	int m_TurningAnimetion = 0;
	int m_ChangeAnimetion = 0;
	int m_EffectCount = 0;
	const float YASUKO_TU = (350.f / 2048.f);
	const float YASUKO_TV = (679.f / 2048.f);
	const float EFFECT_TU = (500.f / 2048.f);
	const float EFFECT_TV = (700.f / 2048.f);
	bool m_ReachedSalesman = false;
};
#endif
