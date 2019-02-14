#ifndef TIMER_H
#define TIMER_H

#include "Object.h"

class Timer:public Object
{
public:
	Timer(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~Timer();
	void Update();
	void Render();
	int TimeShow();
	bool GetGameStart() {
		return m_isGameStart;
	}
	bool GetDeadline() {
		return m_TimeDeadline;
	}
	bool GetTimeUp() {
		return m_isTimeUp;
	}
	void Initialize();
private:
	const float PI = 3.14159265358979f;
	const float LIMIT_TIME = 60.f;//秒
	const float LIMIT_FRAME = (LIMIT_TIME * 60.f);
	const float DEADLINE_SECOND = 300;
	const float HURRY_TIME = (20 * 60);

	//0秒
	const float ZERO_SECOND = 0;	
	//1秒
	const float ONE_SECOND = 60;	
	//2秒
	const float TWO_SECOND = 120;	
	//3秒
	const float THREE_SECOND = 180;	
	//4秒
	const float FOUR_SECOND = 240;

	bool m_isTimeUp = false;
	CENTRAL_STATE m_Timer = { 1210.f, 50.f, 50.f, 50.f };
	CENTRAL_STATE m_TimeUp = { DISPLAY_WIDTH/2, DISPLAY_HEIGHT/2, 260.f, 100.f };
	bool m_TimeDeadline = false;
	int m_TimerCount = 0;
	bool m_isGameStart = false;
};

#endif // !TIMER_H