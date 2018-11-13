#include "Main.h"
#include "FloaMove.h"
#include "GameMain.h"
#include "Goods.h"
#include "Timer.h"
#include "BlowOff.h"

//エフェクト
CUSTOMVERTEX effectExplosion[4];
CENTRAL_STATE effectExplosionCentral = { 1000,800,300,300 };
bool g_isBlowOff = false;

static bool soundOnce = false;
void blowOff() {
	blowOffControl();
	blowOffRender();
	if (g_turn == 0)
	{
		rushButtonShow = rand() % 4;
	}
	else {
		rushButtonShow = rand() % 6;
	}

}
void blowOffControl()
{
	timerControl();
	CreateSquareVertex(effectExplosion, effectExplosionCentral);

	if (comandCount < 5)
	{
		if (g_isGameStart)
		{
			blowOffDeviseControl(&comandCount, comandInput);
		}
		checkedComand = comandCheck(comandPresentment, comandInput, comandCount);
		if (1 == checkedComand && soundOnce)
		{
			soundOnce = false;
			g_SoundSuccess = soundsManager.Start("SUCCESS", false) && g_SoundSuccess;
			checkedComand = 2;
		}
		if (!checkedComand&&soundOnce)
		{
			soundOnce = false;
			checkedComand = 2;
			g_SoundSuccess = soundsManager.Start("MISS", false) && g_SoundSuccess;
			if (comandButton) {
				comandCount -= 1;
			}
		}
	}
	else
	{
		checkedComand = comandCheck(comandPresentment, comandInput, comandCount);
		if (1 == checkedComand)
		{
			g_SoundSuccess = soundsManager.Start("ATTACK", false) && g_SoundSuccess;
			g_isBlowOff = true;
			checkedComand = 2;

		}
		if (!checkedComand)
		{
			g_SoundSuccess = soundsManager.Start("MISS", false) && g_SoundSuccess;
			checkedComand = 2;

		}
	}
	if (g_isBlowOff) {
		madamBlowOff();
		effectExplosionCentral.scaleX++;
		effectExplosionCentral.scaleY++;
		playerCentralHit.x += 30;
		if (g_effectCount >= 180) {
			g_gameScene = PICKGOODS;
			playerCentralHit.x = 200;
			comandCount = 0;
		}
	}

}
void blowOffRender()
{
	CUSTOMVERTEX effectPC[4];
	CENTRAL_STATE effectCentral = { playerCentralHit.x - 2,playerCentralHit.y - 14,playerCentralHit.scaleX*2.03f,playerCentralHit.scaleY*1.4f };

	CreateSquareVertex(effectPC, effectCentral, WHITE, (effectCount * EFFECT_TU), 0, EFFECT_TU, EFFECT_TV);

	CreateSquareVertex(playerHit, playerCentralHit, WHITE, g_blowOffPCEffectCount*YASUKO_TU, 2*YASUKO_TV, -1 * YASUKO_TU, YASUKO_TV);

	BeginSetTexture();
	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, "FLOAMOVE_BG_TEX");

	EasyCreateSquareVertexColor(0, 0, WIDTH, HEIGHT, "BLANK", HARFCLEAR);

	for (int i = 0; i < 5; i++) {
		CreateSquareVertex(mobFloa, mobCentralBlowOff[i], WHITE, 0,0,MOB_TU, MOB_TV);
		if (g_isBlowOff) {
			g_effectCount++;

			mobRad += 0.9f;

			if (mobRad < 0)
			{
				mobRad = mobRad * -1;
			}
			if (i % 2)
			{
				mobRad = mobRad * -1;
			}
			RevolveZTuTv(mobFloa, mobRad, mobCentralBlowOff[i],  0, 0, MOB_TU, MOB_TV);
		}
		SetUpTexture(mobFloa, mobTexNum);
	}
	if ((g_effectCount > 20) && g_isBlowOff) {
		SetUpTexture(effectExplosion, "EXPLOSION_TEX");
	}
	SetUpTexture(effectPC, "YASUKO_EFFECT_TEX");
	SetUpTexture(playerHit, texturePC);

	char debugComandInput[10];
	char debugComandOutput[10];
	char DebugCounter[10];
	for (int i = 0; i < 5; i++)
	{
		RECT DEBUGText = { 300 + (i * 100),200,450 + (i * 100),300 };
		EasyCreateRECTVertex(DEBUGText, comandButtonTexture(comandPresentment[i]));
	}
	for (int i = 0; i < 5; i++)
	{
		RECT DEBUGText = { 300 + (i * 100),300,450 + (i * 100),400 };
		EasyCreateRECTVertex(DEBUGText, comandButtonTexture(comandInput[i]));
	}
#ifdef _DEBUG

	for (int i = 0; i < 5; i++)
	{
		sprintf_s(debugComandInput, 10, "%c", comandButton(comandInput[i]));

		RECT DEBUGText = { 100 + (i * 50),500,900,600 };
		WriteWord(debugComandInput, DEBUGText, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
	}
	for (int i = 0; i < 5; i++)
	{
		sprintf_s(debugComandOutput, 10, "%c", comandButton(comandPresentment[i]));

		RECT DEBUGText = { 100 + (i * 50),450,900,600 };
		WriteWord(debugComandOutput, DEBUGText, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
	}

	sprintf_s(DebugCounter, 10, "%d", comandCount);
	RECT DEBUGText = { 100 ,550,900,600 };
	WriteWord(DebugCounter, DEBUGText, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
#endif

	goodsScoreShow();
	timerRender();
	EndSetTexture();
}
int comandCheck(int comand[], int inputComand[], int count)
{
	for (int i = 0; i < count; i++) {
		if (inputComand[i] == 10) {
			return 2;
		}
		if (comand[i] == inputComand[i]) {
			if (i == count - 1) {
				return 1;
			}
		}
		if (comand[i] != inputComand[i]) {
			if (i == count - 1) {
				return 0;
			}
		}
	}
	return 2;
}
void comandMake() {
	srand((unsigned int)time(NULL));
	if (g_turn == 0)
	{
		comandPresentment[0] = rand() % 4;
		comandPresentment[1] = rand() % 4;
		comandPresentment[2] = rand() % 4;
		comandPresentment[3] = rand() % 4;
		comandPresentment[4] = rand() % 4;

	}
	else {
		comandPresentment[0] = rand() % 6;
		comandPresentment[1] = rand() % 6;
		comandPresentment[2] = rand() % 6;
		comandPresentment[3] = rand() % 6;
		comandPresentment[4] = rand() % 6;
	}
}

char comandButton(int comand)
{
	switch (comand) {
	case ButtonA:
		return 'A';
	case ButtonB:
		return 'B';
	case ButtonX:
		return 'X';
	case ButtonY:
		return 'Y';
	case ButtonRB:
		return 'R';
	case ButtonLB:
		return 'L';
	}

}
std::string comandButtonTexture(int comand)
{
	switch (comand) {
	case ButtonA:
		return "A_TEX";
	case ButtonB:
		return"B_TEX";
	case ButtonX:
		return "X_TEX";
	case ButtonY:
		return"Y_TEX";
	case ButtonRB:
		return"R_TEX";
	case ButtonLB:
		return "L_TEX";
	default:
		return "NULL_BUTTON_TEX";
	}

}

void blowOffDeviseControl(int* i, int comand[])
{
	static int buttonKeyID = 0;
	static int prevbuttonKeyID = 1;
	BottonCheck();
	CheckKeyState(DIK_RETURN);
	CheckKeyState(DIK_NUMPADENTER);
	CheckKeyState(DIK_A);
	CheckKeyState(DIK_B);
	CheckKeyState(DIK_X);
	CheckKeyState(DIK_Y);
	CheckKeyState(DIK_R);
	CheckKeyState(DIK_L);
#ifdef _DEBUG

	if (KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease)
	{
		g_gameScene = PICKGOODS;

	}
#endif
	if (KeyState[DIK_A] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonA;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}
	if (KeyState[DIK_B] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonB;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}
	if (KeyState[DIK_X] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonX;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}
	if (KeyState[DIK_Y] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonY;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}
	if (KeyState[DIK_R] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonRB;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}
	if (KeyState[DIK_L] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonLB;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}
	//XInputデバイス操作
	GetControl(0);
	BottonCheck();
#ifdef _DEBUG

	if (PadState[ButtonStart] == KeyRelease)
	{
		g_gameScene = PICKGOODS;
	}
#endif
	if (PadState[ButtonA] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonA;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}
	if (PadState[ButtonB] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonB;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}
	if (PadState[ButtonX] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonX;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}
	if (PadState[ButtonY] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonY;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}
	if (PadState[ButtonRB] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonRB;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}
	if (PadState[ButtonLB] == KeyRelease)
	{
		soundOnce = true;
		comand[*i] = ButtonLB;
		if (*i < 5) {
			*i += 1;
		}
		buttonSE(Button, 10);
		return;
	}

}

void buttonSE(SoundEffect Button, int SoundNumber) {
	static int buttonKeyID = 0;
	static int prevbuttonKeyID = 1;
	if (buttonKeyID >= SoundNumber) {
		buttonKeyID = 0;
	}

	switch (buttonKeyID) {
	case 14:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE15) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE15, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 0;
			break;
		}
	case 13:
		if (buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE14) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE14, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 14;
			break;
		}
	case 12:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE13) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE13, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 13;
			break;
		}
	case 11:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE12) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE12, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 12;
			break;
		}
	case 10:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE11) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE11, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 11;
			break;
		}

	case 9:
		if (buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE10) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE10, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 10;
			break;
		}
	case 8:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE9) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE9, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 9;
			break;
		}

	case 7:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE8) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE8, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 8;
			break;
		}
	case 6:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE7) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE7, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 7;
			break;
		}
	case 5:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE6) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE6, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 6;
			break;
		}

	case 4:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE5) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE5, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 5;
			break;
		}
	case 3:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE4) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE4, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 4;
			break;
		}
	case 2:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE3) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE3, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 3;
			break;
		}
	case 1:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE2) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE2, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 2;
			break;
		}
	case 0:
		if ( buttonKeyID != prevbuttonKeyID) {
			g_SoundSuccess = soundsManager.Stop(Button.SE1) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start(Button.SE1, false) && g_SoundSuccess;
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 1;
			break;
		}
	}
}
void madamBlowOff() {


	mobCentralBlowOff[0].x -= rand() % 15;
	mobCentralBlowOff[0].y -= rand() % 5;

	mobCentralBlowOff[1].x += rand() % 10;
	mobCentralBlowOff[1].y -= rand() % 10;

	mobCentralBlowOff[2].x += rand() % 3;
	mobCentralBlowOff[2].y -= rand() % 10;

	mobCentralBlowOff[3].x -= rand() % 8;
	mobCentralBlowOff[3].y -= rand() % 10;

	mobCentralBlowOff[4].x += rand() % 25;
	mobCentralBlowOff[4].y -= rand() % 30;

	if (g_effectCount > 500) {
		for (int i = 0; i < 5; i++) {
			mobCentralBlowOff[i].y += 35;
		}
	}

}

void RevolveZTuTv(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float tu, float tv, float scaleTu, float scaleTv) {

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

	Vertex[0] = { CharVertexX[0], CharVertexY[0], 1.f, 1.f, 0xffffffff,  tu, tv };
	Vertex[1] = { CharVertexX[1], CharVertexY[1], 1.f, 1.f, 0xffffffff,  tu + scaleTu, tv };
	Vertex[2] = { CharVertexX[2], CharVertexY[2], 1.f, 1.f, 0xffffffff,  tu + scaleTu, tv + scaleTv };
	Vertex[3] = { CharVertexX[3], CharVertexY[3], 1.f, 1.f, 0xffffffff,  tu, tv + scaleTv };

}
