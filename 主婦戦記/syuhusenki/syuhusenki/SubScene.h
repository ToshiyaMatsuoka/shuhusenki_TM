#pragma once
#include "Goods.h"
#include "Yasuko.h"
#include "Scene.h"

enum GAMESCENE {
	FLOAMOVE,
	CHOSEGOODS,
	BLOWOFF,
	PICKGOODS,
};
struct SoundEffect {
	const char SE1[20];
	const char SE2[20];
	const char SE3[20];
	const char SE4[20];
	const char SE5[20];
	const char SE6[20];
	const char SE7[20];
	const char SE8[20];
	const char SE9[20];
	const char SE10[20];
	const char SE11[20];
	const char SE12[20];
	const char SE13[20];
	const char SE14[20];
	const char SE15[20];

};

class SubScene :
	public Scene
{
public:
	SubScene(DirectX* pDirectX, SoundOperater* pSoundOperater, int turn, Yasuko* pYasuko);
	virtual ~SubScene();

	std::string comandButtonTexture(int comand);

	void ButtonSE(SoundEffect Button, int SoundNumber);

	void madamBlowOff();

protected:
	static CENTRAL_STATE mobCentralBlowOff[5];
	const float CHARCTOR_BLOWOFF_SCALE = 150.f;
	int m_Turn = 0;
	int m_EffectCount = 0;

	static int m_GameScene;
	Yasuko* m_pYasuko;
	void SetGameScene(int gamescene) {
		m_GameScene = gamescene;
	}
	const DWORD WHITE = 0xFFFFFFFF;
	int m_effectCount = 0;
	CUSTOMVERTEX playerHit[4];
	CENTRAL_STATE playerCentralHit;
	SoundEffect Button = { "BUTTON1","BUTTON2","BUTTON3" };
	SoundEffect Pick = { "PICK1", "PICK2","PICK3", "PICK4","PICK5", "PICK6" , "PICK7" ,"PICK8","PICK9","PICK10","PICK11", "PICK12","PICK13", "PICK14","PICK15" };

};

