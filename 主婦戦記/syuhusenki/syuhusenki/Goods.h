#ifndef GOODS_H
#define GOODS_H

enum GOODSNUMBER {
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
	GOODS_MAX
};

enum COMBOMEUE {
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
	CONBOMAX
};

struct GOODSPARAMETER {
	const int goodsID;
	const int nominalCost;
	const int selePrice;
	int haveValue;
};

struct COMBOPARAMETER {
	const int comboID;
	const int comboBonus;
	const int comboElement1;
	const int comboElement2;
	const int comboElement3;
};

//��
extern GOODSPARAMETER beef;
extern GOODSPARAMETER pork;
extern GOODSPARAMETER chicken;
extern GOODSPARAMETER viennese;
extern GOODSPARAMETER mince;
//��
extern GOODSPARAMETER shrimp;
extern GOODSPARAMETER octopus;
extern GOODSPARAMETER inkfish;
extern GOODSPARAMETER fish;
//���
extern GOODSPARAMETER ginseng;
extern GOODSPARAMETER onion;
extern GOODSPARAMETER potato;
extern GOODSPARAMETER tomato;
extern GOODSPARAMETER radish;
//���َq
extern GOODSPARAMETER potatoChips;
extern GOODSPARAMETER chocolate;
extern GOODSPARAMETER ice;
extern GOODSPARAMETER riceCracker;
//�ʕ�
extern GOODSPARAMETER apple;
extern GOODSPARAMETER orange;
extern GOODSPARAMETER banana;
//���ݕ�
extern GOODSPARAMETER tea;
extern GOODSPARAMETER juice;
extern GOODSPARAMETER beer;



#endif