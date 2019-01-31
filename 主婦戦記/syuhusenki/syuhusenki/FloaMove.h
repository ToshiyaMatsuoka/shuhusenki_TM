#ifndef FLOAMOVE_H
#define FLOAMOVE_H

#include "SubScene.h"
#include "Salesman.h"
#include "FloaMob.h"



class FloaMove : public SubScene
{
public:
	FloaMove(DirectX* pDirectX, SoundOperater* pSoundOperater,int turn ,Yasuko* pYasuko);
	~FloaMove();
	int Update();
	void Render();
	void LoadResouce();
	void DebugAction();
private:
	Object* m_pSalesman;
	Object* m_pFloaMob;
	void leachedGondolaCheck(int * leschgondola, SALESMAN * popSales, int whergondola);
	

};

//enum SALESPOSITION
//{
//	POS_MEET,
//	POS_VEGETABLE1,
//	POS_VEGETABLE2,
//	POS_SEAFOOD1,
//	POS_SEAFOOD2,
//	POS_SWEET1,
//	POS_SWEET2,
//	POS_SWEET3,
//	POS_DRINK1,
//	POS_DRINK2,
//	POS_FRUIT1,
//	POS_FRUIT2,
//	POS_FRUIT3,
//	POS_NOTING
//};
//
////モブの画像頂点
//extern CUSTOMVERTEX mobFloa[4];
//extern CENTRAL_STATE mobCentralFloa[4];
//extern CENTRAL_STATE mobCentralBlowOff[5];
//
//extern CENTRAL_STATE m_Center;
//extern CENTRAL_STATE g_startCountSta;
//extern CENTRAL_STATE g_startSta;
//extern int effectCount;
//extern int effectIntervalPrev;
//extern int blowOffEffectIntervalPrev;
//void floaMove();

#endif // !FLOAMOVE_H