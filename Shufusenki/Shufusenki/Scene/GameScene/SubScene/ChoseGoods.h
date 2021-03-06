﻿#ifndef CHOSEGOODS_H
#define CHOSEGOODS_H
/**
* @file ChoseGoods.h
* @brief 商品選択処理
* @author Toshiya Matsuoka
*/

#include "Scene/GameScene/SubScene/SubScene.h"

class ChoseGoods :
	public SubScene
{
public:
	ChoseGoods(DirectX * pDirectX, SoundOperater * pSoundOperater, int turn, Yasuko* pYasuko);
	~ChoseGoods();
	int Update();
	void LoadResouce();
	void Render();
private:
	std::string m_TexKey;
	CENTRAL_STATE m_MobCentralBlowOff[5];
};


#endif