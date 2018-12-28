#include "Yasuko.h"



Yasuko::Yasuko()
{
}


Yasuko::~Yasuko()
{
}

void Yasuko::FloaMoveControl(int* onceSound)
{

	static int animeCount = 0;
	animeCount++;

	if (InputKEY(DIK_RETURN) || InputKEY(DIK_NUMPADENTER) || (PadState[ButtonA] == PadRelease))
	{
		leachedGondolaCheck(&salesChoice, popSales, salesmanToPCCollision(g_PCSta, popSales));
	}
	if (0 < GetAnalogLValue(ANALOG_Y))
	{
		isRight = false;
		if (!g_pause && !g_isTimeUp)
		{
			if (GetAnalogLValue(ANALOG_Y) >= 6000 && GetAnalogLValue(ANALOG_Y) <= 10000)
			{
				g_PCSta.y -= g_PCSpeed / 4;
			}
			else if (GetAnalogLValue(ANALOG_Y) >= 10000 && GetAnalogLValue(ANALOG_Y) <= 18000)
			{
				g_PCSta.y -= g_PCSpeed / 2;
			}
			else if (GetAnalogLValue(ANALOG_Y) >= 18000)
			{
				g_PCSta.y -= g_PCSpeed;
			}
			if (animeCount >= ANIMETIONTIME)
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
	}

	if (0 > GetAnalogLValue(ANALOG_Y))
	{
		isRight = false;
		if (!g_pause && !g_isTimeUp)
		{
			if (GetAnalogLValue(ANALOG_Y) <= -6000 && GetAnalogLValue(ANALOG_Y) >= -10000)
			{
				g_PCSta.y += g_PCSpeed / 4;
			}
			else if (GetAnalogLValue(ANALOG_Y) <= -10000 && GetAnalogLValue(ANALOG_Y) >= -18000)
			{
				g_PCSta.y += g_PCSpeed / 2;
			}
			else if (GetAnalogLValue(ANALOG_Y) <= -18000)
			{
				g_PCSta.y += g_PCSpeed;
			}
			if (animeCount >= ANIMETIONTIME)
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
	}

	if (0 < GetAnalogLValue(ANALOG_X))
	{
		isRight = true;
		if (!g_pause && !g_isTimeUp)
		{
			if (GetAnalogLValue(ANALOG_X) >= 6000 && GetAnalogLValue(ANALOG_X) <= 10000)
			{
				g_PCSta.x += g_PCSpeed / 4;
			}
			else if (GetAnalogLValue(ANALOG_X) >= 10000 && GetAnalogLValue(ANALOG_X) <= 18000)
			{
				g_PCSta.x += g_PCSpeed / 2;
			}
			else if (GetAnalogLValue(ANALOG_X) >= 18000)
			{
				g_PCSta.x += g_PCSpeed;
			}
			if (animeCount >= ANIMETIONTIME)
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
	}

	if (0 > GetAnalogLValue(ANALOG_X))
	{
		isRight = false;
		if (!g_pause && !g_isTimeUp)
		{
			if (GetAnalogLValue(ANALOG_X) <= -6000 && GetAnalogLValue(ANALOG_X) >= -10000)
			{
				g_PCSta.x -= g_PCSpeed / 4;
			}
			else if (GetAnalogLValue(ANALOG_X) <= -10000 && GetAnalogLValue(ANALOG_X) >= -18000)
			{
				g_PCSta.x -= g_PCSpeed / 2;
			}
			else if (GetAnalogLValue(ANALOG_X) <= -18000)
			{
				g_PCSta.x -= g_PCSpeed;
			}
			if (animeCount >= ANIMETIONTIME)
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
	}
	/////////////////////////////////////////
	mobToPCContact(&g_PCSta, mobCentralFloa);
	collision(&g_PCSta);
}


void Yasuko::FloaMoveLeft(int* onceSound) {
	isRight = false;
	if (!g_pause && !g_isTimeUp)
	{
		g_PCSta.x -= g_PCSpeed;

		if (animeCount >= ANIMETIONTIME)
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

}
void Yasuko::FloaMoveRight(int* onceSound) {
	isRight = true;
	if (!g_pause && !g_isTimeUp)
	{
		g_PCSta.x += g_PCSpeed;

		if (PCtu == 0)
		{
			PCtu = 1;
		}
		if (animeCount >= ANIMETIONTIME)
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

}
void Yasuko::FloaMoveUp(int* onceSound) {
	isRight = false;
	if (!g_pause && !g_isTimeUp)
	{
		g_PCSta.y -= g_PCSpeed;
		if (animeCount >= ANIMETIONTIME)
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
}
void Yasuko::FloaMoveDown(int* onceSound) {
	isRight = false;
	if (!g_pause && !g_isTimeUp)
	{
		g_PCSta.y += g_PCSpeed;
		if (animeCount >= ANIMETIONTIME)
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

}
