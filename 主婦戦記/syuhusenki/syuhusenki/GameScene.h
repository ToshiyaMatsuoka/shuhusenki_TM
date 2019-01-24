#pragma once
#include "Scene.h"
#include "SubScene.h"


class FloaMove;
class Object;


struct SoundEffect {
	char SE1[20];
	char SE2[20];
	char SE3[20];
	char SE4[20];
	char SE5[20];
	char SE6[20];
	char SE7[20];
	char SE8[20];
	char SE9[20];
	char SE10[20];
	char SE11[20];
	char SE12[20];
	char SE13[20];
	char SE14[20];
	char SE15[20];
};

class GameScene :public Scene
{
public:
	friend FloaMove;
	GameScene(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~GameScene();
	int Update();
	void KeyOperation();

	void Render();
	void LoadResouce();

	void goodsScoreShow();

	std::string priceEdit(GOODSPARAMETER* foodGoods, int goodsselector, int nomalOrSale);


	CENTRAL_STATE mobCentralFloa[4]
	{
		{ 620,630 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
		{ 600,300 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
		{ 120,500 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
		{ 1030,230 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE }
	
	};
	void SetGameScene(GAMESCENE gamescene) {
		m_GameScene = gamescene;
	}
private:
	static Yasuko* m_pYasuko;
	static bool isFirst;
	SubScene* m_pSubScene;

	const float MOB_FLOA_SCALE = 50;
	int comandCount;
	int checkedComand;
	int rushButtonShow;
	int effectCount;
	int effectIntervalPrev;
	int blowOffEffectIntervalPrev;
	std::string texturePC;
	int m_GameScene = FLOAMOVE;
	int m_EffectCount;
	int m_BlowOffPCEffectCount;
	int m_Turn = 0;
	float mobRad;
	bool m_TimeDeadline = false;
	bool m_isGameStart = true;
	int m_CurrentGameScene;
	SoundEffect Button;
	SoundEffect Pick;
};

