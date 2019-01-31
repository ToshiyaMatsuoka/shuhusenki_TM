﻿#include "Yasuko.h"
#include "FloaMove.h"


Yasuko::Yasuko(DirectX* pDirectX, SoundOperater* pSoundOperater) :Object(pDirectX, pSoundOperater)
{
	m_Center = { 900.f, 580.f, 32.f, 53.f };
	m_EffectCentral = { m_Center.x - 2,m_Center.y - 14,60,75 };

}


Yasuko::~Yasuko()
{
}

void Yasuko::FloaUpdate()
{
	m_EffectCentral.x = m_Center.x - 2.f;
	m_EffectCentral.y = m_Center.y - 14.f;
	static int AnimeCount = 0;
	++AnimeCount;
	if (AnimeCount > 2) {
		TurnTheAnimation(4);
		AnimeCount = 0;
	}
	FloaMoveUpdate();
}

void Yasuko::BlowOffUpdate(bool isAttack)
{
	if (isAttack) {
		m_BOCenter.x += 30;
		return;
	}
}

void Yasuko::FloaRender()
{
	CreateSquareVertex(m_EffectVertex, m_EffectCentral, WHITE, (m_EffectCount * EFFECT_TU), 0, EFFECT_TU, EFFECT_TV);
	m_pDirectX->DrawTexture("YASUKO_EFFECT_TEX", m_EffectVertex);

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
	m_pDirectX->DrawWord( DEBUGTextA,debugPC, "DEBUG_FONT", DT_LEFT, 0xffDDFFDD);
	sprintf_s(debugPC, 10, "%.2f", m_Center.y);
	DEBUGTextA = { 100 ,550,900,600 };
	m_pDirectX->DrawWord( DEBUGTextA,debugPC, "DEBUG_FONT", DT_LEFT, 0xffDDFFDD);
#endif

}

void Yasuko::BlowOffRender()
{
	m_EffectCentral = { m_BOCenter.x - 2,m_BOCenter.y - 14,m_BOCenter.scaleX*2.03f,m_BOCenter.scaleY*1.4f };
	TurnTheAnimation(3);
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
	CreateSquareVertex(m_EffectVertex, m_EffectCentral, WHITE, (m_EffectCount * EFFECT_TU), 0, EFFECT_TU, EFFECT_TV);
	m_pDirectX->DrawTexture("YASUKO_EFFECT_TEX", m_EffectVertex);

		CreateSquareVertex(Vertex, m_BOCenter, WHITE, m_TurningAnimetion*YASUKO_TU, m_ChangeAnimetion*YASUKO_TV, -1 * YASUKO_TU, YASUKO_TV);
	m_pDirectX->DrawTexture("YASUKO_TEX", Vertex);

}

void Yasuko::InitBlowoff()
{
	m_BOCenter = { 200, 550, (CHARCTOR_BLOWOFF_SCALE - 50.f), CHARCTOR_BLOWOFF_SCALE };
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

void Yasuko::TurnTheAnimation(int AnimationPage)
{
	if (m_EffectCount < AnimationPage - 1) {
		m_EffectCount += 1.f;
	}
	else m_EffectCount = 0;
}


void Yasuko::FloaMoveUpdate()
{

	m_AnimeCount++;

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

void Yasuko::Initialize()
{
	//m_Center = { 900.f, 580.f, 32.f, 53.f };
	m_EffectCentral = { m_Center.x - 2,m_Center.y - 14,60,75 };
	m_TurningAnimetion = 0;
	m_ChangeAnimetion = 0;
	m_isRight = false;
}



void Yasuko::mobToPCContact(CENTRAL_STATE* mobCentralFloa)
{
	for (int i = 0; i < 4; i++)
	{
		if ((m_Center.x <= mobCentralFloa[i].x + mobCentralFloa[i].scaleX) && (mobCentralFloa[i].x <= m_Center.x + m_Center.scaleX)
			&& (m_Center.y <= mobCentralFloa[i].y + mobCentralFloa[i].scaleY) && (mobCentralFloa[i].y <= m_Center.y + m_Center.scaleY)) {

			if ((m_Center.x <= mobCentralFloa[i].x + mobCentralFloa[i].scaleX))
			{
				m_Center.x = mobCentralFloa[i].x + mobCentralFloa[i].scaleX;
			}
			if ((m_Center.x >= mobCentralFloa[i].x - mobCentralFloa[i].scaleX))
			{
				m_Center.x = mobCentralFloa[i].x - mobCentralFloa[i].scaleX;
			}
			if ((m_Center.y <= mobCentralFloa[i].y + mobCentralFloa[i].scaleY))
			{
				m_Center.y = mobCentralFloa[i].y + mobCentralFloa[i].scaleY;
			}
			if ((m_Center.y >= mobCentralFloa[i].y - mobCentralFloa[i].scaleY))
			{
				m_Center.y = mobCentralFloa[i].y - mobCentralFloa[i].scaleY;
			}
		}
	}
}

