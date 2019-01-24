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

class SubScene :
	public Scene
{
public:
	SubScene(DirectX* pDirectX, SoundOperater* pSoundOperater, int turn, Yasuko* pYasuko);
	virtual ~SubScene();

protected:
	const float CHARCTOR_BLOWOFF_SCALE = 150.f;
	int m_Turn = 0;

	static int m_GameScene;
	Yasuko* m_pYasuko;
	void SetGameScene(int gamescene) {
		m_GameScene = gamescene;
	}
	const DWORD WHITE = 0xFFFFFFFF;
	int m_effectCount = 0;
	CUSTOMVERTEX playerHit[4];
	CENTRAL_STATE playerCentralHit;

};

