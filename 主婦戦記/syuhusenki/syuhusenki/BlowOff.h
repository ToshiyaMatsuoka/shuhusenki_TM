#ifndef BLOWOFF_H
#define BLOWOFF_H
#include "SubScene.h"

class BlowOff :
	public SubScene
{
public:
	BlowOff(DirectX * pDirectX, SoundOperater * pSoundOperater, int turn, Yasuko* pYasuko);
	~BlowOff();
	int Update();
	void BlowOffKeyOperation();
	void LoadResouce();
	void Render();
	char ComandButton(int comand);
	void ComandMake();
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