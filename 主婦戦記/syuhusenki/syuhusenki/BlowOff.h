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
	char comandButton(int comand);
	void comandMake();
	int comandCheck();
private:
	int comandInput[5];
	int comandPresentment[5];
	int comandCount = 0;
	int checkedComand;
	bool m_isBlowOff = false;
	CUSTOMVERTEX effectExplosion[4];
	CENTRAL_STATE effectExplosionCentral;
	std::string m_mobTexKey;
	int m_TurningAnimetion = 0;
	const float MobHeight = 550.f;
};


//extern CUSTOMVERTEX effectExplosion[4];
//extern CENTRAL_STATE effectExplosionCentral;
//
//extern bool g_isBlowOff;

//void blowOff();
//void blowOffControl();
//void blowOffRender();
//void blowOffDeviseControl(int* i, int comand[]);
//void madamBlowOff();
//int comandCheck(int comand[], int inputComand[], int count);
//void comandMake();
//char comandButton(int comand);
//std::string comandButtonTexture(int comand);
//void RevolveZTuTv(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float tu, float tv, float scaleTu, float scaleTv);

#endif