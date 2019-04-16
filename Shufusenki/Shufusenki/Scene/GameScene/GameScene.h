#ifndef GAMESCENE_H
#define GAMESCENE_H
/**
* @file GameScene.h
* @brief メインゲームシーン処理
* @author Toshiya Matsuoka
*/

#include "Scene/Scene.h"
#include "SubScene/SubScene.h"


class FloaMove;
class Object;
class Timer;

class GameScene :public Scene
{
public:
	GameScene(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~GameScene();
	int Update();
	void KeyOperation();

	void Render();
	void LoadResouce();

	void goodsScoreShow();

	std::string priceEdit(GOODSPARAMETER* foodGoods, int goodsselector, int nomalOrSale);

	void DebugSetting();

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
	int m_BlowOffEffectCount;
	int m_Turn = 0;
	float mobRad;
	bool m_TimeDeadline = false;
	bool m_isGameStart = true;
	int m_CurrentGameScene= DEFAULT;
	static const int ARRAY_NUM = 64;

	void DrawFoodTexture( int arrayNum, CUSTOMVERTEX* vertex);

	void DrawPriceTexture(int arrayNum, int NomalOrSale, CUSTOMVERTEX * vertex);


	CENTRAL_STATE mobCentralFloa[4]
	{
		{ 620,630 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
	{ 600,300 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
	{ 120,500 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
	{ 1030,230 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE }

	};
};
#endif
