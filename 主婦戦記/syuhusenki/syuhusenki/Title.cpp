#include "Main.h"
#include "Title.h"

CENTRAL_STATE g_selectArrowSta = { 330.f, 600.f, 20.f, 20.f };

//�^�C�g�����䏈��
VOID titleControl(VOID)
{
	static int sceneSuccession = 0;
	static int BGM = 0;
	GetControl(0);
	BottonCheck();
	static bool entry[2] = { false,false };
	for (BGM; BGM < 1; BGM++)
	{
		//soundsManager.SetVolume("OP_BGM", 25);
		soundsManager.Start("OP_BGM", true);
	}

	if (g_Xinput.Gamepad.wButtons == 0 && GetAnalogLValue(ANALOG_X) <= 6000 && GetAnalogLValue(ANALOG_X) >= -6000)
	{
		g_inCount = 0;
	}
	else if (g_inCount)
	{
		g_inCount++;
	}

	if (InputKEY(DIK_ESCAPE) && !(g_inCount))
	{
		PostQuitMessage(0);
		g_inCount++;
	}

	if (InputKEY(DIK_A) || PadState[ButtonLEFT] == PadOn && !(g_inCount) || GetAnalogLValue(ANALOG_X) <= -6000 && !(g_inCount))
	{
		soundsManager.Start("CURSOR", false);
		g_selectArrowSta.x = ARROWRIGHT;
		g_inCount++;
	}

	if (InputKEY(DIK_D) || PadState[ButtonRIGHT] == PadOn && !(g_inCount) || GetAnalogLValue(ANALOG_X) >= 6000 && !(g_inCount))
	{
		soundsManager.Start("CURSOR", false);
		g_selectArrowSta.x = ARROWLEFT;
		g_inCount++;
	}
	CheckKeyState(DIK_RETURN);
	CheckKeyState(DIK_NUMPADENTER);

	if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease) && g_selectArrowSta.x == ARROWRIGHT ||PadState[ButtonA] == PadOn && !(g_inCount) && g_selectArrowSta.x == ARROWRIGHT)
	{
		soundsManager.Start("GREETING", false);
		soundsManager.Start("BUTTON1", false);
		soundsManager.Stop("OP_BGM");
		BGM = 0;
		entry[0] = true;
		//g_scene = SCENE_SERECTCHARANDSTAGE;
		g_inCount++;

	}

	if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease) && g_selectArrowSta.x == ARROWLEFT ||PadState[ButtonA] == PadOn && g_selectArrowSta.x == ARROWLEFT)
	{
		soundsManager.Start("BOW", false);
		entry[1] = true;
	}

	if (entry[0])
	{
		sceneSuccession++;
		if ((sceneSuccession >= 70) && entry[0])
		{
			soundsManager.SetVolume("SELECT_BGM", 25);
			soundsManager.Start("SELECT_BGM", true);
			g_scene = SCENE_SERECTCHARANDSTAGE;
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

//�^�C�g���`�揈��
VOID titleRender(VOID)
{
	BeginSetTexture();

	//�^�C�g����ʂ̃e�N�X�`���̐ݒ�
	titleRenderSta();

	EndSetTexture();
}

//�^�C�g����ʂ̃e�N�X�`��
VOID titleRenderSta(VOID)
{
	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, BG_TITLE_TEX);

	CUSTOMVERTEX selectArrow[4];
	CreateSquareVertex(selectArrow, g_selectArrowSta);

	//�^�C�g�����e�N�X�`���̐���
	SetUpTexture(selectArrow, TITLEICON_TEX);
}