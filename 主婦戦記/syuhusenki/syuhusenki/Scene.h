/**
* @file SCENE.h
* @brief SCENEクラス
* @author Toshiya Matsuoka
*/
#pragma once

#include "GAMEMANAGER.h"
#include "XinputDevice.h"
#include "SoundOperater.h"

#define CENTRAL_Y (DISPLAY_HEIGHT / 2)
#define CENTRAL_X (DISPLAY_WIDTH / 2)

struct CENTRAL_STATE;

enum SCENE_NUM
{
	SCENE_NONE,

	TITLE_SCENE,

	GAME_SCENE,

	RESULT_SCENE,

	MAX_SCENE,

};


class Scene {
public:
	SCENE_NUM GetNextScene()
	{
		return m_NextScene;
	}
	void SetNextScene(SCENE_NUM NextScene)
	{
		m_NextScene = NextScene;
	}
	Scene(DirectX* pDirectX, SoundOperater* pSoundOperater);
	virtual ~Scene();
	void Finalize();
	virtual SCENE_NUM Update() = 0;
	virtual void LoadResouce() = 0;
	virtual void Render() = 0;
	void EndGame() {
		m_GameState = WM_QUIT;
	}


	void LoadAnimation();

	void CreateSquareVertex(CUSTOMVERTEX* Vertex, CENTRAL_STATE* Central, DWORD  color = 0xffffffff, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
	void CreateSquareVertex(CUSTOMVERTEX* Vertex, float x, float y, DWORD  color = 0xffffffff, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
	void CreateSquareVertex(CUSTOMVERTEX* Vertex, float x, float y, float xScale, float yScale, DWORD  color = 0xffffffff, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
	void CreateSquareVertex(CUSTOMVERTEX* Vertex, RECT rect, DWORD  color = 0xffffffff, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);


	int GetGameState() {
		return m_GameState;
	}

protected:
	DirectX* m_pDirectX = NULL;
	static XinputDevice* m_pXinputDevice;
	SoundOperater* m_pSoundOperater = NULL;

	int m_StageNum = 0;
	int m_GameState = WM_NULL;
	static const int ARRAY_LONG = 64;

	//! 後で名称変更
	bool m_SoundSetting = false;

	float DegToRad(float deg) {
		return deg * (D3DX_PI / 180);
	}
	bool GetPushedRETURN() {
		return KeyRelease == m_pDirectX->GetKeyStatus(DIK_RETURN) || KeyRelease == m_pDirectX->GetKeyStatus(DIK_NUMPADENTER);
	}
	void RevolveZ(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE* Central, DWORD  color = 0xffffffff, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);

	void showPressA();

	const DWORD BLACK = 0xff000000;
	const DWORD  HARFCLEAR = 0x8a000000;
	const float  YASUKO_TU = (350.f / 2048.f);
	const float  YASUKO_TV = (679.f / 2048.f);
	const float  BOY_TU = (487.f / 2048.f);
	const float  BOY_TV = (707.f / 2048.f);
	const float  MOB_TU = (430.f / 2048.f);
	const float  MOB_TV = (685.f / 2048.f);
	const float  SALE_TU = (480.f / 2048.f);
	const float  SALE_TV = (785.f / 2048.f);
	const float  EFFECT_TU = (500.f / 2048.f);
	const float  EFFECT_TV = (700.f / 2048.f);
	static int m_SalesChoice;

	SCENE_NUM m_NextScene;	//次のシーン
private:

	DWORD m_Color = 0xffffffff;

};
