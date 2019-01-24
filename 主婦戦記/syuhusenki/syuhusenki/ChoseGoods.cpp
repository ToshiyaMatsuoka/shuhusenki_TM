#include "ChoseGoods.h"
//#include "Main.h"
//#include "FloaMove.h"
//#include "GameMain.h"
//#include "Goods.h"
//#include "Timer.h"
//#include "ChoseGoods.h"
//
//
//int salesChoice;
//
//void choseGoods() {
//	if (g_isGameStart)
//	{
//		choseGoodsControl();
//	}
//	choseGoodsReader();
//}
//void choseGoodsControl() {
//
//	timerControl();
//
//	CheckKeyState(DIK_RETURN);
//	CheckKeyState(DIK_NUMPADENTER);
//	CheckKeyState(DIK_Q);
//	CheckKeyState(DIK_E);
//	if (KeyState[DIK_Q] == KeyRelease)
//	{
//		selectedGoods[m_turn] = popSales[salesChoice].merchandise[0];
//		g_gameScene = PUSHENEMY;
//	}
//	if (KeyState[DIK_E] == KeyRelease)
//	{
//		selectedGoods[m_turn] = popSales[salesChoice].merchandise[1];
//		g_gameScene = PUSHENEMY;
//	}
//
//	GetControl(0);
//	BottonCheck();
//	if (PadState[ButtonA] == PadRelease)
//	{
//
//	}
//	if (PadState[ButtonB] == PadRelease)
//	{
//		selectedGoods[m_turn] = popSales[salesChoice].merchandise[1];
//		g_gameScene = PUSHENEMY;
//	}
//	if (PadState[ButtonX] == PadRelease)
//	{
//		selectedGoods[m_turn] = popSales[salesChoice].merchandise[0];
//		g_gameScene = PUSHENEMY;
//	}
//
//}
//void choseGoodsReader() {
//
//	CUSTOMVERTEX effectPC[4];
//	CENTRAL_STATE effectCentral = { playerCentralHit.x - 2,playerCentralHit.y - 14,playerCentralHit.scaleX*2.03f,playerCentralHit.scaleY*1.4f };
//
//	BeginSetTexture();
//	CreateSquareVertex(playerHit, playerCentralHit, WHITE, 0, 0, YASUKO_TU, YASUKO_TV);
//	CreateSquareVertex(effectPC, effectCentral, WHITE, (effectCount * EFFECT_TU), 0, EFFECT_TU, EFFECT_TV);
//
//	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, "FLOAMOVE_BG_TEX");
//
//	EasyCreateSquareVertexColor(0, 0, WIDTH, HEIGHT, "BLANK", HARFCLEAR);
//
//	for (int i = 0; i < 5; i++) {
//		CreateSquareVertex(mobFloa, mobCentralBlowOff[i],0, 0, MOB_TU, MOB_TV);
//		SetUpTexture(mobFloa, mobTexNum);
//	}
//
//	SetUpTexture(effectPC, "YASUKO_EFFECT_TEX");
//	SetUpTexture(playerHit, texturePC);
//	EasyCreateSquareVertex(350, 150, 600, 400, foodGoods[popSales[salesChoice].merchandise[0]].textureID);
//	EasyCreateSquareVertex(660, 150, 910, 400, foodGoods[popSales[salesChoice].merchandise[1]].textureID);
//	EasyCreateSquareVertex(350, 350, 600, 500, "X_TEX");
//	EasyCreateSquareVertex(660, 350, 910, 500, "B_TEX");
//
//	goodsScoreShow();
//	timerRender();
//	EndSetTexture();
//
//}


ChoseGoods::ChoseGoods(DirectX * pDirectX, SoundOperater * pSoundOperater, int turn, Yasuko* pYasuko) :SubScene(pDirectX, pSoundOperater, turn, pYasuko)
{
	switch (turn)
	{
	case 0:
		m_TexKey = "ISOKO_TEX";
		break;
	case 1:
		m_TexKey = "MOB_TEX";
		break;
	case 2:
		m_TexKey = "MITUKO_TEX";
		break;
	}
	mobCentralBlowOff[0] = { 450,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[1] = { 600,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[2] = { 750,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[3] = { 900,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[4] = { 1050,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };

}


ChoseGoods::~ChoseGoods()
{

}

int ChoseGoods::Update()
{
	if (m_pDirectX->GetKeyStatus(DIK_Q) == KeyRelease|| m_pXinputDevice->GetButton(ButtonX) == PadRelease)
	{
		selectedGoods[m_Turn] = m_pYasuko->editMerchandise(m_SalesChoice, 0);
		SetGameScene(BLOWOFF);
	}
	if (m_pDirectX->GetKeyStatus(DIK_E) == KeyRelease|| m_pXinputDevice->GetButton(ButtonB) == PadRelease)
	{
		selectedGoods[m_Turn] = m_pYasuko->editMerchandise(m_SalesChoice, 1);
		SetGameScene(BLOWOFF);
	}

	if (m_pXinputDevice->GetButton(ButtonA) == PadRelease)
	{

	}
	return m_GameScene;
}

void ChoseGoods::LoadResouce()
{
}

void ChoseGoods::Render()
{
	CUSTOMVERTEX vertex[4];
	CENTRAL_STATE effectCentral = { playerCentralHit.x - 2,playerCentralHit.y - 14,playerCentralHit.scaleX*2.03f,playerCentralHit.scaleY*1.4f };

	CreateSquareVertex(playerHit, &playerCentralHit, WHITE, 0.f, 0.f, YASUKO_TU, YASUKO_TV);
	CreateSquareVertex(vertex, &effectCentral, WHITE, (m_effectCount * EFFECT_TU), 0, EFFECT_TU, EFFECT_TV);

	CreateSquareVertex(vertex, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	m_pDirectX->DrawTexture("FLOAMOVE_BG_TEX",vertex);

	CreateSquareVertex(vertex, DISPLAY_WIDTH, DISPLAY_HEIGHT,  HARFCLEAR);
	m_pDirectX->DrawTexture( "BLANK",vertex);

	for (int i = 0; i < 5; i++) {
		CreateSquareVertex(vertex, &mobCentralBlowOff[i], 0, 0, MOB_TU, MOB_TV);
		m_pDirectX->DrawTexture(m_TexKey, vertex);
	}

	m_pDirectX->DrawTexture("YASUKO_EFFECT_TEX",vertex);
	m_pDirectX->DrawTexture("YASUKO_TEX",playerHit );
	CreateSquareVertex(vertex,350.f, 150.f, 600.f, 400.f);
	m_pDirectX->DrawTexture(GetFoodGoodsTexID(m_pYasuko->editMerchandise(m_SalesChoice,0)), vertex);
	CreateSquareVertex(vertex, 660.f, 150.f, 910.f, 400.f);
	m_pDirectX->DrawTexture(GetFoodGoodsTexID(m_pYasuko->editMerchandise(m_SalesChoice,1)), vertex);
	CreateSquareVertex(vertex, 350.f, 350.f, 600.f, 500.f);
	m_pDirectX->DrawTexture("X_TEX", vertex);
	CreateSquareVertex(vertex, 660.f, 350.f, 910.f, 500.f);
	m_pDirectX->DrawTexture("B_TEX", vertex);

}
