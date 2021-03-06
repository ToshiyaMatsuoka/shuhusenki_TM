﻿/**
* @file GameScene.cpp
* @brief メインゲームシーン処理
* @author Toshiya Matsuoka
*/
#include "GameScene.h"
#include "Goods.h"
#include "SubScene/FloaMove.h"
#include "SubScene/ChoseGoods.h"
#include "SubScene/BlowOff.h"
#include "SubScene/PickGoods.h"
#include "Timer.h"

Yasuko* GameScene::m_pYasuko = NULL;
bool GameScene::isFirst = false;

GameScene::GameScene(DirectX* pDirectX, SoundOperater* pSoundOperater) :Scene(pDirectX, pSoundOperater)
{
	m_pGoods->Initialize();
	if (!m_pYasuko) {
		m_pYasuko = new Yasuko(pDirectX, pSoundOperater);
	}
	if (!m_pSubScene) {
		m_pSubScene = new FloaMove(m_pDirectX, m_pSoundOperater, m_Turn, m_pYasuko);
	}
	m_pTimer = new Timer(pDirectX, pSoundOperater);
}

GameScene::~GameScene()
{
	delete m_pYasuko;
	m_pYasuko = NULL;
	delete m_pSubScene;
	m_pSubScene = NULL;
	delete m_pTimer;
	m_pTimer = NULL;
	m_pDirectX->ClearTexture();
	m_pDirectX->ClearFont();

}

int GameScene::Update()
{
	m_pXinputDevice->DeviceUpdate();
	m_pTimer->Update();
	if (m_CurrentGameScene != m_GameScene)
	{
		m_CurrentGameScene = m_GameScene;
		switch (m_GameScene)
		{
		case FLOAMOVE:
				delete m_pSubScene;
				m_pSubScene = new FloaMove(m_pDirectX, m_pSoundOperater, m_Turn, m_pYasuko);
			break;
		case CHOSEGOODS:
				delete m_pSubScene;
				m_pSubScene = new ChoseGoods(m_pDirectX, m_pSoundOperater, m_Turn, m_pYasuko);
			break;
		case BLOWOFF:
				delete m_pSubScene;
				m_pSubScene = new BlowOff(m_pDirectX, m_pSoundOperater, m_Turn, m_pYasuko);
			break;
		case PICKGOODS:
				delete m_pSubScene;
				m_pSubScene = new PickGoods(m_pDirectX, m_pSoundOperater, m_Turn, m_pYasuko);
			break;
		}
		return m_NextScene;
	}
	if (m_pTimer->GetGameStart()) {
		m_GameScene = m_pSubScene->Update();
	}
	else if(m_pTimer->GetTimeUp()){
		static int BehindCount = 0;
		++BehindCount;
		if (BehindCount > 120) {
			m_pTimer->Initialize();
			++m_Turn;
			if (m_Turn > 2) {
				m_pSubScene->Finalize();
				delete m_pSubScene;
				m_pSubScene = NULL;
				m_GameScene = FLOAMOVE;
				return RESULT_SCENE;
			}
			delete m_pSubScene;
			m_pSubScene = new FloaMove(m_pDirectX, m_pSoundOperater, m_Turn, m_pYasuko);
			BehindCount = 0;
		}
	}
	return m_NextScene;
}

void GameScene::KeyOperation()
{

}

void GameScene::Render()
{
	if (!m_pSubScene) return;
	m_pSubScene->Render();
	goodsScoreShow();
	m_pTimer->Render();
}

void GameScene::LoadResouce()
{
	m_pDirectX->LoadTexture("Resource/Texture/Blank.jpg", "BLANK");
	m_pDirectX->LoadTexture("Resource/Texture/Yasuko.png", "YASUKO_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/Mituko.png", "MITUKO_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/Isoko.png", "ISOKO_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/mob.png", "MOB_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/UI/frame_goods.png", "FRAME_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/effect.png", "YASUKO_EFFECT_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/FoodSection.png", "FOOD_STAGE_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/maxresdefault.png", "CUTIN_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/bakuhuhathu.png", "EXPLOSION_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/yasukoCutin.png", "CUTIN_YASUKO_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/UI/durabilityBar.jpg", "DURABILITY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/smoke.png", "SMOKE_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/boy.png", "BOY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/salesclerk.png", "SALESMAN_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/UI/timerFrame.png", "TIMER_FRAME_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/UI/timerHand.png", "TIMER_HAND_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/UI/startCount3.png", "STARTCOUNT_3_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/UI/startCount2.png", "STARTCOUNT_2_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/UI/startCount1.png", "STARTCOUNT_1_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/UI/salerogo.png", "START_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/pauseMenu.png", "PAUSE_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/UI/end.png", "TIMEUP_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/stage.png", "FLOAMOVE_BG_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/scoretext/s50e.png", "FIFTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/s60e.png", "SIXTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/s65e.png", "SIXTYFIVE_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/s100e.png", "HUNDRED_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/s150e.png", "HUNDREDFIFTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/s200e.png", "TWEHANDRED_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/s250e.png", "TWEHANDREDFIFTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/s300e.png", "THREEHANDRED_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/ss30e.png", "S_THRTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/ss40e.png", "S_FOURTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/ss50e.png", "S_FIFTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/ss60e.png", "S_SIXTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/ss70e.png", "S_SEVENTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/ss80e.png", "S_EIGHTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/ss100e.png", "S_HUNDRED_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/ss150e.png", "S_HUNDREDFIFTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/ss180e.png", "S_HUNDREDEIGHTY_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/ss200e.png", "S_TWEHUNDRED_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/scoretext/t1.png", "T_1");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/t2.png", "T_2");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/t3.png", "T_3");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/t4.png", "T_4");
	m_pDirectX->LoadTexture("Resource/Texture/scoretext/t5.png", "T_5");

	m_pDirectX->LoadTexture("Resource/Texture/button/a.png", "A_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/button/b.png", "B_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/button/x.png", "X_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/button/y.png", "Y_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/button/r.png", "R_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/button/l.png", "L_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/button/button.png", "NULL_BUTTON_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/merchandise/beef.png", "BEEF_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/chicken.png", "CHICKEN_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/pork.png", "PORK_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/wiener.png", "VIENNESE_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/mince.png", "MINCE_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/merchandise/shrimp.png", "SHRIMP_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/octopus.png", "OCTOPUS_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/squid.png", "INKFISH_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/fish.png", "FISH_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/merchandise/carrot.png", "GINESENG_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/onion.png", "ONION_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/potato.png", "POTATO_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/tomato.png", "TOMATO_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/radish.png", "RADISH_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/merchandise/snack.png", "POTATOCHIPS_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/choco.png", "CHOCOLATE_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/ice.png", "ICE_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/ricecracker.png", "RICECRACKER_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/merchandise/apple.png", "APPLE_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/orange.png", "ORANGE_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/banana.png", "BANANA_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/merchandise/tea.png", "TEA_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/juice.png", "JUICE_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/merchandise/beer.png", "BEER_TEX");

	m_pDirectX->SetFont(25, 25, "DEBUG_FONT", NULL);
	m_pDirectX->SetFont(70, 50, "HAVEGOODS_FONT", NULL);
}

void GameScene::goodsScoreShow()
{
	static int goodsInfoShowing;
	static int goodsInfoCount = 0;
	CUSTOMVERTEX GoodsShow[4];
	char goodsNumBuff[ARRAY_NUM];
	CreateSquareVertex(GoodsShow,10.f, 0, 1260.f, 90.f);
	m_pDirectX->DrawTexture("FRAME_TEX", GoodsShow);

	if (!m_pTimer->GetDeadline() && m_pTimer->GetGameStart())
	{
		switch (m_GameScene)
		{
		case FLOAMOVE:

			goodsInfoCount++;
			if (goodsInfoCount > 60)
			{
				switch (goodsInfoShowing)
				{
				case 0:
					goodsInfoShowing = 1;
					break;
				case 1:
					goodsInfoShowing = 2;
					break;
				case 2:
					goodsInfoShowing = 0;
					break;
				}
				goodsInfoCount = 0;
			}
			CreateSquareVertex(GoodsShow, 100.f, 10.f, 200.f, 80.f);
			DrawFoodTexture(m_pYasuko->EditMerchandise(goodsInfoShowing, 0), GoodsShow);
			CreateSquareVertex(GoodsShow, 200.f, 10.f, 300.f, 80.f);
			DrawPriceTexture( m_pYasuko->EditMerchandise(goodsInfoShowing, 0), 0, GoodsShow);
			CreateSquareVertex(GoodsShow, 300.f, 10.f, 400.f, 80.f);
			DrawPriceTexture(m_pYasuko->EditMerchandise(goodsInfoShowing, 0), 1, GoodsShow);
			//TODO:関数化
			CreateSquareVertex(GoodsShow, 800.f, 10.f, 900.f, 80.f);
			DrawFoodTexture(m_pYasuko->EditMerchandise(goodsInfoShowing, 1), GoodsShow);
			CreateSquareVertex(GoodsShow, 900.f, 10.f, 1000.f, 80.f);
			DrawPriceTexture(m_pYasuko->EditMerchandise(goodsInfoShowing, 1), 0, GoodsShow);
			CreateSquareVertex(GoodsShow, 1000.f, 10.f, 1100.f, 80.f);
			DrawPriceTexture(m_pYasuko->EditMerchandise(goodsInfoShowing, 1), 1, GoodsShow);

			break;

		case CHOSEGOODS:
			CreateSquareVertex(GoodsShow, 100.f, 10.f, 200.f, 80.f);
			DrawFoodTexture(m_pYasuko->EditMerchandise(m_SalesChoice, 0), GoodsShow);
			CreateSquareVertex(GoodsShow, 200.f, 10.f, 300.f, 80.f);
			DrawPriceTexture(m_pYasuko->EditMerchandise(m_SalesChoice, 0), 0, GoodsShow);
			CreateSquareVertex(GoodsShow, 300.f, 10.f, 400.f, 80.f);
			DrawPriceTexture(m_pYasuko->EditMerchandise(m_SalesChoice, 0), 1, GoodsShow);

			CreateSquareVertex(GoodsShow, 800.f, 10.f, 900.f, 80.f);
			DrawFoodTexture(m_pYasuko->EditMerchandise(m_SalesChoice, 1), GoodsShow);
			CreateSquareVertex(GoodsShow, 900.f, 10.f, 1000.f, 80.f);
			DrawPriceTexture(m_pYasuko->EditMerchandise(m_SalesChoice, 1), 0, GoodsShow);
			CreateSquareVertex(GoodsShow, 1000.f, 10.f, 1100.f, 80.f);
			DrawPriceTexture(m_pYasuko->EditMerchandise(m_SalesChoice, 1), 1, GoodsShow);

			break;
		case BLOWOFF:
		{
			CreateSquareVertex(GoodsShow, 310.f, 10.f, 400.f, 80.f);
			DrawFoodTexture(m_pGoods->GetselectedGoods(m_Turn), GoodsShow);
			CreateSquareVertex(GoodsShow, 450.f, 10.f, 600.f, 80.f);
			DrawPriceTexture(m_pGoods->GetselectedGoods(m_Turn), 0, GoodsShow);

			CreateSquareVertex(GoodsShow, 650.f, 10.f, 800.f, 80.f);
			DrawPriceTexture(m_pGoods->GetselectedGoods(m_Turn), 1, GoodsShow);

			sprintf_s(goodsNumBuff, ARRAY_NUM, "%dコ", m_pGoods->GetHaveValue(m_pGoods->GetselectedGoods(m_Turn)));
			RECT GoodsNUM = { 850 ,10,1100,80 };
			m_pDirectX->DrawWord(GoodsNUM, goodsNumBuff, "HAVEGOODS_FONT", DT_RIGHT, BLACK);

			break;
		}
		case PICKGOODS:
		{
			CreateSquareVertex(GoodsShow, 310.f, 10.f, 400.f, 80.f);
			DrawFoodTexture(m_pGoods->GetselectedGoods(m_Turn), GoodsShow);
			CreateSquareVertex(GoodsShow, 450.f, 10.f, 600.f, 80.f);
			DrawPriceTexture(m_pGoods->GetselectedGoods(m_Turn), 0, GoodsShow);

			CreateSquareVertex(GoodsShow, 650.f, 10.f, 800.f, 80.f);
			DrawPriceTexture(m_pGoods->GetselectedGoods(m_Turn), 1, GoodsShow);
			sprintf_s(goodsNumBuff, ARRAY_NUM, "%dコ", m_pGoods->GetHaveValue(m_pGoods->GetselectedGoods(m_Turn)));
			RECT GoodsNUM = { 850 ,10,1100,80 };
			m_pDirectX->DrawWord(GoodsNUM, goodsNumBuff, "HAVEGOODS_FONT", DT_RIGHT, BLACK);

			break;
		}
		}
	}
	if (m_pTimer->GetDeadline())
	{
		float scaleTimmer = 0;
		float posYTimmer = 0;
		std::string timmerTexture;

		switch (m_pTimer->TimeShow())
		{
		case 0:
			posYTimmer = 200;
			scaleTimmer = 200;
			timmerTexture = "T_1";
			break;
		case 1:
			posYTimmer = 200;
			scaleTimmer = 150;
			timmerTexture = "T_2";
			break;
		case 2:
			posYTimmer = 150;
			scaleTimmer = 100;
			timmerTexture = "T_3";
			break;
		case 3:
			posYTimmer = 100;
			scaleTimmer = 75;
			timmerTexture = "T_4";
			break;
		case 4:
			posYTimmer = 50;
			scaleTimmer = 40;
			timmerTexture = "T_5";
			break;
		}
		sprintf_s(goodsNumBuff, 10, "%dコ", m_pGoods->GetHaveValue(m_pGoods->GetselectedGoods(m_Turn)));
		RECT GoodsNUM = { 850 ,10,1100,80 };
		m_pDirectX->DrawWord( GoodsNUM,goodsNumBuff, "HAVEGOODS_FONT", DT_RIGHT, BLACK);

		CUSTOMVERTEX timeLimitShow[4];
		CENTRAL_STATE timeLimitShowCentral = { 640,posYTimmer,scaleTimmer,scaleTimmer };
		CreateSquareVertex(timeLimitShow, &timeLimitShowCentral);
		m_pDirectX->DrawTexture( timmerTexture,timeLimitShow);

		//char timeText[10];
		//sprintf_s(timeText, 10, "%d ", timeShow() + 1);
		//RECT timeLimit = { 200 ,10,1000,80 };
		//m_pDirectX->DrawWord(timeText, timeLimit, DT_CENTER, RED, HAVEGOODS_FONT);

	}
}

std::string GameScene::priceEdit(GOODSPARAMETER* foodGoods, int goodsselector, int nomalOrSale)
{
	if (!nomalOrSale)
	{
		switch (foodGoods[goodsselector].nominalCost)
		{
		case 300:
			return "THREEHANDRED_TEX";
		case 250:
			return "TWEHANDREDFIFTY_TEX";
		case 200:
			return "TWEHANDRED_TEX";
		case 150:
			return "HUNDREDFIFTY_TEX";
		case 100:
			return "HUNDRED_TEX";
		case 65:
			return "SIXTYFIVE_TEX";
		case 60:
			return "SIXTY_TEX";
		case 50:
			return "FIFTY_TEX";
		}
	}
	if (nomalOrSale)
	{
		switch (foodGoods[goodsselector].selePrice)
		{
		case 200:
			return "S_TWEHUNDRED_TEX";
		case 180:
			return "S_HUNDREDEIGHTY_TEX";
		case 150:
			return "S_HUNDREDFIFTY_TEX";
		case 100:
			return "S_HUNDRED_TEX";
		case 80:
			return "S_EIGHTY_TEX";
		case 70:
			return "S_SEVENTY_TEX";
		case 60:
			return "S_SIXTY_TEX";
		case 50:
			return "S_FIFTY_TEX";
		case 40:
			return "S_FOURTY_TEX";
		case 30:
			return "S_THRTY_TEX";
		}
		return "BLANK";
	}
	return "BLANK";
}

void GameScene::DrawFoodTexture(int arrayNum ,CUSTOMVERTEX* vertex) {
	m_pDirectX->DrawTexture(m_pGoods->GetFoodGoodsTexID(arrayNum), vertex);
}
void GameScene::DrawPriceTexture(int arrayNum,int NomalOrSale, CUSTOMVERTEX* vertex) {
	m_pDirectX->DrawTexture(priceEdit(m_pGoods->GetfoodGoods(), arrayNum, NomalOrSale), vertex);

}

