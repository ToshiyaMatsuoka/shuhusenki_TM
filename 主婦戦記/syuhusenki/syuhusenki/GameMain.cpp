#include "Main.h"
#include "FloaMove.h"
#include "GameMain.h"
#include "Goods.h"
#include "Timer.h"
#include "ChoseGoods.h"
#include "BlowOff.h"
#include "PickGoods.h"



#define CHARCTOR_BLOWOFF_SCALE 150
#define MOVE_MILEAGE 8
#define MOVE_MILEAGE_STICK 2




bool g_pause = false;
bool g_isGameStart = false;
bool g_isTimeUp = false;
int g_inCount = 0;

int g_gameScene = FLOAMOVE;

int g_turn = 0;
std::string mobTexNum;

bool g_isFirst = true;
int g_effectCount = 0;
int g_blowOffPCEffectCount = 0;

float mobRad = 0;

 int comandInput[5] = { 10,10,10,10,10 };
 int comandPresentment[5];
 int comandCount = 0;
 int checkedComand = 2;
 int rushButtonShow;
SoundEffect Button{ "BUTTON1","BUTTON2","BUTTON3" };
SoundEffect Pick{ "PICK1", "PICK2","PICK3", "PICK4","PICK5", "PICK6" , "PICK7" ,"PICK8","PICK9","PICK10","PICK11", "PICK12","PICK13", "PICK14","PICK15" };


//モブの画像頂点
CUSTOMVERTEX mobFloa[4];
CENTRAL_STATE mobCentralBlowOff[5];

CUSTOMVERTEX playerHit[4];
CENTRAL_STATE playerCentralHit = {200,550,(CHARCTOR_BLOWOFF_SCALE-50.f),CHARCTOR_BLOWOFF_SCALE };

CENTRAL_STATE durabilityPointCentral = { 900,75 ,15,40};

std::string texturePC = "YASUKO_TEX";
std::string priceEdit(GOODSPARAMETER foodGoods[], int goodsselector, int nomalOrSale);
int editMerchandise(int selesChoice, int arrayNum);

void gameMain() {
	srand((unsigned int)time(NULL));
	if (g_isFirst) 
	{
		static bool canRead = true;
		if (canRead) 
		{
			if (!LoadConpleate[1]) {
				static bool canCreateThread = true;
				if (canCreateThread) {
					threadHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thread, NULL, 0, NULL);
					canCreateThread = false;
				}
				ResumeThread(threadHandle);
				static DWORD LodingColor = 0xffffffff;
				setNowLoading(LodingColor);
				if (LodingColor < 0xffffff) {
					LodingColor = 0xffffffff;
				}
				LodingColor = colorDecrease(LodingColor);
				GetExitCodeThread(threadHandle, &threadResult);
				if (threadResult != STILL_ACTIVE) {
					LoadConpleate[1] = true;
					g_SoundSuccess = soundsManager.Start("LOAD", false) && g_SoundSuccess;
					CloseHandle(threadHandle);
					canRead = false;
				}
			}

			g_SoundSuccess = soundsManager.Stop("SELECT_BGM") && g_SoundSuccess;

			
		}

		popSales[0].goodsSorting = rand() % 6;//フロア移動で決めたものを入れる
		while (popSales[0].goodsSorting == popSales[1].goodsSorting) {
			popSales[1].goodsSorting = rand() % 6;
		}
		while ((popSales[0].goodsSorting == popSales[2].goodsSorting) || (popSales[1].goodsSorting == popSales[2].goodsSorting)) {

			popSales[2].goodsSorting = rand() % 6;
		}
		selectGoods(&popSales[0]);
		selectGoods(&popSales[1]);
		selectGoods(&popSales[2]);

		comandMake();
		if (LoadConpleate[1]) {
			g_isBlowOff = false;
			g_isFirst = false;
		}
	}
	int effectIntervalCurrnt = g_timerCount;
	if (effectIntervalCurrnt - effectIntervalPrev > 3)
	{
		effectCount++;
		effectIntervalPrev = g_timerCount;
	}
	if (effectCount > 3)
	{
		effectCount = 0;
	}

int blowOffEffectIntervalCurrnt = g_timerCount;
	if (blowOffEffectIntervalCurrnt - blowOffEffectIntervalPrev > 5)
	{
		g_blowOffPCEffectCount++;
		blowOffEffectIntervalPrev = g_timerCount;
	}
	if (g_blowOffPCEffectCount > 4)
	{
		g_blowOffPCEffectCount = 1;
	}
	if (LoadConpleate[1]) {
		switch (g_gameScene)
		{
		case FLOAMOVE:
		{
			switch (g_turn)
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
			g_isBlowOff = false;

			floaMove();

			CheckKeyState(DIK_0);
			if (KeyState[DIK_0] == KeyRelease)
			{
				for (int i = 0; i < 3; i++)
				{
					popSales[i].goodsSorting = rand() % 6;//フロア移動で決めたものを入れる
				}
				selectGoods(&popSales[0]);
				selectGoods(&popSales[1]);
				selectGoods(&popSales[2]);
			}
			CheckKeyState(DIK_1);
			if (KeyState[DIK_1] == KeyRelease)
			{
				salesChoice = 0;
			}
			CheckKeyState(DIK_2);
			if (KeyState[DIK_2] == KeyRelease)
			{
				salesChoice = 1;
			}
			CheckKeyState(DIK_3);
			if (KeyState[DIK_3] == KeyRelease)
			{
				salesChoice = 2;
			}
			break;
		}
		case CHOSEGOODS:

			choseGoods();
			break;
		case PUSHENEMY:
			if (!g_isBlowOff)
			{

				mobCentralBlowOff[0] = { 450,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
				mobCentralBlowOff[1] = { 600,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
				mobCentralBlowOff[2] = { 750,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
				mobCentralBlowOff[3] = { 900,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
				mobCentralBlowOff[4] = { 1050,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };

				effectExplosionCentral = { 900,750,300,300 };
				g_effectCount = 0;
				playerCutinCentral.x = 1200;
			}
			blowOff();
			break;
		case PICKGOODS:
			pickGoods();
			comandMake();
			for (int i = 0; i < 5; i++)
			{
				comandInput[i] = 10;
			}
			break;
		}
	}
}


void goodsScoreShow()
{
	static int goodsInfoShowing;
	static int goodsInfoCount = 0;

	char goodsNumBuff[10];
	EasyCreateSquareVertex(10, 0, 1260, 90, "FRAME_TEX");
	if (!g_timeDeadline && g_isGameStart) 
	{
		switch (g_gameScene)
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
			EasyCreateSquareVertex(100, 10, 200, 80, foodGoods[editMerchandise(goodsInfoShowing, 0)].textureID);
			EasyCreateSquareVertex(200, 10, 300, 80, priceEdit(foodGoods, editMerchandise(goodsInfoShowing, 0), 0));
			EasyCreateSquareVertex(300, 10, 400, 80, priceEdit(foodGoods, editMerchandise(goodsInfoShowing, 0), 1));

			EasyCreateSquareVertex(800, 10, 900, 80, foodGoods[editMerchandise(goodsInfoShowing, 1)].textureID);
			EasyCreateSquareVertex(900, 10, 1000, 80, priceEdit(foodGoods, editMerchandise(goodsInfoShowing, 1), 0));
			EasyCreateSquareVertex(1000, 10, 1100, 80, priceEdit(foodGoods, editMerchandise(goodsInfoShowing, 1), 1));

			break;

		case CHOSEGOODS:
			EasyCreateSquareVertex(100, 10, 200, 80, foodGoods[editMerchandise(salesChoice, 0)].textureID);
			EasyCreateSquareVertex(200, 10, 300, 80, priceEdit(foodGoods, editMerchandise(salesChoice, 0), 0));
			EasyCreateSquareVertex(300, 10, 400, 80, priceEdit(foodGoods, editMerchandise(salesChoice, 0), 1));

			EasyCreateSquareVertex(800, 10, 900, 80, foodGoods[editMerchandise(salesChoice, 1)].textureID);
			EasyCreateSquareVertex(900, 10, 1000, 80, priceEdit(foodGoods, editMerchandise(salesChoice, 1), 0));
			EasyCreateSquareVertex(1000, 10, 1100, 80, priceEdit(foodGoods, editMerchandise(salesChoice, 1), 1));

			break;
		case PUSHENEMY:
		{
			EasyCreateSquareVertex(310, 10, 400, 80, foodGoods[selectedGoods[g_turn]].textureID);
			EasyCreateSquareVertex(450, 10, 600, 80, priceEdit(foodGoods, selectedGoods[g_turn], 0));

			EasyCreateSquareVertex(650, 10, 800, 80, priceEdit(foodGoods, selectedGoods[g_turn], 1));

			sprintf_s(goodsNumBuff, 10, "%dコ", foodGoods[selectedGoods[g_turn]].haveValue);
			RECT GoodsNUM = { 850 ,10,1100,80 };
			WriteWord(goodsNumBuff, GoodsNUM, "HAVEGOODS_FONT", DT_RIGHT, BLACK);

			break;
		}
		case PICKGOODS:
		{
			EasyCreateSquareVertex(310, 10, 400, 80, foodGoods[selectedGoods[g_turn]].textureID);
			EasyCreateSquareVertex(450, 10, 600, 80, priceEdit(foodGoods, selectedGoods[g_turn], 0));

			EasyCreateSquareVertex(650, 10, 800, 80, priceEdit(foodGoods, selectedGoods[g_turn], 1));
			sprintf_s(goodsNumBuff, 10, "%dコ", foodGoods[selectedGoods[g_turn]].haveValue);
			RECT GoodsNUM = { 850 ,10,1100,80 };
			WriteWord(goodsNumBuff, GoodsNUM, "HAVEGOODS_FONT", DT_RIGHT, BLACK);

			break;
		}
		}
	}
	if (g_timeDeadline)
	{
		float scaleTimmer = 0;
		float posYTimmer = 0;
		std::string timmerTexture;

		switch (timeShow())
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
		sprintf_s(goodsNumBuff, 10, "%dコ", foodGoods[selectedGoods[g_turn]].haveValue);
		RECT GoodsNUM = { 850 ,10,1100,80 };
		WriteWord(goodsNumBuff, GoodsNUM, "HAVEGOODS_FONT", DT_RIGHT, BLACK);

		CUSTOMVERTEX timeLimitShow[4];
		CENTRAL_STATE timeLimitShowCentral = { 640,posYTimmer,scaleTimmer,scaleTimmer };
		CreateSquareVertex(timeLimitShow, timeLimitShowCentral);
		SetUpTexture(timeLimitShow, timmerTexture);

		//char timeText[10];
		//sprintf_s(timeText, 10, "%d ", timeShow() + 1);
		//RECT timeLimit = { 200 ,10,1000,80 };
		//WriteWord(timeText, timeLimit, DT_CENTER, RED, HAVEGOODS_FONT);

	}
}

std::string priceEdit(GOODSPARAMETER foodGoods[],int goodsselector,int nomalOrSale)
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

int editMerchandise(int seleChoice,int arrayNum)
{
	return popSales[seleChoice].merchandise[arrayNum];
}


void showPressA()
{
	CUSTOMVERTEX showA[4];
	CENTRAL_STATE centralAButton = {1200,600,50,50};
	CreateSquareVertexColor(showA, centralAButton,m_Color);
	SetUpTexture(showA, "A_TEX");
}