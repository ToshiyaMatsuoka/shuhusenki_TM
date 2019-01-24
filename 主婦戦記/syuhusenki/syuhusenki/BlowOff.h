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
	void LoadResouce();
	void Render();
	std::string comandButtonTexture(int comand);
	char comandButton(int comand);
	void comandMake();
	void madamBlowOff();
	int comandCheck(int comand[], int inputComand[], int count);
private:
	int comandInput[5];
	int comandPresentment[5];
	CENTRAL_STATE mobCentralBlowOff[5];
	int m_EffectCount = 0;
	int comandCount;
	int checkedComand;
	bool m_isBlowOff;
	CUSTOMVERTEX effectExplosion[4];
	CENTRAL_STATE effectExplosionCentral = { 1000,800,300,300 };

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