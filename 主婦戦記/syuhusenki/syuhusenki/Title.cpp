//#include "Main.h"
//#include "Title.h"
//#include "GameMain.h"
//
//
//CENTRAL_STATE m_Cursor = { 500.f, ARROWHIGH, 20.f, 20.f };
//static std::string m_WisdomTex = "WISDOM1_TEX";
//static bool m_canApperMenu = false;
//
////�^�C�g�����䏈��
//void titleControl(void)
//{
//	static int sceneSuccession = 0;
//	static int BGM = 0;
//	GetControl(0);
//	BottonCheck();
//	static bool entry[2] = { false,false };
//	CheckKeyState(DIK_W);
//	CheckKeyState(DIK_S);
//	CheckKeyState(DIK_RETURN);
//	CheckKeyState(DIK_NUMPADENTER);
//	for (BGM; BGM < 1; BGM++)
//	{
//		g_SoundSuccess = soundsManager.SetVolume("OP_BGM", 50) && g_SoundSuccess;
//		g_SoundSuccess = soundsManager.Start("OP_BGM", true) && g_SoundSuccess;
//	}
//
//	if ( GetAnalogLValue(ANALOG_Y) <= 6000 && GetAnalogLValue(ANALOG_Y) >= -6000)
//	{
//		g_inCount = 0;
//	}
//	else if (g_inCount)
//	{
//		g_inCount++;
//	}
//
//
//	if (m_canApperMenu)
//	{
//		if (KeyState[DIK_W] == KeyRelease || PadState[ButtonUP] == PadRelease && !(g_inCount) || GetAnalogLValue(ANALOG_Y) >= 6000 && !(g_inCount))
//		{
//			if (m_Cursor.y == ARROWHIGH)
//			{
//				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//				m_Cursor.y = ARROWDOWN;
//				g_inCount++;
//			}
//
//			else if (m_Cursor.y == ARROWMIDLE)
//			{
//
//				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//				m_Cursor.y = ARROWHIGH;
//				g_inCount++;
//			}
//			else if (m_Cursor.y == ARROWDOWN)
//			{
//				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//				m_Cursor.y = ARROWMIDLE;
//				g_inCount++;
//			}
//
//		}
//
//		if (KeyState[DIK_S] == KeyRelease || PadState[ButtonDOWN] == PadRelease && !(g_inCount) || GetAnalogLValue(ANALOG_Y) <= -6000 && !(g_inCount))
//		{
//
//			if (m_Cursor.y == ARROWHIGH)
//			{
//				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//				m_Cursor.y = ARROWMIDLE;
//				g_inCount++;
//			}
//			else if (m_Cursor.y == ARROWMIDLE)
//			{
//				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//				m_Cursor.y = ARROWDOWN;
//				g_inCount++;
//			}
//			else if (m_Cursor.y == ARROWDOWN)
//			{
//				g_SoundSuccess = soundsManager.Start("CURSOR", false) && g_SoundSuccess;
//				m_Cursor.y = ARROWHIGH;
//				g_inCount++;
//			}
//
//		}
//
//		if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease) && m_Cursor.y == ARROWHIGH || PadState[ButtonA] == PadRelease && !(g_inCount) && m_Cursor.y == ARROWHIGH && (!entry[0]))
//		{
//			g_SoundSuccess = soundsManager.Start("GREETING", false) && g_SoundSuccess;
//			g_SoundSuccess = soundsManager.Start("BUTTON1", false) && g_SoundSuccess;
//			g_SoundSuccess = soundsManager.Stop("OP_BGM") && g_SoundSuccess;
//			BGM = 0;
//			entry[0] = true;
//			//g_scene = SCENE_SERECTCHARANDSTAGE;
//			g_inCount++;
//
//		}
//
//		if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease) && m_Cursor.y == ARROWMIDLE || PadState[ButtonA] == PadRelease && m_Cursor.y == ARROWMIDLE)
//		{
//			g_SoundSuccess = soundsManager.Start("BOW", false) && g_SoundSuccess;
//			g_SoundSuccess = soundsManager.Stop("OP_BGM") && g_SoundSuccess;
//
//			entry[1] = true;
//		}
//		if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease) && m_Cursor.y == ARROWDOWN || PadState[ButtonA] == PadRelease && m_Cursor.y == ARROWDOWN)
//		{
//			m_TitleOrWisdom = WISDOM;
//		}
//
//		if (entry[0])
//		{
//			sceneSuccession++;
//			if ((sceneSuccession >= 70) && entry[0])
//			{
//				//soundsManager.SetVolume("SELECT_BGM", 25);
//				//soundsManager.Start("SELECT_BGM", true);
//				g_scene = SCENE_MAIN;
//				sceneSuccession = 0;
//				entry[0] = false;
//			}
//		}
//		if (entry[1])
//		{
//			sceneSuccession++;
//
//			if ((sceneSuccession >= 170) && entry[1])
//			{
//				PostQuitMessage(0);
//			}
//
//		}
//
//	}
//	if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease || PadState[ButtonA] == PadRelease) && (!m_canApperMenu))
//	{
//		m_canApperMenu = true;
//
//	}
//
//
//}
//
////�^�C�g���`�揈��
//void titleRender(void)
//{
//	BeginSetTexture();
//
//	//�^�C�g����ʂ̃e�N�X�`���̐ݒ�
//	titleRenderSta();
//
//	EndSetTexture();
//}
//
////�^�C�g����ʂ̃e�N�X�`��
//void titleRenderSta(void)
//{
//	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, "TITLE_BG_TEX");
//	CENTRAL_STATE titleUICentral = { WIDTH / 2, 550, 200.f, 100.f };
//	CUSTOMVERTEX titleUI[4];
//	CreateSquareVertex(titleUI, titleUICentral);
//
//	CUSTOMVERTEX selectArrow[4];
//	CreateSquareVertexColor(selectArrow, m_Cursor, g_cursolColor);
//
//	//�^�C�g�����e�N�X�`���̐���
//	if (m_canApperMenu)
//	{
//		SetUpTexture(titleUI, "TITLE_UI_TEX");
//
//		SetUpTexture(selectArrow, "TITLEICON_TEX");
//	}
//	else
//	{
//		static int count = 0;
//		count++;
//		if (count > 40)
//		{
//			count = 0;
//		}
//		if (count > 20)
//		{
//			SetUpTexture(titleUI, "PRESS_TEX");
//		}
//	}
//
//}
////��w�̒m�b
//void WisdomControl()
//{
//	static int wisdomPage = PAGE1;
//	GetControl(0);
//	BottonCheck();
//
//	CheckKeyState(DIK_RETURN);
//	CheckKeyState(DIK_NUMPADENTER);
//
//	if (KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease|| PadState[ButtonA] == PadRelease)
//	{
//		switch (wisdomPage)
//		{
//		case PAGE1:
//			m_WisdomTex = "WISDOM2_TEX";
//			wisdomPage = PAGE2;
//			break;
//		case PAGE2:
//			m_WisdomTex = "WISDOM3_TEX";
//			wisdomPage = PAGE3;
//			break;
//		case PAGE3:
//			m_WisdomTex = "WISDOM1_TEX";
//			wisdomPage = PAGE1;
//			m_TitleOrWisdom = TITLE;
//			break;
//		}
//
//	}
//
//}
//
//void WisdomRender()
//{
//	BeginSetTexture();
//
//	EasyCreateSquareVertex(0, 0, 1270, 680, m_WisdomTex);
//
//	showPressA();
//
//	EndSetTexture();
//
//}