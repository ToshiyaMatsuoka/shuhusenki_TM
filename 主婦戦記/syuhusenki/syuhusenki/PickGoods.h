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

	void PickGoodsKeyOperation(int * rushInput);

	void RushButtonCheck(int rushInput, int rushShow);
private:
	int rushButtonShow;
	float cutinAnimeCount = 0;
	float cutinAnime = 0.5f; 
	bool canCutin = true;

	CENTRAL_STATE playerCutinCentral = { 1200,350,320,280 };
	std::string m_mobTexKey;
};



//extern CENTRAL_STATE playerCutinCentral;
//
//void pickGoods();
//void pickGoodsControl();
//void pickGoodsRender();
//void pickGoodsDeviseControl(int* rushInput);
//void rushButtonCheck(int rushInput, int rushShow);

#endif