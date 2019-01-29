/**
* @file GameManager.h
* @brief Mainループ処理,Window関連
* @author Toshiya Matsuoka
*/
#pragma once
#include <time.h>
#include "DirectX.h"
#include "SceneManager.h"
#include "SoundOperater.h"

#define _CRTDBG_MAP_ALLOC
#define new ::new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define DISPLAY_WIDTH 1280.f
#define DISPLAY_HEIGHT 720.f

struct CENTRAL_STATE
{
	float x, y, scaleX, scaleY;
};

class SceneManager;

class GameManager
{
public:
	GameManager(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow);
	~GameManager();
	int MessageLoop();
	static void ChangeDisplayMode(void);
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);

private:
	const char ApiName[20] = "☆主婦戦記☆";
	static DirectX* pDirectX;
	static SceneManager* pSceneManager;
	static HWND hWnd;
	static bool isWindowMode;	//true:Window　false:Full
	static bool isDeviceLost;
	static RECT WinRect;			//Window Mode での位置大きさ
	static SoundOperater* pSoundOperater;
};

