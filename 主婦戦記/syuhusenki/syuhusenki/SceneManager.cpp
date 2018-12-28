﻿/**
* @file SceneManager.cpp
* @brief SceneManagerクラス
* @author Toshiya Matsuoka
*/
#include "SceneManager.h"
#include "TITLESCENE.h"
#include "GAMESCENE.h"
#include "ResultScene.h"
#include "Goods.h"

Scene*	SceneManager::m_pScene = NULL;
SoundOperater* SceneManager::m_pSoundOperater = NULL;

SceneManager::SceneManager(DirectX* pDirectX, SoundOperater* pSoundOperater)
	:m_CurrentScene(SCENE_NONE), m_NextScene(TITLE_SCENE)
{
	m_pDirectX = pDirectX;
	m_pScene = new TitleScene(m_pDirectX, m_pSoundOperater);
	m_pSoundOperater = pSoundOperater;

	//ゲームシーンへショートカットする
	//m_NextScene = GAME_SCENE;
}

SceneManager::~SceneManager()
{
	m_pSoundOperater->AllStop();
	delete m_pScene;
	m_pScene = NULL;
}

int SceneManager::Update()
{
	#ifdef _DEBUG
		if (m_pDirectX->GetKeyStatus(DIK_F4) == KeyRelease && m_pDirectX->GetKeyStatus(DIK_LSHIFT))
		{
			m_pSoundOperater->Stop("FOOD");
			m_pSoundOperater->Stop("HURRY_UP");
			m_pSoundOperater->SetVolume("HURRY_UP", 100);
	
			m_pSoundOperater->Stop("TIME_LIMIT");
	
	
			selectedGoods[0] = POTATO;
			selectedGoods[1] = BEEF;
			selectedGoods[2] = ONION;
			for (int i = 0; i < 3; i++) {
				foodGoods[selectedGoods[i]].haveValue += 300;
			}
			m_NextScene = RESULT_SCENE;
		}
	#endif

	if (m_CurrentScene != m_NextScene)
	{
		switch (m_NextScene)
		{
		case TITLE_SCENE:
			if (!isRunOnce) {
				delete m_pScene;
			}
			isThreadActive = true;
			m_pScene = new  TitleScene(m_pDirectX, m_pSoundOperater);
			break;
		case GAME_SCENE:
			if (!isRunOnce) {
				delete m_pScene;
			}
			isThreadActive = true;
			m_pScene = new  GameScene(m_pDirectX, m_pSoundOperater);
			break;
		case RESULT_SCENE:
			if (!isRunOnce) {
				delete m_pScene;
			}
			isThreadActive = true;
			m_pScene = new  ResultScene(m_pDirectX, m_pSoundOperater);
			break;
		}
		m_NextScene = m_pScene->GetNextScene();

	}
	if (!isThreadActive) {
		m_NextScene = m_pScene->Update();
		//m_NextScene = m_pScene->GetNextScene();
	}
	else LoadAction();

	return m_pScene->GetGameState();
}

void SceneManager::Render()
{

	if (!isThreadActive) {
		m_pScene->Render();
	}
	else {
		LoadAnimation();

	}
}
void SceneManager::LoadResouce()
{
	m_pScene->LoadResouce();

}
DWORD WINAPI SceneManager::Thread(LPVOID *data)
{
	m_pScene->LoadResouce();
	SoundLoad();

	ExitThread(0);
}

void SceneManager::LoadAnimation() {
	m_pScene->LoadAnimation();
}

void SceneManager::SoundLoad()
{
	m_pSoundOperater->AddFile("Sound/loadEnd.mp3", "LOAD", SE);

	m_pSoundOperater->AddFile("Sound/foodbgm.mp3", "FOOD", BGM);

	m_pSoundOperater->AddFile("Sound/bottun.mp3", "BUTTON1", SE);
	m_pSoundOperater->AddFile("Sound/bottun.mp3", "BUTTON2", SE);
	m_pSoundOperater->AddFile("Sound/bottun.mp3", "BUTTON3", SE);

	m_pSoundOperater->AddFile("Sound/Welcome.mp3", "GREETING", SE);
	m_pSoundOperater->AddFile("Sound/thankyou.mp3", "BOW", SE);
	m_pSoundOperater->AddFile("Sound/correct answer.mp3", "SUCCESS", SE);
	m_pSoundOperater->AddFile("Sound/mistake.mp3", "MISS", SE);
	m_pSoundOperater->AddFile("Sound/explosion.mp3", "ATTACK", SE);
	m_pSoundOperater->AddFile("Sound/timer.mp3", "TIME_LIMIT", SE);
	m_pSoundOperater->AddFile("Sound/salebgm.mp3", "HURRY_UP", SE);

	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK1", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK2", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK3", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK4", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK5", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK6", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK7", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK8", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK9", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK10", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK11", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK12", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK13", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK14", SE);
	m_pSoundOperater->AddFile("Sound/shopping.mp3", "PICK15", SE);

	m_pSoundOperater->AddFile("Sound/selectBGM.mp3", "SELECT", BGM);
	m_pSoundOperater->AddFile("Sound/cursor.mp3", "CURSOR", SE);
	m_pSoundOperater->AddFile("Sound/gong.mp3", "GONG", SE);
	m_pSoundOperater->AddFile("Sound/whistle1.mp3", "WHISYLE", SE);
	m_pSoundOperater->AddFile("Sound/newop.mp3", "OP_BGM", BGM);
	m_pSoundOperater->AddFile("Sound/select.mp3", "SELECT_BGM", BGM);
	m_pSoundOperater->AddFile("Sound/clothBreak.mp3", "BREAK", SE);
	m_pSoundOperater->AddFile("Sound/stupid3.mp3", "LOSE", SE);
	m_pSoundOperater->AddFile("Sound/trumpet1.mp3", "WIN", SE);
	m_pSoundOperater->AddFile("Sound/select.mp3", "SELECT_BGM", BGM);
	m_pSoundOperater->AddFile("Sound/clothBreak.mp3", "BREAK", SE);
	m_pSoundOperater->AddFile("Sound/stupid3.mp3", "LOSE", SE);
	m_pSoundOperater->AddFile("Sound/trumpet1.mp3", "WIN", SE);

	m_pSoundOperater->AddFile("Sound/money.mp3", "COIN1", SE);
	m_pSoundOperater->AddFile("Sound/money.mp3", "COIN2", SE);
	m_pSoundOperater->AddFile("Sound/money.mp3", "COIN3", SE);
	m_pSoundOperater->AddFile("Sound/money.mp3", "COIN4", SE);
	m_pSoundOperater->AddFile("Sound/money.mp3", "COIN5", SE);
	m_pSoundOperater->AddFile("Sound/money.mp3", "COIN6", SE);

	m_pSoundOperater->AddFile("Sound/madam.mp3", "WISDOM", SE);
	m_pSoundOperater->AddFile("Sound/cutin.mp3", "CUTIN", SE);
	m_pSoundOperater->AddFile("Sound/tin1.mp3", "LOW_SCORE", SE);
	m_pSoundOperater->AddFile("Sound/people.mp3", "MIDLE_SCORE", SE);
	m_pSoundOperater->AddFile("Sound/people2.mp3", "HIGH_SCORE", SE);

	m_pSoundOperater->AddFile("Sound/sound.mp3", "LOGO", SE);
	m_pSoundOperater->AddFile("Sound/cash.mp3", "CASHER", SE);
	m_pSoundOperater->AddFile("Sound/drum roll.mp3", "DRUM", SE);
}

void SceneManager::LoadAction() {
	++LoadTime;

	if (!isRunOnce) {
		m_threadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Thread, m_pScene, 0, NULL);
		ResumeThread(m_threadHandle);
		isRunOnce = true;
		isThreadActive = true;
	}
	GetExitCodeThread(m_threadHandle, &m_threadResult);
	if (m_threadResult != STILL_ACTIVE && LoadTime >= 20) {
		CloseHandle(m_threadHandle);
		isRunOnce = false;
		LoadTime = 0;
		isThreadActive = false;
		m_CurrentScene = m_NextScene;
		m_pSoundOperater->Start("LOAD", false);
		Sleep(100);
	}
}

