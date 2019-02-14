#include "Timer.h"
//#include "Main.h"
//#include "GameMain.h"
//#include "FloaMove.h"
//
//#define PI 3.14159265358979
//#define LIMIT_TIME 60//秒
//#define Limit_frame (LIMIT_TIME*60)
//#define DEADLINE_SECOND 300
//#define HURRY_TIME (20*60)
//
//
//CENTRAL_STATE g_timerSta = { 1210.f, 50.f, 50.f, 50.f };
//CENTRAL_STATE g_timeUpSta = { WIDTH/2, HEIGHT/2, 260.f, 100.f };
//bool g_timeDeadline = false;
//int m_TimerCount = 0;
//
////タイマー制御処理
//void timerControl(void)
//{
//	if (m_TimerCount < THREE_SECOND + Limit_frame)
//	{
//		m_TimerCount++;
//	}
//
//	if (m_TimerCount == THREE_SECOND)
//	{
//		g_isGameStart = true;
//		m_pSoundOperater->Start("WHISYLE", false);
//		m_pSoundOperater->SetVolume("FOOD", 25);
//		m_pSoundOperater->Start("FOOD", true);
//
//	}
//	if (g_isGameStart)
//	{
//		if ((Limit_frame + THREE_SECOND) - m_TimerCount == DEADLINE_SECOND)
//		{
//			m_pSoundOperater->Stop("FOOD");
//			m_pSoundOperater->SetVolume("HURRY_UP", 10);
//
//			m_pSoundOperater->Start("TIME_LIMIT", false);
//
//			g_timeDeadline = true;
//		}
//		if ((Limit_frame + THREE_SECOND) - m_TimerCount < ONE_SECOND)
//		{
//			m_pSoundOperater->Stop("TIME_LIMIT");
//
//		}
//		if ((Limit_frame + THREE_SECOND) - m_TimerCount < HURRY_TIME)
//		{
//			m_pSoundOperater->Stop("FOOD");
//			m_pSoundOperater->Start("HURRY_UP", true);
//		}
//		if (m_TimerCount == THREE_SECOND + Limit_frame)
//		{
//			m_pSoundOperater->Start("GONG", false);
//			m_TimerCount = 0;
//			m_pSoundOperater->Stop("HURRY_UP");
//			m_pSoundOperater->SetVolume("HURRY_UP", 100);
//			comandCount = 0;
//			effectIntervalPrev = 0;
//
//			m_pSoundOperater->Stop("TIME_LIMIT");
//			g_isGameStart = false;
//			g_timeDeadline = false;
//			g_isTimeUp = true;
//		}
//	}
//}
//
////タイマー描画処理
//void timerRender(void)
//{
//	static float timerRotation = 0.f;
//
//	CUSTOMVERTEX timer[4];
//	CUSTOMVERTEX timerHand[4];
//	CUSTOMVERTEX timeUp[4];
//
//	CreateSquareVertex(timeUp, g_timeUpSta);
//	CreateSquareVertex(timer, g_timerSta);
//	CreateSquareVertex(timerHand, g_timerSta);
//
//	//秒針回転
//	RevolveZ(timerHand, timerRotation, g_timerSta);
//
//	//タイマーのテクスチャの描画
//	SetUpTexture(timer, "TIMER_FRAME_TEX");
//
//	//タイマーのテクスチャの描画
//	SetUpTexture(timerHand, "TIMER_HAND_TEX");
//#ifdef _DEBUG
//	char debugTime[10];
//	sprintf_s(debugTime, 10, "%d", m_TimerCount);
//	RECT DEBUGText = { 100 ,300,900,600 };
//	WriteWord(debugTime, DEBUGText,"DEBUG_FONT", DT_LEFT, 0xff0000ff);
//	sprintf_s(debugTime, 10, "%d", Limit_frame);
//	DEBUGText = { 400 ,300,900,600 };
//	WriteWord(debugTime, DEBUGText, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
//	sprintf_s(debugTime, 10, "%f", ((360.f / Limit_frame) / 180.f)*PI);
//	DEBUGText = { 400 ,350,900,600 };
//	WriteWord(debugTime, DEBUGText, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
//
//#endif
//	if (m_TimerCount >= THREE_SECOND && !g_isTimeUp)
//	{
//		timerRotation -= ((360.f / Limit_frame) / 180.f)*PI;
//	}
//
//	if (g_isTimeUp /*&& g_turn == 2*/)
//	{
//		//タイムアップのテクスチャの描画
//		SetUpTexture(timeUp, "TIMEUP_TEX");
//		
//	}
//}
//
//int timeShow()
//{
//	return ((Limit_frame + THREE_SECOND) - m_TimerCount) / 60;
//}

Timer::Timer(DirectX* pDirectX, SoundOperater* pSoundOperater) :Object(pDirectX, pSoundOperater)
{
}


Timer::~Timer()
{
}

void Timer::Update()
{
		if (m_TimerCount < THREE_SECOND + LIMIT_FRAME)
		{
			m_TimerCount++;
		}
	
		if (m_TimerCount == THREE_SECOND)
		{
			m_isGameStart = true;
			m_pSoundOperater->Start("WHISYLE", false);
			m_pSoundOperater->SetVolume("FOOD", 25);
			m_pSoundOperater->Start("FOOD", true);
	
		}
		if (m_isGameStart)
		{
			if ((LIMIT_FRAME + THREE_SECOND) - m_TimerCount == DEADLINE_SECOND)
			{
				m_pSoundOperater->Stop("FOOD");
				m_pSoundOperater->SetVolume("HURRY_UP", 10);
	
				m_pSoundOperater->Start("TIME_LIMIT", false);
	
				m_TimeDeadline = true;
			}
			if ((LIMIT_FRAME + THREE_SECOND) - m_TimerCount < ONE_SECOND)
			{
				m_pSoundOperater->Stop("TIME_LIMIT");
	
			}
			if ((LIMIT_FRAME + THREE_SECOND) - m_TimerCount < HURRY_TIME)
			{
				m_pSoundOperater->Stop("FOOD");
				m_pSoundOperater->Start("HURRY_UP", true);
			}
			if (m_TimerCount == THREE_SECOND + LIMIT_FRAME)
			{
				m_pSoundOperater->Start("GONG", false);
				m_pSoundOperater->Stop("HURRY_UP");
				m_pSoundOperater->SetVolume("HURRY_UP", 100);
	
				m_pSoundOperater->Stop("TIME_LIMIT");
				m_isTimeUp = true;
				m_TimeDeadline = false;
				m_isGameStart = false;
			}
		}

}


void Timer::Render()
{
	static float timerRotation = 0.f;

	CUSTOMVERTEX timer[4];
	CUSTOMVERTEX timerHand[4];
	CUSTOMVERTEX timeUp[4];
	CUSTOMVERTEX startCount[4];
	CUSTOMVERTEX start[4];

	CENTRAL_STATE StartCountCentral = { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, 150.f, 150.f };
	CENTRAL_STATE StartCentral = { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, 200.f, 96.25f };

	CreateSquareVertex(timeUp, m_TimeUp);
	CreateSquareVertex(timer, m_Timer);
	CreateSquareVertex(timerHand, m_Timer);
	CreateSquareVertex(startCount, StartCountCentral);
	CreateSquareVertex(start, StartCentral);

	//秒針回転
	RevolveZ(timerHand, timerRotation, m_Timer);

	//タイマーのテクスチャの描画
	m_pDirectX->DrawTexture("TIMER_FRAME_TEX", timer);

	//タイマーのテクスチャの描画
	m_pDirectX->DrawTexture("TIMER_HAND_TEX", timerHand);
#ifdef _DEBUG
	char debugTime[10];
	sprintf_s(debugTime, 10, "%d", m_TimerCount);
	RECT DEBUGText = { 100 ,300,900,600 };
	m_pDirectX->DrawWord(DEBUGText, debugTime, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
	sprintf_s(debugTime, 10, "%d", LIMIT_FRAME);
	DEBUGText = { 400 ,300,900,600 };
	m_pDirectX->DrawWord(DEBUGText, debugTime, "DEBUG_FONT", DT_LEFT, 0xff0000ff);
	sprintf_s(debugTime, 10, "%f", ((360.f / LIMIT_FRAME) / 180.f)*PI);
	DEBUGText = { 400 ,350,900,600 };
	m_pDirectX->DrawWord(DEBUGText, debugTime, "DEBUG_FONT", DT_LEFT, 0xff0000ff);

#endif
	if (m_TimerCount >= THREE_SECOND && !m_isTimeUp)
	{
		timerRotation -= ((360.f / LIMIT_FRAME) / 180.f)*PI;
	}

	if (m_isTimeUp)
	{
		//タイムアップのテクスチャの描画
		m_pDirectX->DrawTexture("TIMEUP_TEX", timeUp);
	}
	if ((m_TimerCount > ZERO_SECOND) && (m_TimerCount <= ONE_SECOND))
	{
		//スタートカウントのテクスチャの描画
		m_pDirectX->DrawTexture("STARTCOUNT_3_TEX",startCount);
	}
	else if ((m_TimerCount > ONE_SECOND) && (m_TimerCount <= TWO_SECOND))
	{
		//スタートカウントのテクスチャの描画
		m_pDirectX->DrawTexture( "STARTCOUNT_2_TEX",startCount);
	}
	else if ((m_TimerCount > TWO_SECOND) && (m_TimerCount <= THREE_SECOND))
	{
		//スタートカウントのテクスチャの描画
		m_pDirectX->DrawTexture( "STARTCOUNT_1_TEX",startCount);
	}
	else if ((m_TimerCount > THREE_SECOND) && (m_TimerCount <= FOUR_SECOND))
	{
		//スタートカウントのテクスチャの描画
		m_pDirectX->DrawTexture( "START_TEX",start);
	}

}

int Timer::TimeShow()
{
	return ((LIMIT_FRAME + THREE_SECOND) - m_TimerCount) / 60;
}

void Timer::Initialize()
{
	m_TimerCount = 0;
	m_TimeDeadline = false;
	m_isTimeUp = false;
}


