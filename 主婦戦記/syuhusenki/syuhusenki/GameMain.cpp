#include "Main.h"

enum GAMESCENE {
	FLOAMOVE,
	PUSHENEMY,
	TAKEGOODS
};

int gameScene = FLOAMOVE;

RECT testText = { 100,600,1100,1000 };
void gameControl();
void gameRender();



void gameMain() {
	switch (gameScene) {
	case FLOAMOVE:
		gameControl();
		gameRender();
		WriteWord("�t���A�ړ�", testText, DT_CENTER, RED, FONT);
		break;
	case PUSHENEMY:
		gameControl();
		gameRender();
		WriteWord("���u��w�r��", testText, DT_CENTER, RED, FONT);
		break;
	case TAKEGOODS:
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
		case FLOAMOVE:
			gameScene = PUSHENEMY;
			break;
		case PUSHENEMY:
			gameScene = TAKEGOODS;
			break;
		case TAKEGOODS:
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
			gameScene = TAKEGOODS;
			break;
		case TAKEGOODS:
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
	case FLOAMOVE:
		WriteWord("�t���A�ړ�", testText, DT_CENTER, RED, FONT);
		break;
	case PUSHENEMY:
		WriteWord("���u��w�r��", testText, DT_CENTER, RED, FONT);
		break;
	case TAKEGOODS:
		WriteWord("�Z�[���i����", testText, DT_CENTER, RED, FONT);
		break;

	}

	EndSetTexture();
}