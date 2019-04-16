/**
* @file FloaMob.cpp
* @brief 徘徊モブ処理
* @author Toshiya Matsuoka
*/
#include "FloaMob.h"

//モブの動く方向
enum MOBDIRECTION {
	NORTH,
	SOUTH,
	EAST,
	WEST
};


FloaMob::FloaMob(DirectX* pDirectX, SoundOperater* pSoundOperater,int turn) :Object(pDirectX, pSoundOperater)
{
	switch (turn)
	{
	case 0:
		m_TexKey = "ISOKO_TEX";
		break;
	case 1:
		m_TexKey = "MOB_TEX";
		break;
	case 2:
		m_TexKey = "MITUKO_TEX";
		break;
	}

}


FloaMob::~FloaMob()
{
}

void FloaMob::Update()
{
	static int collisionCount[4] = { 0,0,0,0 };
	static int mobAnimeCount[4] = { 0,0,0,0 };
	SelectDirection();
	if (!BtoBContact(&m_MobCenter[0], &m_Center))
	{
		if (m_MobCenter[0].x <= 120)
		{
			m_MobCenter[0].y -= 3;
			m_isRight[0] = false;
			m_Tv[0] = 1;

		}
		if (m_MobCenter[0].x >= 1190)
		{
			m_MobCenter[0].y += 3;
			m_isRight[0] = false;
			m_Tv[0] = 0;
		}
		if (m_MobCenter[0].y >= 630)
		{
			m_MobCenter[0].x -= 4;
			m_isRight[0] = false;
			m_Tv[0] = 2;

		}
		if (m_MobCenter[0].y <= 165)
		{
			m_MobCenter[0].x += 4;
			m_isRight[0] = true;
			m_Tv[0] = 2;

		}

	}
	else
	{
		collisionCount[0]++;
		if (collisionCount[0] > 30)
		{
			if (m_MobCenter[0].x <= 120)
			{
				m_MobCenter[0].y += 10;
				m_isRight[0] = false;
				m_Tv[0] = 0;

			}
			if (m_MobCenter[0].x >= 1190)
			{
				m_MobCenter[0].y -= 10;
				m_isRight[0] = false;
				m_Tv[0] = 1;
			}
			if (m_MobCenter[0].y >= 630)
			{
				m_MobCenter[0].x += 6;
				m_isRight[0] = true;
				m_Tv[0] = 2;


			}
			if (m_MobCenter[0].y <= 165)
			{
				m_MobCenter[0].x -= 6;
				m_isRight[0] = false;
				m_Tv[0] = 2;

			}
			collisionCount[0] = 0;
		}
	}
	mobAnimeCount[0]++;
	if (mobAnimeCount[0] >= ANIMETION_TIME)
	{
		m_Tu[0]++;
		mobAnimeCount[0] = 0;
	}
	if (m_Tu[0] > 1 && !m_isRight[0])
	{
		m_Tu[0] = 0;
	}
	if (m_Tu[0] > 2 && m_isRight[0])
	{
		m_Tu[0] = 1;
	}


	if (!BtoBContact(&m_MobCenter[1], &m_Center))
	{
		switch (Direction[0])
		{
		case NORTH:
			m_MobCenter[1].y -= 3;
			m_isRight[1] = false;
			m_Tv[1] = 1;
			break;
		case SOUTH:
			m_MobCenter[1].y += 3;
			m_isRight[1] = false;
			m_Tv[1] = 0;
			break;
		case EAST:
			m_MobCenter[1].x -= 3;
			m_isRight[1] = false;
			m_Tv[1] = 2;
			break;
		case WEST:
			m_MobCenter[1].x += 3;
			m_isRight[1] = true;
			m_Tv[1] = 2;
			break;
		}
	}
	else
	{
		collisionCount[1]++;
		if (collisionCount[1] > 30)
		{
			m_MobCenter[1].y += 5;
			m_MobCenter[1].x += 5;

			collisionCount[1] = 0;
		}
	}
	mobAnimeCount[1]++;
	if (mobAnimeCount[1] >= ANIMETION_TIME)
	{
		m_Tu[1]++;
		mobAnimeCount[1] = 0;
	}
	if (m_Tu[1] > 1 && !m_isRight[1])
	{
		m_Tu[1] = 0;
	}
	if (m_Tu[1] > 2 && m_isRight[1])
	{
		m_Tu[1] = 1;
	}

	if (!BtoBContact(&m_MobCenter[2], &m_Center))
	{
		switch (Direction[1])
		{
		case NORTH:
			m_MobCenter[2].y -= 1.5f;
			m_isRight[2] = false;
			m_Tv[2] = 1;
			break;
		case SOUTH:
			m_MobCenter[2].y += 1.5f;
			m_isRight[2] = false;
			m_Tv[2] = 0;
			break;
		case EAST:
			m_MobCenter[2].x -= 2;
			m_isRight[2] = false;
			m_Tv[2] = 2;
			break;
		case WEST:
			m_MobCenter[2].x += 2;
			m_isRight[2] = true;
			m_Tv[2] = 2;
			break;
		default:
			break;
		}
	}
	else
	{
		collisionCount[2]++;
		if (collisionCount[2] > 30)
		{
			m_MobCenter[2].y += 5;
			m_MobCenter[2].x += 5;
			collisionCount[2] = 0;
		}
	}
	if (!BtoBContact(&m_MobCenter[3], &m_Center))
	{
		switch (Direction[2])
		{
		case NORTH:
			m_MobCenter[3].y -= 1.5f;
			m_isRight[3] = false;
			m_Tv[3] = 1;
			break;
		case SOUTH:
			m_MobCenter[3].y += 1.5f;
			m_isRight[3] = false;
			m_Tv[3] = 0;
			break;
		case EAST:
			m_MobCenter[3].x -= 2;
			m_isRight[3] = false;
			m_Tv[3] = 2;
			break;
		case WEST:
			m_MobCenter[3].x += 2;
			m_isRight[3] = true;
			m_Tv[3] = 2;
			break;
		default:
			break;
		}
	}
	else
	{
		collisionCount[3]++;
		if (collisionCount[3] > 30)
		{
			m_MobCenter[3].y += 5;
			m_MobCenter[3].x += 5;
			collisionCount[3] = 0;
		}
	}

	collision(&m_MobCenter[1]);
	collision(&m_MobCenter[2]);
	collision(&m_MobCenter[3]);


}

void FloaMob::Render()
{


	for (int i = 0; i < 4; i++)
	{
		if (i == 0 || i == 1)
		{
			if (m_isRight[i])
			{
				CreateSquareVertex(Vertex, m_MobCenter[i], WHITE, m_Tu[i] * BOY_TU, m_Tv[i] * BOY_TV, -BOY_TU, BOY_TV);
			}
			else CreateSquareVertex(Vertex, m_MobCenter[i], WHITE, m_Tu[i] * BOY_TU, m_Tv[i] * BOY_TV, BOY_TU, BOY_TV);
		}
		else {
			if (m_isRight[i])
			{
				CreateSquareVertex(Vertex, m_MobCenter[i], WHITE, MOB_TU, m_Tv[i] * MOB_TV, -MOB_TU, MOB_TV);
			}
			else CreateSquareVertex(Vertex, m_MobCenter[i], WHITE, 0, m_Tv[i] * MOB_TV, MOB_TU, MOB_TV);
		}
		if (i >= 2)
		{
			m_pDirectX->DrawTexture(m_TexKey, Vertex);
		}
		else m_pDirectX->DrawTexture("BOY_TEX", Vertex);
	}

}

void FloaMob::SelectDirection() {
	static int time = 0;
	++time;
	if (time > 20) {
		Direction[0] = rand() % 4;
		Direction[1] = rand() % 5;
		Direction[2] = rand() % 5;
		time = 0;
	}
}
