#include "Main.h"
#include "Select.h"

XINPUT_STATE g_Xinput;

CENTRAL_STATE g_yasukoSta = { 237.f, 270.f, 120.f, 120.f };
CENTRAL_STATE g_mitukoSta = { 525.f, 264.f, 120.f, 120.f };
CENTRAL_STATE g_isokoSta = { 817.f, 264.f, 120.f, 120.f };
CENTRAL_STATE g_charSelectFrameSta = { 235.f, 265.f, 140.f, 140.f };
CENTRAL_STATE g_stageSelectFrameSta = { 299.f,866.f,200.f,180.f };
CENTRAL_STATE g_selectCharSta = { 1562.5, 430.f, 400.f, 400.f };
CENTRAL_STATE g_lastCheckSta = { 770.f, 590.f,30.f,30.f };

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
	HRESULT hr;

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

		if (g_Xinput.Gamepad.wButtons == A_BUTTON && !(g_inCount))
		{
			if (g_isNextSelect && g_isLastCheck && g_lastCheckSta.y == 490.f)
			{
				soundsManager.Start("BUTTON1", false);
				g_isNextSelect = false;
				g_isLastCheck = false;
				g_scene = SCENE_MAIN;
			}
			else if (g_isNextSelect && g_isLastCheck && g_lastCheckSta.y == 590.f)
			{
				soundsManager.Start("BUTTON1", false);
				g_isNextSelect = false;
				g_isLastCheck = false;
				g_inCount++;
			}

			else if (g_stageSelectFrameSta.x == 299.f && g_isNextSelect && !(g_isLastCheck))
			{
				soundsManager.Start("BUTTON1", false);
				soundsManager.Stop("SELECT");
				g_isLastCheck = true;
				g_inCount++;
			}
			else if (g_stageSelectFrameSta.x == 745.f && g_isNextSelect && !(g_isLastCheck))
			{
				soundsManager.Start("MISS", false);
				g_inCount++;
			}

			else if (g_charSelectFrameSta.x == 235.f && !(g_isNextSelect) && !(g_isLastCheck))
			{
				soundsManager.Start("BUTTON1", false);
				g_isNextSelect = true;
				g_inCount++;
			}
			else if (g_charSelectFrameSta.x == 525.f && !(g_isNextSelect) && !(g_isLastCheck))
			{
				soundsManager.Start("MISS", false);
				g_inCount++;
			}
			else if (g_charSelectFrameSta.x == 817.f && !(g_isNextSelect) && !(g_isLastCheck))
			{
				soundsManager.Start("MISS", false);
				g_inCount++;
			}
		}

		if (g_Xinput.Gamepad.wButtons == B_BUTTON && !(g_inCount))
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

		if (g_Xinput.Gamepad.wButtons == UP_BUTTON && !(g_inCount) || g_Xinput.Gamepad.sThumbLY >= 6000 && !(g_inCount))
		{
			if (g_lastCheckSta.y == 590.f && g_isNextSelect && g_isLastCheck)
			{
				g_lastCheckSta.y = 490.f;
			}
		}

		if (g_Xinput.Gamepad.wButtons == DOWN_BUTTON && !(g_inCount) || g_Xinput.Gamepad.sThumbLY <= -6000 && !(g_inCount))
		{
			if (g_lastCheckSta.y == 490.f && g_isNextSelect && g_isLastCheck)
			{
				g_lastCheckSta.y = 590.f;
			}
		}

		if (g_Xinput.Gamepad.wButtons == RIGHT_BUTTON && !(g_inCount) || g_Xinput.Gamepad.sThumbLX >= 6000 && !(g_inCount))
		{
			if (g_charSelectFrameSta.x == 525.f && !(g_isNextSelect) && !(g_isLastCheck))
			{
				soundsManager.Start("CURSOR", false);
				g_charSelectFrameSta.x = 817.f;
				g_inCount++;
			}
			else if (g_charSelectFrameSta.x == 235.f && !(g_isNextSelect) && !(g_isLastCheck))
			{
				soundsManager.Start("CURSOR", false);
				g_charSelectFrameSta.x = 525.f;
				g_inCount++;
			}

			if (g_stageSelectFrameSta.x == 299.f && g_isNextSelect && !(g_isLastCheck))
			{
				soundsManager.Start("CURSOR", false);
				g_stageSelectFrameSta.x = 745.f;
				g_inCount++;
			}
		}
		else if (g_Xinput.Gamepad.wButtons == LEFT_BUTTON && !(g_inCount) || g_Xinput.Gamepad.sThumbLX <= -6000 && !(g_inCount))
		{
			if (g_charSelectFrameSta.x == 817.f && !(g_isNextSelect) && !(g_isLastCheck))
			{
				soundsManager.Start("CURSOR", false);
				g_charSelectFrameSta.x = 525.f;
				g_inCount++;
			}
			else if (g_charSelectFrameSta.x == 525.f && !(g_isNextSelect) && !(g_isLastCheck))
			{
				soundsManager.Start("CURSOR", false);
				g_charSelectFrameSta.x = 235.f;
				g_inCount++;
			}

			if (g_stageSelectFrameSta.x == 745.f && g_isNextSelect && !(g_isLastCheck))
			{
				soundsManager.Start("CURSOR", false);
				g_stageSelectFrameSta.x = 299.f;
				g_inCount++;
			}
		}
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
	g_pD3Device->SetTexture(0, g_pTexture[SELECT_YASUKO_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, yasuko, sizeof(CUSTOMVERTEX));

	//�~�c�q�̃e�N�X�`���̕`��
	g_pD3Device->SetTexture(0, g_pTexture[SELECT_MITUKO_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, mituko, sizeof(CUSTOMVERTEX));

	//�C�\�q�̃e�N�X�`���̕`��
	g_pD3Device->SetTexture(0, g_pTexture[SELECT_ISOKO_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, isoko, sizeof(CUSTOMVERTEX));

	//�I���̘g�̃e�N�X�`���̕`��
	g_pD3Device->SetTexture(0, g_pTexture[SELECTFRAME_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, frame, sizeof(CUSTOMVERTEX));

	if (g_charSelectFrameSta.x == 235.f)
	{
		g_pD3Device->SetTexture(0, g_pTexture[SELECT_YASUKO_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, selectChar, sizeof(CUSTOMVERTEX));
	}
	else if (g_charSelectFrameSta.x == 525.f)
	{
		g_pD3Device->SetTexture(0, g_pTexture[SELECT_MITUKO_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, selectChar, sizeof(CUSTOMVERTEX));
	}
	else if (g_charSelectFrameSta.x == 817.f)
	{
		g_pD3Device->SetTexture(0, g_pTexture[SELECT_ISOKO_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, selectChar, sizeof(CUSTOMVERTEX));
	}

	//�I���̘g�̃e�N�X�`���̕`��
	g_pD3Device->SetTexture(0, g_pTexture[SELECTFRAME_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, selectStage, sizeof(CUSTOMVERTEX));

	if (g_isLastCheck)
	{
		EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, BLANK);
		//�ŏI�m�F��ʂ̖��e�N�X�`���̕`��
		g_pD3Device->SetTexture(0, g_pTexture[TITLEICON_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, lastCheck, sizeof(CUSTOMVERTEX));
	}
}