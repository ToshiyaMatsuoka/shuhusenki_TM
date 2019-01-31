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
bool Object::toBoxContact(CENTRAL_STATE* central1, CENTRAL_STATE* central2) {
	if ((central1->x <= central2->x + central2->scaleX) && (central1->x >= central2->x - central2->scaleX)
		&& (central1->y <= central2->y + central2->scaleY) && (central1->y >= central2->y - central2->scaleY)) {
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
		if (toBoxContact(central, &popSales[i].popPositionCentral))
		{
			return popSales[i].popPosition;
		}
	}
	return POS_NOTING;
}


int Object::editMerchandise(int seleChoice, int arrayNum)
{
	return popSales[seleChoice].merchandise[arrayNum];
}

bool Object::MoveOutToErea(CENTRAL_STATE* central, float Left, float Top, float Right, float Bottom, int direction)
{
	static float posBuff = 0;
	posBuff = central->y;
	if ((Left <= central->x) && (central->x <= Right)
		&& (Top <= central->y) && (central->y <= Bottom))
	{
		switch (direction)
		{
		case 0:
			if ((Left + (Right - Left) / 2) >= central->x) {
				central->x = Left - 1;
				return true;
			}
			if (central->x >= (Right - (Right - Left) / 2)) {
				central->x = Right + 1;
				return true;
			}
			break;
		case 1:
			if ((Top + (Bottom - Top) / 2) >= central->y) {
				central->y = Top - 1;
				return true;
			}
			break;
		case 2:
			if (central->y >= (Bottom - (Bottom - Top) / 2)) {
				central->y = Bottom + 1;
				return true;
			}
			break;
		default:
			return false;
		}
	}
}

void Object::DrawLotsgoodsSorting(){
	popSales[0].goodsSorting = rand() % 6;
	while (popSales[0].goodsSorting == popSales[1].goodsSorting) {
		popSales[1].goodsSorting = rand() % 6;
	}
	while ((popSales[0].goodsSorting == popSales[2].goodsSorting) || (popSales[1].goodsSorting == popSales[2].goodsSorting)) {

		popSales[2].goodsSorting = rand() % 6;
	}
}

void Object::collision(CENTRAL_STATE* charctor)
{
	MoveInToErea(charctor, 0.f, 145.f, 1280.f, 690.f);
	//商品棚
	//ジュース1
	MoveOutToErea(charctor, -50, 195, 100, 545, SIDE);//左右
	MoveOutToErea(charctor, 0, 185, 100, 194, UPPER);//上
	MoveOutToErea(charctor, 0, 545, 100, 555, UNDER);//下

													 //肉
	MoveOutToErea(charctor, 125, -50, 640, 139, SIDE);//左右
	MoveOutToErea(charctor, 125, 140, 640, 145, UNDER);//下

													   //魚1
	MoveOutToErea(charctor, 640, -50, 1230, 139, SIDE);//左右
	MoveOutToErea(charctor, 640, 140, 1230, 145, UNDER);//下
														//野菜1
	MoveOutToErea(charctor, 1200, 170, 1380, 608, SIDE);//左右
	MoveOutToErea(charctor, 1200, 165, 1280, 169, UPPER);//上
	MoveOutToErea(charctor, 1200, 609, 1280, 615, UNDER);//下

														 //果実2
	MoveOutToErea(charctor, 786, 425, 1016, 568, SIDE);//左右
	MoveOutToErea(charctor, 786, 420, 1016, 425, UPPER);//上
	MoveOutToErea(charctor, 786, 568, 1016, 575, UNDER);//下

														//野菜2
	MoveOutToErea(charctor, 1040, 218, 1152, 558, SIDE);//左右
	MoveOutToErea(charctor, 1040, 213, 1152, 217, UPPER);//上
	MoveOutToErea(charctor, 1040, 557, 1152, 565, UNDER);//下
														 //魚2
	MoveOutToErea(charctor, 640, 178, 1152, 246, SIDE);//左右
	MoveOutToErea(charctor, 640, 170, 1152, 177, UPPER);//上
	MoveOutToErea(charctor, 640, 245, 1152, 250, UNDER);//下
														//ジュース3
	MoveOutToErea(charctor, 682, 265, 1016, 399, SIDE);//左右
	MoveOutToErea(charctor, 682, 260, 1016, 264, UPPER);//上
	MoveOutToErea(charctor, 682, 400, 1016, 405, UNDER);//下
														//果実1
	MoveOutToErea(charctor, 442, 436, 770, 584, SIDE);//左右
	MoveOutToErea(charctor, 442, 429, 770, 435, UPPER);//上
	MoveOutToErea(charctor, 442, 585, 770, 590, UNDER);//下
													   //おやつ1
	MoveOutToErea(charctor, 270, 176, 595, 284, SIDE);//左右
	MoveOutToErea(charctor, 270, 170, 595, 175, UPPER);//上
	MoveOutToErea(charctor, 270, 285, 595, 290, UNDER);//下
													   //おやつ2-1
	MoveOutToErea(charctor, 135, 175, 250, 330, SIDE);//左右
	MoveOutToErea(charctor, 135, 170, 250, 174, UPPER);//上
													   //おやつ2-2
	MoveOutToErea(charctor, 135, 328, 600, 389, SIDE);//左右
	MoveOutToErea(charctor, 135, 320, 600, 327, UPPER);//上
	MoveOutToErea(charctor, 135, 390, 600, 400, UNDER);//下
													   //おやつ3
	MoveOutToErea(charctor, 135, 436, 420, 584, SIDE);//左右
	MoveOutToErea(charctor, 135, 430, 420, 435, UPPER);//上
	MoveOutToErea(charctor, 135, 585, 420, 590, UNDER);//下

}

