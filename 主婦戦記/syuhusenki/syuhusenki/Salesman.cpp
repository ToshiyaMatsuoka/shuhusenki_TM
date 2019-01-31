#include "Salesman.h"
#include "Goods.h"



Salesman::Salesman(DirectX* pDirectX, SoundOperater* pSoundOperater) :Object(pDirectX, pSoundOperater)
{
}


Salesman::~Salesman()
{
}


void Salesman::Render() {

	static int saleAnimeCount = 0;
	int saleAnimeTv;
	static bool saleAnimeChainger = false;
	saleAnimeCount++;
	if (saleAnimeCount > ANIMETION_TIME && !saleAnimeChainger)
	{
		saleAnimeCount = 0;
		saleAnimeChainger = true;
	}
	if (saleAnimeCount > ANIMETION_TIME && saleAnimeChainger)
	{
		saleAnimeCount = 0;
		saleAnimeChainger = false;
	}
	if (saleAnimeChainger)
	{
		saleAnimeTv = 1;
	}
	else saleAnimeTv = 0;
	for (int i = 0; i < 3; i++)
	{
		CreateSquareVertex(Vertex, popSales[i].popPositionCentral, WHITE, 0, saleAnimeTv * SALE_TV, SALE_TU, SALE_TV);
		m_pDirectX->DrawTexture("SALESMAN_TEX", Vertex);
		CreateSquareVertex(Vertex, popSales[i].popPositionCentral, HARFCLEAR, 0, saleAnimeTv * SALE_TV, SALE_TU, SALE_TV);
		m_pDirectX->DrawTexture("BLANK", Vertex);
	}
}
void Salesman::Update()
{
	for (int i = 0; i < 3; i++)
	{
		//‘å‚«‚³AÀ•W‚ÍŒ»•¨‡‚í‚¹
		switch (popSales[i].goodsSorting)
		{
		case MEET_SORT:
			popSales[i].popPositionCentral = { 285,125,75,75 };
			popSales[i].popPosition = POS_MEET;
			break;
		case VEGETABLE_SORT:
			switch (i)
			{
			case 0:
				popSales[i].popPositionCentral = { 1190,360,75,75 };
				popSales[i].popPosition = POS_VEGETABLE1;
				break;
			case 1:
				popSales[i].popPositionCentral = { 1095,400,90,75 };
				popSales[i].popPosition = POS_VEGETABLE2;
				break;
			case 2:
				if (rand() % 2)
				{
					popSales[i].popPositionCentral = { 1095,400,90,75 };
					popSales[i].popPosition = POS_VEGETABLE2;
				}
				else
				{
					popSales[i].popPositionCentral = { 1190,360,75,75 };
					popSales[i].popPosition = POS_VEGETABLE1;
				}
				break;
			}
			continue;
		case SEAFOOD_SORT:
			switch (i)
			{
			case 0:
				popSales[i].popPositionCentral = { 800,125,75,75 };
				popSales[i].popPosition = POS_SEAFOOD1;
				break;
			case 1:
				popSales[i].popPositionCentral = { 875,210,75,75 };
				popSales[i].popPosition = POS_SEAFOOD2;
				break;
			case 2:
				if (rand() % 2)
				{
					popSales[i].popPositionCentral = { 875,210,75,75 };
					popSales[i].popPosition = POS_SEAFOOD2;
				}
				else
				{
					popSales[i].popPositionCentral = { 800,120,75,75 };
					popSales[i].popPosition = POS_SEAFOOD1;
				}
				break;
			}
			continue;
		case SWEET_SORT:
			switch (i)
			{
			case 0:
				popSales[i].popPositionCentral = { 410,230,75,90 };
				popSales[i].popPosition = POS_SWEET1;
				break;
			case 1:
				popSales[i].popPositionCentral = { 270,360,60,60 };
				popSales[i].popPosition = POS_SWEET2;
				break;
			case 2:
				popSales[i].popPositionCentral = { 270,530,100,100 };
				popSales[i].popPosition = POS_SWEET3;
				break;
			}
			continue;
		case FRUIT_SORT:
			switch (i)
			{
			case 0:
				popSales[i].popPositionCentral = { 610,540,170,80 };
				popSales[i].popPosition = POS_FRUIT1;
				break;
			case 1:
				popSales[i].popPositionCentral = { 917,512,100,100 };
				popSales[i].popPosition = POS_FRUIT2;
				break;
			case 2:
				if (rand() % 2) {
					popSales[i].popPositionCentral = { 917,512,100,100 };
					popSales[i].popPosition = POS_FRUIT2;
				}
				else
				{
					popSales[i].popPositionCentral = { 610,540,170,80 };
					popSales[i].popPosition = POS_FRUIT1;
				}
				break;
			}
			continue;
		case DRINK_SORT:
			switch (i)
			{
			case 0:
				popSales[i].popPositionCentral = { 65,450,75,100 };
				popSales[i].popPosition = POS_DRINK1;
				break;
			case 1:
				popSales[i].popPositionCentral = { 820,360,100,100 };
				popSales[i].popPosition = POS_DRINK2;
				break;
			case 2:
				if (rand() % 2) {
					popSales[i].popPositionCentral = { 820,360,100,100 };
					popSales[i].popPosition = POS_DRINK2;
				}
				else
				{
					popSales[i].popPositionCentral = { 70,450,75,75 };
					popSales[i].popPosition = POS_DRINK1;
				}
				break;
			}
			continue;
		}
	}
}

