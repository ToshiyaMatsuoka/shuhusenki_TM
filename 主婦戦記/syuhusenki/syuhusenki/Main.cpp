#include "Main.h"
#include "GameMain.h"

SoundLib::SoundsManager soundsManager;

bool SoundSuccess;

const char* soundNum[SOUND_MAX];

RECT testWord = { 50,200,1200,500 };
void gameRoop();
void soundLoad();
int g_scene = SCENE_TEAMLOGO;
//int g_scene = SCENE_MAIN;
void render(void);//��
void control(void);//��
void sound(void);//��

void gamePad(void);


bool seOn = false;

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hInstance, LPSTR szStr, INT iCmdShow) {
	HWND hWnd = NULL;

#ifdef _DEBUG
	InitWindowEx("����w��L��", &hWnd, WIDTH, HEIGHT, hInst, hInstance, NULL, "Texture/Yasuko.png");
#else
	InitWindowFullscreenEx("����w��L��", &hWnd, WIDTH, HEIGHT, hInst, hInstance, NULL, "Texture/Yasuko.png");
#endif
	SoundSuccess = soundsManager.Initialize();

	ReadInTexture("Texture/Blank.jpg", BLANK);
	ReadInTexture("Texture/Yasuko.png", YASUKO_TEX);
	ReadInTexture("Texture/karititle.png", BG_TITLE_TEX);
	ReadInTexture("Texture/shopping_cart_woman.png", MOB_TEX);

	SetUpFont(100, 70, DEFAULT_CHARSET, NULL, FONT);
	soundLoad();
	soundsManager.AddFile("Sound/foodbgm.mp3", "FOOD");

	SoundSuccess = soundsManager.Start("FOOD", true) && SoundSuccess;


	FlameRoop(gameRoop);

}
void gameRoop() {
	static bool isFirst = true;
	sound();
	switch (g_scene) {
	case SCENE_TEAMLOGO:
		if (isFirst) {

		ReadInTexture("Texture/Blank.jpg", BLANK);
		ReadInTexture("Texture/Yasuko.png", YASUKO_TEX);
		ReadInTexture("Texture/karititle.png", BG_TITLE_TEX);
		ReadInTexture("Texture/shopping_cart_woman.png", MOB_TEX);
		ReadInTexture("Texture/team_logo.png", TEAMLOGO_TEX);
		isFirst = false;
		}
		control();
		render();
		break;
	case SCENE_TITLE:
		control();
		render();
		break;
	case SCENE_SERECTCHARANDSTAGE:
		control();
		render();
		break;
	case SCENE_MAIN:
		gameMain();
		break;
	case SCENE_RESULT:
		control();
		render();
		break;
	}

}

void control(void) {
	gamePad();
	
	CheckKeyState(DIK_RETURN);
	if (KeyState[DIK_RETURN] == KeyRelease)
	{
		seOn = true;
		switch (g_scene) {
		case SCENE_TEAMLOGO:
			g_scene = SCENE_TITLE;
			break;
		case SCENE_TITLE:
			g_scene = SCENE_SERECTCHARANDSTAGE;
			break;
		case SCENE_SERECTCHARANDSTAGE:
			g_scene = SCENE_MAIN;
			break;
		case SCENE_MAIN:
			//g_scene = SCENE_RESULT;
			break;
		case SCENE_RESULT:
			g_scene = SCENE_TITLE;
			break;
		}
	}
}

void render(void) {
	BeginSetTexture();
	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, BLANK);


	switch (g_scene) {
	case SCENE_TEAMLOGO:
		EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, TEAMLOGO_TEX);
		break;
	case SCENE_TITLE:
		//WriteWord("��w��L", testWord, DT_CENTER, RED, FONT);
		EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, BG_TITLE_TEX);

		break;
	case SCENE_SERECTCHARANDSTAGE:
		EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, YASUKO_TEX);

		WriteWord("�L����&�X�e�[�W\n�I��", testWord, DT_CENTER, RED, FONT);
		break;
	case SCENE_MAIN:
		EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, YASUKO_TEX);

		WriteWord("���C���Q�[��", testWord, DT_CENTER, RED, FONT);
		break;
	case SCENE_RESULT:
		EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, YASUKO_TEX);

		WriteWord("���U���g", testWord, DT_CENTER, RED, FONT);
		break;
	}

	EndSetTexture();

}
void sound(void) {
	if (seOn) {
		seOn = false;
	}

}
void gamePad() {
	//XInput�f�o�C�X����
	GetControl(0);
	BottonCheck();
	if (PadState[ButtonA] == PadRelease) {
		seOn = true;
		switch (g_scene) {
		case SCENE_TEAMLOGO:
			g_scene = SCENE_TITLE;
			break;
		case SCENE_TITLE:
			g_scene = SCENE_SERECTCHARANDSTAGE;
			break;
		case SCENE_SERECTCHARANDSTAGE:
			g_scene = SCENE_MAIN;
			break;
		case SCENE_MAIN:
			g_scene = SCENE_RESULT;
			break;
		case SCENE_RESULT:
			g_scene = SCENE_TITLE;
			break;
		}

	}

}

void soundLoad() {
}