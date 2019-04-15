#include "BlowOff.h"

BlowOff::BlowOff(DirectX * pDirectX, SoundOperater * pSoundOperater, int turn, Yasuko* pYasuko) :SubScene(pDirectX, pSoundOperater, turn, pYasuko)
{
	for (int i = 0; i < 5; i++)
	{
		m_ComandInput[i] = 10;
	}
	switch (turn)
	{
	case 0:
		m_MobTexKey = "ISOKO_TEX";
		break;
	case 1:
		m_MobTexKey = "MOB_TEX";
		break;
	case 2:
		m_MobTexKey = "MITUKO_TEX";
		break;
	}
	mobCentralBlowOff[0] = { 450,MOB_HEIGHT ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[1] = { 600,MOB_HEIGHT ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[2] = { 750,MOB_HEIGHT ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[3] = { 900,MOB_HEIGHT ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[4] = { 1050,MOB_HEIGHT ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };

	m_EffectExplosionCentral = { 900,800,300,300 }; 
	m_pYasuko->InitBlowoff();
	m_GameScene = BLOWOFF;

	ComandMake();
}


BlowOff::~BlowOff()
{
}

int BlowOff::Update()
{
	//CreateSquareVertex(effectExplosion, effectExplosionCentral);
	if (m_ComandCount < 5)
	{
		BlowOffKeyOperation();
		m_CheckedComand = ComandCheck();
		if (1 == m_CheckedComand)
		{
			if (SoundLib::Playing != m_pSoundOperater->GetStatus("SUCCESS")) {
				m_pSoundOperater->Start("SUCCESS", false);
			}
		}
		if (!m_CheckedComand)
		{
			if (SoundLib::Playing != m_pSoundOperater->GetStatus("MISS")) {
				m_pSoundOperater->Start("MISS", false);
			}
			if (m_ComandCount) {
				m_ComandCount -= 1;
			}
		}
	}
	else
	{
		m_CheckedComand = ComandCheck();
		if (1 == m_CheckedComand)
		{
			if (m_BlowOffEffectCount < 1) {
				m_pSoundOperater->Start("ATTACK", false);
			}
			m_isBlowOff = true;
		}
		if (!m_CheckedComand)
		{
			if (SoundLib::Playing != m_pSoundOperater->GetStatus("MISS")) {
				m_pSoundOperater->Start("MISS", false);
			}
		}
	}
	m_CheckedComand = 2;
	if (m_isBlowOff) {
		++m_BlowOffEffectCount;
		madamBlowOff();
		++m_EffectExplosionCentral.scaleX;
		++m_EffectExplosionCentral.scaleY;
		if (m_BlowOffEffectCount >= 60) {
			m_pSoundOperater->Stop("ATTACK");
			m_GameScene = PICKGOODS;
			m_ComandCount = 0;
		}
	}
	m_pYasuko->BlowOffUpdate(m_isBlowOff);
	return m_GameScene;
}

void BlowOff::BlowOffKeyOperation() {
		static int buttonKeyID = 0;
		static int prevbuttonKeyID = 1;
	#ifdef _DEBUG	
		if (GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonStart) == PadPush)
		{
			m_GameScene = PICKGOODS;
	
		}
	#endif
		if (m_pDirectX->GetKeyStatus(DIK_A) == KeyPush || m_pXinputDevice->GetButton(ButtonA) == PadPush)
		{

			m_ComandInput[m_ComandCount] = ButtonA;
			if (m_ComandCount < 5) {
				m_ComandCount += 1;
			}
			ButtonSE(Button, 3);
			return;
		}
		if (m_pDirectX->GetKeyStatus(DIK_B) == KeyPush || m_pXinputDevice->GetButton(ButtonB) == PadPush)
		{

			m_ComandInput[m_ComandCount] = ButtonB;
			if (m_ComandCount < 5) {
				m_ComandCount += 1;
			}
			ButtonSE(Button, 3);
			return;
		}
		if (m_pDirectX->GetKeyStatus(DIK_X) == KeyPush || m_pXinputDevice->GetButton(ButtonX) == PadPush)
		{

			m_ComandInput[m_ComandCount] = ButtonX;
			if (m_ComandCount < 5) {
				m_ComandCount += 1;
			}
			ButtonSE(Button, 3);
			return;
		}
		if (m_pDirectX->GetKeyStatus(DIK_Y) == KeyPush || m_pXinputDevice->GetButton(ButtonY) == PadPush)
		{

			m_ComandInput[m_ComandCount] = ButtonY;
			if (m_ComandCount < 5) {
				m_ComandCount += 1;
			}
			ButtonSE(Button, 3);
			return;
		}
		if (m_pDirectX->GetKeyStatus(DIK_R) == KeyPush || m_pXinputDevice->GetButton(ButtonRB) == PadPush)
		{

			m_ComandInput[m_ComandCount] = ButtonRB;
			if (m_ComandCount < 5) {
				m_ComandCount += 1;
			}
			ButtonSE(Button, 3);
			return;
		}
		if (m_pDirectX->GetKeyStatus(DIK_L) == KeyPush || m_pXinputDevice->GetButton(ButtonLB) == KeyPush)
		{

			m_ComandInput[m_ComandCount] = ButtonLB;
			if (m_ComandCount < 5) {
				m_ComandCount += 1;
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
	RECT Background = { 0,100,static_cast<long>(DISPLAY_WIDTH) ,700 };
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
			m_pDirectX->DrawTexture( m_MobTexKey, Vertex);
		}
		if ((m_BlowOffEffectCount > 20) && m_isBlowOff) {
			CreateSquareVertex(m_EffectExplosion, &m_EffectExplosionCentral);
			m_pDirectX->DrawTexture("EXPLOSION_TEX",m_EffectExplosion);
		}
	
		for (int i = 0; i < 5; i++)
		{
			RECT PresentCommand = { 300 + (i * 100),200,450 + (i * 100),300 };
			CreateSquareVertex(Vertex, PresentCommand);
			m_pDirectX->DrawTexture(comandButtonTexture(m_ComandPresentment[i]), Vertex);
		}
		for (int i = 0; i < 5; i++)
		{
			RECT InputComand = { 300 + (i * 100),300,450 + (i * 100),400 };
			CreateSquareVertex(Vertex, InputComand);
			m_pDirectX->DrawTexture(comandButtonTexture(m_ComandInput[i]), Vertex);
		}
		m_pYasuko->BlowOffRender();
}


char BlowOff::ComandButton(int comand)
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
	return ' ';
}

void BlowOff::ComandMake() {
	srand((unsigned int)time(NULL));
	if (m_Turn == 0)
	{
		m_ComandPresentment[0] = rand() % 4;
		m_ComandPresentment[1] = rand() % 4;
		m_ComandPresentment[2] = rand() % 4;
		m_ComandPresentment[3] = rand() % 4;
		m_ComandPresentment[4] = rand() % 4;

	}
	else {
		m_ComandPresentment[0] = rand() % 6;
		m_ComandPresentment[1] = rand() % 6;
		m_ComandPresentment[2] = rand() % 6;
		m_ComandPresentment[3] = rand() % 6;
		m_ComandPresentment[4] = rand() % 6;
	}
}


int BlowOff::ComandCheck()
{
	for (int i = 0; i < m_ComandCount; i++) {
		if (m_ComandInput[i] == 10) {
			return 2;
		}
		if (m_ComandPresentment[i] == m_ComandInput[i]) {
			if (i == m_ComandCount - 1) {
				return 1;
			}
		}
		if (m_ComandPresentment[i] != m_ComandInput[i]) {
			if (i == m_ComandCount - 1) {
				return 0;
			}
		}
	}
	return 2;
}


