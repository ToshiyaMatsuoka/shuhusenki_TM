#include "Yasuko.h"
#include "FloaMove.h"

enum CONTACTDIRECTION
{
	SIDE,
	UPPER,
	UNDER
};

bool Yasuko::MoveOutToErea(CENTRAL_STATE* central,float Left, float Top, float Right, float Bottom, int direction)
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
int Yasuko::salesmanToPCCollision(CENTRAL_STATE central, SALESMAN* popSales)
{
	for (int i = 0; i < 3; i++)
	{
		if (BtoBContact(&central, &popSales[i].popPositionCentral))
		{
			return popSales[i].popPosition;
		}
	}
	return POS_NOTING;
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
void Yasuko::leachedGondolaCheck(int* leschgondola, SALESMAN* popSales, int whergondola)
{
	for (int i = 0; i < 3; i++)
	{
		if (popSales[i].popPosition == whergondola)
		{
			*leschgondola = i;
			//g_gameScene = CHOSEGOODS;
		}
	}
}


Yasuko::Yasuko(DirectX* pDirectX, SoundOperater* pSoundOperater):Object(pDirectX,pSoundOperater)
{
}


Yasuko::~Yasuko()
{
}

void Yasuko::FloaMoveControl(KeyInput vec)
{

	animeCount++;

	if (vec == ACTION)
	{
		leachedGondolaCheck(&salesChoice, popSales, salesmanToPCCollision(g_PCSta, popSales));
	}
	if (vec == ACTION)
	{
		isRight = false;
			//if (GetAnalogLValue(ANALOG_Y) >= 6000 && GetAnalogLValue(ANALOG_Y) <= 10000)
			//{
			//	g_PCSta.y -= g_PCSpeed / 4;
			//}
			//else if (GetAnalogLValue(ANALOG_Y) >= 10000 && GetAnalogLValue(ANALOG_Y) <= 18000)
			//{
			//	g_PCSta.y -= g_PCSpeed / 2;
			//}
			//else if (GetAnalogLValue(ANALOG_Y) >= 18000)
			//{
			//	g_PCSta.y -= g_PCSpeed;
			//}
			if (animeCount >= ANIMETION_TIME)
			{
				PCtu++;
				animeCount = 0;
			}
			if (PCtu >= 3)
			{
				PCtu = 1;
			}
			PCtv = 1;
	}

	if (vec == ACTION)
	{
		isRight = false;
			//if (GetAnalogLValue(ANALOG_Y) <= -6000 && GetAnalogLValue(ANALOG_Y) >= -10000)
			//{
			//	g_PCSta.y += g_PCSpeed / 4;
			//}
			//else if (GetAnalogLValue(ANALOG_Y) <= -10000 && GetAnalogLValue(ANALOG_Y) >= -18000)
			//{
			//	g_PCSta.y += g_PCSpeed / 2;
			//}
			//else if (GetAnalogLValue(ANALOG_Y) <= -18000)
			//{
			//	g_PCSta.y += g_PCSpeed;
			//}
			if (animeCount >= ANIMETION_TIME)
			{
				PCtu++;
				animeCount = 0;
			}
			if (PCtu >= 3)
			{
				PCtu = 1;
			}
			PCtv = 0;
	}

	if (vec == ACTION)
	{
		isRight = true;
			//if (GetAnalogLValue(ANALOG_X) >= 6000 && GetAnalogLValue(ANALOG_X) <= 10000)
			//{
			//	g_PCSta.x += g_PCSpeed / 4;
			//}
			//else if (GetAnalogLValue(ANALOG_X) >= 10000 && GetAnalogLValue(ANALOG_X) <= 18000)
			//{
			//	g_PCSta.x += g_PCSpeed / 2;
			//}
			//else if (GetAnalogLValue(ANALOG_X) >= 18000)
			//{
			//	g_PCSta.x += g_PCSpeed;
			//}
			if (animeCount >= ANIMETION_TIME)
			{
				PCtu++;
				animeCount = 0;
			}
			if (PCtu > 4)
			{
				PCtu = 1;
			}
			PCtv = 2;
	}

	if (vec == ACTION)
	{
		isRight = false;
			//if (GetAnalogLValue(ANALOG_X) <= -6000 && GetAnalogLValue(ANALOG_X) >= -10000)
			//{
			//	g_PCSta.x -= g_PCSpeed / 4;
			//}
			//else if (GetAnalogLValue(ANALOG_X) <= -10000 && GetAnalogLValue(ANALOG_X) >= -18000)
			//{
			//	g_PCSta.x -= g_PCSpeed / 2;
			//}
			//else if (GetAnalogLValue(ANALOG_X) <= -18000)
			//{
			//	g_PCSta.x -= g_PCSpeed;
			//}
			if (animeCount >= ANIMETION_TIME)
			{
				PCtu++;
				animeCount = 0;
			}
			if (PCtu > 3)
			{
				PCtu = 0;
			}
			PCtv = 2;
	}
	/////////////////////////////////////////
	//mobToPCContact(&g_PCSta, mobCentralFloa);
	collision(&g_PCSta);
}


void Yasuko::FloaMoveLeft(int* onceSound) {
	isRight = false;
		g_PCSta.x -= g_PCSpeed;

		if (animeCount >= ANIMETION_TIME)
		{
			PCtu++;
			animeCount = 0;
		}
		if (PCtu > 3)
		{
			PCtu = 0;
		}
		PCtv = 2;
}
void Yasuko::FloaMoveRight(int* onceSound) {
	isRight = true;
		g_PCSta.x += g_PCSpeed;

		if (PCtu == 0)
		{
			PCtu = 1;
		}
		if (animeCount >= ANIMETION_TIME)
		{
			PCtu++;
			animeCount = 0;
		}
		if (PCtu > 4)
		{
			PCtu = 1;
		}
		PCtv = 2;
}
void Yasuko::FloaMoveUp(int* onceSound) {
	isRight = false;
		g_PCSta.y -= g_PCSpeed;
		if (animeCount >= ANIMETION_TIME)
		{
			PCtu++;
			animeCount = 0;
		}
		if (PCtu >= 3)
		{
			PCtu = 1;
		}
		PCtv = 1;
}
void Yasuko::FloaMoveDown(int* onceSound) {
	isRight = false;
		g_PCSta.y += g_PCSpeed;
		if (animeCount >= ANIMETION_TIME)
		{
			PCtu++;
			animeCount = 0;
		}
		if (PCtu >= 3)
		{
			PCtu = 1;
		}
		PCtv = 0;
}
