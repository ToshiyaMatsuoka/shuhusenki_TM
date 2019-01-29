/**
* @file SCENE.cpp
* @brief SCENEクラス
* @author Toshiya Matsuoka
*/
#include "SCENE.h"
#include "Goods.h"

int Scene::m_SalesChoice = 0;
XinputDevice* Scene::m_pXinputDevice = NULL;
Goods* Scene::m_pGoods = NULL;

Scene::Scene(DirectX* pDirectX, SoundOperater* pSoundOperater) :m_pDirectX(pDirectX), m_pSoundOperater(pSoundOperater)
{
	m_pDirectX = pDirectX;
	m_pXinputDevice = new XinputDevice;
	m_pSoundOperater = pSoundOperater;
	m_pDirectX->LoadTexture("Texture/nowloading.png", "LOAD_TEX");

}

Scene::~Scene()
{

	delete m_pXinputDevice;
	m_pXinputDevice = NULL;

}

void Scene::CreateSquareVertex(CUSTOMVERTEX* Vertex, CENTRAL_STATE* Central, DWORD  color, float tu, float tv, float scaleTu, float scaleTv) {
	Vertex[0] = { Central->x - Central->scaleX, Central->y - Central->scaleY, 1.f, 1.f, color, tu, tv };
	Vertex[1] = { Central->x + Central->scaleX, Central->y - Central->scaleY, 1.f, 1.f, color, tu + scaleTu, tv };
	Vertex[2] = { Central->x + Central->scaleX, Central->y + Central->scaleY, 1.f, 1.f, color, tu + scaleTu, tv + scaleTv };
	Vertex[3] = { Central->x - Central->scaleX, Central->y + Central->scaleY, 1.f, 1.f, color, tu, tv + scaleTv };
}
void Scene::CreateSquareVertex(CUSTOMVERTEX* Vertex, float x, float y, DWORD  color, float tu, float tv, float scaleTu, float scaleTv) {
	Vertex[0] = { 0,  0, 1.f, 1.f, color, tu, tv };
	Vertex[1] = { x, 0, 1.f, 1.f, color, tu + scaleTu, tv };
	Vertex[2] = { x, y, 1.f, 1.f, color, tu + scaleTu, tv + scaleTv };
	Vertex[3] = { 0,  y, 1.f, 1.f, color, tu, tv + scaleTv };
}
void Scene::CreateSquareVertex(CUSTOMVERTEX* Vertex, float x, float y, float xScale, float yScale, DWORD  color, float tu, float tv, float scaleTu, float scaleTv) {
	Vertex[0] = { x,  y, 1.f, 1.f, color, tu, tv };
	Vertex[1] = { xScale, y, 1.f, 1.f, color, tu + scaleTu, tv };
	Vertex[2] = { xScale, yScale, 1.f, 1.f, color, tu + scaleTu, tv + scaleTv };
	Vertex[3] = { x,  yScale, 1.f, 1.f, color, tu, tv + scaleTv };
}
void Scene::CreateSquareVertex(CUSTOMVERTEX* Vertex, RECT rect, DWORD color, float tu, float tv, float scaleTu, float scaleTv) {

	Vertex[0] = { static_cast<float>(rect.left), static_cast<float>(rect.top),    1.f, 1.f, color, tu, tv };
	Vertex[1] = { static_cast<float>(rect.right),static_cast<float>(rect.top),    1.f, 1.f, color, tu + scaleTu, tv };
	Vertex[2] = { static_cast<float>(rect.right),static_cast<float>(rect.bottom), 1.f, 1.f, color, tu + scaleTu, tv + scaleTv };
	Vertex[3] = { static_cast<float>(rect.left), static_cast<float>(rect.bottom), 1.f, 1.f, color, tu, tv + scaleTv };

}

void Scene::LoadAnimation() {

	static int CursorAnimeInterval = 0;
	++CursorAnimeInterval;
	static bool CursorColorOn = false;
	if (CursorAnimeInterval > 20) {

		m_Color += (0xFF << 24) * ((CursorColorOn) ? +1 : -1);

		CursorColorOn = !CursorColorOn;
		CursorAnimeInterval = 0;
	}

	CUSTOMVERTEX LoadBg[4];
	CreateSquareVertex(LoadBg, DISPLAY_WIDTH, DISPLAY_HEIGHT - 20, m_Color);
	m_pDirectX->DrawTexture("LOAD_TEX", LoadBg);

}


void Scene::RevolveZ(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE* Central, DWORD  color, float tu, float tv, float scaleTu, float scaleTv) {

	float CharVertexX[4];
	float CharVertexY[4];

	CharVertexX[0] = Central->x - Central->scaleX;
	CharVertexX[1] = Central->x + Central->scaleX;
	CharVertexX[2] = Central->x + Central->scaleX;
	CharVertexX[3] = Central->x - Central->scaleX;

	CharVertexY[0] = Central->y - Central->scaleY;
	CharVertexY[1] = Central->y - Central->scaleY;
	CharVertexY[2] = Central->y + Central->scaleY;
	CharVertexY[3] = Central->y + Central->scaleY;

	for (int RoteCnt = 0; RoteCnt < 4; RoteCnt++) {

		CharVertexX[RoteCnt] -= Central->x;
		CharVertexY[RoteCnt] -= Central->y;

		float KEEPER = CharVertexX[RoteCnt];

		CharVertexX[RoteCnt] = (CharVertexX[RoteCnt] * cos(-Rad)) - (CharVertexY[RoteCnt] * sin(-Rad));
		CharVertexY[RoteCnt] = (CharVertexY[RoteCnt] * cos(-Rad)) + (KEEPER * sin(-Rad));

		CharVertexX[RoteCnt] += Central->x;
		CharVertexY[RoteCnt] += Central->y;

	}

	Vertex[0] = { CharVertexX[0], CharVertexY[0], 1.f, 1.f, color, tu, tv };
	Vertex[1] = { CharVertexX[1], CharVertexY[1], 1.f, 1.f, color, tu + scaleTu, tv };
	Vertex[2] = { CharVertexX[2], CharVertexY[2], 1.f, 1.f, color, tu + scaleTu, tv + scaleTv };
	Vertex[3] = { CharVertexX[3], CharVertexY[3], 1.f, 1.f, color, tu, tv + scaleTv };

}

void Scene::showPressA()
{
	static DWORD Color = 0xffffffff;
	static int CursorAnimeInterval = 0;
	++CursorAnimeInterval;
	static bool CursorColorOn = false;
	if (CursorAnimeInterval > 40) {

		Color += (0xFF << 24) * ((CursorColorOn) ? +1 : -1);

		CursorColorOn = !CursorColorOn;
		CursorAnimeInterval = 0;
	}

	CUSTOMVERTEX showA[4];
	CENTRAL_STATE centralAButton = { 1200,600,50,50 };
	CreateSquareVertex(showA, &centralAButton, Color);
	m_pDirectX->DrawTexture("A_TEX", showA);
}

void Scene::Debug() {
#ifdef _DEBUG
		m_pSoundOperater->Stop("FOOD");
		m_pSoundOperater->Stop("HURRY_UP");
		m_pSoundOperater->SetVolume("HURRY_UP", 100);

		m_pSoundOperater->Stop("TIME_LIMIT");


		m_pGoods->SetselectedGoods(0, POTATO);
		m_pGoods->SetselectedGoods(1, BEEF);
		m_pGoods->SetselectedGoods(2, ONION);

		for (int i = 0; i < 3; i++) {
			m_pGoods->AddHaveValue(300, m_pGoods->GetselectedGoods(i));
		}
		m_NextScene = RESULT_SCENE;
#endif

}


