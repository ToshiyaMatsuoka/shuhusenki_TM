#include "Main.h"
#include "Select.h"

CENTRAL_STATE g_yasukoTexSta = { 226.4f, 177.f, 52.f, 73.f };
CENTRAL_STATE g_mitukoTexSta = { 419.5f, 180.f, 52.f, 73.f };
CENTRAL_STATE g_isokoTexSta = { 614.7f, 183.f, 52.f, 73.f };
CENTRAL_STATE g_charSelectFrameSta = { 226.4f, 177.f, 90.f, 90.f };
CENTRAL_STATE g_stageSelectFrameSta = { 269.f,480.f,140.f,120.f };
CENTRAL_STATE g_selectCharSta = { 1050.f, 270.f, 230.f, 230.f };
CENTRAL_STATE g_lastCheckSta = { 500.f, 390.f,20.f,20.f };

int g_inCount = 0;

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

	if (g_Xinput.Gamepad.wButtons == 0 && g_Xinput.Gamepad.sThumbLX <= 6000 && g_Xinput.Gamepad.sThumbLX >= -6000)
	{
		g_inCount = 0;
	}
	else if (g_inCount)
	{
		g_inCount++;
	}

	if (PadState[ButtonA] == PadOn && !(g_inCount))
	{
		//�o���m�F�̏���
		if (g_isNextSelect && g_isLastCheck && g_lastCheckSta.y == LASTCHECKTOP)
		{
			soundsManager.Start("BUTTON1", false);
			g_isNextSelect = false;
			g_isLastCheck = false;
			g_scene = SCENE_MAIN;
		}
		else if (g_isNextSelect && g_isLastCheck && g_lastCheckSta.y == LASTCHECKBOTTOM)
		{
			soundsManager.Start("BUTTON1", false);
			g_isNextSelect = false;
			g_isLastCheck = false;
			g_inCount++;
		}

		//�X�e�[�W�I���̏���
		else if (g_stageSelectFrameSta.x == STAGESELECTLEFT && g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("BUTTON1", false);
			soundsManager.Stop("SELECT");
			g_isLastCheck = true;
			g_inCount++;
		}
		else if (g_stageSelectFrameSta.x == STAGESELECTRIGHT && g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("MISS", false);
			g_inCount++;
		}

		//�L�����I���̏���
		else if (g_charSelectFrameSta.x == CHARSELECTLEFT && !(g_isNextSelect) && !(g_isLastCheck))
		{
			g_PCSpeed = g_yasukoSta.speed;
			soundsManager.Start("BUTTON1", false);
			g_isNextSelect = true;
			g_inCount++;
		}
		else if (g_charSelectFrameSta.x == CHARSELECTCENTER && !(g_isNextSelect) && !(g_isLastCheck))
		{
			g_PCSpeed = g_mitukoSta.speed;
			soundsManager.Start("BUTTON1", false);
			g_isNextSelect = true;
			g_inCount++;
		}
		else if (g_charSelectFrameSta.x == CHARSELECTRIGHT && !(g_isNextSelect) && !(g_isLastCheck))
		{
			g_PCSpeed = g_isokoSta.speed;
			soundsManager.Start("BUTTON1", false);
			g_isNextSelect = true;
			g_inCount++;
		}
	}
	if (PadState[ButtonB] == PadOn && !(g_inCount))
	{
		//B�{�^���������ƃ^�C�g���ɖ߂鏈��
		if (!(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Stop("SELECT");
			soundsManager.Start("BUTTON1", false);
			g_scene = SCENE_TITLE;
			g_inCount++;
		}

		//�o���̍ŏI�m�F�̎���B�{�^���̏���
		if (g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("BUTTON1", false);
			g_isNextSelect = false;
			g_inCount++;
		}
	}
	if (PadState[ButtonUP] == PadOn && !(g_inCount))
	{
		if (g_lastCheckSta.y == LASTCHECKBOTTOM && g_isNextSelect && g_isLastCheck)
		{
			soundsManager.Start("CURSOR", false);
			g_lastCheckSta.y = LASTCHECKTOP;
		}
	}
	if (PadState[ButtonDOWN] == PadOn && !(g_inCount))
	{
		if (g_lastCheckSta.y == LASTCHECKTOP && g_isNextSelect && g_isLastCheck)
		{
			soundsManager.Start("CURSOR", false);
			g_lastCheckSta.y = LASTCHECKBOTTOM;
		}
	}
	if (PadState[ButtonRIGHT] == PadOn && !(g_inCount))
	{
		if (g_charSelectFrameSta.x == CHARSELECTCENTER && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = CHARSELECTRIGHT;
			g_inCount++;
		}
		else if (g_charSelectFrameSta.x == CHARSELECTLEFT && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = CHARSELECTCENTER;
			g_inCount++;
		}

		if (g_stageSelectFrameSta.x == STAGESELECTLEFT && g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_stageSelectFrameSta.x = STAGESELECTRIGHT;
			g_inCount++;
		}
	}
	if (PadState[ButtonLEFT] == PadOn && !(g_inCount))
	{
		if (g_charSelectFrameSta.x == CHARSELECTRIGHT && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = CHARSELECTCENTER;
			g_inCount++;
		}
		else if (g_charSelectFrameSta.x == CHARSELECTCENTER && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = CHARSELECTLEFT;
			g_inCount++;
		}

		if (g_stageSelectFrameSta.x == STAGESELECTRIGHT && g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_stageSelectFrameSta.x = STAGESELECTLEFT;
			g_inCount++;
		}
	}
	
	//���X�e�B�b�N����ɓ|�����Ƃ��̏���
	if (g_Xinput.Gamepad.sThumbLY >= 6000 && !(g_inCount))
	{
		if (g_lastCheckSta.y == LASTCHECKBOTTOM && g_isNextSelect && g_isLastCheck)
		{
			soundsManager.Start("CURSOR", false);
			g_lastCheckSta.y = LASTCHECKTOP;
		}
	}

	//���X�e�B�b�N�����ɓ|�����Ƃ��̏���
	if (g_Xinput.Gamepad.sThumbLY <= -6000 && !(g_inCount))
	{
		if (g_lastCheckSta.y == LASTCHECKTOP && g_isNextSelect && g_isLastCheck)
		{
			soundsManager.Start("CURSOR", false);
			g_lastCheckSta.y = LASTCHECKBOTTOM;
		}
	}

	//���X�e�B�b�N���E�ɓ|�������̏���
	if (g_Xinput.Gamepad.sThumbLX >= 6000 && !(g_inCount))
	{
		//�L�����I���̃J�[�\���ړ�
		if (g_charSelectFrameSta.x == CHARSELECTCENTER && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = CHARSELECTRIGHT;
			g_inCount++;
		}
		else if (g_charSelectFrameSta.x == CHARSELECTLEFT && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = CHARSELECTCENTER;
			g_inCount++;
		}

		//�X�e�[�W�I���̃J�[�\���ړ�
		if (g_stageSelectFrameSta.x == STAGESELECTLEFT && g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_stageSelectFrameSta.x = STAGESELECTRIGHT;
			g_inCount++;
		}
	}
	//���X�e�B�b�N�����ɓ|�����Ƃ��̏���
	else if (g_Xinput.Gamepad.sThumbLX <= -6000 && !(g_inCount))
	{
		//�L�����I���̃J�[�\���ړ�
		if (g_charSelectFrameSta.x == CHARSELECTRIGHT && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = CHARSELECTCENTER;
			g_inCount++;
		}
		else if (g_charSelectFrameSta.x == CHARSELECTCENTER && !(g_isNextSelect) && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_charSelectFrameSta.x = CHARSELECTLEFT;
			g_inCount++;
		}

		//�X�e�[�W�I���̃J�[�\���ړ�
		if (g_stageSelectFrameSta.x == STAGESELECTRIGHT && g_isNextSelect && !(g_isLastCheck))
		{
			soundsManager.Start("CURSOR", false);
			g_stageSelectFrameSta.x = STAGESELECTLEFT;
			g_inCount++;
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
	CreateSquareVertex(yasuko, g_yasukoTexSta);
	CUSTOMVERTEX mituko[4];
	CreateSquareVertex(mituko, g_mitukoTexSta);
	CUSTOMVERTEX isoko[4];
	CreateSquareVertex(isoko, g_isokoTexSta);
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

	if (g_charSelectFrameSta.x == CHARSELECTLEFT)
	{
		SetUpTexture(selectChar, SELECT_YASUKO_TEX);
	}
	else if (g_charSelectFrameSta.x == CHARSELECTCENTER)
	{
		SetUpTexture(selectChar, SELECT_MITUKO_TEX);
	}
	else if (g_charSelectFrameSta.x == CHARSELECTRIGHT)
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