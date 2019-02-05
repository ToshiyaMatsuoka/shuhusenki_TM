#include "BlowOff.h"

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
	mobCentralBlowOff[0] = { 450,MobHeight ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[1] = { 600,MobHeight ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[2] = { 750,MobHeight ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[3] = { 900,MobHeight ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };
	mobCentralBlowOff[4] = { 1050,MobHeight ,CHARCTOR_BLOWOFF_SCALE,CHARCTOR_BLOWOFF_SCALE };

	effectExplosionCentral = { 900,800,300,300 }; 
	m_pYasuko->InitBlowoff();

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
		BlowOffKeyOperation();
		checkedComand = comandCheck();
		if (1 == checkedComand)
		{
			if (SoundLib::Playing != m_pSoundOperater->GetStatus("SUCCESS")) {
				m_pSoundOperater->Start("SUCCESS", false);
			}
		}
		if (!checkedComand)
		{
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
			if (m_BlowOffEffectCount < 1) {
				m_pSoundOperater->Start("ATTACK", false);
			}
			m_isBlowOff = true;
		}
		if (!checkedComand)
		{
			if (SoundLib::Playing != m_pSoundOperater->GetStatus("MISS")) {
				m_pSoundOperater->Start("MISS", false);
			}
		}
	}
	checkedComand = 2;
	if (m_isBlowOff) {
		++m_BlowOffEffectCount;
		madamBlowOff();
		++effectExplosionCentral.scaleX;
		++effectExplosionCentral.scaleY;
		if (m_BlowOffEffectCount >= 60) {
			m_pSoundOperater->Stop("ATTACK");
			m_GameScene = PICKGOODS;
			comandCount = 0;
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
		if ((m_BlowOffEffectCount > 20) && m_isBlowOff) {
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
		m_pYasuko->BlowOffRender();
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


