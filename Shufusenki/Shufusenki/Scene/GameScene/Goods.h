#ifndef GOODS_H
#define GOODS_H
/**
* @file Goods.h
* @brief 売り物処理
* @author Toshiya Matsuoka
*/

#include "GameManager/GameManager.h"
#include "Object.h"

namespace COMBO_RARE {
	const int RARE1 = 100;
	const int RARE2 = 300;
	const int RARE3 = 500;
}

//! 商品管理ID
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

//! コンボ料理ID
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

//! 商品の種別
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

//! 商品情報
struct GOODSPARAMETER 
{
	const int goodsID;
	std::string textureID;
	const int nominalCost;
	const int selePrice;
	int haveValue;

};
//! コンボ料理情報
struct COMBOPARAMETER 
{
	const int comboID;
	std::string textureID;
	const int comboBonus;
	//! 要素1
	const int comboElement1;
	//! 要素2
	const int comboElement2;
	//! 要素3
	const int comboElement3;
	bool comboSucceed;
};


class Goods :public Object
{
public:
	Goods(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~Goods();
	void Initialize();

	/**
	* @brief 商品の所持数＊値段を返す
	* @param num 何番目に選択した商品か
	* @param isNomal 欲しいのは定価か否か
	* @return 商品の所持数＊値段
	*/
	int AddPrice(int num, bool isNomal);

	/**
	* @brief コンボが成立したか確認し、成立したコンボIDを返す
	* @return 成立したコンボID
	*/
	int ComboSucceceCheck();

	/**
	* @brief 3つの商品の組み合わせがコンボとなるか照合する
	* @param goodsId1 1つ目の商品ID
	* @param goodsId2 2つ目の商品ID
	* @param goodsId3 3つ目の商品ID
	* @details 成立したか否かの結果はm_FoodComboのメンバに保存する
	*/
	void ComboCheck(int goodsId1, int goodsId2, int goodsId3);

	/**
	* @brief 売り子の商品種別から商品を選択する
	* @param popSales 売り子
	*/
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