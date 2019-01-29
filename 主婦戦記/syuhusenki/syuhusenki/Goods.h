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
	COMBOMAX
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
	int addPrice(int num, int nomalOrSale);
	int comboSucceceCheck(void);
	void comboCheck(int goodsId1, int goodsId2, int goodsId3);
	void selectGoods(SALESMAN* popSales);

	int GetselectedGoods(int ArrayNum) {
		return selectedGoods[ArrayNum];
	}
	int SetselectedGoods(int ArrayNum,int Value) {
		return selectedGoods[ArrayNum] = Value;
	}

	
	int GetHaveValue(int ArrayNum) {
		return foodGoods[ArrayNum].haveValue;
	}
	GOODSPARAMETER* GetfoodGoods() {
		return foodGoods;
	}
	COMBOPARAMETER* GetfoodCombo() {
		return foodCombo;
	}
	void SetHaveValue(int ArrayNum, int Value) {
		foodGoods[ArrayNum].haveValue = Value;
	}
	int GetComboBonus(int ArrayNum) {
		return foodCombo[ArrayNum].comboBonus;
	}
	std::string GetFoodGoodsTexID(int ArrayNum) {
		return foodGoods[ArrayNum].textureID;
	}
	std::string GetFoodComboTexID(int ArrayNum) {
		return foodCombo[ArrayNum].textureID;
	}
	void AddHaveValue(int Add, int ArrayNum) {
		foodGoods[ArrayNum].haveValue += Add;
	}
	int GetnominalCost(int ArrayNum) {
		return foodGoods[ArrayNum].nominalCost;
	}
	int GetselePrice(int ArrayNum) {
		return foodGoods[ArrayNum].selePrice;
	}
	bool GetFoodComboSucceed(int ArrayNum) {
		return foodCombo[ArrayNum].comboSucceed;
	}

private:
	static GOODSPARAMETER foodGoods[GOODS_MAX];
	static COMBOPARAMETER foodCombo[COMBOMAX];

	int selectedGoods[3];



};
#endif