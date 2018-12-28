/**
* @file TitleCursol.cpp
* @brief タイトルのカーソル処理
* @author Toshiya Matsuoka
*/
#include "TITLESCENE.h"
#include "TitleCursol.h"

using namespace Cursol;

TitleCursol::TitleCursol(DirectX* pDirectX, SoundOperater* pSoundOperater) :Object(pDirectX, pSoundOperater)
{

}

TitleCursol::~TitleCursol()
{

}


void TitleCursol::Update() {
	//数値は仮
	switch (m_CursolPos) {
	case START:
		m_Cursol.y = 430;
		break;
	case OPTION:
		m_Cursol.y = 500;
		break;
	case END:
		m_Cursol.y = 570;
		break;
	}

}
void TitleCursol::Render()
{
	CUSTOMVERTEX CursolVertex[4];
	RevolveZ(CursolVertex, DegToRad(180),m_Cursol);
	TextureRender("CURSOL_TEX", CursolVertex);

}

void TitleCursol::KeyOperation(KeyInput vec) {

	switch (vec)
	{
	case UP:
		//if (KeyState[DIK_W] == KeyRelease || PadState[ButtonUP] == PadRelease && !(g_inCount) || GetAnalogLValue(ANALOG_Y) >= 6000 && !(g_inCount))
		//{
		//	if (m_Cursor.y == ARROWHIGH)
		//	{
		//		m_pSoundOperater->Start("CURSOR", false);
		//		m_Cursor.y = ARROWDOWN;
		//		g_inCount++;
		//	}

		//	else if (m_Cursor.y == ARROWMIDLE)
		//	{

		//		m_pSoundOperater->Start("CURSOR", false);
		//		m_Cursor.y = ARROWHIGH;
		//		g_inCount++;
		//	}
		//	else if (m_Cursor.y == ARROWDOWN)
		//	{
		//		m_pSoundOperater->Start("CURSOR", false);
		//		m_Cursor.y = ARROWMIDLE;
		//		g_inCount++;
		//	}

		//}
		MoveUp();
		break;
	case DOWN:
		MoveDown();
		break;

		//if (KeyState[DIK_S] == KeyRelease || PadState[ButtonDOWN] == PadRelease && !(g_inCount) || GetAnalogLValue(ANALOG_Y) <= -6000 && !(g_inCount))
		//{

		//	if (m_Cursor.y == ARROWHIGH)
		//	{
		//		m_pSoundOperater->Start("CURSOR", false);
		//		m_Cursor.y = ARROWMIDLE;
		//		g_inCount++;
		//	}
		//	else if (m_Cursor.y == ARROWMIDLE)
		//	{
		//		m_pSoundOperater->Start("CURSOR", false);
		//		m_Cursor.y = ARROWDOWN;
		//		g_inCount++;
		//	}
		//	else if (m_Cursor.y == ARROWDOWN)
		//	{
		//		m_pSoundOperater->Start("CURSOR", false);
		//		m_Cursor.y = ARROWHIGH;
		//		g_inCount++;
		//	}

		//}
		//};

		//if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease) && m_Cursor.y == ARROWHIGH || PadState[ButtonA] == PadRelease && !(g_inCount) && m_Cursor.y == ARROWHIGH && (!entry[0]))
		//{
		//	m_pSoundOperater->Start("GREETING", false);
		//	m_pSoundOperater->Start("BUTTON1", false);
		//	m_pSoundOperater->Stop("OP_BGM");
		//	BGM = 0;
		//	entry[0] = true;
		//	//g_scene = SCENE_SERECTCHARANDSTAGE;
		//	g_inCount++;

		//}

		//if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease) && m_Cursor.y == ARROWMIDLE || PadState[ButtonA] == PadRelease && m_Cursor.y == ARROWMIDLE)
		//{
		//	m_pSoundOperater->Start("BOW", false);
		//	m_pSoundOperater->Stop("OP_BGM");

		//	entry[1] = true;
		//}
		//if ((KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease) && m_Cursor.y == ARROWDOWN || PadState[ButtonA] == PadRelease && m_Cursor.y == ARROWDOWN)
		//{
		//	m_TitleOrWisdom = WISDOM;
		//}


	}
}
void TitleCursol::MoveUp() {

	switch (m_CursolPos) {
	case START:
		m_CursolPos = END;
		break;
	case OPTION:
		m_CursolPos = START;
		break;
	case END:
		m_CursolPos = OPTION;
		break;
	}
}
void TitleCursol::MoveDown() {
	switch (m_CursolPos) {
	case Cursol::START:
		m_CursolPos = OPTION;
		break;
	case Cursol::OPTION:
		m_CursolPos = END;
		break;
	case Cursol::END:
		m_CursolPos = START;
		break;
	}
}
CursolPosition TitleCursol::getCursolPosition() {
	return m_CursolPos;
}
