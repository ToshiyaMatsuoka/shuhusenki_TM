#include "Main.h"
#include "Select.h"

//XINPUT_STATE g_Xinput;

CENTRAL_STATE g_yasukoSta = { 225.f, 177.f, 52.f, 73.f };
CENTRAL_STATE g_mitukoSta = { 419.5f, 176.3f, 80.f, 80.f };
CENTRAL_STATE g_isokoSta = { 614.7f, 176.3f, 80.f, 80.f };
CENTRAL_STATE g_charSelectFrameSta = { 226.4f, 177.f, 90.f, 90.f };
CENTRAL_STATE g_stageSelectFrameSta = { 269.f,480.f,140.f,120.f };
CENTRAL_STATE g_selectCharSta = { 1050.f, 270.f, 230.f, 230.f };
CENTRAL_STATE g_lastCheckSta = { 500.f, 390.f,20.f,20.f };

int g_inCount = 0;
int g_gameCount = 0;

bool g_pause = false;
bool g_isGameStart = false;
bool g_isTimeUp = false;
bool g_isNextSelect = false;
bool g_isLastCheck = false;

//�Z���N�g���䏈��
VOID selectControl(VOID)
{
	GetControl(0);
	BottonCheck();

	HRESULT hr;

	if (PadState[ButtonA] == PadOn && !(g_inCount))
	{
		if (g_isNextSelect && g_isLastCheck && g_lastCheckSta.y == 320.f)
		{
			soundsManager.Start("BUTTON1", false);
			g_isNextSelect = false;
			g_isLastCheck = false;
			g_scene = SCENE_MAIN;
		}
		else if (g_isNextSelect && g_isLastCheck && g_lastCheckSta.y == 390.f)
		{
			soundsManager.Start("BUTTON1", false);
			g_isNextSelect = false;
			g_isLastCheck = false;
			g_inCount++;
		}

		else if (g_stageSelectFrameSta.x == 269.f && g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("BUTTON1", false);
			soundsManager.Stop("SELECT");
			g_isLastCheck = true;
			g_inCount++;
		}
		else if (g_stageSelectFrameSta.x == 565.f && g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("MISS", false);
			g_inCount++;
		}

		else if (g_charSelectFrameSta.x == 226.4f && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("BUTTON1", false);
			g_isNextSelect = true;
			g_inCount++;
		}
		else if (g_charSelectFrameSta.x == 419.5f && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("MISS", false);
			g_inCount++;
		}
		else if (g_charSelectFrameSta.x == 614.7f && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("MISS", false);
			g_inCount++;
		}
	}
	if (PadState[ButtonB] == PadOn && !(g_inCount))
	{
		if (!(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Stop("SELECT");
			soundsManager.Start("BUTTON1", false);
			g_scene = SCENE_TITLE;
			g_inCount++;
		}
		if (g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("BUTTON1", false);
			g_isNextSelect = false;
			g_inCount++;
		}
	}
	if (PadState[ButtonUP] == PadOn && !(g_inCount))
	{
		if (g_lastCheckSta.y == 390.f && g_isNextSelect && g_isLastCheck)
		{
			soundsManager.Start("CURSOR", false);
			g_lastCheckSta.y = 320.f;
		}
	}
	if (PadState[ButtonDOWN] == PadOn && !(g_inCount))
	{
		if (g_lastCheckSta.y == 320.f && g_isNextSelect && g_isLastCheck)
		{
			soundsManager.Start("CURSOR", false);
			g_lastCheckSta.y = 390.f;
		}
	}
	/*if (PadState[ButtonY] == PadOn && !(g_inCount))
	{
		if (g_lastCheckSta.y == 490.f && g_isNextSelect && g_isLastCheck)
		{
			g_lastCheckSta.y = 590.f;
		}
	}*/
	if (PadState[ButtonRIGHT] == PadOn && !(g_inCount))
	{
		if (g_charSelectFrameSta.x == 419.5f && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = 614.7f;
			g_inCount++;
		}
		else if (g_charSelectFrameSta.x == 226.4f && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = 419.5f;
			g_inCount++;
		}

		if (g_stageSelectFrameSta.x == 269.f && g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_stageSelectFrameSta.x = 565.f;
			g_inCount++;
		}
	}
	if (PadState[ButtonLEFT] == PadOn && !(g_inCount))
	{
		if (g_charSelectFrameSta.x == 614.7f && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = 419.5f;
			g_inCount++;
		}
		else if (g_charSelectFrameSta.x == 419.5f && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = 226.4f;
			g_inCount++;
		}

		if (g_stageSelectFrameSta.x == 565.f && g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_stageSelectFrameSta.x = 269.f;
			g_inCount++;
		}
	}

	XInputGetState(0, &g_Xinput);

	hr = g_pKeyDevice->Acquire();

	if ((hr == DI_OK) || (hr == S_FALSE))
	{
		BYTE diks[256];
		g_pKeyDevice->GetDeviceState(sizeof(diks), &diks);

		if (g_Xinput.Gamepad.wButtons == 0 && g_Xinput.Gamepad.sThumbLX <= 6000 && g_Xinput.Gamepad.sThumbLX >= -6000)
		{
			g_inCount = 0;
		}
		else if (g_inCount)
		{
			g_inCount++;
		}

		//if (g_Xinput.Gamepad.wButtons == A_BUTTON && !(g_inCount))
		//{
		//	if (g_isNextSelect && g_isLastCheck && g_lastCheckSta.y == 490.f)
		//	{
		//		soundsManager.Start("BUTTON1", false);
		//		g_isNextSelect = false;
		//		g_isLastCheck = false;
		//		g_scene = SCENE_MAIN;
		//	}
		//	else if (g_isNextSelect && g_isLastCheck && g_lastCheckSta.y == 590.f)
		//	{
		//		soundsManager.Start("BUTTON1", false);
		//		g_isNextSelect = false;
		//		g_isLastCheck = false;
		//		g_inCount++;
		//	}

		//	else if (g_stageSelectFrameSta.x == 269.f && g_isNextSelect && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("BUTTON1", false);
		//		soundsManager.Stop("SELECT");
		//		g_isLastCheck = true;
		//		g_inCount++;
		//	}
		//	else if (g_stageSelectFrameSta.x == 565.f && g_isNextSelect && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("MISS", false);
		//		g_inCount++;
		//	}

		//	else if (g_charSelectFrameSta.x == 226.4f && !(g_isNextSelect) && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("BUTTON1", false);
		//		g_isNextSelect = true;
		//		g_inCount++;
		//	}
		//	else if (g_charSelectFrameSta.x == 419.5f && !(g_isNextSelect) && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("MISS", false);
		//		g_inCount++;
		//	}
		//	else if (g_charSelectFrameSta.x == 614.7f && !(g_isNextSelect) && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("MISS", false);
		//		g_inCount++;
		//	}
		//}
		//if (g_Xinput.Gamepad.wButtons == B_BUTTON && !(g_inCount))
		//{
		//	if (!(g_isNextSelect) && !(g_isLastCheck))
		//	{
		//		soundsManager.Stop("SELECT");
		//		soundsManager.Start("BUTTON1", false);
		//		g_scene = SCENE_TITLE;
		//		g_inCount++;
		//	}
		//	if (g_isNextSelect && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("BUTTON1", false);
		//		g_isNextSelect = false;
		//		g_inCount++;
		//	}
		//}
		//if (g_Xinput.Gamepad.wButtons == UP_BUTTON && !(g_inCount) || g_Xinput.Gamepad.sThumbLY >= 6000 && !(g_inCount))
		//{
		//	if (g_lastCheckSta.y == 590.f && g_isNextSelect && g_isLastCheck)
		//	{
		//		g_lastCheckSta.y = 490.f;
		//	}
		//}
		//if (g_Xinput.Gamepad.wButtons == DOWN_BUTTON && !(g_inCount) || g_Xinput.Gamepad.sThumbLY <= -6000 && !(g_inCount))
		//{
		//	if (g_lastCheckSta.y == 490.f && g_isNextSelect && g_isLastCheck)
		//	{
		//		g_lastCheckSta.y = 590.f;
		//	}
		//}
		//if (g_Xinput.Gamepad.wButtons == RIGHT_BUTTON && !(g_inCount) || g_Xinput.Gamepad.sThumbLX >= 6000 && !(g_inCount))
		//{
		//	if (g_charSelectFrameSta.x == 419.5f && !(g_isNextSelect) && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("CURSOR", false);
		//		g_charSelectFrameSta.x = 614.7f;
		//		g_inCount++;
		//	}
		//	else if (g_charSelectFrameSta.x == 226.4f && !(g_isNextSelect) && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("CURSOR", false);
		//		g_charSelectFrameSta.x = 419.5f;
		//		g_inCount++;
		//	}

		//	if (g_stageSelectFrameSta.x == 269.f && g_isNextSelect && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("CURSOR", false);
		//		g_stageSelectFrameSta.x = 565.f;
		//		g_inCount++;
		//	}
		//}
		//else if (g_Xinput.Gamepad.wButtons == LEFT_BUTTON && !(g_inCount) || g_Xinput.Gamepad.sThumbLX <= -6000 && !(g_inCount))
		//{
		//	if (g_charSelectFrameSta.x == 614.7f && !(g_isNextSelect) && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("CURSOR", false);
		//		g_charSelectFrameSta.x = 419.5f;
		//		g_inCount++;
		//	}
		//	else if (g_charSelectFrameSta.x == 419.5f && !(g_isNextSelect) && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("CURSOR", false);
		//		g_charSelectFrameSta.x = 226.4f;
		//		g_inCount++;
		//	}

		//	if (g_stageSelectFrameSta.x == 565.f && g_isNextSelect && !(g_isLastCheck))
		//	{
		//		soundsManager.Start("CURSOR", false);
		//		g_stageSelectFrameSta.x = 269.f;
		//		g_inCount++;
		//	}
		//}
	}
}

//�Z���N�g�`�揈��
VOID selectRender(VOID)
{
	BeginSetTexture();

	//�Z���N�g��ʂ̃e�N�X�`���̐ݒ�
	selectRenderSta();

	EndSetTexture();
}

//�Z���N�g��ʂ̃e�N�X�`��
VOID selectRenderSta(VOID)
{
	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, BLANK);
	CUSTOMVERTEX yasuko[4];
	CreateSquareVertex(yasuko, g_yasukoSta);
	CUSTOMVERTEX mituko[4];
	CreateSquareVertex(mituko, g_mitukoSta);
	CUSTOMVERTEX isoko[4];
	CreateSquareVertex(isoko, g_isokoSta);
	CUSTOMVERTEX frame[4];
	CreateSquareVertex(frame, g_charSelectFrameSta);
	CUSTOMVERTEX selectChar[4];
	CreateSquareVertex(selectChar, g_selectCharSta);
	CUSTOMVERTEX selectStage[4];
	CreateSquareVertex(selectStage, g_stageSelectFrameSta);
	CUSTOMVERTEX lastCheck[4];
	CreateSquareVertex(lastCheck, g_lastCheckSta);


	//���X�q�̃e�N�X�`���̕`��
	SetUpTexture(yasuko, SELECT_YASUKO_TEX);
	//�~�c�q�̃e�N�X�`���̕`��
	SetUpTexture(mituko, SELECT_MITUKO_TEX);
	//�C�\�q�̃e�N�X�`���̕`��
	SetUpTexture(isoko, SELECT_ISOKO_TEX);

	//�I���̘g�̃e�N�X�`���̕`��
	SetUpTexture(frame, SELECTFRAME_TEX);

	if (g_charSelectFrameSta.x == 226.4f)
	{
		SetUpTexture(selectChar, SELECT_YASUKO_TEX);
	}
	else if (g_charSelectFrameSta.x == 419.5f)
	{
		SetUpTexture(selectChar, SELECT_MITUKO_TEX);
	}
	else if (g_charSelectFrameSta.x == 614.7f)
	{
		SetUpTexture(selectChar, SELECT_ISOKO_TEX);
	}

	//�I���̘g�̃e�N�X�`���̕`��
	SetUpTexture(selectStage, SELECTFRAME_TEX);

	if (g_isLastCheck)
	{
		EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, SELECTLASTCHECK_TEX);
		//�ŏI�m�F��ʂ̖��e�N�X�`���̕`��
		SetUpTexture(lastCheck, TITLEICON_TEX);
	}
}