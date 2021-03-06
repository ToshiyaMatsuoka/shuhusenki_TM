﻿#ifndef TITLESCENE_H
#define TITLESCENE_H
/**
* @file TitleScene.h
* @brief タイトルシーン
* @author Toshiya Matsuoka
*/

#include "Scene/Scene.h"

class TitleCursol;

class TitleScene : public Scene
{
public:
	TitleScene(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~TitleScene();
	int Update();
	void Render();
	void LoadResouce();

private:
	enum SCENEPAGE
	{
		PAGE1,
		PAGE2,
		PAGE3
	};
	enum TITLE_PAGE {
		TITLE,
		WISDOM
	};
	const float ARROWHIGH = 500.f;
	const float ARROWMIDLE = 550.f;
	const float ARROWDOWN = 600.f;

	CUSTOMVERTEX  m_TitleBackground[4];
	Scene* m_pScene = NULL;

	CENTRAL_STATE m_Logo = { CENTRAL_X ,200,400,150 };
	CENTRAL_STATE m_Menu = { CENTRAL_X ,500,100,100 };
	CENTRAL_STATE m_Cursor = { 500.f, ARROWHIGH, 20.f, 20.f };
	DWORD m_Color = 0xffffffff;

	int m_timecount = 0;
	TitleCursol* m_pCursor = NULL;
	static bool m_isRuningTeamlogo;
	bool m_canApperMenu = false;
	std::string m_WisdomTex = "WISDOM1_TEX";
	TITLE_PAGE m_TitleOrWisdom = TITLE;
	int BGM = 0;

	void ChoseMenu();
	void TeamlogoControl();
	void TeamlogoRender();
	void WisdomControl();
	void WisdomRender();
};
#endif
