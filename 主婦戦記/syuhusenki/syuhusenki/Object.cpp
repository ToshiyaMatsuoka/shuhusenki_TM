/**
* @file Object.cpp
* @brief 色々な物体の基底クラス
* @author Toshiya Matsuoka
*/
#include "Object.h"

SALESMAN Object::popSales[3];

Object::Object(DirectX* pDirectX, SoundOperater* pSoundOperater):m_pDirectX(pDirectX), m_pSoundOperater(pSoundOperater)
{
}



Object::~Object()
{
}



void Object::KeyOperation()
{
}


void Object::Update()
{
}



void Object::TextureRender(std::string TextureKey, CUSTOMVERTEX* TextureSize)
{
	m_pDirectX->DrawTexture(TextureKey, TextureSize);
}


void Object::Render()
{
}


void Object::CreateSquareVertex(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, DWORD  color, float tu, float tv, float scaleTu, float scaleTv) {
	Vertex[0] = { Central.x - Central.scaleX, Central.y - Central.scaleY, 1.f, 1.f, color, tu, tv };
	Vertex[1] = { Central.x + Central.scaleX, Central.y - Central.scaleY, 1.f, 1.f, color, tu + scaleTu, tv };
	Vertex[2] = { Central.x + Central.scaleX, Central.y + Central.scaleY, 1.f, 1.f, color, tu + scaleTu, tv + scaleTv };
	Vertex[3] = { Central.x - Central.scaleX, Central.y + Central.scaleY, 1.f, 1.f, color, tu, tv + scaleTv };
}
void Object::CreateSquareVertex(CUSTOMVERTEX* Vertex, float x, float y, DWORD  color, float tu, float tv, float scaleTu, float scaleTv) {
	Vertex[0] = { 0,  0, 1.f, 1.f, color, tu, tv };
	Vertex[1] = { x, 0, 1.f, 1.f, color, tu + scaleTu, tv };
	Vertex[2] = { x, y, 1.f, 1.f, color, tu + scaleTu, tv + scaleTv };
	Vertex[3] = { 0,  y, 1.f, 1.f, color, tu, tv + scaleTv };
}
void Object::CreateSquareVertex( CENTRAL_STATE Central,CUSTOMVERTEX* Vertex, DWORD  color, float tu, float tv, float scaleTu, float scaleTv) {
	Vertex[0] = { Central.x , Central.y , 1.f, 1.f, color, tu, tv };
	Vertex[1] = { Central.x + Central.scaleX, Central.y , 1.f, 1.f, color, tu + scaleTu, tv };
	Vertex[2] = { Central.x + Central.scaleX, Central.y + Central.scaleY, 1.f, 1.f, color, tu + scaleTu, tv + scaleTv };
	Vertex[3] = { Central.x , Central.y + Central.scaleY, 1.f, 1.f, color, tu, tv + scaleTv };
}

void Object::TranslateCentral_State(CENTRAL_STATE* Central, CUSTOMVERTEX* Vertex) {
	Central->x = Vertex[0].x;
	Central->y = Vertex[0].y;
	Central->scaleX = Vertex[1].x - Vertex[0].x;
	Central->scaleY = Vertex[3].y - Vertex[0].y;
}

void Object::RevolveZ(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, DWORD  color, float tu, float tv, float scaleTu, float scaleTv) {

	float CharVertexX[4];
	float CharVertexY[4];

	CharVertexX[0] = Central.x - Central.scaleX;
	CharVertexX[1] = Central.x + Central.scaleX;
	CharVertexX[2] = Central.x + Central.scaleX;
	CharVertexX[3] = Central.x - Central.scaleX;

	CharVertexY[0] = Central.y - Central.scaleY;
	CharVertexY[1] = Central.y - Central.scaleY;
	CharVertexY[2] = Central.y + Central.scaleY;
	CharVertexY[3] = Central.y + Central.scaleY;

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

void Object::RevolveZEX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float RevolvingShaftX, float RevolvingShaftY, DWORD  color, float tu, float tv, float scaleTu, float scaleTv) {

	float CharVertexX[4];
	float CharVertexY[4];

	CharVertexX[0] = Central.x - Central.scaleX;
	CharVertexX[1] = Central.x + Central.scaleX;
	CharVertexX[2] = Central.x + Central.scaleX;
	CharVertexX[3] = Central.x - Central.scaleX;

	CharVertexY[0] = Central.y - Central.scaleY;
	CharVertexY[1] = Central.y - Central.scaleY;
	CharVertexY[2] = Central.y + Central.scaleY;
	CharVertexY[3] = Central.y + Central.scaleY;

	for (int RoteCnt = 0; RoteCnt < 4; RoteCnt++) {

		CharVertexX[RoteCnt] -= RevolvingShaftX;
		CharVertexY[RoteCnt] -= RevolvingShaftY;

		float KEEPER = CharVertexX[RoteCnt];

		CharVertexX[RoteCnt] = (CharVertexX[RoteCnt] * cos(-Rad)) - (CharVertexY[RoteCnt] * sin(-Rad));
		CharVertexY[RoteCnt] = (CharVertexY[RoteCnt] * cos(-Rad)) + (KEEPER * sin(-Rad));

		CharVertexX[RoteCnt] += RevolvingShaftX;
		CharVertexY[RoteCnt] += RevolvingShaftY;

	}

	Vertex[0] = { CharVertexX[0], CharVertexY[0], 1.f, 1.f, color, tu, tv };
	Vertex[1] = { CharVertexX[1], CharVertexY[1], 1.f, 1.f, color, tu + scaleTu, tv };
	Vertex[2] = { CharVertexX[2], CharVertexY[2], 1.f, 1.f, color, tu + scaleTu, tv + scaleTv };
	Vertex[3] = { CharVertexX[3], CharVertexY[3], 1.f, 1.f, color, tu, tv + scaleTv };

}

bool Object::BtoBContact(CENTRAL_STATE* central1, CENTRAL_STATE* central2) {
	if ((central1->x <= central2->x + central2->scaleX) && (central2->x <= central1->x + central1->scaleX)
		&& (central1->y <= central2->y + central2->scaleY) && (central2->y <= central1->y + central1->scaleY)) {
		return true;
	}
	else return false;
}
////矩形が指定範囲外に出ないようにする
void Object::MoveInToErea(CENTRAL_STATE* central, float Left, float Top, float Right, float Bottom) {
	if (Left >= central->x - central->scaleX || central->x + central->scaleX >= Right
		|| Top >= central->y || central->y + central->scaleY >= Bottom) {

		if (Left >= central->x - central->scaleX) {
			central->x = Left + central->scaleX;
		}
		if (central->x + central->scaleX >= Right) {
			central->x = Right - central->scaleX;
		}
		if (Top >= central->y) {
			central->y = Top;
		}
		if (central->y + central->scaleY >= Bottom) {
			central->y = Bottom - central->scaleY;
		}
	}
}

int Object::salesmanToPCCollision(CENTRAL_STATE* central)
{
	for (int i = 0; i < 3; i++)
	{
		if (BtoBContact(central, &popSales[i].popPositionCentral))
		{
			return popSales[i].popPosition;
		}
	}
	return POS_NOTING;
}

void Object::DebugSetting() {
	for (int i = 0; i < 3; i++)
	{
		popSales[i].goodsSorting = rand() % 6;//フロア移動で決めたものを入れる
	}
	selectGoods(&popSales[0]);
	selectGoods(&popSales[1]);
	selectGoods(&popSales[2]);
}

int Object::editMerchandise(int seleChoice, int arrayNum)
{
	return popSales[seleChoice].merchandise[arrayNum];
}

