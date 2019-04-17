#ifndef RESULTSCENE_H
#define RESULTSCENE_H
/**
* @file ResultScene.h
* @brief リザルトシーン処理
* @author Toshiya Matsuoka
*/

#include "Scene/Scene.h"
class ResultScene :
	public Scene
{
public:
	ResultScene(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~ResultScene();

	int Update();
	void KeyOperation();

	void Render();
	//! 1ページ目の描画
	void resultRenderOne(void);
	//! 2ページ目の描画
	void resultRenderTwo(void);
	//! 3ページ目の描画
	void resultRenderThree(void);
	void LoadResouce();
private:
	enum SCENEPAGE
	{
		PAGE1,
		PAGE2,
		PAGE3
	};

	const int HIGH_SCORE = 35000;
	const int LOW_SCORE = 15000;
	CENTRAL_STATE cursorResult{ 100,490,25,25 };
	int succeedCombo;
	int resultPage = PAGE1;
	int nomalSum = 0;
	int saleSale = 0;
	int resultCounter = 0;
	DWORD SyncOld;
	DWORD SyncNow;
	bool apperText[10] = { false };
	DWORD m_Color = 0xffffffff;

	void PageOneKeyOperation();
	void PageTwoKeyOperation();
	void PageThreeKeyOperation();

	void ApperResult(int* resultCounter);


	CENTRAL_STATE BaseTexCentral1{ 100,150,50,50 };
	CENTRAL_STATE BaseTexCentral2{ 100,250,50,50 };
	CENTRAL_STATE BaseTexCentral3{ 100,350,50,50 };
	CENTRAL_STATE SeleTexCentral1{ 850,150,50,50 };
	CENTRAL_STATE SeleTexCentral2{ 850,250,50,50 };
	CENTRAL_STATE SeleTexCentral3{ 850,350,50,50 };
	CENTRAL_STATE comboTexCentral{ 640,315,100,100 };
	CENTRAL_STATE nomalTResult{ 200,30,100,25 };
	CENTRAL_STATE saleTResult{ 1020,30,100,25 };
	CENTRAL_STATE comboTResult{ 640,30,100,25 };
	CENTRAL_STATE comboStarResult{ 640,150,100,25 };
	CENTRAL_STATE comboTextResult{ 640,650,300,25 };

};
#endif
