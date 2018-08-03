#include "Main.h"

#define PLAYERSCALE 100
#define MOVE_MILEAGE 8
#define MOVE_MILEAGE_STICK 2

enum MOBDIRECTION {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum GAMESCENE {
	FLOAMOVE,
	PUSHENEMY,
	PICKGOODS
};

enum FLOA {
	FOOD,
	CLOTH
};

int gameScene = FLOAMOVE;
int seletFloa = FOOD;

RECT testText = { 100,600,1100,1000 };
//�v���C���[�̉摜���_
CUSTOMVERTEX playerFloa[4];
CENTRAL_STATE playerCentralFloa = {800,800,PLAYERSCALE,PLAYERSCALE };
//���u�̉摜���_
CUSTOMVERTEX mobFloa[4];
CENTRAL_STATE mobCentralFloa = { 500,500 ,PLAYERSCALE,PLAYERSCALE };


void gameControl();
void gameRender();
void floaMove();
void floaMoveControl();
void floaMoveRender();
void keyControl(CENTRAL_STATE* central);
void mobMoving(CENTRAL_STATE* mob);



void gameMain() {
	switch (gameScene) {
	case FLOAMOVE:
		floaMove();
		//WriteWord("�t���A�ړ�", testText, DT_CENTER, RED, FONT);
		break;
	case PUSHENEMY:
		gameControl();
		gameRender();
		WriteWord("���u��w�r��", testText, DT_CENTER, RED, FONT);
		break;
	case PICKGOODS:
		gameControl();
		gameRender();
		WriteWord("�Z�[���i����", testText, DT_CENTER, RED, FONT);
		break;
	
	}
}
void gameControl() {
	GetControl(0);
	BottonCheck();
	CheckKeyState(DIK_RETURN);

	if (KeyState[DIK_RETURN] == KeyRelease)// ���L�[�������Ă�
	{
		soundManager.Play("Sound/Buppigan2.wav", false);

		switch (gameScene) {
		//case FLOAMOVE:
		//	gameScene = PUSHENEMY;
		//	break;
		case PUSHENEMY:
			gameScene = PICKGOODS;
			break;
		case PICKGOODS:
			g_scene = SCENE_RESULT;
			gameScene = FLOAMOVE;
			break;
		}
	}
	if (PadState[ButtonA] == KeyRelease)// ���L�[�������Ă�
	{
		soundManager.Play("Sound/Buppigan2.wav", false);

		switch (gameScene) {
		case FLOAMOVE:
			gameScene = PUSHENEMY;
			break;
		case PUSHENEMY:
			gameScene = PICKGOODS;
			break;
		case PICKGOODS:
			g_scene = SCENE_RESULT;
			gameScene = FLOAMOVE;
			break;
		}
	}
}

void gameRender() {
	BeginSetTexture();
	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, BLANK);

	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, YASUKO_TEX);

		WriteWord("���C���Q�[��", testWord, DT_CENTER, RED, FONT);
	switch (gameScene) {
	//case FLOAMOVE:
	//	WriteWord("�t���A�ړ�", testText, DT_CENTER, RED, FONT);
	//	break;
	case PUSHENEMY:
		WriteWord("���u��w�r��", testText, DT_CENTER, RED, FONT);
		break;
	case PICKGOODS:
		WriteWord("�Z�[���i����", testText, DT_CENTER, RED, FONT);
		break;

	}

	EndSetTexture();
}
//�t���A�ړ����
void floaMove() {
	static bool isFirst = true;
	if (isFirst) {
		ReadInTexture("Texture/testFrame.png", FRAME_TEX);
		ReadInTexture("Texture/FoodSection.png", FOOD_STAGE_TEX);
		ReadInTexture("Texture/ClothingOrnament.png", CLOTH_STAGE_TEX);
		

		isFirst = false;
	}
	floaMoveControl();
	floaMoveRender();
}

void floaMoveControl() {
	CreateSquareVertex(playerFloa, playerCentralFloa);
	CreateSquareVertex(mobFloa,mobCentralFloa);

	BottonCheck();
	CheckKeyState(DIK_RETURN);

	keyControl(&playerCentralFloa);

	if (KeyState[DIK_RETURN] == KeyRelease)// ���L�[�������Ă�
	{
		soundManager.Play("Sound/Buppigan2.wav", false);

			gameScene = PUSHENEMY;
	}

	GetControl(0);
	if (PadState[ButtonA] == KeyRelease)// ���L�[�������Ă�
	{
		soundManager.Play("Sound/Buppigan2.wav", false);

			gameScene = PUSHENEMY;
	}
	mobMoving(&mobCentralFloa);
	MoveInToErea(&playerCentralFloa, 20, 20, 1520, 1000);
	MoveInToErea(&mobCentralFloa, 20, 20, 1520, 1000);
}

void floaMoveRender() {
	BeginSetTexture();
	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, BLANK);
	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, FRAME_TEX);
	switch (seletFloa) {
	case FOOD:
		EasyCreateSquareVertex(20, 20, 1520, 1000, FOOD_STAGE_TEX);
		break;
	case CLOTH:
		EasyCreateSquareVertex(20, 20, 1520, 1000, CLOTH_STAGE_TEX);
		break;
	}
	SetUpTexture(playerFloa, YASUKO_TEX);
	SetUpTexture(mobFloa, MOB_TEX);

	WriteWord("�t���A�ړ�", testText, DT_CENTER, RED, FONT);

	EndSetTexture();
}

void keyControl(CENTRAL_STATE* central) {
	CheckKeyState(DIK_LEFT);
	CheckKeyState(DIK_RIGHT);
	CheckKeyState(DIK_UP);
	CheckKeyState(DIK_DOWN);
	if (KeyState[DIK_LEFT])// ���L�[�������Ă�
	{
		central->x -= MOVE_MILEAGE;
	}
	if (KeyState[DIK_RIGHT])// ���L�[�������Ă�
	{
		central->x += MOVE_MILEAGE;
	}
	if (KeyState[DIK_UP])// ���L�[�������Ă�
	{
		central->y -= MOVE_MILEAGE;
	}
	if (KeyState[DIK_DOWN])// ���L�[�������Ă�
	{
		central->y += MOVE_MILEAGE;
	}
	//XInput�f�o�C�X����
	GetControl(0);
	BottonCheck();
	if (GetAnalogL(ANALOGRIGHT))
	{
		for (int i = 0; i < 4; i++)
		{
			central->x += MOVE_MILEAGE_STICK;
		}
	}

	if (GetAnalogL(ANALOGLEFT))
	{
		for (int i = 0; i < 4; i++)
		{
			central->x -= MOVE_MILEAGE_STICK;
		}
	}
	if (!GetAnalogL(ANALOGDOWN))
	{
		for (int i = 0; i < 4; i++)
		{
			central->y -= MOVE_MILEAGE_STICK;
		}
	}
	if (!GetAnalogL(ANALOGUP))
	{
		for (int i = 0; i < 4; i++)
		{
			central->y += MOVE_MILEAGE_STICK;
		}
	}
	if (PadState[ButtonLEFT])// ���L�[�������Ă�
	{
		central->x += MOVE_MILEAGE;
	}
	if (PadState[ButtonRIGHT])// ���L�[�������Ă�
	{
		central->x -= MOVE_MILEAGE;
	}
	if (PadState[ButtonUP])// ���L�[�������Ă�
	{
		central->y += MOVE_MILEAGE;
	}
	if (PadState[ButtonDOWN])// ���L�[�������Ă�
	{
		central->y -= MOVE_MILEAGE;
	}

}

void mobMoving(CENTRAL_STATE* mob) {
	static int mobDirection = EAST;
	static int mobTurnCount = 0;
	mobTurnCount++;
	if (mobTurnCount > 10) {
		mobDirection = rand() % 4;
		mobTurnCount = 0;
	}
	switch (mobDirection) {
	case NORTH:
		mob->y -= MOVE_MILEAGE;
		break;

	case SOUTH:	
		mob->y += MOVE_MILEAGE;
		break;

	case EAST:
		mob->x += MOVE_MILEAGE;
		break;

	case WEST:
		mob->x -= MOVE_MILEAGE;
		break;
	}
}


//�R�}���h���͏��

void blowOff() {


}