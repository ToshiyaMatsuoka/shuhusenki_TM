#pragma once
#include "Scene.h"
#include "SubScene.h"


class FloaMove;
class Object;
class Timer;

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

	void DebugSetting();


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
	SubScene* m_pSubScene = NULL;
	Timer* m_pTimer = NULL;

	const float MOB_FLOA_SCALE = 50;
	int comandCount;
	int checkedComand;
	int rushButtonShow;
	int m_EffectCount;
	int effectIntervalPrev;
	int blowOffEffectIntervalPrev;
	std::string texturePC;
	int m_GameScene = FLOAMOVE;
	int m_BlowOffPCEffectCount;
	int m_Turn = 0;
	float mobRad;
	bool m_TimeDeadline = false;
	bool m_isGameStart = true;
	int m_CurrentGameScene;
	static const int ARRAY_NUM = 64;
};

