#ifndef PICKGOODS_H
#define PICKGOODS_H
#include "SubScene.h"

class PickGoods :
	public SubScene
{
public:
	PickGoods(DirectX * pDirectX, SoundOperater * pSoundOperater, int turn, Yasuko* pYasuko);
	~PickGoods();
	int Update();
	void LoadResouce();
	void Render();

};



//extern CENTRAL_STATE playerCutinCentral;
//
//void pickGoods();
//void pickGoodsControl();
//void pickGoodsRender();
//void pickGoodsDeviseControl(int* rushInput);
//void rushButtonCheck(int rushInput, int rushShow);

#endif