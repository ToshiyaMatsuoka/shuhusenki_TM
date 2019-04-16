#ifndef FLOAMOB_H
#define FLOAMOB_H
/**
* @file FloaMob.h
* @brief 徘徊モブ処理
* @author Toshiya Matsuoka
*/

#include "Object.h"
class FloaMob :
	public Object
{
public:
	FloaMob(DirectX* pDirectX, SoundOperater* pSoundOperater,int turn);
	~FloaMob();
	void Update();
	void Render();
	void SelectDirection();
	CENTRAL_STATE* GetCentral() {
		return m_MobCenter;
	}
private:
	const float BOY_TU = (487.f / 2048.f);
	const float BOY_TV = (707.f / 2048.f);
	const float MOB_TU = (430.f / 2048.f);
	const float MOB_TV = (685.f / 2048.f);
	const float MOB_FLOA_SCALE = 50.f;
	
	bool m_isRight[4];
	int m_Tu[4] = { 0,0,0,0 };
	int m_Tv[4] = { 0,0,0,0 };
	std::string m_TexKey;

	CENTRAL_STATE m_MobCenter[4]{
		{ 620,630 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
		{ 600,300 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
		{ 120,500 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE },
		{ 1030,230 ,MOB_FLOA_SCALE,MOB_FLOA_SCALE }
	};
	int Direction[3];
};
#endif
