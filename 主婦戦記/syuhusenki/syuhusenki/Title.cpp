#include "Main.h"
#include "Title.h"
#include "GameMain.h"


CENTRAL_STATE g_selectArrowSta = { 500.f, ARROWHIGH, 20.f, 20.f };
static std::string wisdomTex = "WISDOM1_TEX";
static bool canApperMene = false;

//�^�C�g�����䏈��
void titleControl(void)
{
	static int sceneSuccession = 0;
	static int BGM = 0;
	GetControl(0);
	BottonCheck();
	static bool entry[2] = { false,false };
	CheckKeyState(DIK_W);
	CheckKeyState(DIK_S);
	CheckKeyState(DIK_RETURN);
	CheckKeyState(DIK_NUMPADENTER);
	for (BGM; BGM < 1; BGM++)
	{
		g_SoundSuccess = soundsManager.SetVolume("OP_BGM", 50) && g_SoundSuccess;
		g_SoundSuccess = soundsManager.Start("OP_BGM", true) && g_SoundSuccess;
	}

	if ( GetAnalogLValue(ANALOG_Y) <= 6000 && GetAnalogLValue(ANALOG_Y) >= -6000)
	{
		g_inCount = 0;
	}
	else if (g_inCount)
	{
		g_inCount++;
	}


	if (canApperMene)
	{
		if (KeyState[DIK_W] == KeyRelease || PadState[ButtonUP] == PadRelease && !(g_inCount) || GetAnalogLValue(ANALOG_Y) >= 6000 && !(g_inCount))
		{
			if (g_selectArrowSta.y == ARROWHIGH)
			{
				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
				g_selectArrowSta.y = ARROWDOWN;
				g_inCount++;
			}

			else if (g_selectArrowSta.y == ARROWMIDLE)
			{

				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
				g_selectArrowSta.y = ARROWHIGH;
				g_inCount++;
			}
			else if (g_selectArrowSta.y == ARROWDOWN)
			{
				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
				g_selectArrowSta.y = ARROWMIDLE;
				g_inCount++;
			}

		}

		if (KeyState[DIK_S] == KeyRelease || PadState[ButtonDOWN] == PadRelease && !(g_inCount) || GetAnalogLValue(ANALOG_Y) <= -6000 && !(g_inCount))
		{

			if (g_selectArrowSta.y == ARROWHIGH)
			{
				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
				g_selectArrowSta.y = ARROWMIDLE;
				g_inCount++;
			}
			else if (g_selectArrowSta.y == ARROWMIDLE)
			{
				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
				g_selectArrowSta.y = ARROWDOWN;
				g_inCount++;
			}
			else if (g_selectArrowSta.y == ARROWDOWN)
			{
				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
				g_selectArrowSta.y = ARROWHIGH;
				g_inCount++;
			}

		}

		if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease) && g_selectArrowSta.y == ARROWHIGH || PadState[ButtonA] == PadRelease && !(g_inCount) && g_selectArrowSta.y == ARROWHIGH && (!entry[0]))
		{
			g_SoundSuccess = soundsManager.Start("GREETING", false) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Start("BUTTON1", false) && g_SoundSuccess;
			g_SoundSuccess = soundsManager.Stop("OP_BGM") && g_SoundSuccess;
			BGM = 0;
			entry[0] = true;
			//g_scene = SCENE_SERECTCHARANDSTAGE;
			g_inCount++;

		}

		if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease) && g_selectArrowSta.y == ARROWMIDLE || PadState[ButtonA] == PadRelease && g_selectArrowSta.y == ARROWMIDLE)
		{
			g_SoundSuccess = soundsManager.Start("BOW", false) && g_SoundSuccess;
			entry[1] = true;
		}
		if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease) && g_selectArrowSta.y == ARROWDOWN || PadState[ButtonA] == PadRelease && g_selectArrowSta.y == ARROWDOWN)
		{
			g_titleScene = WISDOM;
		}

		if (entry[0])
		{
			sceneSuccession++;
			if ((sceneSuccession >= 70) && entry[0])
			{
				//soundsManager.SetVolume("SELECT_BGM", 25);
				//soundsManager.Start("SELECT_BGM", true);
				g_scene = SCENE_MAIN;
				sceneSuccession = 0;
				entry[0] = false;
			}
		}
		if (entry[1])
		{
			sceneSuccession++;

			if ((sceneSuccession >= 170) && entry[1])
			{
				PostQuitMessage(0);
			}

		}

	}
	if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease || PadState[ButtonA] == PadRelease) && (!canApperMene))
	{
		canApperMene = true;

	}


}

//�^�C�g���`�揈��
void titleRender(void)
{
	BeginSetTexture();

	//�^�C�g����ʂ̃e�N�X�`���̐ݒ�
	titleRenderSta();

	EndSetTexture();
}

//�^�C�g����ʂ̃e�N�X�`��
void titleRenderSta(void)
{
	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, "TITLE_BG_TEX");
	CENTRAL_STATE titleUICentral = { WIDTH / 2, 550, 200.f, 100.f };
	CUSTOMVERTEX titleUI[4];
	CreateSquareVertex(titleUI, titleUICentral);

	CUSTOMVERTEX selectArrow[4];
	CreateSquareVertexColor(selectArrow, g_selectArrowSta, g_cursolColor);

	//�^�C�g�����e�N�X�`���̐���
	if (canApperMene)
	{
		SetUpTexture(titleUI, "TITLE_UI_TEX");

		SetUpTexture(selectArrow, "TITLEICON_TEX");
	}
	else
	{
		static int count = 0;
		count++;
		if (count > 40)
		{
			count = 0;
		}
		if (count > 20)
		{
			SetUpTexture(titleUI, "PRESS_TEX");
		}
	}

}
//��w�̒m�b
void wisdomControl()
{
	static int wisdomPage = PAGE1;
	GetControl(0);
	BottonCheck();

	CheckKeyState(DIK_RETURN);
	CheckKeyState(DIK_NUMPADENTER);

	if (KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease|| PadState[ButtonA] == PadRelease)
	{
		switch (wisdomPage)
		{
		case PAGE1:
			wisdomTex = "WISDOM2_TEX";
			wisdomPage = PAGE2;
			break;
		case PAGE2:
			wisdomTex = "WISDOM3_TEX";
			wisdomPage = PAGE3;
			break;
		case PAGE3:
			wisdomTex = "WISDOM1_TEX";
			wisdomPage = PAGE1;
			g_titleScene = TITLE;
			break;
		}

	}

}

void wisdomRender()
{
	BeginSetTexture();

	EasyCreateSquareVertex(0, 0, 1270, 680, wisdomTex);

	showPressA();

	EndSetTexture();

}