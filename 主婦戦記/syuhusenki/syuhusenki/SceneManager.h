/**
* @file SceneManager.h
* @brief SceneManagerクラス
* @author Toshiya Matsuoka
*/
#pragma once

#include "Scene.h"
#include "SoundOperater.h"

enum SCENE_NUM;
class Scene;


class SceneManager
{
public:
	SceneManager(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~SceneManager();
	int Update();
	void Render();
	static void LoadResouce();
	static DWORD WINAPI Thread(LPVOID *data);

private:
	void LoadAnimation();

	SCENE_NUM m_CurrentScene;

	//! メモリリーク検知器では検出されないと思われる。
	static Scene*	m_pScene;
	SCENE_NUM m_NextScene;
	DirectX* m_pDirectX = NULL;
	static SoundOperater* m_pSoundOperater;

	HANDLE m_threadHandle;
	DWORD m_threadResult;
	static void SoundLoad();
	void LoadAction();
	bool isRunOnce = false;
	bool isThreadActive = false;
	int LoadTime = 0;
	int TestTime = 0;
};
