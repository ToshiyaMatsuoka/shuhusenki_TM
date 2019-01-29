#include "BlowOff.h"
//#include "Main.h"
//#include "FloaMove.h"
//#include "GameMain.h"
//#include "Goods.h"
//#include "Timer.h"
//#include "BlowOff.h"
//
////エフェクト
//CUSTOMVERTEX effectExplosion[4];
//CENTRAL_STATE effectExplosionCentral = { 1000,800,300,300 };
//bool m_isBlowOff = false;
//
//static bool soundOnce = false;
//void blowOff() {
//	blowOffControl();
//	blowOffRender();
//	if (m_Turn == 0)
//	{
//		rushButtonShow = rand() % 4;
//	}
//	else {
//		rushButtonShow = rand() % 6;
//	}
//
//}

//void blowOffControl()
//{
//	timerControl();
//	CreateSquareVertex(effectExplosion, effectExplosionCentral);
//
//	if (comandCount < 5)
//	{
//		if (g_isGameStart)
//		{
//			blowOffDeviseControl(&comandCount, comandInput);
//		}
//		checkedComand = comandCheck(comandPresentment, comandInput, comandCount);
//		if (1 == checkedComand && soundOnce)
//		{
//			soundOnce = false;
//			m_pSoundOperater->Start("SUCCESS", false);
//			checkedComand = 2;
//		}
//		if (!checkedComand&&soundOnce)
//		{
//			soundOnce = false;
//			checkedComand = 2;
//			m_pSoundOperater->Start("MISS", false);
//			if (comandButton) {
//				comandCount -= 1;
//			}
//		}
//	}
//	else
//	{
//		checkedComand = comandCheck(comandPresentment, comandInput, comandCount);
//		if (1 == checkedComand)
//		{
//			m_pSoundOperater->Start("ATTACK", false);
//			m_isBlowOff = true;
//			checkedComand = 2;
//
//		}
//		if (!checkedComand)
//		{
//			m_pSoundOperater->Start("MISS", false);
//			checkedComand = 2;
//
//		}
//	}
//	if (m_isBlowOff) {
//		madamBlowOff();
//		effectExplosionCentral.scaleX++;
//		effectExplosionCentral.scaleY++;
//		playerCentralHit.x += 30;
//		if (g_effectCount >= 180) {
//			m_GameScene = PICKGOODS;
//			playerCentralHit.x = 200;
//			comandCount = 0;
//		}
//	}
//
//}

//void blowOffRender()
//{
//	CUSTOMVERTEX effectPC[4];
//	CENTRAL_STATE effectCentral = { playerCentralHit.x - 2,playerCentralHit.y - 14,playerCentralHit.scaleX*2.03f,playerCentralHit.scaleY*1.4f };
//
//	CreateSquareVertex(effectPC, effectCentral, WHITE, (effectCount * EFFECT_TU), 0, EFFECT_TU, EFFECT_TV);
//
//	CreateSquareVertex(playerHit, playerCentralHit, WHITE, g_blowOffPCEffectCount*YASUKO_TU, 2*YASUKO_TV, -1 * YASUKO_TU, YASUKO_TV);
//
//	BeginSetTexture();
//	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, "FLOAMOVE_BG_TEX");
//
//	EasyCreateSquareVertexColor(0, 0, WIDTH, HEIGHT, "BLANK", HARFCLEAR);
//
//	for (int i = 0; i < 5; i++) {
//		CreateSquareVertex(mobFloa, mobCentralBlowOff[i], WHITE, 0,0,MOB_TU, MOB_TV);
//		if (m_isBlowOff) {
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
//			RevolveZTuTv(mobFloa, mobRad, mobCentralBlowOff[i],  0, 0, MOB_TU, MOB_TV);
//		}
//		SetUpTexture(mobFloa, mobTexNum);
//	}
//	if ((g_effectCount > 20) && m_isBlowOff) {
//		SetUpTexture(effectExplosion, "EXPLOSION_TEX");
//	}
//	SetUpTexture(effectPC, "YASUKO_EFFECT_TEX");
//	SetUpTexture(playerHit, texturePC);
//
//	char debugComandInput[10];
//	char debugComandOutput[10];
//	char DebugCounter[10];
//	for (int i = 0; i < 5; i++)
//	{
//		RECT DEBUGText = { 300 + (i * 100),200,450 + (i * 100),300 };
//		EasyCreateRECTVertex(DEBUGText, comandButtonTexture(comandPresentment[i]));
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		RECT DEBUGText = { 300 + (i * 100),300,450 + (i * 100),400 };
//		EasyCreateRECTVertex(DEBUGText, comandButtonTexture(comandInput[i]));
//	}
//#ifdef _DEBUG
//
//	for (int i = 0; i < 5; i++)
//	{
//		sprintf_s(debugComandInput, 10, "%c", comandButton(comandInput[i]));
//
//		RECT DEBUGText = { 100 + (i * 50),500,900,600 };
//		WriteWord(debugComandInput, DEBUGText, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		sprintf_s(debugComandOutput, 10, "%c", comandButton(comandPresentment[i]));
//
//		RECT DEBUGText = { 100 + (i * 50),450,900,600 };
//		WriteWord(debugComandOutput, DEBUGText, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
//	}
//
//	sprintf_s(DebugCounter, 10, "%d", comandCount);
//	RECT DEBUGText = { 100 ,550,900,600 };
//	WriteWord(DebugCounter, DEBUGText, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
//#endif
//
//	goodsScoreShow();
//	timerRender();
//	EndSetTexture();
//}
//int comandCheck(int comand[], int inputComand[], int count)
//{
//	for (int i = 0; i < count; i++) {
//		if (inputComand[i] == 10) {
//			return 2;
//		}
//		if (comand[i] == inputComand[i]) {
//			if (i == count - 1) {
//				return 1;
//			}
//		}
//		if (comand[i] != inputComand[i]) {
//			if (i == count - 1) {
//				return 0;
//			}
//		}
//	}
//	return 2;
//}


BlowOff::BlowOff(DirectX * pDirectX, SoundOperater * pSoundOperater, int turn, Yasuko* pYasuko) :SubScene(pDirectX, pSoundOperater, turn, pYasuko)
{
	for (int i = 0; i < 5; i++)
	{
		comandInput[i] = 10;
	}
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
	mobCentralBlowOff[0] = { 450,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[1] = { 600,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[2] = { 750,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[3] = { 900,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[4] = { 1050,550 ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };

	effectExplosionCentral = { 900,800,300,300 }; 

	comandMake();
}


BlowOff::~BlowOff()
{
}

int BlowOff::Update()
{
	//CreateSquareVertex(effectExplosion, effectExplosionCentral);

	if (comandCount < 5)
	{
		//if (g_isGameStart)
		//{
		BlowOffKeyOperation();
		//}
		checkedComand = comandCheck();
		if (1 == checkedComand)
		{
			if (SoundLib::Playing != m_pSoundOperater->GetStatus("SUCCESS")) {
				m_pSoundOperater->Start("SUCCESS", false);
			}
			checkedComand = 2;
		}
		if (!checkedComand)
		{
			checkedComand = 2;
			if (SoundLib::Playing != m_pSoundOperater->GetStatus("MISS")) {
				m_pSoundOperater->Start("MISS", false);
			}
			if (comandCount) {
				comandCount -= 1;
			}
		}
	}
	else
	{
		checkedComand = comandCheck();
		if (1 == checkedComand)
		{
			m_pSoundOperater->Start("ATTACK", false);
			m_isBlowOff = true;
			checkedComand = 2;

		}
		if (!checkedComand)
		{
			if (SoundLib::Playing != m_pSoundOperater->GetStatus("MISS")) {
				m_pSoundOperater->Start("MISS", false);
			}
			checkedComand = 2;
		}
	}
	if (m_isBlowOff) {
		++m_EffectCount;
		madamBlowOff();
		effectExplosionCentral.scaleX++;
		effectExplosionCentral.scaleY++;
		playerCentralHit.x += 30;
		if (m_EffectCount >= 180) {
			m_GameScene = PICKGOODS;
			playerCentralHit.x = 200;
			comandCount = 0;
		}
	}
	return m_GameScene;
}

void BlowOff::BlowOffKeyOperation() {
		static int buttonKeyID = 0;
		static int prevbuttonKeyID = 1;
	#ifdef _DEBUG	
		if (m_pDirectX->GetKeyStatus(DIK_RETURN) == KeyPush || m_pDirectX->GetKeyStatus(DIK_NUMPADENTER) == KeyPush || m_pXinputDevice->GetButton(ButtonStart) == PadPush)
		{
			m_GameScene = PICKGOODS;
	
		}
	#endif
		if (m_pDirectX->GetKeyStatus(DIK_A) == KeyPush || m_pXinputDevice->GetButton(ButtonA) == PadPush)
		{

			comandInput[comandCount] = ButtonA;
			if (comandCount < 5) {
				comandCount += 1;
			}
			ButtonSE(Button, 3);
			return;
		}
		if (m_pDirectX->GetKeyStatus(DIK_B) == KeyPush || m_pXinputDevice->GetButton(ButtonB) == PadPush)
		{

			comandInput[comandCount] = ButtonB;
			if (comandCount < 5) {
				comandCount += 1;
			}
			ButtonSE(Button, 3);
			return;
		}
		if (m_pDirectX->GetKeyStatus(DIK_X) == KeyPush || m_pXinputDevice->GetButton(ButtonX) == PadPush)
		{

			comandInput[comandCount] = ButtonX;
			if (comandCount < 5) {
				comandCount += 1;
			}
			ButtonSE(Button, 3);
			return;
		}
		if (m_pDirectX->GetKeyStatus(DIK_Y) == KeyPush || m_pXinputDevice->GetButton(ButtonY) == PadPush)
		{

			comandInput[comandCount] = ButtonY;
			if (comandCount < 5) {
				comandCount += 1;
			}
			ButtonSE(Button, 3);
			return;
		}
		if (m_pDirectX->GetKeyStatus(DIK_R) == KeyPush || m_pXinputDevice->GetButton(ButtonRB) == PadPush)
		{

			comandInput[comandCount] = ButtonRB;
			if (comandCount < 5) {
				comandCount += 1;
			}
			ButtonSE(Button, 3);
			return;
		}
		if (m_pDirectX->GetKeyStatus(DIK_L) == KeyPush || m_pXinputDevice->GetButton(ButtonLB) == KeyPush)
		{

			comandInput[comandCount] = ButtonLB;
			if (comandCount < 5) {
				comandCount += 1;
			}
			ButtonSE(Button, 3);
			return;
		}
}

void BlowOff::LoadResouce()
{
}

void BlowOff::Render()
{
	static float mobRad = 0;
	CUSTOMVERTEX Vertex[4];
	RECT Background = { 0,100,DISPLAY_WIDTH ,700 };
	CreateSquareVertex(Vertex, Background);
	m_pDirectX->DrawTexture("FLOAMOVE_BG_TEX", Vertex);
	CreateSquareVertex(Vertex, Background, HARFCLEAR);
	m_pDirectX->DrawTexture("BLANK", Vertex);
		for (int i = 0; i < 5; i++) {
			if (m_isBlowOff) {
	
				mobRad += 0.9f;
	
				if (mobRad < 0)
				{
					mobRad = mobRad * -1;
				}
				if (i % 2)
				{
					mobRad = mobRad * -1;
				}
				RevolveZ(Vertex, mobRad, &mobCentralBlowOff[i],WHITE, 0, 0, MOB_TU, MOB_TV);
			}
			else CreateSquareVertex(Vertex, &mobCentralBlowOff[i], WHITE, 0, 0, MOB_TU, MOB_TV);
			m_pDirectX->DrawTexture( m_mobTexKey, Vertex);
		}
		if ((m_EffectCount > 20) && m_isBlowOff) {
			CreateSquareVertex(effectExplosion, &effectExplosionCentral);
			m_pDirectX->DrawTexture("EXPLOSION_TEX",effectExplosion);
		}
	
		for (int i = 0; i < 5; i++)
		{
			RECT PresentCommand = { 300 + (i * 100),200,450 + (i * 100),300 };
			CreateSquareVertex(Vertex, PresentCommand);
			m_pDirectX->DrawTexture(comandButtonTexture(comandPresentment[i]), Vertex);
		}
		for (int i = 0; i < 5; i++)
		{
			RECT InputComand = { 300 + (i * 100),300,450 + (i * 100),400 };
			CreateSquareVertex(Vertex, InputComand);
			m_pDirectX->DrawTexture(comandButtonTexture(comandInput[i]), Vertex);
		}
	//#ifdef _DEBUG
	//	char debugComandInput[10];
	//	char debugComandOutput[10];
	//	char DebugCounter[10];

	//	for (int i = 0; i < 5; i++)
	//	{
	//		sprintf_s(debugComandInput, 10, "%c", comandButton(comandInput[i]));
	//
	//		RECT DEBUGText = { 100 + (i * 50),500,900,600 };
	//		m_pDirectX->DrawWord( DEBUGText,debugComandInput, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
	//	}
	//	for (int i = 0; i < 5; i++)
	//	{
	//		sprintf_s(debugComandOutput, 10, "%c", comandButton(comandPresentment[i]));
	//
	//		RECT DEBUGText = { 100 + (i * 50),450,900,600 };
	//		m_pDirectX->DrawWord( DEBUGText,debugComandOutput, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
	//	}
	//
	//	sprintf_s(DebugCounter, 10, "%d", comandCount);
	//	RECT DEBUGText = { 100 ,550,900,600 };
	//	m_pDirectX->DrawWord( DEBUGText,DebugCounter, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
	//#endif
	//
	//}
}


char BlowOff::comandButton(int comand)
{
	switch (comand) {
	case ButtonA:
		return 'A';
	case ButtonB:
		return 'B';
	case ButtonX:
		return 'X';
	case ButtonY:
		return 'Y';
	case ButtonRB:
		return 'R';
	case ButtonLB:
		return 'L';
	}

}

void BlowOff::comandMake() {
	srand((unsigned int)time(NULL));
	if (m_Turn == 0)
	{
		comandPresentment[0] = rand() % 4;
		comandPresentment[1] = rand() % 4;
		comandPresentment[2] = rand() % 4;
		comandPresentment[3] = rand() % 4;
		comandPresentment[4] = rand() % 4;

	}
	else {
		comandPresentment[0] = rand() % 6;
		comandPresentment[1] = rand() % 6;
		comandPresentment[2] = rand() % 6;
		comandPresentment[3] = rand() % 6;
		comandPresentment[4] = rand() % 6;
	}
}


int BlowOff::comandCheck()
{
	for (int i = 0; i < comandCount; i++) {
		if (comandInput[i] == 10) {
			return 2;
		}
		if (comandPresentment[i] == comandInput[i]) {
			if (i == comandCount - 1) {
				return 1;
			}
		}
		if (comandPresentment[i] != comandInput[i]) {
			if (i == comandCount - 1) {
				return 0;
			}
		}
	}
	return 2;
}


