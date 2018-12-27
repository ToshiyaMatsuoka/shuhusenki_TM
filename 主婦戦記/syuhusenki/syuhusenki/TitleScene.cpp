/**
* @file TitleScene.cpp
* @brief タイトルシーン
* @author Toshiya Matsuoka
*/
#include "SCENE.h"
#include "TitleScene.h"
#include "TitleCursol.h"

TitleScene::TitleScene(DirectX* pDirectX, SoundOperater* pSoundOperater) :Scene(pDirectX, pSoundOperater)
{
	m_pScene = this;
	m_pCursol = new TitleCursol(m_pDirectX, m_pSoundOperater);

	CreateSquareVertex(m_TitleBackground, DISPLAY_WIDTH, DISPLAY_HEIGHT);
}

TitleScene::~TitleScene()
{
	delete m_pCursol;
	m_pDirectX->ClearTexture();
	m_pDirectX->ClearFont();
}

SCENE_NUM  TitleScene::Update()
{
	m_pXinputDevice->DeviceUpdate();

	if (KeyPush == m_pDirectX->GetKeyStatus(DIK_UP))
	{
		m_pCursol->KeyOperation(UP);
	}
	if (KeyPush == m_pDirectX->GetKeyStatus(DIK_DOWN))
	{
		m_pCursol->KeyOperation(DOWN);
	}
	if (PadRelease == m_pXinputDevice->GetButton(ButtonUP))
	{
		m_pCursol->KeyOperation(UP);
	}
	if (PadRelease == m_pXinputDevice->GetButton(ButtonDOWN))
	{
		m_pCursol->KeyOperation(DOWN);
	}
	if (PadPush == m_pXinputDevice->GetAnalogLState(ANALOGUP))
	{
		m_pCursol->KeyOperation(UP);
	}
	if (PadPush == m_pXinputDevice->GetAnalogLState(ANALOGDOWN))
	{
		m_pCursol->KeyOperation(DOWN);
	}

	if (GetPushedRETURN()) {
		ChoseMenu();
	}
	if (PadRelease == m_pXinputDevice->GetButton(ButtonA)) {
		ChoseMenu();
	}
	m_pCursol->Update();
	return GetNextScene();
}

void TitleScene::Render()
{


	m_pDirectX->DrawTexture("BACKGROUND_TEX", m_TitleBackground);

	CUSTOMVERTEX LogoVertex[4];
	CreateSquareVertex(LogoVertex, m_Logo);
	m_pDirectX->DrawTexture("LOGO_TEX", LogoVertex);

	m_pCursol->Render();

	CUSTOMVERTEX MenuVertex[4];
	CreateSquareVertex(MenuVertex, m_Menu);
	m_pDirectX->DrawTexture("MENU_TEX", MenuVertex);

}

void TitleScene::LoadResouce()
{
	m_pDirectX->LoadTexture("Texture/Blank.jpg", "BLANK");
	m_pDirectX->LoadTexture("Texture/title.jpg", "TITLE_BG_TEX");
	m_pDirectX->LoadTexture("Texture/title_select.png", "TITLE_UI_TEX");
	m_pDirectX->LoadTexture("Texture/UI/pressA.png", "PRESS_TEX");

	m_pDirectX->LoadTexture("Texture/team_logo.png", "TEAMLOGO_TEX");

	m_pDirectX->LoadTexture("Texture/UI/arrow.png", "TITLEICON_TEX");
	m_pDirectX->LoadTexture("Texture/wisdomP1.png", "WISDOM1_TEX");
	m_pDirectX->LoadTexture("Texture/wisdomP2.png", "WISDOM2_TEX");
	m_pDirectX->LoadTexture("Texture/wisdomP3.png", "WISDOM3_TEX");

	m_pDirectX->LoadTexture("Texture/button/a.png", "A_TEX");

}
void TitleScene::ChoseMenu() {
	switch (m_pCursol->getCursolPosition()) {
	case Cursol::START:
		SetNextScene(GAME_SCENE);
		break;
	case Cursol::END:
		EndGame();
		break;

	}
}

