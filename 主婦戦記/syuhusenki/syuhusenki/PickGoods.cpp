#include "PickGoods.h"
//#include "Main.h"
//#include "FloaMove.h"
//#include "GameMain.h"
//#include "Goods.h"
//#include "Timer.h"
//#include "BlowOff.h"
//#include "PickGoods.h"
//
//
//
//CENTRAL_STATE playerCutinCentral = { 1200,350,320,280 };
//static float cutinAnime = 0.5f;
//static float cutinAnimeCount = 0;
//static bool canCutin = true;
//void pickGoods() {
//	if (canCutin)
//	{
//		m_pSoundOperater->SetVolume("CUTIN",65);
//		m_pSoundOperater->Start("CUTIN", false);
//		canCutin = false;
//	}
//	pickGoodsControl();
//	pickGoodsRender();
//}
//
//void pickGoodsControl() {
//	timerControl();
//	float deleatPosX = 250;
//	int rushInput = 10;
//	playerCutinCentral.x -= 5;
//	if (playerCutinCentral.x < 50)
//	{
//		g_isBlowOff = false;
//		canCutin = true;
//		g_gameScene = PUSHENEMY;
//	}
//	if (g_isGameStart)
//	{
//		pickGoodsDeviseControl(&rushInput);
//	}
//	if (g_isBlowOff) {
//		madamBlowOff();
//	}
//
//}
//
//void pickGoodsRender() {
//	CUSTOMVERTEX playerCutin[4];
//	//CreateSquareVertex(playerHit, playerCentralHit, WHITE, 0, 0, YASUKO_TU, YASUKO_TV);
//	CreateSquareVertex(playerCutin, playerCutinCentral, WHITE, 0, cutinAnimeCount, 0.8f, cutinAnime);
//
//	BeginSetTexture();
//	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, "FLOAMOVE_BG_TEX");
//
//	EasyCreateSquareVertexColor(0, 0, WIDTH, HEIGHT, "BLANK", HARFCLEAR);
//
//	for (int i = 0; i < 5; i++) {
//		CreateSquareVertex(mobFloa, mobCentralBlowOff[i], WHITE, 0, 0, MOB_TU, MOB_TV);
//		if (g_isBlowOff) {
//			g_effectCount++;
//
//			mobRad += 0.9f;
//
//			if (mobRad < 0)
//			{
//				mobRad = mobRad * -1;
//			}
//			if (i % 2)
//			{
//				mobRad = mobRad * -1;
//			}
//			RevolveZTuTv(mobFloa, mobRad, mobCentralBlowOff[i], 0, 0, MOB_TU, MOB_TV);
//		}
//		SetUpTexture(mobFloa, mobTexNum);
//	}
//
//
//	//SetUpTexture(playerHit, texturePC);
//
//
//	EasyCreateSquareVertex(0, 150, WIDTH, 550, "CUTIN_TEX");
//
//	SetUpTexture(playerCutin, "CUTIN_YASUKO_TEX");
//
//	//char rushButton[10];
//	RECT rushButtonAppear = { 470,200,810,550 };
//	EasyCreateRECTVertex(rushButtonAppear, comandButtonTexture(rushButtonShow));
//
//	//sprintf_s(rushButton, 10, "%c", comandButton(rushButtonShow));
//	//m_pDirectX->DrawWord(rushButton, rushButtonAppear, DT_CENTER, RED, RUSH_FONT);
//#ifdef _DEBUG
//	char goodsNumA[10];
//	char DebugTakeBoolA[10];
//
//	sprintf_s(goodsNumA, 10, "%d ", foodGoods[selectedGoods[g_turn]].haveValue);
//	RECT DEBUGGoodsA = { 100 ,200,900,600 };
//	m_pDirectX->DrawWord(goodsNumA, DEBUGGoodsA, "DEBUG_FONT", 0xff00ffff, DT_LEFT);
//
//	SoundLib::PlayingStatus status = m_pSoundOperater->GetStatus("PICK1");
//	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
//	RECT DEBUGTextA = { 100 ,150,900,600 };
//	m_pDirectX->DrawWord(DebugTakeBoolA, DEBUGTextA, "DEBUG_FONT", DT_LEFT,0xfff0f00f);
//	status = m_pSoundOperater->GetStatus("PICK2");
//	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
//	DEBUGTextA = { 150  ,150,900,600 };
//	m_pDirectX->DrawWord(DebugTakeBoolA, DEBUGTextA, "DEBUG_FONT", DT_LEFT,0xfff0f00f);
//	status = m_pSoundOperater->GetStatus("PICK3");
//	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
//	DEBUGTextA = { 200  ,150,900,600 };
//	m_pDirectX->DrawWord(DebugTakeBoolA, DEBUGTextA, "DEBUG_FONT", DT_LEFT,0xfff0f00f);
//	status = m_pSoundOperater->GetStatus("PICK4");
//	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
//	DEBUGTextA = { 250  ,150,900,600 };
//	m_pDirectX->DrawWord(DebugTakeBoolA, DEBUGTextA, "DEBUG_FONT", DT_LEFT,0xfff0f00f);
//	status = m_pSoundOperater->GetStatus("PICK5");
//	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
//	DEBUGTextA = { 300  ,150,900,600 };
//	m_pDirectX->DrawWord(DebugTakeBoolA, DEBUGTextA, "DEBUG_FONT", DT_LEFT,0xfff0f00f);
//	status = m_pSoundOperater->GetStatus("PICK6");
//	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
//	DEBUGTextA = { 350  ,150,900,600 };
//	m_pDirectX->DrawWord(DebugTakeBoolA, DEBUGTextA, "DEBUG_FONT", DT_LEFT,0xfff0f00f);
//	status = m_pSoundOperater->GetStatus("PICK7");
//	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
//	DEBUGTextA = { 400  ,150,900,600 };
//	m_pDirectX->DrawWord(DebugTakeBoolA, DEBUGTextA, "DEBUG_FONT", DT_LEFT,0xfff0f00f);
//	status = m_pSoundOperater->GetStatus("PICK8");
//	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
//	DEBUGTextA = { 450  ,150,900,600 };
//	m_pDirectX->DrawWord(DebugTakeBoolA, DEBUGTextA, "DEBUG_FONT", DT_LEFT,0xfff0f00f);
//	status = m_pSoundOperater->GetStatus("PICK9");
//	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
//	DEBUGTextA = { 500  ,150,900,600 };
//	m_pDirectX->DrawWord(DebugTakeBoolA, DEBUGTextA, "DEBUG_FONT", DT_LEFT,0xfff0f00f);
//	status = m_pSoundOperater->GetStatus("PICK10");
//	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
//	DEBUGTextA = { 550  ,150,900,600 };
//	m_pDirectX->DrawWord(DebugTakeBoolA, DEBUGTextA, "DEBUG_FONT", DT_LEFT, 0xfff0f00f);
//
//#endif
//
//	goodsScoreShow();
//	timerRender();
//	EndSetTexture();
//}

//void pickGoodsDeviseControl(int* rushInput) {
//	BottonCheck();
//	CheckKeyState(DIK_RETURN);
//	CheckKeyState(DIK_NUMPADENTER);
//
//	CheckKeyState(DIK_A);
//	CheckKeyState(DIK_B);
//	CheckKeyState(DIK_X);
//	CheckKeyState(DIK_Y);
//	CheckKeyState(DIK_R);
//	CheckKeyState(DIK_L);
//#ifdef _DEBUG
//
//	if (m_pDirectX->GetKeyStatus(DIK_RETURN) == KeyPush || m_pDirectX->GetKeyStatus(DIK_NUMPADENTER) == KeyPush)
//	{
//		g_isFirst = true;
//		m_pSoundOperater->Stop("FOOD");
//		m_pSoundOperater->Stop("HURRY_UP");
//		m_pSoundOperater->SetVolume("HURRY_UP", 100);
//
//		m_pSoundOperater->Stop("FOOD");
//
//		m_pSoundOperater->Stop("TIME_LIMIT");
//
//		g_timeDeadline = false;
//
//		g_scene = SCENE_RESULT;
//		g_gameScene = FLOAMOVE;
//	}
//#endif
//	if (m_pDirectX->GetKeyStatus(DIK_A) == KeyPush)
//	{
//		*rushInput = ButtonA;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//	if (m_pDirectX->GetKeyStatus(DIK_B) == KeyPush)
//	{
//		*rushInput = ButtonB;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//	if (m_pDirectX->GetKeyStatus(DIK_X) == KeyPush)
//	{
//		*rushInput = ButtonX;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//	if (m_pDirectX->GetKeyStatus(DIK_Y) == KeyPush)
//	{
//		*rushInput = ButtonY;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//	if (m_pDirectX->GetKeyStatus(DIK_R) == KeyPush)
//	{
//		*rushInput = ButtonRB;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//	if (m_pDirectX->GetKeyStatus(DIK_L) == KeyPush)
//	{
//		*rushInput = ButtonLB;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//
//	//XInputデバイス操作
//	GetControl(0);
//	BottonCheck();
//#ifdef _DEBUG
//	if (m_pXinputDevice->GetButton(ButtonStart) == PadPush)
//	{
//		g_isFirst = true;
//		m_pSoundOperater->Stop("FOOD");
//		m_pSoundOperater->Stop("HURRY_UP");
//		m_pSoundOperater->SetVolume("HURRY_UP", 100);
//
//		m_pSoundOperater->Stop("FOOD");
//
//		m_pSoundOperater->Stop("TIME_LIMIT");
//
//		g_timeDeadline = false;
//
//		g_scene = SCENE_RESULT;
//		g_gameScene = FLOAMOVE;
//	}
//#endif
//	if (m_pXinputDevice->GetButton(ButtonA) == PadPush)
//	{
//		*rushInput = ButtonA;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//	if (m_pXinputDevice->GetButton(ButtonB) == PadPush)
//	{
//		*rushInput = ButtonB;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//	if (m_pXinputDevice->GetButton(ButtonX) == PadPush)
//	{
//		*rushInput = ButtonX;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//	if (m_pXinputDevice->GetButton(ButtonY) == PadPush)
//	{
//		*rushInput = ButtonY;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//	if (m_pXinputDevice->GetButton(ButtonRB) == PadPush)
//	{
//		*rushInput = ButtonRB;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//	if (m_pXinputDevice->GetButton(ButtonLB) == PadPush)
//	{
//		*rushInput = ButtonLB;
//		RushButtonCheck(*rushInput, rushButtonShow);
//		ButtonSE(Pick, 15);
//	}
//
//}

//void RushButtonCheck(int rushInput, int rushShow)
//{
//	if (rushInput == rushShow)
//	{
//		foodGoods[selectedGoods[g_turn]].haveValue++;
//		cutinAnimeCount += 0.5f;
//	}
//	else m_pSoundOperater->Start("MISS", false);
//
//}


PickGoods::PickGoods(DirectX * pDirectX, SoundOperater * pSoundOperater, int turn, Yasuko* pYasuko) :SubScene(pDirectX, pSoundOperater, turn, pYasuko)
{
	switch (turn)
	{
	case 0:
		m_mobTexKey = "ISOKO_TEX";
		break;
	case 1:
		m_mobTexKey = "MOB_TEX";
		break;
	case 2:
		m_mobTexKey = "MITUKO_TEX";
		break;
	}
	if (m_Turn == 0)
	{
		rushButtonShow = rand() % 4;
	}
	else {
		rushButtonShow = rand() % 6;
	}

}


PickGoods::~PickGoods()
{
}

int PickGoods::Update()
{
	float deleatPosX = 250;
	int rushInput = 10;
	playerCutinCentral.x -= 5;
	if (playerCutinCentral.x < 50)
	{
		m_GameScene = BLOWOFF;
	}
	PickGoodsKeyOperation(&rushInput);
	madamBlowOff();

	return m_GameScene;
}

void PickGoods::LoadResouce()
{
}

void PickGoods::Render()
{
	static float mobRad = 0;
	CUSTOMVERTEX playerCutin[4];
	CUSTOMVERTEX Vertex[4];

	RECT Background = { 0,100,DISPLAY_WIDTH ,700 };
	CreateSquareVertex(Vertex, Background);
	m_pDirectX->DrawTexture("FLOAMOVE_BG_TEX", Vertex);

	CreateSquareVertex(Vertex, Background, HARFCLEAR);
	m_pDirectX->DrawTexture("BLANK", Vertex);

	for (int i = 0; i < 5; i++) {

		mobRad += 0.9f;

		if (mobRad < 0)
		{
			mobRad = mobRad * -1;
		}
		if (i % 2)
		{
			mobRad = mobRad * -1;
		}
		RevolveZ(Vertex, mobRad, &mobCentralBlowOff[i], WHITE, 0, 0, MOB_TU, MOB_TV);
		m_pDirectX->DrawTexture(m_mobTexKey, Vertex);
	}

	CreateSquareVertex(Vertex,0.f, 150.f, DISPLAY_WIDTH, 550.f);
	m_pDirectX->DrawTexture("CUTIN_TEX", Vertex);
	CreateSquareVertex(playerCutin, &playerCutinCentral, WHITE, 0, cutinAnimeCount, 0.8f, cutinAnime);
	m_pDirectX->DrawTexture("CUTIN_YASUKO_TEX", playerCutin);

	RECT rushButtonAppear = { 470,200,810,550 };
	CreateSquareVertex(Vertex,rushButtonAppear);
	m_pDirectX->DrawTexture(comandButtonTexture(rushButtonShow), Vertex);
#ifdef _DEBUG
	char goodsNumA[10];
	char DebugTakeBoolA[10];

	sprintf_s(goodsNumA, 10, "%d ", m_pGoods->GetHaveValue(m_pGoods->GetselectedGoods(m_Turn)));
	RECT DEBUGGoodsA = { 100 ,200,900,600 };
	m_pDirectX->DrawWord(DEBUGGoodsA, goodsNumA, "DEBUG_FONT", 0xff00ffff, DT_LEFT);

	SoundLib::PlayingStatus status = m_pSoundOperater->GetStatus("PICK1");
	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
	RECT DEBUGTextA = { 100 ,150,900,600 };
	m_pDirectX->DrawWord(DEBUGTextA, DebugTakeBoolA, "DEBUG_FONT", DT_LEFT, 0xfff0f00f);
	status = m_pSoundOperater->GetStatus("PICK2");
	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
	DEBUGTextA = { 150  ,150,900,600 };
	m_pDirectX->DrawWord(DEBUGTextA, DebugTakeBoolA, "DEBUG_FONT", DT_LEFT, 0xfff0f00f);
	status = m_pSoundOperater->GetStatus("PICK3");
	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
	DEBUGTextA = { 200  ,150,900,600 };
	m_pDirectX->DrawWord(DEBUGTextA, DebugTakeBoolA, "DEBUG_FONT", DT_LEFT, 0xfff0f00f);
	status = m_pSoundOperater->GetStatus("PICK4");
	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
	DEBUGTextA = { 250  ,150,900,600 };
	m_pDirectX->DrawWord(DEBUGTextA, DebugTakeBoolA, "DEBUG_FONT", DT_LEFT, 0xfff0f00f);
	status = m_pSoundOperater->GetStatus("PICK5");
	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
	DEBUGTextA = { 300  ,150,900,600 };
	m_pDirectX->DrawWord(DEBUGTextA, DebugTakeBoolA, "DEBUG_FONT", DT_LEFT, 0xfff0f00f);
	status = m_pSoundOperater->GetStatus("PICK6");
	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
	DEBUGTextA = { 350  ,150,900,600 };
	m_pDirectX->DrawWord(DEBUGTextA, DebugTakeBoolA, "DEBUG_FONT", DT_LEFT, 0xfff0f00f);
	status = m_pSoundOperater->GetStatus("PICK7");
	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
	DEBUGTextA = { 400  ,150,900,600 };
	m_pDirectX->DrawWord(DEBUGTextA, DebugTakeBoolA, "DEBUG_FONT", DT_LEFT, 0xfff0f00f);
	status = m_pSoundOperater->GetStatus("PICK8");
	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
	DEBUGTextA = { 450  ,150,900,600 };
	m_pDirectX->DrawWord(DEBUGTextA, DebugTakeBoolA, "DEBUG_FONT", DT_LEFT, 0xfff0f00f);
	status = m_pSoundOperater->GetStatus("PICK9");
	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
	DEBUGTextA = { 500  ,150,900,600 };
	m_pDirectX->DrawWord(DEBUGTextA, DebugTakeBoolA, "DEBUG_FONT", DT_LEFT, 0xfff0f00f);
	status = m_pSoundOperater->GetStatus("PICK10");
	sprintf_s(DebugTakeBoolA, 10, "%d ", status);
	DEBUGTextA = { 550  ,150,900,600 };
	m_pDirectX->DrawWord(DEBUGTextA, DebugTakeBoolA, "DEBUG_FONT", DT_LEFT, 0xfff0f00f);
#endif

}

void PickGoods::PickGoodsKeyOperation(int* rushInput) {
#ifdef _DEBUG

	if (m_pDirectX->GetKeyStatus(DIK_RETURN) == KeyPush || m_pDirectX->GetKeyStatus(DIK_NUMPADENTER) == KeyPush || m_pXinputDevice->GetButton(ButtonStart) == PadPush)
	{
		m_pSoundOperater->Stop("FOOD");
		m_pSoundOperater->Stop("HURRY_UP");
		m_pSoundOperater->SetVolume("HURRY_UP", 100);

		m_pSoundOperater->Stop("FOOD");

		m_pSoundOperater->Stop("TIME_LIMIT");

		//g_timeDeadline = false;

		//m_Scene = SCENE_RESULT;
		m_GameScene = FLOAMOVE;
	}
#endif
	if (m_pDirectX->GetKeyStatus(DIK_A) == KeyPush || m_pXinputDevice->GetButton(ButtonA) == PadPush)
	{
		*rushInput = ButtonA;
		RushButtonCheck(*rushInput, rushButtonShow);
		ButtonSE(Pick, 15);
	}
	if (m_pDirectX->GetKeyStatus(DIK_B) == KeyPush || m_pXinputDevice->GetButton(ButtonB) == PadPush)
	{
		*rushInput = ButtonB;
		RushButtonCheck(*rushInput, rushButtonShow);
		ButtonSE(Pick, 15);
	}
	if (m_pDirectX->GetKeyStatus(DIK_X) == KeyPush || m_pXinputDevice->GetButton(ButtonX) == PadPush)
	{
		*rushInput = ButtonX;
		RushButtonCheck(*rushInput, rushButtonShow);
		ButtonSE(Pick, 15);
	}
	if (m_pDirectX->GetKeyStatus(DIK_Y) == KeyPush || m_pXinputDevice->GetButton(ButtonY) == PadPush)
	{
		*rushInput = ButtonY;
		RushButtonCheck(*rushInput, rushButtonShow);
		ButtonSE(Pick, 15);
	}
	if (m_pDirectX->GetKeyStatus(DIK_R) == KeyPush || m_pXinputDevice->GetButton(ButtonRB) == PadPush)
	{
		*rushInput = ButtonRB;
		RushButtonCheck(*rushInput, rushButtonShow);
		ButtonSE(Pick, 15);
	}
	if (m_pDirectX->GetKeyStatus(DIK_L) == KeyPush || m_pXinputDevice->GetButton(ButtonLB) == PadPush)
	{
		*rushInput = ButtonLB;
		RushButtonCheck(*rushInput, rushButtonShow);
		ButtonSE(Pick, 15);
	}
}


void PickGoods::RushButtonCheck(int rushInput, int rushShow)
{
	if (rushInput == rushShow)
	{
		m_pGoods->AddHaveValue(1, m_pGoods->GetselectedGoods(m_Turn));
		cutinAnimeCount += 0.5f;
	}
	else m_pSoundOperater->Start("MISS", false);

}

