/**
* @file SCENE.cpp
* @brief SCENEクラス
* @author Toshiya Matsuoka
*/
#include "SCENE.h"

Scene::Scene(DirectX* pDirectX, SoundOperater* pSoundOperater) :m_pDirectX(pDirectX), m_pSoundOperater(pSoundOperater)
{
	m_pDirectX = pDirectX;
	m_pXinputDevice = new XinputDevice;
	m_pSoundOperater = pSoundOperater;
	m_pDirectX->LoadTexture("Texture/nowloading.png", "LOAD_TEX");

	m_pDirectX->SetFont(75, 75, "LOAD_FONT");
}

Scene::~Scene()
{
	delete m_pXinputDevice;
	m_pXinputDevice = NULL;
}


void Scene::CreateSquareVertex(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, DWORD  color, float tu, float tv, float scaleTu, float scaleTv) {
	Vertex[0] = { Central.x - Central.scale_x, Central.y - Central.scale_y, 1.f, 1.f, color, tu, tv };
	Vertex[1] = { Central.x + Central.scale_x, Central.y - Central.scale_y, 1.f, 1.f, color, tu + scaleTu, tv };
	Vertex[2] = { Central.x + Central.scale_x, Central.y + Central.scale_y, 1.f, 1.f, color, tu + scaleTu, tv + scaleTv };
	Vertex[3] = { Central.x - Central.scale_x, Central.y + Central.scale_y, 1.f, 1.f, color, tu, tv + scaleTv };
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


void Scene::RevolveZ(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, DWORD  color, float tu, float tv, float scaleTu, float scaleTv) {

	float CharVertexX[4];
	float CharVertexY[4];

	CharVertexX[0] = Central.x - Central.scale_x;
	CharVertexX[1] = Central.x + Central.scale_x;
	CharVertexX[2] = Central.x + Central.scale_x;
	CharVertexX[3] = Central.x - Central.scale_x;

	CharVertexY[0] = Central.y - Central.scale_y;
	CharVertexY[1] = Central.y - Central.scale_y;
	CharVertexY[2] = Central.y + Central.scale_y;
	CharVertexY[3] = Central.y + Central.scale_y;

	for (int RoteCnt = 0; RoteCnt < 4; RoteCnt++) {

		CharVertexX[RoteCnt] -= Central.x;
		CharVertexY[RoteCnt] -= Central.y;

		float KEEPER = CharVertexX[RoteCnt];

		CharVertexX[RoteCnt] = (CharVertexX[RoteCnt] * cos(-Rad)) - (CharVertexY[RoteCnt] * sin(-Rad));
		CharVertexY[RoteCnt] = (CharVertexY[RoteCnt] * cos(-Rad)) + (KEEPER * sin(-Rad));

		CharVertexX[RoteCnt] += Central.x;
		CharVertexY[RoteCnt] += Central.y;

	}

	Vertex[0] = { CharVertexX[0], CharVertexY[0], 1.f, 1.f, color, tu, tv };
	Vertex[1] = { CharVertexX[1], CharVertexY[1], 1.f, 1.f, color, tu + scaleTu, tv };
	Vertex[2] = { CharVertexX[2], CharVertexY[2], 1.f, 1.f, color, tu + scaleTu, tv + scaleTv };
	Vertex[3] = { CharVertexX[3], CharVertexY[3], 1.f, 1.f, color, tu, tv + scaleTv };

}

void Scene::showPressA()
{
	CUSTOMVERTEX showA[4];
	CENTRAL_STATE centralAButton = { 1200,600,50,50 };
	CreateSquareVertex(showA, centralAButton, m_Color);
	m_pDirectX->DrawTexture("A_TEX", showA);
}

