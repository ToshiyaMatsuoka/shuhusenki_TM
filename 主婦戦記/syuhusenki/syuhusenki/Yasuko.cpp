#include "Yasuko.h"
#include "FloaMove.h"

enum CONTACTDIRECTION
{
	SIDE,
	UPPER,
	UNDER
};

Yasuko::Yasuko(DirectX* pDirectX, SoundOperater* pSoundOperater) :Object(pDirectX, pSoundOperater)
{
	m_Center = { 900.f, 580.f, 32.f, 53.f };
}


Yasuko::~Yasuko()
{
}

void Yasuko::Update()
{
	FloaMoveUpdate();
}

void Yasuko::Render()
{

	if (m_isRight)
	{
		CreateSquareVertex(Vertex, m_Center, WHITE, m_TurningAnimetion*YASUKO_TU, m_ChangeAnimetion*YASUKO_TV, -1 * YASUKO_TU, YASUKO_TV);
	}
	else CreateSquareVertex(Vertex, m_Center, WHITE, m_TurningAnimetion*YASUKO_TU, m_ChangeAnimetion*YASUKO_TV, YASUKO_TU, YASUKO_TV);
	m_pDirectX->DrawTexture("YASUKO_TEX", Vertex);

#ifdef _DEBUG
	char debugPC[10];
	sprintf_s(debugPC, 10, "%.2f", m_Center.x);
	RECT DEBUGTextA = { 100 ,500,900,600 };
	m_pDirectX->DrawWord( DEBUGTextA,debugPC, "DEBUG_FONT", DT_LEFT, 0xffDDDDDD);
	sprintf_s(debugPC, 10, "%.2f", m_Center.y);
	DEBUGTextA = { 100 ,550,900,600 };
	m_pDirectX->DrawWord( DEBUGTextA,debugPC, "DEBUG_FONT", DT_LEFT, 0xffDDDDDD
	);

#endif

}

void Yasuko::KeyOperation(KeyInput key)
{
	switch (key) {
	case UP:
		FloaMoveUp();
		break;
	case DOWN:
		FloaMoveDown();
		break;
	case RIGHT:
		FloaMoveRight();
		break;
	case LEFT:
		FloaMoveLeft();
		break;
	case ACTION:
		break;

	}
}



void Yasuko::FloaMoveUpdate()
{

	m_AnimeCount++;

	/////////////////////////////////////////
	//mobToPCContact(&m_Center, mobCentralFloa);
	collision(&m_Center);
}


void Yasuko::FloaMoveLeft() {
	m_isRight = false;
		m_Center.x -= MOVE_SPEED;

		if (m_AnimeCount >= ANIMETION_TIME)
		{
			m_TurningAnimetion++;
			m_AnimeCount = 0;
		}
		if (m_TurningAnimetion > 3)
		{
			m_TurningAnimetion = 0;
		}
		m_ChangeAnimetion = 2;
}
void Yasuko::FloaMoveRight() {
	m_isRight = true;
		m_Center.x += MOVE_SPEED;

		if (m_TurningAnimetion == 0)
		{
			m_TurningAnimetion = 1;
		}
		if (m_AnimeCount >= ANIMETION_TIME)
		{
			m_TurningAnimetion++;
			m_AnimeCount = 0;
		}
		if (m_TurningAnimetion > 4)
		{
			m_TurningAnimetion = 1;
		}
		m_ChangeAnimetion = 2;
}
void Yasuko::FloaMoveUp() {
	m_isRight = false;
		m_Center.y -= MOVE_SPEED;
		if (m_AnimeCount >= ANIMETION_TIME)
		{
			m_TurningAnimetion++;
			m_AnimeCount = 0;
		}
		if (m_TurningAnimetion >= 3)
		{
			m_TurningAnimetion = 1;
		}
		m_ChangeAnimetion = 1;
}
void Yasuko::FloaMoveDown() {
	m_isRight = false;
		m_Center.y += MOVE_SPEED;
		if (m_AnimeCount >= ANIMETION_TIME)
		{
			m_TurningAnimetion++;
			m_AnimeCount = 0;
		}
		if (m_TurningAnimetion >= 3)
		{
			m_TurningAnimetion = 1;
		}
		m_ChangeAnimetion = 0;
}

bool Yasuko::MoveOutToErea(CENTRAL_STATE* central, float Left, float Top, float Right, float Bottom, int direction)
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

void Yasuko::collision(CENTRAL_STATE* charctor)
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
	MoveOutToErea(charctor, 1035, 218, 1152, 558, SIDE);//左右
	MoveOutToErea(charctor, 1035, 213, 1152, 217, UPPER);//上
	MoveOutToErea(charctor, 1035, 557, 1152, 565, UNDER);//下
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
