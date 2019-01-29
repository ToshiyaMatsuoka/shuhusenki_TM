
#include "FloaMove.h"
//#define ANIMETIONTIME 20
////モブの動く方向
//enum MOBDIRECTION {
//	NORTH,
//	SOUTH,
//	EAST,
//	WEST
//};
//enum CONTACTDIRECTION
//{
//	SIDE,
//	UPPER,
//	UNDER
//};
//
//CENTRAL_STATE mobCentralFloa[4]
//{
//	{ 620,630 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
//	{ 600,300 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
//	{ 120,500 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
//	{ 1030,230 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE }
//
//};
//CUSTOMVERTEX Vertex[4];
//
//static bool m_isRight[4];
//static bool m_isRight = false;
//
//static int m_TurningAnimetion = 0;
//static int m_ChangeAnimetion = 0;
//static int m_Tu[4] = {0,0,0,0};
//static int m_Tv[4] = {0,0,0,0};
//int effectCount = 0;
//int effectIntervalPrev = 0;
//int blowOffEffectIntervalPrev = 0;
//
//void playerControl(int* onceSound);
//void leachedGondolaCheck(int* leschgondola, SALESMAN popSales[], int whergondola);
//bool MoveOutToErea(CENTRAL_STATE* central, float Left, float Top, float Right, float Bottom, int direction);
//void salesmanPoping(SALESMAN popSales[]);
//int salesmanToPCCollision(CENTRAL_STATE central, SALESMAN popSales[]);
//void floaMoveControl();
//void floaMoveRender();
//void floaMoveRenderSta();
//void collision(CENTRAL_STATE* charctor);
//void mobControler(CENTRAL_STATE mobCentralFloa[]);
//void mobToPCContact(CENTRAL_STATE* charctor, CENTRAL_STATE mobCentralFloa[]);
//
//
//CENTRAL_STATE m_Center = { 900.f, 580.f, 32.f, 53.f };
//
//CENTRAL_STATE g_startCountSta = { WIDTH / 2, HEIGHT / 2, 150.f, 150.f };
//CENTRAL_STATE g_startSta = { WIDTH / 2, HEIGHT / 2, 200.f, 96.25f };
//
//FLOAT MOVE_SPEED = 2.f;
//
//void floaMove() {
//
//	floaMoveControl();
//	floaMoveRender();
//}

////ゲーム制御処理
//void floaMoveControl()
//{
//	static int onceSound = 0;
//
//	timerControl();
//	if (g_timerCount < THREE_SECOND)
//	{
//		salesmanPoping(popSales);
//	}
//	if (g_isTimeUp)
//	{
//		for (onceSound; onceSound < 2; onceSound++)
//		{
//			soundsManager.Start("GONG", false);
//			
//		}
//	}
//
//	if (g_isGameStart)
//	{
//		playerControl(&onceSound);
//		mobControler(mobCentralFloa);
//		for (int i = 0; i < 4; i++)
//		{
//			collision(&mobCentralFloa[i]);
//;		}
//#ifdef _DEBUG
//		CheckKeyState(DIK_SPACE);
//		if (KeyState[DIK_SPACE] == KeyRelease)
//		{
//			g_gameScene = CHOSEGOODS;
//			onceSound = 0;
//		}
//#endif
//	}
//	if (m_isRight)
//	{
//		CreateSquareVertex(Vertex, m_Center, WHITE, m_TurningAnimetion*YASUKO_TU, m_ChangeAnimetion*YASUKO_TV, -1 * YASUKO_TU, YASUKO_TV);
//	}
//	else CreateSquareVertex(Vertex, m_Center, WHITE, m_TurningAnimetion*YASUKO_TU, m_ChangeAnimetion*YASUKO_TV, YASUKO_TU, YASUKO_TV);
//
//}
//void playerControl(int* onceSound)
//{
//	GetControl(0);
//	BottonCheck();
//
//	static int m_AnimeCount = 0;
//	m_AnimeCount++;
//
//	if (InputKEY(DIK_RETURN) || InputKEY(DIK_NUMPADENTER) || (PadState[ButtonA] == PadRelease))
//	{
//		leachedGondolaCheck(&salesChoice, popSales, salesmanToPCCollision(m_Center, popSales));
//	}
//	if ( 0 < GetAnalogLValue(ANALOG_Y))
//		{
//			m_isRight = false;
//			if (!g_pause && !g_isTimeUp)
//			{
//				if (GetAnalogLValue(ANALOG_Y) >= 6000 && GetAnalogLValue(ANALOG_Y) <= 10000)
//				{
//					m_Center.y -= MOVE_SPEED / 4;
//				}
//				else if (GetAnalogLValue(ANALOG_Y) >= 10000 && GetAnalogLValue(ANALOG_Y) <= 18000)
//				{
//					m_Center.y -= MOVE_SPEED / 2;
//				}
//				else if (GetAnalogLValue(ANALOG_Y) >= 18000)
//				{
//					m_Center.y -= MOVE_SPEED;
//				}
//				if (m_AnimeCount >= ANIMETIONTIME)
//				{
//					m_TurningAnimetion++;
//					m_AnimeCount = 0;
//				}
//				if (m_TurningAnimetion >= 3)
//				{
//					m_TurningAnimetion = 1;
//				}
//				m_ChangeAnimetion = 1;
//
//
//			}
//		}
//
//	if ( 0 > GetAnalogLValue(ANALOG_Y))
//		{
//			m_isRight = false;
//			if (!g_pause && !g_isTimeUp)
//			{
//				if (GetAnalogLValue(ANALOG_Y) <= -6000 && GetAnalogLValue(ANALOG_Y) >= -10000)
//				{
//					m_Center.y += MOVE_SPEED / 4;
//				}
//				else if (GetAnalogLValue(ANALOG_Y) <= -10000 && GetAnalogLValue(ANALOG_Y) >= -18000)
//				{
//					m_Center.y += MOVE_SPEED / 2;
//				}
//				else if (GetAnalogLValue(ANALOG_Y) <= -18000)
//				{
//					m_Center.y += MOVE_SPEED;
//				}
//				if (m_AnimeCount >= ANIMETIONTIME)
//				{
//					m_TurningAnimetion++;
//					m_AnimeCount = 0;
//				}
//				if (m_TurningAnimetion >= 3)
//				{
//					m_TurningAnimetion = 1;
//				}
//				m_ChangeAnimetion = 0;
//
//			}
//		}
//
//	if ( 0 < GetAnalogLValue(ANALOG_X) )
//		{
//			m_isRight = true;
//			if (!g_pause && !g_isTimeUp)
//			{
//				if (GetAnalogLValue(ANALOG_X) >= 6000 && GetAnalogLValue(ANALOG_X) <= 10000)
//				{
//					m_Center.x += MOVE_SPEED / 4;
//				}
//				else if (GetAnalogLValue(ANALOG_X) >= 10000 && GetAnalogLValue(ANALOG_X) <= 18000)
//				{
//					m_Center.x += MOVE_SPEED / 2;
//				}
//				else if (GetAnalogLValue(ANALOG_X) >= 18000)
//				{
//					m_Center.x += MOVE_SPEED;
//				}
//				if (m_AnimeCount >= ANIMETIONTIME)
//				{
//					m_TurningAnimetion++;
//					m_AnimeCount = 0;
//				}
//				if (m_TurningAnimetion > 4)
//				{
//					m_TurningAnimetion = 1;
//				}
//				m_ChangeAnimetion = 2;
//			}
//		}
//
//	if ( 0 > GetAnalogLValue(ANALOG_X))
//		{
//			m_isRight = false;
//			if (!g_pause && !g_isTimeUp)
//			{
//				if (GetAnalogLValue(ANALOG_X) <= -6000 && GetAnalogLValue(ANALOG_X) >= -10000)
//				{
//					m_Center.x -= MOVE_SPEED / 4;
//				}
//				else if (GetAnalogLValue(ANALOG_X) <= -10000 && GetAnalogLValue(ANALOG_X) >= -18000)
//				{
//					m_Center.x -= MOVE_SPEED / 2;
//				}
//				else if (GetAnalogLValue(ANALOG_X) <= -18000)
//				{
//					m_Center.x -= MOVE_SPEED;
//				}
//				if (m_AnimeCount >= ANIMETIONTIME)
//				{
//					m_TurningAnimetion++;
//					m_AnimeCount = 0;
//				}
//				if (m_TurningAnimetion > 3)
//				{
//					m_TurningAnimetion = 0;
//				}
//				m_ChangeAnimetion = 2;
//			}
//		}
//		/////////////////////////////////////////
//	if (InputKEY(DIK_W) || (PadState[ButtonUP] == PadOn))
//	{
//		m_isRight = false;
//		if (!g_pause && !g_isTimeUp)
//		{
//			m_Center.y -= MOVE_SPEED;
//			if (m_AnimeCount >= ANIMETIONTIME)
//			{
//				m_TurningAnimetion++;
//				m_AnimeCount = 0;
//			}
//			if (m_TurningAnimetion >= 3)
//			{
//				m_TurningAnimetion = 1;
//			}
//			m_ChangeAnimetion = 1;
//
//
//		}
//	}
//
//	if (InputKEY(DIK_S) || (PadState[ButtonDOWN] == PadOn))
//	{
//		m_isRight = false;
//		if (!g_pause && !g_isTimeUp)
//		{
//			m_Center.y += MOVE_SPEED;
//			if (m_AnimeCount >= ANIMETIONTIME)
//			{
//				m_TurningAnimetion++;
//				m_AnimeCount = 0;
//			}
//			if (m_TurningAnimetion >= 3)
//			{
//				m_TurningAnimetion = 1;
//			}
//			m_ChangeAnimetion = 0;
//
//		}
//	}
//
//	if (InputKEY(DIK_D) || (PadState[ButtonRIGHT] == PadOn))
//		{
//			m_isRight = true;
//			if (!g_pause && !g_isTimeUp)
//			{
//				m_Center.x += MOVE_SPEED;
//
//				if (m_TurningAnimetion == 0)
//				{
//					m_TurningAnimetion = 1;
//				}
//				if (m_AnimeCount >= ANIMETIONTIME)
//				{
//					m_TurningAnimetion++;
//					m_AnimeCount = 0;
//				}
//				if (m_TurningAnimetion > 4)
//				{
//					m_TurningAnimetion = 1;
//				}
//				m_ChangeAnimetion = 2;
//			}
//		}
//
//	if (InputKEY(DIK_A) || (PadState[ButtonLEFT] == PadOn))
//		{
//			m_isRight = false;
//			if (!g_pause && !g_isTimeUp)
//			{
//				m_Center.x -= MOVE_SPEED;
//
//				if (m_AnimeCount >= ANIMETIONTIME)
//				{
//					m_TurningAnimetion++;
//					m_AnimeCount = 0;
//				}
//				if (m_TurningAnimetion > 3)
//				{
//					m_TurningAnimetion = 0;
//				}
//				m_ChangeAnimetion = 2;
//			}
//		}
//	mobToPCContact(&m_Center, mobCentralFloa);
//	collision(&m_Center);
//}

////当たり判定処理
//void collision(CENTRAL_STATE* charctor)
//{
//	MoveInToErea(charctor, 0.f, 145.f, 1280.f, 690.f);
//	//商品棚
//	//ジュース1
//	MoveOutToErea(charctor, -50, 195, 100, 545, SIDE);//左右
//	MoveOutToErea(charctor, 0, 185, 100, 194, UPPER);//上
//	MoveOutToErea(charctor, 0, 545, 100, 555, UNDER);//下
//
//	//肉
//	MoveOutToErea(charctor, 125, -50, 640, 139, SIDE);//左右
//	MoveOutToErea(charctor, 125, 140, 640, 145, UNDER);//下
//
//	//魚1
//	MoveOutToErea(charctor, 640, -50, 1230, 139, SIDE);//左右
//	MoveOutToErea(charctor, 640, 140, 1230, 145, UNDER);//下
//	//野菜1
//	MoveOutToErea(charctor, 1200, 170, 1380, 608, SIDE);//左右
//	MoveOutToErea(charctor, 1200, 165, 1280, 169, UPPER);//上
//	MoveOutToErea(charctor, 1200, 609, 1280, 615, UNDER);//下
//
//	//果実2
//	MoveOutToErea(charctor, 786, 425, 1016, 568, SIDE);//左右
//	MoveOutToErea(charctor, 786, 420, 1016, 425, UPPER);//上
//	MoveOutToErea(charctor, 786, 568, 1016, 575, UNDER);//下
//
//	//野菜2
//	MoveOutToErea(charctor, 1035, 218, 1152, 558, SIDE);//左右
//	MoveOutToErea(charctor, 1035, 213, 1152, 217, UPPER);//上
//	MoveOutToErea(charctor, 1035, 557, 1152, 565, UNDER);//下
//	//魚2
//	MoveOutToErea(charctor, 640, 178, 1152, 246, SIDE);//左右
//	MoveOutToErea(charctor, 640, 170, 1152, 177, UPPER);//上
//	MoveOutToErea(charctor, 640, 245, 1152, 250, UNDER);//下
//	//ジュース3
//	MoveOutToErea(charctor, 682, 265, 1016, 399, SIDE);//左右
//	MoveOutToErea(charctor, 682, 260, 1016, 264, UPPER);//上
//	MoveOutToErea(charctor, 682, 400, 1016, 405, UNDER);//下
//	//果実1
//	MoveOutToErea(charctor, 442, 436, 770, 584, SIDE);//左右
//	MoveOutToErea(charctor, 442, 429, 770, 435, UPPER);//上
//	MoveOutToErea(charctor, 442, 585, 770, 590, UNDER);//下
//	//おやつ1
//	MoveOutToErea(charctor, 270, 176, 595, 284, SIDE);//左右
//	MoveOutToErea(charctor, 270, 170, 595, 175, UPPER);//上
//	MoveOutToErea(charctor, 270, 285, 595, 290, UNDER);//下
//	//おやつ2-1
//	MoveOutToErea(charctor, 135, 175, 250, 330, SIDE);//左右
//	MoveOutToErea(charctor, 135, 170, 250, 174, UPPER);//上
//	//おやつ2-2
//	MoveOutToErea(charctor, 135, 328, 600, 389, SIDE);//左右
//	MoveOutToErea(charctor, 135, 320, 600, 327, UPPER);//上
//	MoveOutToErea(charctor, 135, 390, 600, 400, UNDER);//下
//	//おやつ3
//	MoveOutToErea(charctor, 135, 436, 420, 584, SIDE);//左右
//	MoveOutToErea(charctor, 135, 430, 420, 435, UPPER);//上
//	MoveOutToErea(charctor, 135, 585, 420, 590, UNDER);//下
//
//}
//void leachedGondolaCheck(int* leschgondola, SALESMAN popSales[], int whergondola)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		if (popSales[i].popPosition == whergondola)
//		{
//			*leschgondola = i;
//			g_gameScene = CHOSEGOODS;
//		}
//	}
//}
//bool MoveOutToErea(CENTRAL_STATE* central,float Left, float Top, float Right, float Bottom, int direction)
//{
//	static float posBuff = 0;
//	posBuff = central->y;
//	if ((Left <= central->x) && (central->x <= Right)
//		&& (Top <= central->y) && (central->y <= Bottom))
//	{
//		switch (direction)
//		{
//		case 0:
//			if ((Left + (Right - Left) / 2) >= central->x) {
//				central->x = Left - 1;
//				return true;
//			}
//			if (central->x >= (Right - (Right - Left) / 2)) {
//				central->x = Right + 1;
//				return true;
//			}
//			break;
//		case 1:
//			if ((Top + (Bottom - Top) / 2) >= central->y) {
//				central->y = Top - 1;
//				return true;
//			}
//			break;
//		case 2:
//			if (central->y >= (Bottom - (Bottom - Top) / 2)) {
//				central->y = Bottom + 1;
//				return true;
//			}
//			break;
//		default:
//			return false;
//		}
//	}
//}
//int salesmanToPCCollision(CENTRAL_STATE central, SALESMAN popSales[])
//{
//	for (int i = 0; i < 3; i++)
//	{
//		if (BtoBContact(&central, &popSales[i].popPositionCentral))
//		{
//			return popSales[i].popPosition;
//		}
//	}
//	return POS_NOTING;
//}

////ゲーム描画処理
//void floaMoveRender()
//{
//	BeginSetTexture();
//
//	//ゲーム画面のテクスチャの設定
//	floaMoveRenderSta();
//#ifdef _DEBUG
//	char debugPC[10];
//	sprintf_s(debugPC, 10, "%.2f", m_Center.x);
//	RECT DEBUGTextA = { 100 ,500,900,600 };
//	WriteWord(debugPC, DEBUGTextA, "DEBUG_FONT", DT_LEFT, 0xff000000);
//	sprintf_s(debugPC, 10, "%.2f", m_Center.y);
//	DEBUGTextA = { 100 ,550,900,600 };
//	WriteWord(debugPC, DEBUGTextA, "DEBUG_FONT", DT_LEFT, 0xff000000);
//
//#endif
//
//	EndSetTexture();
//}

////ゲーム画面のテクスチャ
//void floaMoveRenderSta()
//{
//	EasyCreateSquareVertex(0, 100, WIDTH, 680, "FLOAMOVE_BG_TEX");
//
//	CUSTOMVERTEX startCount[4];
//	CUSTOMVERTEX start[4];
//	CUSTOMVERTEX salesmans[4];
//	CUSTOMVERTEX effectPC[4];
//	CENTRAL_STATE effectCentral = { m_Center.x-2,m_Center.y-14,60,75 };
//
//	CreateSquareVertex(effectPC, effectCentral, WHITE, (effectCount * EFFECT_TU), 0, EFFECT_TU, EFFECT_TV);
//	CreateSquareVertex(startCount, g_startCountSta);
//	CreateSquareVertex(start, g_startSta);
//	for (int i = 0; i < 4; i++)
//	{
//		if (i == 0 || i == 1)
//		{
//			if (m_isRight[i])
//			{
//				CreateSquareVertex(salesmans, mobCentralFloa[i],WHITE, m_Tu[i] * BOY_TU, m_Tv[i] * BOY_TV, -BOY_TU, BOY_TV);
//			}
//			else CreateSquareVertex(salesmans, mobCentralFloa[i], WHITE, m_Tu[i] * BOY_TU, m_Tv[i] * BOY_TV, BOY_TU, BOY_TV);
//		}
//		else {
//			if (m_isRight[i])
//			{
//				CreateSquareVertex(salesmans, mobCentralFloa[i], WHITE, MOB_TU, m_Tv[i] * MOB_TV, -MOB_TU, MOB_TV);
//			}
//			else CreateSquareVertex(salesmans, mobCentralFloa[i], WHITE, 0, m_Tv[i] * MOB_TV, MOB_TU, MOB_TV);
//		}
//		if (i >= 2)
//		{
//			SetUpTexture(salesmans, mobTexNum);
//		}
//		else SetUpTexture(salesmans, "BOY_TEX");
//	}
//
//
//	goodsScoreShow();
//	if (g_isGameStart)
//	{
//		static int saleAnimeCount = 0;
//		int saleAnimeTv;
//		static bool saleAnimeChainger = false;
//		saleAnimeCount++;
//		if (saleAnimeCount > ANIMETIONTIME && !saleAnimeChainger)
//		{
//			saleAnimeCount = 0;
//			saleAnimeChainger = true;
//		}
//		if(saleAnimeCount > ANIMETIONTIME && saleAnimeChainger)
//		{
//			saleAnimeCount = 0;
//			saleAnimeChainger = false;
//		}
//		if (saleAnimeChainger)
//		{
//			saleAnimeTv = 1;
//		}
//		else saleAnimeTv = 0;
//		for (int i = 0; i < 3; i++)
//		{
//			CreateSquareVertex(salesmans, popSales[i].popPositionCentral, WHITE, 0, saleAnimeTv * SALE_TV, SALE_TU, SALE_TV);
//			SetUpTexture(salesmans, "SALESMAN_TEX");
//		}
//	}
//	//プレイヤーキャラクターのテクスチャの描画
//	SetUpTexture(effectPC, "YASUKO_EFFECT_TEX");
//	SetUpTexture(Vertex, "YASUKO_TEX");
//
//	timerRender();
//
//	if ((g_timerCount > ZERO_SECOND) && (g_timerCount <= ONE_SECOND))
//	{
//		//スタートカウントのテクスチャの描画
//		SetUpTexture(startCount, "STARTCOUNT_3_TEX");
//	}
//	else if ((g_timerCount > ONE_SECOND) && (g_timerCount <= TWO_SECOND))
//	{
//		//スタートカウントのテクスチャの描画
//		SetUpTexture(startCount, "STARTCOUNT_2_TEX");
//	}
//	else if ((g_timerCount > TWO_SECOND) && (g_timerCount <= THREE_SECOND))
//	{
//		//スタートカウントのテクスチャの描画
//		SetUpTexture(startCount, "STARTCOUNT_1_TEX");
//	}
//	else if ((g_timerCount > THREE_SECOND) && (g_timerCount <= FOUR_SECOND))
//	{
//		//スタートカウントのテクスチャの描画
//		SetUpTexture(start, "START_TEX");
//	}
//
//	if (g_pause && !(g_isTimeUp))
//	{
//		EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, "PAUSE_TEX");
//	}
//}


//void mobControler(CENTRAL_STATE mobCentralFloa[])
//{
//	static int collisionCount[4] = { 0,0,0,0};
//	static int mobAnimeCount[4] = { 0,0,0,0 };
//	if (!BtoBContact(&mobCentralFloa[0], &m_Center))
//	{
//		if (mobCentralFloa[0].x <= 120)
//		{
//			mobCentralFloa[0].y -= 3;
//			m_isRight[0] = false;
//			m_Tv[0] = 1;
//
//		}
//		if (mobCentralFloa[0].x >= 1190)
//		{
//			mobCentralFloa[0].y += 3;
//			m_isRight[0] = false;
//			m_Tv[0] = 0;
//		}
//		if (mobCentralFloa[0].y >= 630)
//		{
//			mobCentralFloa[0].x -= 4;
//			m_isRight[0] = false;
//			m_Tv[0] = 2;
//
//		}
//		if (mobCentralFloa[0].y <= 165)
//		{
//			mobCentralFloa[0].x += 4;
//			m_isRight[0] = true;
//			m_Tv[0] = 2;
//
//		}
//
//	}
//	else
//	{
//		collisionCount[0]++;
//		if (collisionCount[0] > 30)
//		{
//			if (mobCentralFloa[0].x <= 120)
//			{
//				mobCentralFloa[0].y += 10;
//				m_isRight[0] = false;
//				m_Tv[0] = 0;
//
//			}
//			if (mobCentralFloa[0].x >= 1190)
//			{
//				mobCentralFloa[0].y -= 10;
//				m_isRight[0] = false;
//				m_Tv[0] = 1;
//			}
//			if (mobCentralFloa[0].y >= 630)
//			{
//				mobCentralFloa[0].x += 6;
//				m_isRight[0] = true;
//				m_Tv[0] = 2;
//
//
//			}
//			if (mobCentralFloa[0].y <= 165)
//			{
//				mobCentralFloa[0].x -= 6;
//				m_isRight[0] = false;
//				m_Tv[0] = 2;
//
//			}
//			collisionCount[0] = 0;
//		}
//	}
//	mobAnimeCount[0]++;
//	if (mobAnimeCount[0] >= ANIMETIONTIME)
//	{
//		m_Tu[0]++;
//		mobAnimeCount[0] = 0;
//	}
//	if (m_Tu[0] > 1 && !m_isRight[0])
//	{
//		m_Tu[0] = 0;
//	}
//	if (m_Tu[0] > 2 && m_isRight[0])
//	{
//		m_Tu[0] = 1;
//	}
//
//
//	if (!BtoBContact(&mobCentralFloa[1], &m_Center))
//	{
//		switch (rand() % 4)
//		{
//		case NORTH:
//			mobCentralFloa[1].y -= 3;
//			m_isRight[1] = false;
//			m_Tv[1] = 1;
//			break;
//		case SOUTH:
//			mobCentralFloa[1].y += 3;
//			m_isRight[1] = false;
//			m_Tv[1] = 0;
//			break;
//		case EAST:
//			mobCentralFloa[1].x -= 3;
//			m_isRight[1] = false;
//			m_Tv[1] = 2;
//			break;
//		case WEST:
//			mobCentralFloa[1].x += 3;
//			m_isRight[1] = true;
//			m_Tv[1] = 2;
//			break;
//		}
//	}
//	else
//	{
//		collisionCount[1]++;
//		if (collisionCount[1] > 30)
//		{
//			mobCentralFloa[1].y += 5;
//			mobCentralFloa[1].x += 5;
//
//			collisionCount[1] = 0;
//		}
//	}
//	mobAnimeCount[1]++;
//	if (mobAnimeCount[1] >= ANIMETIONTIME)
//	{
//		m_Tu[1]++;
//		mobAnimeCount[1] = 0;
//	}
//	if (m_Tu[1] > 1 && !m_isRight[1])
//	{
//		m_Tu[1] = 0;
//	}
//	if (m_Tu[1] > 2 && m_isRight[1])
//	{
//		m_Tu[1] = 1;
//	}
//
//	if (!BtoBContact(&mobCentralFloa[2], &m_Center))
//	{
//		switch (rand() % 5)
//		{
//		case NORTH:
//			mobCentralFloa[2].y -= 1.5f;
//			m_isRight[2] = false;
//			m_Tv[2] = 1;
//			break;
//		case SOUTH:
//			mobCentralFloa[2].y += 1.5f;
//			m_isRight[2] = false;
//			m_Tv[2] = 0;
//			break;
//		case EAST:
//			mobCentralFloa[2].x -= 2;
//			m_isRight[2] = false;
//			m_Tv[2] = 2;
//			break;
//		case WEST:
//			mobCentralFloa[2].x += 2;
//			m_isRight[2] = true;
//			m_Tv[2] = 2;
//			break;
//		default:
//			break;
//		}
//	}
//	else
//	{
//		collisionCount[2]++;
//		if (collisionCount[2] > 30)
//		{
//			mobCentralFloa[2].y += 5;
//			mobCentralFloa[2].x += 5;
//			collisionCount[2] = 0;
//		}
//	}
//	if (!BtoBContact(&mobCentralFloa[3], &m_Center))
//	{
//		switch (rand() % 5)
//		{
//		case NORTH:
//			mobCentralFloa[3].y -= 1.5f;
//			m_isRight[3] = false;
//			m_Tv[3] = 1;
//			break;
//		case SOUTH:
//			mobCentralFloa[3].y += 1.5f;
//			m_isRight[3] = false;
//			m_Tv[3] = 0;
//			break;
//		case EAST:
//			mobCentralFloa[3].x -= 2;
//			m_isRight[3] = false;
//			m_Tv[3] = 2;
//			break;
//		case WEST:
//			mobCentralFloa[3].x += 2;
//			m_isRight[3] = true;
//			m_Tv[3] = 2;
//			break;
//		default:
//			break;
//		}
//	}
//	else
//	{
//		collisionCount[3]++;
//		if (collisionCount[3] > 30)
//		{
//			mobCentralFloa[3].y += 5;
//			mobCentralFloa[3].x += 5;
//			collisionCount[3] = 0;
//		}
//	}
//
//	collision(&mobCentralFloa[1]);
//	collision(&mobCentralFloa[2]);
//	collision(&mobCentralFloa[3]);
//
//}
//
//void mobToPCContact(CENTRAL_STATE* charctor, CENTRAL_STATE mobCentralFloa[])
//{
//	for (int i = 0; i < 4; i++)
//	{
//		if ((charctor->x <= mobCentralFloa[i].x + mobCentralFloa[i].scaleX) && (mobCentralFloa[i].x <= charctor->x + charctor->scaleX)
//			&& (charctor->y <= mobCentralFloa[i].y + mobCentralFloa[i].scaleY) && (mobCentralFloa[i].y <= charctor->y + charctor->scaleY)) {
//
//			if ((charctor->x <= mobCentralFloa[i].x + mobCentralFloa[i].scaleX))
//			{
//				charctor->x = mobCentralFloa[i].x + mobCentralFloa[i].scaleX;
//			}
//			if ((charctor->x >= mobCentralFloa[i].x - mobCentralFloa[i].scaleX))
//			{
//				charctor->x = mobCentralFloa[i].x - mobCentralFloa[i].scaleX;
//			}
//			if ((charctor->y <= mobCentralFloa[i].y + mobCentralFloa[i].scaleY))
//			{
//				charctor->y = mobCentralFloa[i].y + mobCentralFloa[i].scaleY;
//			}
//			if ((charctor->y >= mobCentralFloa[i].y - mobCentralFloa[i].scaleY))
//			{
//				charctor->y = mobCentralFloa[i].y - mobCentralFloa[i].scaleY;
//			}
//		}
//	}
//}

FloaMove::FloaMove(DirectX * pDirectX, SoundOperater * pSoundOperater,int turn, Yasuko* pYasuko) :SubScene(pDirectX, pSoundOperater,turn,pYasuko)
{
	m_pYasuko = pYasuko;

	m_pSalesman = new Salesman(pDirectX, pSoundOperater);
	m_pSalesman->Update();
	m_pFloaMob = new FloaMob(pDirectX, pSoundOperater,turn);
}

FloaMove::~FloaMove()
{
	delete m_pSalesman;
	m_pSalesman = NULL;
	delete m_pFloaMob;
	m_pFloaMob = NULL;
}

int FloaMove::Update()
{
	if (m_pDirectX->GetKeyStatus(DIK_RIGHT) || m_pDirectX->GetKeyStatus(DIK_D) || m_pXinputDevice->GetButton(ButtonRIGHT) || m_pXinputDevice->GetAnalogL(ANALOGRIGHT)){
		m_pYasuko->KeyOperation(RIGHT);
	}
	if (m_pDirectX->GetKeyStatus(DIK_LEFT) || m_pDirectX->GetKeyStatus(DIK_A) || m_pXinputDevice->GetButton(ButtonLEFT) || m_pXinputDevice->GetAnalogL(ANALOGLEFT)){
		m_pYasuko->KeyOperation(LEFT);
	}
	if (m_pDirectX->GetKeyStatus(DIK_UP) || m_pDirectX->GetKeyStatus(DIK_W) || m_pXinputDevice->GetButton(ButtonUP) || m_pXinputDevice->GetAnalogL(ANALOGUP)) {
		m_pYasuko->KeyOperation(UP);
	}
	if (m_pDirectX->GetKeyStatus(DIK_DOWN) || m_pDirectX->GetKeyStatus(DIK_S) || m_pXinputDevice->GetButton(ButtonDOWN) || m_pXinputDevice->GetAnalogL(ANALOGDOWN)) {
		m_pYasuko->KeyOperation(DOWN);
	}
	if (m_pDirectX->GetKeyStatus(DIK_RETURN) || m_pDirectX->GetKeyStatus(DIK_S) || m_pXinputDevice->GetButton(ButtonA)) {
		leachedGondolaCheck(&m_SalesChoice, m_pSalesman->GetSalesman(), m_pYasuko->salesmanToPCCollision(m_pYasuko->GetCentral()));
	}
	//	static int onceSound = 0;
	//
	//	timerControl();
	//	if (g_timerCount < THREE_SECOND)
	//	{
	//		salesmanPoping(popSales);
	//	}
	//	if (g_isTimeUp)
	//	{
	//		for (onceSound; onceSound < 2; onceSound++)
	//		{
	//			soundsManager.Start("GONG", false);
	//			
	//		}
	//	}
	//
	//	if (g_isGameStart)
	//	{
	//		playerControl(&onceSound);
	//		mobControler(mobCentralFloa);
	//		for (int i = 0; i < 4; i++)
	//		{
	//			collision(&mobCentralFloa[i]);
	//;		}
	//#ifdef _DEBUG
	//		CheckKeyState(DIK_SPACE);
	//		if (KeyState[DIK_SPACE] == KeyRelease)
	//		{
	//			g_gameScene = CHOSEGOODS;
	//			onceSound = 0;
	//		}
	//#endif
	//	}
	m_pYasuko->Update();
	m_pFloaMob->Update();
	m_pYasuko->mobToPCContact(m_pFloaMob->GetCentral());

	return m_GameScene;
}

void FloaMove::Render()
{
	CUSTOMVERTEX Vertex[4];
	RECT Background = { 0,100,DISPLAY_WIDTH ,700 };
	CreateSquareVertex(Vertex, Background);
	m_pDirectX->DrawTexture("FLOAMOVE_BG_TEX", Vertex);

	CUSTOMVERTEX startCount[4];
	CUSTOMVERTEX start[4];
	CUSTOMVERTEX m_EffectVertex[4];
	//CENTRAL_STATE effectCentral = { m_Center.x-2,m_Center.y-14,60,75 };

	//CreateSquareVertex(effectPC, effectCentral, WHITE, (effectCount * EFFECT_TU), 0, EFFECT_TU, EFFECT_TV);
	//CreateSquareVertex(startCount, g_startCountSta);
	//CreateSquareVertex(start, g_startSta);
	//for (int i = 0; i < 4; i++)
	//{
	//	if (i == 0 || i == 1)
	//	{
	//		if (m_isRight[i])
	//		{
	//			CreateSquareVertex(salesmans, mobCentralFloa[i],WHITE, m_Tu[i] * BOY_TU, m_Tv[i] * BOY_TV, -BOY_TU, BOY_TV);
	//		}
	//		else CreateSquareVertex(salesmans, mobCentralFloa[i], WHITE, m_Tu[i] * BOY_TU, m_Tv[i] * BOY_TV, BOY_TU, BOY_TV);
	//	}
	//	else {
	//		if (m_isRight[i])
	//		{
	//			CreateSquareVertex(salesmans, mobCentralFloa[i], WHITE, MOB_TU, m_Tv[i] * MOB_TV, -MOB_TU, MOB_TV);
	//		}
	//		else CreateSquareVertex(salesmans, mobCentralFloa[i], WHITE, 0, m_Tv[i] * MOB_TV, MOB_TU, MOB_TV);
	//	}
	//	if (i >= 2)
	//	{
	//		SetUpTexture(salesmans, mobTexNum);
	//	}
	//	else SetUpTexture(salesmans, "BOY_TEX");
	//}
	m_pFloaMob->Render();
	m_pSalesman->Render();
	//goodsScoreShow();
	//if (g_isGameStart)
	//{
	//	static int saleAnimeCount = 0;
	//	int saleAnimeTv;
	//	static bool saleAnimeChainger = false;
	//	saleAnimeCount++;
	//	if (saleAnimeCount > ANIMETIONTIME && !saleAnimeChainger)
	//	{
	//		saleAnimeCount = 0;
	//		saleAnimeChainger = true;
	//	}
	//	if(saleAnimeCount > ANIMETIONTIME && saleAnimeChainger)
	//	{
	//		saleAnimeCount = 0;
	//		saleAnimeChainger = false;
	//	}
	//	if (saleAnimeChainger)
	//	{
	//		saleAnimeTv = 1;
	//	}
	//	else saleAnimeTv = 0;
	//	for (int i = 0; i < 3; i++)
	//	{
	//		CreateSquareVertex(salesmans, popSales[i].popPositionCentral, WHITE, 0, saleAnimeTv * SALE_TV, SALE_TU, SALE_TV);
	//		SetUpTexture(salesmans, "SALESMAN_TEX");
	//	}
	//}
	////プレイヤーキャラクターのテクスチャの描画
	//SetUpTexture(effectPC, "YASUKO_EFFECT_TEX");
	m_pYasuko->Render();
	//timerRender();

	//if ((g_timerCount > ZERO_SECOND) && (g_timerCount <= ONE_SECOND))
	//{
	//	//スタートカウントのテクスチャの描画
	//	SetUpTexture(startCount, "STARTCOUNT_3_TEX");
	//}
	//else if ((g_timerCount > ONE_SECOND) && (g_timerCount <= TWO_SECOND))
	//{
	//	//スタートカウントのテクスチャの描画
	//	SetUpTexture(startCount, "STARTCOUNT_2_TEX");
	//}
	//else if ((g_timerCount > TWO_SECOND) && (g_timerCount <= THREE_SECOND))
	//{
	//	//スタートカウントのテクスチャの描画
	//	SetUpTexture(startCount, "STARTCOUNT_1_TEX");
	//}
	//else if ((g_timerCount > THREE_SECOND) && (g_timerCount <= FOUR_SECOND))
	//{
	//	//スタートカウントのテクスチャの描画
	//	SetUpTexture(start, "START_TEX");
	//}

	//if (g_pause && !(g_isTimeUp))
	//{
	//	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, "PAUSE_TEX");
	//}


}


void FloaMove::LoadResouce()
{
}

void FloaMove::leachedGondolaCheck(int* leschgondola, SALESMAN* popSales, int whergondola)
{
	for (int i = 0; i < 3; i++)
	{
		if (popSales[i].popPosition == whergondola)
		{
			*leschgondola = i;
			SetGameScene(CHOSEGOODS);
		}
	}
}


