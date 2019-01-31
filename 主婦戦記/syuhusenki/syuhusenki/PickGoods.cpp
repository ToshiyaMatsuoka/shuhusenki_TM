#include "PickGoods.h"

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

	if (GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonStart) == PadPush)
	{
		m_pSoundOperater->Stop("FOOD");
		m_pSoundOperater->Stop("HURRY_UP");
		m_pSoundOperater->SetVolume("HURRY_UP", 100);

		m_pSoundOperater->Stop("FOOD");

		m_pSoundOperater->Stop("TIME_LIMIT");

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

