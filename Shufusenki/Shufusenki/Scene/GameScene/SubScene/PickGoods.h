#ifndef PICKGOODS_H
#define PICKGOODS_H
/**
* @file PickGoods.h
* @brief 商品取得シーン処理
* @author Toshiya Matsuoka
*/

#include "Scene/GameScene/SubScene/SubScene.h"

class PickGoods :
	public SubScene
{
public:
	PickGoods(DirectX * pDirectX, SoundOperater * pSoundOperater, int turn, Yasuko* pYasuko);
	~PickGoods();
	int Update();
	void LoadResouce();
	void Render();

	void KeyOperation(int * rushInput);
	/**
	* @brief 入力ボタンと提示ボタンの照合と結果処理 
	*/
	void RushButtonCheck(int rushInput, int rushShow);
private:
	int rushButtonShow;
	float cutinAnimeCount = 0;
	float cutinAnime = 0.5f; 
	bool canCutin = true;

	CENTRAL_STATE playerCutinCentral = { 1200,350,320,280 };
	std::string m_mobTexKey;
};
#endif