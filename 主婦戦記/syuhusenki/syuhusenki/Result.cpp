//#include "Result.h"
//#include "Goods.h"
//#include "Main.h"
//#include "GameMain.h"
//#include "FloaMove.h"
//
//
//static CENTRAL_STATE cursorResult{ 100,490,25,25 };
//static int succeedCombo;
//static bool apperText[10];
//static int resultPage;
//static int nomalSum = 0;
//static int saleSale = 0;
//static int resultCounter = 0;
//void resultControl(void);
//void resultRenderOne(void);
//void resultRenderTwo(void);
//void resultRenderThree(void);
//void apperResult(int* resultCounter);
//
//int addPrice(int num, int nomalOrSale);
//
//static bool isFirst = true;
//static DWORD SyncOld;
//static DWORD SyncNow;
//
//void result()
//{
//
//	if (isFirst) {
//		if (!LoadConpleate[2]) {
//			static bool canCreateThread = true;
//			if (canCreateThread) {
//				threadHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thread, NULL, 0, NULL);
//				canCreateThread = false;
//			}
//			ResumeThread(threadHandle);
//			static DWORD LodingColor = 0xffffffff;
//			setNowLoading(LodingColor);
//			if (LodingColor < 0xffffff) {
//				LodingColor = 0xffffffff;
//			}
//			LodingColor = colorDecrease(LodingColor);
//			GetExitCodeThread(threadHandle, &threadResult);
//			if (threadResult != STILL_ACTIVE) {
//				LoadConpleate[2] = true;
//				g_SoundSuccess = soundsManager.Start("LOAD", false) && g_SoundSuccess;
//				CloseHandle(threadHandle);
//			}
//		}
//		else {
//			g_SoundSuccess = soundsManager.Stop("HURRY_UP") && g_SoundSuccess;
//			g_SoundSuccess = soundsManager.Stop("FOOD") && g_SoundSuccess;
//			g_SoundSuccess = soundsManager.Stop("TIME_LIMIT") && g_SoundSuccess;
//
//			comboCheck(selectedGoods[0], selectedGoods[1], selectedGoods[2]);
//			succeedCombo = comboSucceceCheck();
//
//
//			if (selectedGoods[0] == selectedGoods[1] && selectedGoods[0] == selectedGoods[2]) {
//				foodGoods[selectedGoods[0]].haveValue = (foodGoods[selectedGoods[0]].haveValue / 3);
//			}
//			else if (selectedGoods[0] == selectedGoods[1] || selectedGoods[0] == selectedGoods[2]) {
//				foodGoods[selectedGoods[0]].haveValue = (foodGoods[selectedGoods[0]].haveValue / 2);
//			}
//			else if (selectedGoods[1] == selectedGoods[2]) {
//				foodGoods[selectedGoods[1]].haveValue = (foodGoods[selectedGoods[1]].haveValue / 2);
//			}
//
//			for (int i = 0; i < 3; i++)
//			{
//				nomalSum += addPrice(i, 0);
//				saleSale += addPrice(i, 1);
//			}
//			for (int i = 0; i < 10; i++)
//			{
//				apperText[i] = false;
//			}
//			g_SoundSuccess = soundsManager.Start("LOAD", false) && g_SoundSuccess;
//			resultCounter = 0;
//			isFirst = false;
//			g_timerCount = 0;
//		}
//
//	}
//	if (LoadConpleate[2]) {
//		resultControl();
//		BeginSetTexture();
//		static bool canSound = true;
//		switch (resultPage)
//		{
//		case PAGE1:
//			resultRenderOne();
//			showPressA();
//			break;
//		case PAGE2:
//		{
//			SyncNow = timeGetTime();
//
//			resultRenderOne();
//			if (SyncNow - SyncOld > 3000)
//			{
//				resultRenderTwo();
//				if (canSound)
//				{
//					canSound = false;
//					if ((nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) < LOW_SCORE)
//					{
//						g_SoundSuccess = soundsManager.Start("LOW_SCORE", false) && g_SoundSuccess;
//					}
//					if (LOW_SCORE <= (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) && (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) <= HIGH_SCORE)
//					{
//						g_SoundSuccess = soundsManager.Start("MIDLE_SCORE", false) && g_SoundSuccess;
//
//					}
//					if (HIGH_SCORE < (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus))
//					{
//						g_SoundSuccess = soundsManager.Start("HIGH_SCORE", false) && g_SoundSuccess;
//
//					}
//				}
//			}
//		}
//		showPressA();
//		break;
//		case PAGE3:
//			canSound = true;
//			resultRenderOne();
//			resultRenderTwo();
//			resultRenderThree();
//		}
//		EndSetTexture();
//	}
//}
//
//void resultControl(void)
//{
//	resultCounter++;
//	apperResult(&resultCounter);
//	GetControl(0);
//	BottonCheck();
//
//	CheckKeyState(DIK_RETURN);
//	CheckKeyState(DIK_NUMPADENTER);
//	CheckKeyState(DIK_SPACE);
//	CheckKeyState(DIK_W);
//	CheckKeyState(DIK_S);
//
//	if (KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease)
//	{
//		switch (resultPage)
//		{
//		case PAGE1:
//			g_SoundSuccess = soundsManager.Start("DRUM", false) && g_SoundSuccess;
//			SyncOld = timeGetTime();
//
//			resultPage = PAGE2;
//			break;
//		case PAGE2:
//		{
//			resultPage = PAGE3;
//			break;
//		}
//		case PAGE3:
//			resultPage = PAGE1;
//			g_PCSta = { 900.f, 580.f, 32.f, 53.f };
//			mobCentralFloa[0] = { 620,630 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE };
//			mobCentralFloa[1] = { 600,300 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE };			
//			mobCentralFloa[1] = { 120,500 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE };
//			nomalSum = 0; 
//			saleSale = 0; 
//			isFirst = true;
//			memset(apperText, false, 10);
//			for (int i = 0; i < 3; i++)
//			{
//				foodGoods[selectedGoods[i]].haveValue = 0;
//			}
//			if (cursorResult.y < 500) {
//				g_gameScene = FLOAMOVE;
//				g_scene = SCENE_MAIN;
//			}
//			else
//			{
//				g_scene = SCENE_TITLE;
//			}
//			break;
//		}
//	}
//#ifdef _DEBUG
//
//	if (KeyState[DIK_SPACE] == KeyRelease)
//	{
//		isFirst = true;
//		g_scene = SCENE_TITLE;
//	}
//#endif
//	if (resultPage == PAGE3) {
//		if (KeyState[DIK_W] == KeyRelease)
//		{
//			g_SoundSuccess = soundsManager.Stop("CURSOR") && g_SoundSuccess;
//			g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//			cursorResult.y = 490;
//		}
//		if (KeyState[DIK_S] == KeyRelease)
//		{
//			g_SoundSuccess = soundsManager.Stop("CURSOR") && g_SoundSuccess;
//			g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//			cursorResult.y = 560;
//
//		}
//		if (PadState[ButtonUP] == PadRelease)
//		{
//			g_SoundSuccess = soundsManager.Stop("CURSOR") && g_SoundSuccess;
//			g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//			cursorResult.y = 490;
//
//		}
//
//		if (PadState[ButtonDOWN] == PadRelease)
//		{
//			g_SoundSuccess = soundsManager.Stop("CURSOR") && g_SoundSuccess;
//			g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//			cursorResult.y = 560;
//
//		}
//		if (!GetAnalogL(ANALOGDOWN))
//		{
//			g_SoundSuccess = soundsManager.Stop("CURSOR") && g_SoundSuccess;
//			g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//			cursorResult.y = 490;
//
//		}
//
//		if (!GetAnalogL(ANALOGUP))
//		{
//			g_SoundSuccess = soundsManager.Stop("CURSOR") && g_SoundSuccess;
//			g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//			cursorResult.y = 560;
//
//		}
//
//	}
//	if (PadState[ButtonA] == PadRelease) {
//		switch (resultPage)
//		{
//		case PAGE1:
//			g_SoundSuccess = soundsManager.Start("DRUM", false) && g_SoundSuccess;
//			SyncOld = timeGetTime();
//
//			resultPage = PAGE2;
//			break;
//		case PAGE2:
//		{
//			resultPage = PAGE3;
//			break;
//		}
//		case PAGE3:
//			resultPage = PAGE1;
//			g_PCSta = { 900.f, 580.f, 32.f, 53.f };
//			mobCentralFloa[0] = { 1200,500 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE };
//			mobCentralFloa[1] = { 600,300 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE };
//			mobCentralFloa[1] = { 120,500 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE };
//			nomalSum = 0;
//			saleSale = 0;
//			isFirst = true;
//			memset(apperText, false, 10);
//			for (int i = 0; i < 3; i++)
//			{
//				foodGoods[selectedGoods[i]].haveValue = 0;
//			}
//			if (cursorResult.y < 500) {
//				g_gameScene = FLOAMOVE;
//				g_scene = SCENE_MAIN;
//			}
//			else g_scene = SCENE_TITLE;
//			break;
//		}
//	}
//
//}
//
//void resultRenderOne(void)
//{
//
//	EasyCreateSquareVertex(0, 0, WIDTH, 700, "RESULT_BG_TEX");
//
//	CUSTOMVERTEX resultBaseTex1[4];
//	CUSTOMVERTEX resultBaseTex2[4];
//	CUSTOMVERTEX resultBaseTex3[4];
//	CUSTOMVERTEX resultSeleTex1[4];
//	CUSTOMVERTEX resultSeleTex2[4];
//	CUSTOMVERTEX resultSeleTex3[4];
//	CUSTOMVERTEX resultComboTex[4];
//	CUSTOMVERTEX saleTResultTex[4];
//	CUSTOMVERTEX nomalTResultTex[4];
//	CUSTOMVERTEX comboTResultTex[4];
//	CUSTOMVERTEX comboStarResultTex[4];
//	CUSTOMVERTEX comboTextResultTex[4];
//
//	CENTRAL_STATE BaseTexCentral1{ 100,150,50,50 };
//	CENTRAL_STATE BaseTexCentral2{ 100,250,50,50 };
//	CENTRAL_STATE BaseTexCentral3{ 100,350,50,50 };
//	CENTRAL_STATE SeleTexCentral1{ 850,150,50,50 };
//	CENTRAL_STATE SeleTexCentral2{ 850,250,50,50 };
//	CENTRAL_STATE SeleTexCentral3{ 850,350,50,50 };
//	CENTRAL_STATE comboTexCentral{ 640,315,100,100 };
//	CENTRAL_STATE nomalTResult{ 200,30,100,25 };
//	CENTRAL_STATE saleTResult{ 1020,30,100,25 };
//	CENTRAL_STATE comboTResult{ 640,30,100,25 };
//	CENTRAL_STATE comboStarResult{ 640,150,100,25 };
//	CENTRAL_STATE comboTextResult{ 640,650,300,25 };
//
//	CreateSquareVertex(saleTResultTex, saleTResult);
//	CreateSquareVertex(nomalTResultTex, nomalTResult);
//	CreateSquareVertex(comboTResultTex, comboTResult);
//	CreateSquareVertex(comboStarResultTex, comboStarResult);
//
//	CreateSquareVertex(resultBaseTex1, BaseTexCentral1);
//	CreateSquareVertex(resultBaseTex2, BaseTexCentral2);
//	CreateSquareVertex(resultBaseTex3, BaseTexCentral3);
//	CreateSquareVertex(resultSeleTex1, SeleTexCentral1);
//	CreateSquareVertex(resultSeleTex2, SeleTexCentral2);
//	CreateSquareVertex(resultSeleTex3, SeleTexCentral3);
//	CreateSquareVertex(resultComboTex, comboTexCentral);
//	CreateSquareVertex(comboTextResultTex, comboTextResult);
//
//	SetUpTexture(saleTResultTex, "RESULT_SALE_TEX");
//	SetUpTexture(nomalTResultTex, "RESULT_NOMAL_TEX");
//	SetUpTexture(comboTResultTex, "RESULT_COMBO_TEX");
//
//
//
//	char resulttantValue[32];
//	if (apperText[0]) 
//	{
//		SetUpTexture(resultBaseTex1, foodGoods[selectedGoods[0]].textureID);
//		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[0]].nominalCost, foodGoods[selectedGoods[0]].haveValue, addPrice(0, 0));
//		RECT resultBase1{ 160,125,600,275 };
//		WriteWord(resulttantValue, resultBase1,  "RESULT_FONT",DT_LEFT, BLACK);
//
//		SetUpTexture(resultSeleTex1, foodGoods[selectedGoods[0]].textureID);
//		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[0]].selePrice, foodGoods[selectedGoods[0]].haveValue, addPrice(0, 1));
//		RECT resultSele1{ 930,125,1240,275 };
//		WriteWord(resulttantValue, resultSele1,  "RESULT_FONT",DT_LEFT, BLACK);
//	}
//	if (apperText[1]) 
//	{
//		SetUpTexture(resultBaseTex2, foodGoods[selectedGoods[1]].textureID);
//		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[1]].nominalCost, foodGoods[selectedGoods[1]].haveValue, addPrice(1, 0));
//		RECT resultBase2{ 160,225,600,275 };
//		WriteWord(resulttantValue, resultBase2,  "RESULT_FONT",DT_LEFT, BLACK);
//		SetUpTexture(resultSeleTex2, foodGoods[selectedGoods[1]].textureID);
//		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[1]].selePrice, foodGoods[selectedGoods[1]].haveValue, addPrice(1, 1));
//		RECT resultSele2{ 930,225,1240,275 };
//		WriteWord(resulttantValue, resultSele2,  "RESULT_FONT",DT_LEFT, BLACK);
//	}
//	if (apperText[2]) 
//	{
//		SetUpTexture(resultBaseTex3, foodGoods[selectedGoods[2]].textureID);
//		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[2]].nominalCost, foodGoods[selectedGoods[2]].haveValue, addPrice(2,0));
//		RECT resultBase3{ 160,325,600,475};
//		WriteWord(resulttantValue, resultBase3,  "RESULT_FONT",DT_LEFT, BLACK);
//		SetUpTexture(resultSeleTex3, foodGoods[selectedGoods[2]].textureID);
//		sprintf_s(resulttantValue, 32, "%d�~%d=%d", foodGoods[selectedGoods[2]].selePrice, foodGoods[selectedGoods[2]].haveValue, addPrice(2, 1));
//		RECT resultSele3{ 930,325,1240,475 };
//		WriteWord(resulttantValue, resultSele3,  "RESULT_FONT",DT_LEFT, BLACK);
//	}
//	if (apperText[3]) 
//	{
//
//		sprintf_s(resulttantValue, 32, "���v%d�~", nomalSum);
//		RECT resultBaseTotal{ 160,425,440,575 };
//		WriteWord(resulttantValue, resultBaseTotal ,"RESULT_FONT", DT_RIGHT, BLACK);
//		sprintf_s(resulttantValue, 32, "���v%d�~", saleSale);
//		RECT resultSeleTotal{ 930,425,1240,575 };
//		WriteWord(resulttantValue, resultSeleTotal ,"RESULT_FONT", DT_RIGHT, BLACK);
//
//	}
//	if (apperText[4]) 
//	{
//		sprintf_s(resulttantValue, 32, "%d-%d=%d", nomalSum, saleSale, nomalSum - saleSale);
//		RECT resultTotal{ 100,525,1180,700 };
//		WriteWord(resulttantValue, resultTotal, "SCORE_FONT", DT_CENTER, BLACK);
//	}
//	if (apperText[5]) 
//	{
//
//		SetUpTexture(resultComboTex, foodCombo[succeedCombo].textureID);
//
//		switch (foodCombo[succeedCombo].comboBonus)
//		{
//		case RARE1:
//			SetUpTexture(comboStarResultTex, "RESULT_STAR1_TEX");
//			SetUpTexture(comboTextResultTex, "RESULT_COMBOTEXT1_TEX");
//			break;
//		case RARE2:
//			SetUpTexture(comboStarResultTex, "RESULT_STAR2_TEX");
//			SetUpTexture(comboTextResultTex, "RESULT_COMBOTEXT2_TEX");
//			break;
//		case RARE3:
//			SetUpTexture(comboStarResultTex, "RESULT_STAR3_TEX");
//			SetUpTexture(comboTextResultTex, "RESULT_COMBOTEXT3_TEX");
//			break;
//		}
//
//	}
//}
//
//void resultRenderTwo(void)
//{
//	EasyCreateSquareVertexColor(0, 0, WIDTH, HEIGHT, "BLANK", HARFCLEAR);
//	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT,"RESULT_POP_TEX");
//
//	char resulttantValue[32];
//	sprintf_s(resulttantValue, 32, "%d",nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus);
//	RECT resultTotal{ 0,235,435,400 };
//	WriteWord(resulttantValue, resultTotal, "LAST_SCORE_FONT", DT_RIGHT, BLACK);
//	CUSTOMVERTEX resultPCTex[4];
//	CENTRAL_STATE resultPC{ 1050,350,200,300 };
//	CreateSquareVertex(resultPCTex, resultPC);
//	if ((nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) < LOW_SCORE)
//	{
//		SetUpTexture(resultPCTex, "YASUKO_EMOTION3_TEX");
//	}
//	if (LOW_SCORE <= (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) && (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) <= HIGH_SCORE)
//	{
//		SetUpTexture(resultPCTex, "YASUKO_EMOTION2_TEX");
//	}
//	if (HIGH_SCORE < (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus)) 
//	{
//		SetUpTexture(resultPCTex, "YASUKO_EMOTION1_TEX");
//	}
//
//}
//
//void resultRenderThree(void)
//{
//	CUSTOMVERTEX cursor[4];
//	CreateSquareVertexColor(cursor, cursorResult, g_cursolColor);
//	EasyCreateSquareVertex(50, 450, 500, 600, "RESULT_END_TEX");
//	SetUpTexture(cursor, "TITLEICON_TEX");
//}
//
////int addPrice(int num, int nomalOrSale)
////{
////	switch(nomalOrSale)
////	{
////	case 0:
////		return foodGoods[selectedGoods[num]].nominalCost * foodGoods[selectedGoods[num]].haveValue;
////		break;
////	case 1:
////		return foodGoods[selectedGoods[num]].selePrice * foodGoods[selectedGoods[num]].haveValue;
////		break;
////	}
////}
//
//void apperResult(int* resultCounter)
//{
//	
//	if (*resultCounter == 30) {
//		apperText[0] = true;
//		g_SoundSuccess = soundsManager.Start("COIN1", false) && g_SoundSuccess;
//	}
//	if (*resultCounter == 60) {
//		apperText[1] = true;
//		g_SoundSuccess = soundsManager.Start("COIN2", false) && g_SoundSuccess;
//	}
//	if (*resultCounter == 90) {
//		apperText[2] = true;
//		g_SoundSuccess = soundsManager.Start("COIN3", false) && g_SoundSuccess;
//	}
//	if (*resultCounter == 120) {
//		apperText[3] = true;
//		g_SoundSuccess = soundsManager.Start("COIN4", false) && g_SoundSuccess;
//	}
//	if (*resultCounter == 150) {
//		apperText[4] = true;
//		g_SoundSuccess = soundsManager.Start("CASHER", false) && g_SoundSuccess;
//	}
//	if ((*resultCounter == 180) && (foodCombo[succeedCombo].comboSucceed)) {
//		apperText[5] = true;
//		g_SoundSuccess = soundsManager.Start("WIN", false) && g_SoundSuccess;
//	}
//
//}