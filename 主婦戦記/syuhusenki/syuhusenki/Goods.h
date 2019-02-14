#ifndef GOODS_H
#define GOODS_H

#include "GAMEMANAGER.h"
#include "Object.h"

namespace COMBO_RARE {
	const int RARE1 = 100;
	const int RARE2 = 300;
	const int RARE3 = 500;
}


enum GOODSNUMBER 
{
	BLANKGOODS,
	BEEF,
	PORK,
	CHICKEN,
	VIENNESE,
	MINCE,
	SHRIMP,
	OCTOPUS,
	INKFISH,
	FISH,
	GINESENG,
	ONION,
	POTATO,
	TOMATO,
	RADISH,
	POTATOCHIPS,
	CHOCOLATE,
	ICE,
	RICECRACKER,
	APPLE,
	ORANGE,
	BANANA,
	TEA,
	JUICE,
	BEER,
	MEET,
	FRUIT,
	GOODS_MAX
};

enum COMBOMEUE 
{
	BURIDAIKON,
	RELISH,
	TEATIME,
	CURRY,
	HAMBERG,
	ASSORTEDSASHIMI,
	AFTERNOONREFRESHMENT,
	SOUP,
	NIMONO,
	PARFAIT,
	BLANK_COMBO,
	COMBO_MAX
};

enum GOODSSORTING
{
	MEET_SORT,
	VEGETABLE_SORT,
	SEAFOOD_SORT,
	SWEET_SORT,
	FRUIT_SORT,
	DRINK_SORT,
	SORT_MAX
};

struct GOODSPARAMETER 
{
	const int goodsID;
	std::string textureID;
	const int nominalCost;
	const int selePrice;
	int haveValue;

};

struct COMBOPARAMETER 
{
	const int comboID;
	std::string textureID;
	const int comboBonus;
	const int comboElement1;
	const int comboElement2;
	const int comboElement3;
	bool comboSucceed;
};


class Goods :public Object
{
public:
	Goods(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~Goods();
	void Initialize();
	int AddPrice(int num, int nomalOrSale);
	int ComboSucceceCheck(void);
	void ComboCheck(int goodsId1, int goodsId2, int goodsId3);
	void SelectGoods(SALESMAN* popSales);

	int GetselectedGoods(int ArrayNum) {
		return m_SelectedGoods[ArrayNum];
	}
	int SetselectedGoods(int ArrayNum,int Value) {
		return m_SelectedGoods[ArrayNum] = Value;
	}

	
	int GetHaveValue(int ArrayNum) {
		return m_FoodGoods[ArrayNum].haveValue;
	}
	GOODSPARAMETER* GetfoodGoods() {
		return m_FoodGoods;
	}
	COMBOPARAMETER* GetfoodCombo() {
		return m_FoodCombo;
	}
	void SetHaveValue(int ArrayNum, int Value) {
		m_FoodGoods[ArrayNum].haveValue = Value;
	}
	int GetComboBonus(int ArrayNum) {
		return m_FoodCombo[ArrayNum].comboBonus;
	}
	std::string GetFoodGoodsTexID(int ArrayNum) {
		return m_FoodGoods[ArrayNum].textureID;
	}
	std::string GetFoodComboTexID(int ArrayNum) {
		return m_FoodCombo[ArrayNum].textureID;
	}
	void AddHaveValue(int Add, int ArrayNum) {
		m_FoodGoods[ArrayNum].haveValue += Add;
	}
	int GetnominalCost(int ArrayNum) {
		return m_FoodGoods[ArrayNum].nominalCost;
	}
	int GetselePrice(int ArrayNum) {
		return m_FoodGoods[ArrayNum].selePrice;
	}
	bool GetFoodComboSucceed(int ArrayNum) {
		return m_FoodCombo[ArrayNum].comboSucceed;
	}

private:
	static GOODSPARAMETER m_FoodGoods[GOODS_MAX];
	static COMBOPARAMETER m_FoodCombo[COMBO_MAX];

	int m_SelectedGoods[3] = { 0,0,0 };



};
#endif