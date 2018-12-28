#include "GameScene.h"



GameScene::GameScene(DirectX* pDirectX, SoundOperater* pSoundOperater) :Scene(pDirectX, pSoundOperater)
{

}

GameScene::~GameScene()
{
	m_pDirectX->ClearTexture();
	m_pDirectX->ClearFont();
}

SCENE_NUM GameScene::Update()
{

	switch (m_GameScene)
	{
	case FLOAMOVE:
	{
		switch (m_Turn)
		{
		case 0:
			mobTexNum = "ISOKO_TEX";
			break;
		case 1:
			mobTexNum = "MOB_TEX";
			break;
		case 2:
			mobTexNum = "MITUKO_TEX";
			break;
		}

		for (int i = 0; i < 5; i++)
		{
			comandInput[i] = 10;
		}
		m_isBlowOff = false;

		//floaMove();

		if (m_pDirectX->GetKeyStatus(DIK_0) == KeyRelease)
		{
			for (int i = 0; i < 3; i++)
			{
				popSales[i].goodsSorting = rand() % 6;//フロア移動で決めたものを入れる
			}
			selectGoods(&popSales[0]);
			selectGoods(&popSales[1]);
			selectGoods(&popSales[2]);
		}
		if (m_pDirectX->GetKeyStatus(DIK_1) == KeyRelease)
		{
			m_SalesChoice = 0;
		}
		if (m_pDirectX->GetKeyStatus(DIK_2) == KeyRelease)
		{
			m_SalesChoice = 1;
		}
		if (m_pDirectX->GetKeyStatus(DIK_3) == KeyRelease)
		{
			m_SalesChoice = 2;
		}
		break;
	}
	case CHOSEGOODS:

		//choseGoods();
		break;
	case PUSHENEMY:
		if (!m_isBlowOff)
		{

			//mobCentralBlowOff[0] = { 450,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
			//mobCentralBlowOff[1] = { 600,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
			//mobCentralBlowOff[2] = { 750,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
			//mobCentralBlowOff[3] = { 900,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
			//mobCentralBlowOff[4] = { 1050,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
			//
			//effectExplosionCentral = { 900,750,300,300 };
			//g_effectCount = 0;
			//playerCutinCentral.x = 1200;
		}
		//blowOff();
		break;
	case PICKGOODS:
		//pickGoods();
		//comandMake();
		for (int i = 0; i < 5; i++)
		{
			comandInput[i] = 10;
		}
		break;
	}

	return SCENE_NONE;
}

void GameScene::KeyOperation()
{
}

void GameScene::Render()
{
	switch (m_GameScene)
	{
	case FLOAMOVE:
		break;
	case CHOSEGOODS:
		break;
	case PUSHENEMY:
		break;
	case PICKGOODS:
		break;
	}

	goodsScoreShow();
}

void GameScene::LoadResouce()
{
	m_pDirectX->LoadTexture("Texture/Blank.jpg", "BLANK");
	m_pDirectX->LoadTexture("Texture/Yasuko.png", "YASUKO_TEX");
	m_pDirectX->LoadTexture("Texture/Mituko.png", "MITUKO_TEX");
	m_pDirectX->LoadTexture("Texture/Isoko.png", "ISOKO_TEX");
	m_pDirectX->LoadTexture("Texture/mob.png", "MOB_TEX");

	m_pDirectX->LoadTexture("Texture/UI/frame_goods.png", "FRAME_TEX");
	m_pDirectX->LoadTexture("Texture/effect.png", "YASUKO_EFFECT_TEX");

	m_pDirectX->LoadTexture("Texture/FoodSection.png", "FOOD_STAGE_TEX");
	m_pDirectX->LoadTexture("Texture/maxresdefault.png", "CUTIN_TEX");
	m_pDirectX->LoadTexture("Texture/bakuhuhathu.png", "EXPLOSION_TEX");
	m_pDirectX->LoadTexture("Texture/yasukoCutin.png", "CUTIN_YASUKO_TEX");
	m_pDirectX->LoadTexture("Texture/UI/durabilityBar.jpg", "DURABILITY_TEX");
	m_pDirectX->LoadTexture("Texture/smoke.png", "SMOKE_TEX");
	m_pDirectX->LoadTexture("Texture/boy.png", "BOY_TEX");
	m_pDirectX->LoadTexture("Texture/salesclerk.png", "SALESMAN_TEX");

	m_pDirectX->LoadTexture("Texture/UI/timerFrame.png", "TIMER_FRAME_TEX");
	m_pDirectX->LoadTexture("Texture/UI/timerHand.png", "TIMER_HAND_TEX");
	m_pDirectX->LoadTexture("Texture/UI/startCount3.png", "STARTCOUNT_3_TEX");
	m_pDirectX->LoadTexture("Texture/UI/startCount2.png", "STARTCOUNT_2_TEX");
	m_pDirectX->LoadTexture("Texture/UI/startCount1.png", "STARTCOUNT_1_TEX");
	m_pDirectX->LoadTexture("Texture/UI/salerogo.png", "START_TEX");
	m_pDirectX->LoadTexture("Texture/pauseMenu.png", "PAUSE_TEX");
	m_pDirectX->LoadTexture("Texture/UI/end.png", "TIMEUP_TEX");
	m_pDirectX->LoadTexture("Texture/stage.png", "FLOAMOVE_BG_TEX");

	m_pDirectX->LoadTexture("Texture/scoretext/s50e.png", "FIFTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s60e.png", "SIXTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s65e.png", "SIXTYFIVE_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s100e.png", "HUNDRED_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s150e.png", "HUNDREDFIFTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s200e.png", "TWEHANDRED_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s250e.png", "TWEHANDREDFIFTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s300e.png", "THREEHANDRED_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss30e.png", "S_THRTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss40e.png", "S_FOURTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss50e.png", "S_FIFTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss60e.png", "S_SIXTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss70e.png", "S_SEVENTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss80e.png", "S_EIGHTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss100e.png", "S_HUNDRED_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss150e.png", "S_HUNDREDFIFTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss180e.png", "S_HUNDREDEIGHTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss200e.png", "S_TWEHUNDRED_TEX");

	m_pDirectX->LoadTexture("Texture/scoretext/t1.png", "T_1");
	m_pDirectX->LoadTexture("Texture/scoretext/t2.png", "T_2");
	m_pDirectX->LoadTexture("Texture/scoretext/t3.png", "T_3");
	m_pDirectX->LoadTexture("Texture/scoretext/t4.png", "T_4");
	m_pDirectX->LoadTexture("Texture/scoretext/t5.png", "T_5");

	m_pDirectX->LoadTexture("Texture/button/a.png", "A_TEX");
	m_pDirectX->LoadTexture("Texture/button/b.png", "B_TEX");
	m_pDirectX->LoadTexture("Texture/button/x.png", "X_TEX");
	m_pDirectX->LoadTexture("Texture/button/y.png", "Y_TEX");
	m_pDirectX->LoadTexture("Texture/button/r.png", "R_TEX");
	m_pDirectX->LoadTexture("Texture/button/l.png", "L_TEX");
	m_pDirectX->LoadTexture("Texture/button/button.png", "NULL_BUTTON_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/beef.png", "BEEF_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/chicken.png", "CHICKEN_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/pork.png", "PORK_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/wiener.png", "VIENNESE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/mince.png", "MINCE_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/shrimp.png", "SHRIMP_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/octopus.png", "OCTOPUS_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/squid.png", "INKFISH_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/fish.png", "FISH_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/carrot.png", "GINESENG_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/onion.png", "ONION_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/potato.png", "POTATO_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/tomato.png", "TOMATO_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/radish.png", "RADISH_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/snack.png", "POTATOCHIPS_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/choco.png", "CHOCOLATE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/ice.png", "ICE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/ricecracker.png", "RICECRACKER_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/apple.png", "APPLE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/orange.png", "ORANGE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/banana.png", "BANANA_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/tea.png", "TEA_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/juice.png", "JUICE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/beer.png", "BEER_TEX");

}

void GameScene::goodsScoreShow()
{
	static int goodsInfoShowing;
	static int goodsInfoCount = 0;
	CUSTOMVERTEX GoodsShow[4];
	char goodsNumBuff[10];
	CreateSquareVertex(GoodsShow,10.f, 0, 1260.f, 90.f);
	m_pDirectX->DrawTexture("FRAME_TEX", GoodsShow);

	if (!m_TimeDeadline && m_isGameStart) 
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
			m_pDirectX->DrawTexture(foodGoods[editMerchandise(goodsInfoShowing, 0)].textureID, GoodsShow);
			CreateSquareVertex(GoodsShow, 200.f, 10.f, 300.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, editMerchandise(goodsInfoShowing, 0), 0), GoodsShow);
			CreateSquareVertex(GoodsShow, 300.f, 10.f, 400.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, editMerchandise(goodsInfoShowing, 0), 1), GoodsShow);

			CreateSquareVertex(GoodsShow, 800.f, 10.f, 900.f, 80.f);
			m_pDirectX->DrawTexture(foodGoods[editMerchandise(goodsInfoShowing, 1)].textureID, GoodsShow);
			CreateSquareVertex(GoodsShow, 900.f, 10.f, 1000.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, editMerchandise(goodsInfoShowing, 1), 0), GoodsShow);
			CreateSquareVertex(GoodsShow, 1000.f, 10.f, 1100.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, editMerchandise(goodsInfoShowing, 1), 1), GoodsShow);

			break;

		case CHOSEGOODS:
			CreateSquareVertex(GoodsShow, 100.f, 10.f, 200.f, 80.f);
			m_pDirectX->DrawTexture(foodGoods[editMerchandise(m_SalesChoice, 0)].textureID, GoodsShow);
			CreateSquareVertex(GoodsShow, 200.f, 10.f, 300.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, editMerchandise(m_SalesChoice, 0), 0), GoodsShow);
			CreateSquareVertex(GoodsShow, 300.f, 10.f, 400.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, editMerchandise(m_SalesChoice, 0), 1), GoodsShow);

			CreateSquareVertex(GoodsShow, 800.f, 10.f, 900.f, 80.f);
			m_pDirectX->DrawTexture(foodGoods[editMerchandise(m_SalesChoice, 1)].textureID, GoodsShow);
			CreateSquareVertex(GoodsShow, 900.f, 10.f, 1000.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, editMerchandise(m_SalesChoice, 1), 0), GoodsShow);
			CreateSquareVertex(GoodsShow, 1000.f, 10.f, 1100.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, editMerchandise(m_SalesChoice, 1), 1), GoodsShow);

			break;
		case PUSHENEMY:
		{
			CreateSquareVertex(GoodsShow, 310.f, 10.f, 400.f, 80.f);
			m_pDirectX->DrawTexture(foodGoods[selectedGoods[m_Turn]].textureID, GoodsShow);
			CreateSquareVertex(GoodsShow, 450.f, 10.f, 600.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, selectedGoods[m_Turn], 0), GoodsShow);

			CreateSquareVertex(GoodsShow, 650.f, 10.f, 800.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, selectedGoods[m_Turn], 1), GoodsShow);

			sprintf_s(goodsNumBuff, 10, "%dコ", foodGoods[selectedGoods[m_Turn]].haveValue);
			RECT GoodsNUM = { 850 ,10,1100,80 };
			m_pDirectX->DrawWord(GoodsNUM, goodsNumBuff, "HAVEGOODS_FONT", DT_RIGHT, BLACK);

			break;
		}
		case PICKGOODS:
		{
			CreateSquareVertex(GoodsShow, 310.f, 10.f, 400.f, 80.f);
			m_pDirectX->DrawTexture(foodGoods[selectedGoods[m_Turn]].textureID, GoodsShow);
			CreateSquareVertex(GoodsShow, 450.f, 10.f, 600.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, selectedGoods[m_Turn], 0), GoodsShow);

			CreateSquareVertex(GoodsShow, 650.f, 10.f, 800.f, 80.f);
			m_pDirectX->DrawTexture(priceEdit(foodGoods, selectedGoods[m_Turn], 1), GoodsShow);
			sprintf_s(goodsNumBuff, 10, "%dコ", foodGoods[selectedGoods[m_Turn]].haveValue);
			RECT GoodsNUM = { 850 ,10,1100,80 };
			m_pDirectX->DrawWord(GoodsNUM, goodsNumBuff, "HAVEGOODS_FONT", DT_RIGHT, BLACK);

			break;
		}
		}
	}
	if (m_TimeDeadline)
	{
		float scaleTimmer = 0;
		float posYTimmer = 0;
		std::string timmerTexture;

		switch (0/*timeShow()*/)
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
		sprintf_s(goodsNumBuff, 10, "%dコ", foodGoods[selectedGoods[m_Turn]].haveValue);
		RECT GoodsNUM = { 850 ,10,1100,80 };
		m_pDirectX->DrawWord( GoodsNUM,goodsNumBuff, "HAVEGOODS_FONT", DT_RIGHT, BLACK);

		CUSTOMVERTEX timeLimitShow[4];
		CENTRAL_STATE timeLimitShowCentral = { 640,posYTimmer,scaleTimmer,scaleTimmer };
		CreateSquareVertex(timeLimitShow, timeLimitShowCentral);
		m_pDirectX->DrawTexture( timmerTexture,timeLimitShow);

		//char timeText[10];
		//sprintf_s(timeText, 10, "%d ", timeShow() + 1);
		//RECT timeLimit = { 200 ,10,1000,80 };
		//m_pDirectX->DrawWord(timeText, timeLimit, DT_CENTER, RED, HAVEGOODS_FONT);

	}
}

std::string GameScene::priceEdit(GOODSPARAMETER* foodGoods,int goodsselector,int nomalOrSale)
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
	}

int GameScene::editMerchandise(int seleChoice,int arrayNum)
{
	return popSales[seleChoice].merchandise[arrayNum];
}

