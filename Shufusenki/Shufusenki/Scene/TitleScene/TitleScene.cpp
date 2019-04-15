/**
* @file TitleScene.cpp
* @brief タイトルシーン
* @author Toshiya Matsuoka
*/
#include "Scene/Scene.h"
#include "TitleScene.h"
#include "TitleCursol.h"

bool TitleScene::m_isRuningTeamlogo = true;

TitleScene::TitleScene(DirectX* pDirectX, SoundOperater* pSoundOperater) :Scene(pDirectX, pSoundOperater)
{
	m_pCursor = new TitleCursol(pDirectX, pSoundOperater);

	CreateSquareVertex(m_TitleBackground, DISPLAY_WIDTH, DISPLAY_HEIGHT);
}

TitleScene::~TitleScene()
{
	delete m_pCursor;
	m_pCursor = NULL;
	m_pDirectX->ClearTexture();
	m_pDirectX->ClearFont();

}

int  TitleScene::Update()
{
	m_pXinputDevice->DeviceUpdate();

	if (m_isRuningTeamlogo) {
		TeamlogoControl();
		return GetNextScene();
	}

	static int CursorAnimeInterval = 0;
	++CursorAnimeInterval;
	static bool CursorColorOn = false;
	if (CursorAnimeInterval > 20) {

		m_Color += (0xFF << 24) * ((CursorColorOn) ? 1 : -1);

		CursorColorOn = !CursorColorOn;
		CursorAnimeInterval = 0;
	}

	static int sceneSuccession = 0;
	static bool entry[2] = { false,false };
	for (BGM; BGM < 1; BGM++)
	{
		m_pSoundOperater->SetVolume("OP_BGM", 50);
		m_pSoundOperater->Start("OP_BGM", true);
	}

	if (m_TitleOrWisdom == WISDOM) {
		WisdomControl();
		return GetNextScene();
	}


	if (m_canApperMenu)
	{
		if (m_pDirectX->GetKeyStatus(DIK_W) == KeyPush || m_pDirectX->GetKeyStatus(DIK_UP) == KeyPush || m_pXinputDevice->GetButton(ButtonUP) == PadPush || m_pXinputDevice->GetAnalogLValue(ANALOG_Y) >= 6000)
		{
			if (m_Cursor.y == ARROWHIGH)
			{
				m_pSoundOperater->Start("CURSOR", false);
				m_Cursor.y = ARROWDOWN;
			}

			else if (m_Cursor.y == ARROWMIDLE)
			{
				m_pSoundOperater->Start("CURSOR", false);
				m_Cursor.y = ARROWHIGH;
			}
			else if (m_Cursor.y == ARROWDOWN)
			{
				m_pSoundOperater->Start("CURSOR", false);
				m_Cursor.y = ARROWMIDLE;
			}

		}

		if (m_pDirectX->GetKeyStatus(DIK_S) == KeyPush || m_pDirectX->GetKeyStatus(DIK_DOWN) == KeyPush || m_pXinputDevice->GetButton(ButtonDOWN) == PadPush || m_pXinputDevice->GetAnalogLValue(ANALOG_Y) <= -6000)
		{

			if (m_Cursor.y == ARROWHIGH)
			{
				m_pSoundOperater->Start("CURSOR", false);
				m_Cursor.y = ARROWMIDLE;
			}
			else if (m_Cursor.y == ARROWMIDLE)
			{
				m_pSoundOperater->Start("CURSOR", false);
				m_Cursor.y = ARROWDOWN;
			}
			else if (m_Cursor.y == ARROWDOWN)
			{
				m_pSoundOperater->Start("CURSOR", false);
				m_Cursor.y = ARROWHIGH;
			}

		}

		if ((GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonA) == PadPush) && m_Cursor.y == ARROWHIGH && (!entry[0]))
		{
			m_pSoundOperater->Start("GREETING", false);
			m_pSoundOperater->Start("BUTTON1", false);
			m_pSoundOperater->Stop("OP_BGM");
			BGM = 0;
			entry[0] = true;
		}

		if ((GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonA) == PadPush) && m_Cursor.y == ARROWMIDLE)
		{
			m_pSoundOperater->Start("BOW", false);
			m_pSoundOperater->Stop("OP_BGM");

			entry[1] = true;
		}
		if ((GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonA) == PadPush) && m_Cursor.y == ARROWDOWN)
		{
			m_TitleOrWisdom = WISDOM;
		}

		if (entry[0])
		{
			sceneSuccession++;
			if ((sceneSuccession >= 70) && entry[0])
			{
				SetNextScene(GAME_SCENE);
				sceneSuccession = 0;
				entry[0] = false;
			}
		}
		if (entry[1])
		{
			sceneSuccession++;

			if ((sceneSuccession >= 170) && entry[1])
			{
				PostQuitMessage(0);
			}

		}

	}
	if ((GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonA) == PadPush) && (!m_canApperMenu))
	{
		m_canApperMenu = true;

	}

	return GetNextScene();
}

void TitleScene::Render()
{
	if (m_TitleOrWisdom == WISDOM) {
		WisdomRender();
		return;
	}
	if (m_isRuningTeamlogo) {
		CUSTOMVERTEX teamlogo[4];
		CENTRAL_STATE logo{ 640,320,400,400 };
		static DWORD logoColor = 0x00ffffff;
		static bool canCleared = false;
		if (!canCleared) {
			logoColor += 2 << 24;
		}
		if (canCleared && (logoColor > 0xfffffff)) {
			logoColor -= 2 << 24;
		}
		if (canCleared && (logoColor > 0xffffff)) {
			logoColor -= 1 << 24;
		}

		if (logoColor == (0xfeffffff))
		{
			canCleared = true;
		}

		CreateSquareVertex(teamlogo, DISPLAY_WIDTH, DISPLAY_HEIGHT);
		m_pDirectX->DrawTexture("BLANK", teamlogo);

		CreateSquareVertex(teamlogo, &logo, logoColor);
		m_pDirectX->DrawTexture( "TEAMLOGO_TEX",teamlogo);
		return;
	}

	CUSTOMVERTEX MenuVertex[4];
	CreateSquareVertex(MenuVertex, &m_Menu);
	//m_pDirectX->DrawTexture("TITLE_UI_TEX", MenuVertex);
	CreateSquareVertex(m_TitleBackground, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	m_pDirectX->DrawTexture("TITLE_BG_TEX", m_TitleBackground);
	CENTRAL_STATE titleUICentral = { DISPLAY_WIDTH / 2, 550, 200.f, 100.f };
	CUSTOMVERTEX titleUI[4];
	CreateSquareVertex(titleUI, &titleUICentral);

	CUSTOMVERTEX selectArrow[4];
	CreateSquareVertex(selectArrow, &m_Cursor, m_Color);

	//タイトル矢印テクスチャの生成
	if (m_canApperMenu)
	{
		m_pDirectX->DrawTexture("TITLE_UI_TEX", titleUI);

		m_pDirectX->DrawTexture("TITLEICON_TEX", selectArrow);
	}
	else
	{
		static int count = 0;
		count++;
		if (count > 40)
		{
			count = 0;
		}
		if (count > 20)
		{
			m_pDirectX->DrawTexture("PRESS_TEX", titleUI);
		}
	}
}

void TitleScene::LoadResouce()
{
	m_pDirectX->LoadTexture("Resource/Texture/Blank.jpg", "BLANK");
	m_pDirectX->LoadTexture("Resource/Texture/title.jpg", "TITLE_BG_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/title_select.png", "TITLE_UI_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/UI/pressA.png", "PRESS_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/team_logo.png", "TEAMLOGO_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/UI/arrow.png", "TITLEICON_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/wisdomP1.png", "WISDOM1_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/wisdomP2.png", "WISDOM2_TEX");
	m_pDirectX->LoadTexture("Resource/Texture/wisdomP3.png", "WISDOM3_TEX");

	m_pDirectX->LoadTexture("Resource/Texture/button/a.png", "A_TEX");

}

void TitleScene::ChoseMenu() {
	switch (m_pCursor->getCursolPosition()) {
	case Cursol::START:
		SetNextScene(GAME_SCENE);
		break;
	case Cursol::END:
		EndGame();
		break;

	}
}

void TitleScene::TeamlogoControl(void) {
	
	if (SoundLib::Playing != m_pSoundOperater->GetStatus("LOGO")) {
		m_pSoundOperater->Start("LOGO", false);
	}
	static DWORD SyncOld = timeGetTime();
	DWORD SyncNow = timeGetTime();
	if (SyncNow - SyncOld > 4500 || GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonA) == PadPush)
	{
		m_isRuningTeamlogo = false;
	}
}

void TitleScene::TeamlogoRender(void) {
	CUSTOMVERTEX teamlogo[4];
	CENTRAL_STATE logo{ 640,320,400,400 };
	static DWORD logoColor = 0x00ffffff;
	static bool canCleared = false;
	if (!canCleared) {
		logoColor += 2 << 24;
	}
	if (canCleared && (logoColor > 0xfffffff)) {
		logoColor -= 2 << 24;
	}
	if (canCleared && (logoColor > 0xffffff)) {
		logoColor -= 1 << 24;
	}

	if (logoColor == (0xfeffffff))
	{
		canCleared = true;
	}

	CreateSquareVertex(teamlogo, DISPLAY_WIDTH, DISPLAY_HEIGHT);
	m_pDirectX->DrawTexture( "BLANK", teamlogo);

	CreateSquareVertex(teamlogo, &logo, logoColor);
	m_pDirectX->DrawTexture("TEAMLOGO_TEX", teamlogo);


}

//主婦の知恵
void TitleScene::WisdomControl()
{
	static int wisdomPage = PAGE1;

	if (GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonA) == PadPush)
	{
		switch (wisdomPage)
		{
		case PAGE1:
			m_WisdomTex = "WISDOM2_TEX";
			wisdomPage = PAGE2;
			break;
		case PAGE2:
			m_WisdomTex = "WISDOM3_TEX";
			wisdomPage = PAGE3;
			break;
		case PAGE3:
			m_WisdomTex = "WISDOM1_TEX";
			wisdomPage = PAGE1;
			m_TitleOrWisdom = TITLE;
			break;
		}

	}

}

void TitleScene::WisdomRender()
{
	CUSTOMVERTEX WisdomVertex[4];
	CreateSquareVertex(WisdomVertex,1270, 680);
	m_pDirectX->DrawTexture(m_WisdomTex, WisdomVertex);

	showPressA();
}
