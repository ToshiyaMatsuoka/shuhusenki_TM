#include "Main.h"
#include "GameMain.h"
#include "FloaMove.h"
#include "Timer.h"
#include "Goods.h"
#include "ChoseGoods.h"

#define ANIMETIONTIME 20
//���u�̓�������
enum MOBDIRECTION {
	NORTH,
	SOUTH,
	EAST,
	WEST
};
enum CONTACTDIRECTION
{
	SIDE,
	UPPER,
	UNDER
};

CENTRAL_STATE mobCentralFloa[4]
{
	{ 620,630 ,PLAYER_FLOA_SCALE,PLAYER_FLOA_SCALE },
	{ 600,300 ,PLAYER_FLOA_SCALE,PLAYER_FLOA_SCALE },
	{ 120,500 ,PLAYER_FLOA_SCALE,PLAYER_FLOA_SCALE },
	{ 1030,230 ,PLAYER_FLOA_SCALE,PLAYER_FLOA_SCALE }

};
CUSTOMVERTEX PC[4];

static bool mobMovedRight[4];
static bool isRight = false;

static int PCtu = 0;
static int PCtv = 0;
static int mobtu[4] = {0,0,0,0};
static int mobtv[4] = {0,0,0,0};
int effectCount = 0;
int effectIntervalPrev = 0;


void playerControl(int* onceSound);
void leachedGondolaCheck(int* leschgondola, SALESMAN popSales[], int whergondola);
bool MoveOutToErea(CENTRAL_STATE* central, float Left, float Top, float Right, float Bottom, int direction);
void salesmanPoping(SALESMAN popSales[]);
int salesmanToPCCollision(CENTRAL_STATE central, SALESMAN popSales[]);
void floaMoveControl();
void floaMoveRender();
void floaMoveRenderSta();
void collision(CENTRAL_STATE* charctor);
void mobControler(CENTRAL_STATE mobCentralFloa[]);
void mobToPCContact(CENTRAL_STATE* charctor, CENTRAL_STATE mobCentralFloa[]);


CENTRAL_STATE g_PCSta = { 900.f, 580.f, 32.f, 53.f };

CENTRAL_STATE g_startCountSta = { WIDTH / 2, HEIGHT / 2, 150.f, 150.f };
CENTRAL_STATE g_startSta = { WIDTH / 2, HEIGHT / 2, 200.f, 96.25f };

FLOAT g_PCSpeed = 2.f;

void floaMove() {

	floaMoveControl();
	floaMoveRender();
}

//�Q�[�����䏈��
void floaMoveControl()
{
	static int onceSound = 0;
	int effectIntervalCurrnt = g_timerCount;
	if (effectIntervalCurrnt - effectIntervalPrev > 3)
	{
		effectCount++;
		effectIntervalPrev = g_timerCount;
	}
	if (effectCount > 3)
	{
		effectCount = 0;
	}

	timerControl();
	if (g_timerCount < THREE_SECOND)
	{
		salesmanPoping(popSales);
	}
	if (g_isTimeUp)
	{
		for (onceSound; onceSound < 2; onceSound++)
		{
			soundsManager.Start("GONG", false);
			
		}
	}

	if (g_isGameStart)
	{
		playerControl(&onceSound);
		mobControler(mobCentralFloa);
		for (int i = 0; i < 4; i++)
		{
			collision(&mobCentralFloa[i]);
;		}
#ifdef _DEBUG
		CheckKeyState(DIK_SPACE);
		if (KeyState[DIK_SPACE] == KeyRelease)
		{
			g_gameScene = CHOSEGOODS;
			onceSound = 0;
		}
#endif
	}
	if (isRight)
	{
		CreateSquareVertexEx(PC, g_PCSta, PCtu*YASUKO_TU, PCtv*YASUKO_TV, -1 * YASUKO_TU, YASUKO_TV);
	}
	else CreateSquareVertexEx(PC, g_PCSta, PCtu*YASUKO_TU, PCtv*YASUKO_TV, YASUKO_TU, YASUKO_TV);

}
void playerControl(int* onceSound)
{
	GetControl(0);
	BottonCheck();

	static int animeCount = 0;
	animeCount++;

	if (InputKEY(DIK_RETURN) || InputKEY(DIK_NUMPADENTER) || (PadState[ButtonA] == PadRelease))
	{
		leachedGondolaCheck(&salesChoice, popSales, salesmanToPCCollision(g_PCSta, popSales));
	}
	if ( 0 < GetAnalogLValue(ANALOG_Y))
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

	if ( 0 > GetAnalogLValue(ANALOG_Y))
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

	if ( 0 < GetAnalogLValue(ANALOG_X) )
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

	if ( 0 > GetAnalogLValue(ANALOG_X))
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
	if (InputKEY(DIK_W) || (PadState[ButtonUP] == PadOn))
	{
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

	if (InputKEY(DIK_S) || (PadState[ButtonDOWN] == PadOn))
	{
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

	if (InputKEY(DIK_D) || (PadState[ButtonRIGHT] == PadOn))
		{
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

	if (InputKEY(DIK_A) || (PadState[ButtonLEFT] == PadOn))
		{
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
	mobToPCContact(&g_PCSta, mobCentralFloa);
	collision(&g_PCSta);
}

//�����蔻�菈��
void collision(CENTRAL_STATE* charctor)
{
	MoveInToErea(charctor, 0.f, 145.f, 1280.f, 690.f);
	//���i�I
	//�W���[�X1
	MoveOutToErea(charctor, -50, 195, 100, 545, SIDE);//���E
	MoveOutToErea(charctor, 0, 185, 100, 194, UPPER);//��
	MoveOutToErea(charctor, 0, 545, 100, 555, UNDER);//��

	//��
	MoveOutToErea(charctor, 125, -50, 640, 139, SIDE);//���E
	MoveOutToErea(charctor, 125, 140, 640, 145, UNDER);//��

	//��1
	MoveOutToErea(charctor, 640, -50, 1230, 139, SIDE);//���E
	MoveOutToErea(charctor, 640, 140, 1230, 145, UNDER);//��
	//���1
	MoveOutToErea(charctor, 1200, 170, 1380, 608, SIDE);//���E
	MoveOutToErea(charctor, 1200, 165, 1280, 169, UPPER);//��
	MoveOutToErea(charctor, 1200, 609, 1280, 615, UNDER);//��

	//�ʎ�2
	MoveOutToErea(charctor, 786, 425, 1016, 568, SIDE);//���E
	MoveOutToErea(charctor, 786, 420, 1016, 425, UPPER);//��
	MoveOutToErea(charctor, 786, 568, 1016, 575, UNDER);//��

	//���2
	MoveOutToErea(charctor, 1035, 218, 1152, 558, SIDE);//���E
	MoveOutToErea(charctor, 1035, 213, 1152, 217, UPPER);//��
	MoveOutToErea(charctor, 1035, 557, 1152, 565, UNDER);//��
	//��2
	MoveOutToErea(charctor, 640, 178, 1152, 246, SIDE);//���E
	MoveOutToErea(charctor, 640, 170, 1152, 177, UPPER);//��
	MoveOutToErea(charctor, 640, 245, 1152, 250, UNDER);//��
	//�W���[�X3
	MoveOutToErea(charctor, 682, 265, 1016, 399, SIDE);//���E
	MoveOutToErea(charctor, 682, 260, 1016, 264, UPPER);//��
	MoveOutToErea(charctor, 682, 400, 1016, 405, UNDER);//��
	//�ʎ�1
	MoveOutToErea(charctor, 442, 436, 770, 584, SIDE);//���E
	MoveOutToErea(charctor, 442, 429, 770, 435, UPPER);//��
	MoveOutToErea(charctor, 442, 585, 770, 590, UNDER);//��
	//�����1
	MoveOutToErea(charctor, 270, 176, 595, 284, SIDE);//���E
	MoveOutToErea(charctor, 270, 170, 595, 175, UPPER);//��
	MoveOutToErea(charctor, 270, 285, 595, 290, UNDER);//��
	//�����2-1
	MoveOutToErea(charctor, 135, 175, 250, 330, SIDE);//���E
	MoveOutToErea(charctor, 135, 170, 250, 174, UPPER);//��
	//�����2-2
	MoveOutToErea(charctor, 135, 328, 600, 389, SIDE);//���E
	MoveOutToErea(charctor, 135, 320, 600, 327, UPPER);//��
	MoveOutToErea(charctor, 135, 390, 600, 400, UNDER);//��
	//�����3
	MoveOutToErea(charctor, 135, 436, 420, 584, SIDE);//���E
	MoveOutToErea(charctor, 135, 430, 420, 435, UPPER);//��
	MoveOutToErea(charctor, 135, 585, 420, 590, UNDER);//��

}
void leachedGondolaCheck(int* leschgondola, SALESMAN popSales[], int whergondola)
{
	for (int i = 0; i < 3; i++)
	{
		if (popSales[i].popPosition == whergondola)
		{
			*leschgondola = i;
			g_gameScene = CHOSEGOODS;
		}
	}
}
bool MoveOutToErea(CENTRAL_STATE* central,float Left, float Top, float Right, float Bottom, int direction)
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
int salesmanToPCCollision(CENTRAL_STATE central, SALESMAN popSales[])
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
//�Q�[���`�揈��
void floaMoveRender()
{
	BeginSetTexture();

	//�Q�[����ʂ̃e�N�X�`���̐ݒ�
	floaMoveRenderSta();
#ifdef _DEBUG
	char debugPC[10];
	sprintf_s(debugPC, 10, "%.2f", g_PCSta.x);
	RECT DEBUGTextA = { 100 ,500,900,600 };
	WriteWord(debugPC, DEBUGTextA, DT_LEFT, 0xff000000, DEBUG_FONT);
	sprintf_s(debugPC, 10, "%.2f", g_PCSta.y);
	DEBUGTextA = { 100 ,550,900,600 };
	WriteWord(debugPC, DEBUGTextA, DT_LEFT, 0xff000000, DEBUG_FONT);

#endif

	EndSetTexture();
}

//�Q�[����ʂ̃e�N�X�`��
void floaMoveRenderSta()
{
	EasyCreateSquareVertex(0, 100, WIDTH, 680, FLOAMOVE_BG_TEX);

	CUSTOMVERTEX startCount[4];
	CUSTOMVERTEX start[4];
	CUSTOMVERTEX salesmans[4];
	CUSTOMVERTEX effectPC[4];
	CENTRAL_STATE effectCentral = { g_PCSta.x-2,g_PCSta.y-14,60,75 };

	CreateSquareVertexEx(effectPC, effectCentral, (effectCount * EFFECT_TU), 0, EFFECT_TU, EFFECT_TV);
	CreateSquareVertex(startCount, g_startCountSta);
	CreateSquareVertex(start, g_startSta);
	for (int i = 0; i < 4; i++)
	{
		if (i == 0 || i == 1)
		{
			if (mobMovedRight[i])
			{
				CreateSquareVertexEx(salesmans, mobCentralFloa[i], mobtu[i] * BOY_TU, mobtv[i] * BOY_TV, -BOY_TU, BOY_TV);
			}
			else CreateSquareVertexEx(salesmans, mobCentralFloa[i], mobtu[i] * BOY_TU, mobtv[i] * BOY_TV, BOY_TU, BOY_TV);
		}
		else {
			if (mobMovedRight[i])
			{
				CreateSquareVertexEx(salesmans, mobCentralFloa[i], MOB_TU, mobtv[i] * MOB_TV, -MOB_TU, MOB_TV);
			}
			else CreateSquareVertexEx(salesmans, mobCentralFloa[i], 0, mobtv[i] * MOB_TV, MOB_TU, MOB_TV);
		}
		if (i >= 2)
		{
			SetUpTexture(salesmans, mobTexNum);
		}
		else SetUpTexture(salesmans, BOY_TEX);
	}


	goodsScoreShow();
	if (g_isGameStart)
	{
		static int saleAnimeCount = 0;
		int saleAnimeTv;
		static bool saleAnimeChainger = false;
		saleAnimeCount++;
		if (saleAnimeCount > ANIMETIONTIME && !saleAnimeChainger)
		{
			saleAnimeCount = 0;
			saleAnimeChainger = true;
		}
		if(saleAnimeCount > ANIMETIONTIME && saleAnimeChainger)
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
			CreateSquareVertexEx(salesmans, popSales[i].popPositionCentral, 0, saleAnimeTv * SALE_TV, SALE_TU, SALE_TV);
			SetUpTexture(salesmans, SALESMAN_TEX);
		}
	}
	//�v���C���[�L�����N�^�[�̃e�N�X�`���̕`��
	SetUpTexture(effectPC, YASUKO_EFFECT_TEX);
	SetUpTexture(PC, YASUKO_TEX);

	timerRender();

	if ((g_timerCount > ZERO_SECOND) && (g_timerCount <= ONE_SECOND))
	{
		//�X�^�[�g�J�E���g�̃e�N�X�`���̕`��
		SetUpTexture(startCount, STARTCOUNT_3_TEX);
	}
	else if ((g_timerCount > ONE_SECOND) && (g_timerCount <= TWO_SECOND))
	{
		//�X�^�[�g�J�E���g�̃e�N�X�`���̕`��
		SetUpTexture(startCount, STARTCOUNT_2_TEX);
	}
	else if ((g_timerCount > TWO_SECOND) && (g_timerCount <= THREE_SECOND))
	{
		//�X�^�[�g�J�E���g�̃e�N�X�`���̕`��
		SetUpTexture(startCount, STARTCOUNT_1_TEX);
	}
	else if ((g_timerCount > THREE_SECOND) && (g_timerCount <= FOUR_SECOND))
	{
		//�X�^�[�g�J�E���g�̃e�N�X�`���̕`��
		SetUpTexture(start, START_TEX);
	}

	if (g_pause && !(g_isTimeUp))
	{
		EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, PAUSE_TEX);
	}
}
void salesmanPoping(SALESMAN popSales[])
{
	for (int i = 0; i < 3; i++)
	{
		switch (popSales[i].goodsSorting)
		{
		case MEET_SORT:
			popSales[i].popPositionCentral = { 285,120,75,75 };
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
				popSales[i].popPositionCentral = { 800,120,75,75 };
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
void mobControler(CENTRAL_STATE mobCentralFloa[])
{
	static int collisionCount[4] = { 0,0,0,0};
	static int mobAnimeCount[4] = { 0,0,0,0 };
	if (!BtoBContact(&mobCentralFloa[0], &g_PCSta))
	{
		if (mobCentralFloa[0].x <= 120)
		{
			mobCentralFloa[0].y -= 3;
			mobMovedRight[0] = false;
			mobtv[0] = 1;

		}
		if (mobCentralFloa[0].x >= 1190)
		{
			mobCentralFloa[0].y += 3;
			mobMovedRight[0] = false;
			mobtv[0] = 0;
		}
		if (mobCentralFloa[0].y >= 630)
		{
			mobCentralFloa[0].x -= 4;
			mobMovedRight[0] = false;
			mobtv[0] = 2;

		}
		if (mobCentralFloa[0].y <= 165)
		{
			mobCentralFloa[0].x += 4;
			mobMovedRight[0] = true;
			mobtv[0] = 2;

		}

	}
	else
	{
		collisionCount[0]++;
		if (collisionCount[0] > 30)
		{
			if (mobCentralFloa[0].x <= 120)
			{
				mobCentralFloa[0].y += 10;
				mobMovedRight[0] = false;
				mobtv[0] = 0;

			}
			if (mobCentralFloa[0].x >= 1190)
			{
				mobCentralFloa[0].y -= 10;
				mobMovedRight[0] = false;
				mobtv[0] = 1;
			}
			if (mobCentralFloa[0].y >= 630)
			{
				mobCentralFloa[0].x += 6;
				mobMovedRight[0] = true;
				mobtv[0] = 2;


			}
			if (mobCentralFloa[0].y <= 165)
			{
				mobCentralFloa[0].x -= 6;
				mobMovedRight[0] = false;
				mobtv[0] = 2;

			}
			collisionCount[0] = 0;
		}
	}
	mobAnimeCount[0]++;
	if (mobAnimeCount[0] >= ANIMETIONTIME)
	{
		mobtu[0]++;
		mobAnimeCount[0] = 0;
	}
	if (mobtu[0] > 1 && !mobMovedRight[0])
	{
		mobtu[0] = 0;
	}
	if (mobtu[0] > 2 && mobMovedRight[0])
	{
		mobtu[0] = 1;
	}


	if (!BtoBContact(&mobCentralFloa[1], &g_PCSta))
	{
		switch (rand() % 4)
		{
		case NORTH:
			mobCentralFloa[1].y -= 3;
			mobMovedRight[1] = false;
			mobtv[1] = 1;
			break;
		case SOUTH:
			mobCentralFloa[1].y += 3;
			mobMovedRight[1] = false;
			mobtv[1] = 0;
			break;
		case EAST:
			mobCentralFloa[1].x -= 3;
			mobMovedRight[1] = false;
			mobtv[1] = 2;
			break;
		case WEST:
			mobCentralFloa[1].x += 3;
			mobMovedRight[1] = true;
			mobtv[1] = 2;
			break;
		}
	}
	else
	{
		collisionCount[1]++;
		if (collisionCount[1] > 30)
		{
			mobCentralFloa[1].y += 5;
			mobCentralFloa[1].x += 5;

			collisionCount[1] = 0;
		}
	}
	mobAnimeCount[1]++;
	if (mobAnimeCount[1] >= ANIMETIONTIME)
	{
		mobtu[1]++;
		mobAnimeCount[1] = 0;
	}
	if (mobtu[1] > 1 && !mobMovedRight[1])
	{
		mobtu[1] = 0;
	}
	if (mobtu[1] > 2 && mobMovedRight[1])
	{
		mobtu[1] = 1;
	}

	if (!BtoBContact(&mobCentralFloa[2], &g_PCSta))
	{
		switch (rand() % 5)
		{
		case NORTH:
			mobCentralFloa[2].y -= 1.5f;
			mobMovedRight[2] = false;
			mobtv[2] = 1;
			break;
		case SOUTH:
			mobCentralFloa[2].y += 1.5f;
			mobMovedRight[2] = false;
			mobtv[2] = 0;
			break;
		case EAST:
			mobCentralFloa[2].x -= 2;
			mobMovedRight[2] = false;
			mobtv[2] = 2;
			break;
		case WEST:
			mobCentralFloa[2].x += 2;
			mobMovedRight[2] = true;
			mobtv[2] = 2;
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
			mobCentralFloa[2].y += 5;
			mobCentralFloa[2].x += 5;
			collisionCount[2] = 0;
		}
	}
	if (!BtoBContact(&mobCentralFloa[3], &g_PCSta))
	{
		switch (rand() % 5)
		{
		case NORTH:
			mobCentralFloa[3].y -= 1.5f;
			mobMovedRight[3] = false;
			mobtv[3] = 1;
			break;
		case SOUTH:
			mobCentralFloa[3].y += 1.5f;
			mobMovedRight[3] = false;
			mobtv[3] = 0;
			break;
		case EAST:
			mobCentralFloa[3].x -= 2;
			mobMovedRight[3] = false;
			mobtv[3] = 2;
			break;
		case WEST:
			mobCentralFloa[3].x += 2;
			mobMovedRight[3] = true;
			mobtv[3] = 2;
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
			mobCentralFloa[3].y += 5;
			mobCentralFloa[3].x += 5;
			collisionCount[3] = 0;
		}
	}

	collision(&mobCentralFloa[1]);
	collision(&mobCentralFloa[2]);
	collision(&mobCentralFloa[3]);

}

void mobToPCContact(CENTRAL_STATE* charctor, CENTRAL_STATE mobCentralFloa[])
{
	for (int i = 0; i < 4; i++)
	{
		if ((charctor->x <= mobCentralFloa[i].x + mobCentralFloa[i].scaleX) && (mobCentralFloa[i].x <= charctor->x + charctor->scaleX)
			&& (charctor->y <= mobCentralFloa[i].y + mobCentralFloa[i].scaleY) && (mobCentralFloa[i].y <= charctor->y + charctor->scaleY)) {

			if ((charctor->x <= mobCentralFloa[i].x + mobCentralFloa[i].scaleX))
			{
				charctor->x = mobCentralFloa[i].x + mobCentralFloa[i].scaleX;
			}
			if ((charctor->x >= mobCentralFloa[i].x - mobCentralFloa[i].scaleX))
			{
				charctor->x = mobCentralFloa[i].x - mobCentralFloa[i].scaleX;
			}
			if ((charctor->y <= mobCentralFloa[i].y + mobCentralFloa[i].scaleY))
			{
				charctor->y = mobCentralFloa[i].y + mobCentralFloa[i].scaleY;
			}
			if ((charctor->y >= mobCentralFloa[i].y - mobCentralFloa[i].scaleY))
			{
				charctor->y = mobCentralFloa[i].y - mobCentralFloa[i].scaleY;
			}
		}
	}
}
