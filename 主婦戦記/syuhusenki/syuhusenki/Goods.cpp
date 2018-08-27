#include "Goods.h"
#include "Main.h"

GOODSPARAMETER foodGoods[GOODS_MAX]
{
{BLANKGOODS,0,0,0},
//��
{ BEEF,300,200,0 },
{ PORK,200,150,0 },
{ CHICKEN,100,80,0 },
{ VIENNESE,200,100,0 },
{ MINCE,150,100,0 },
//��
{ SHRIMP,250,200,0 },
{ OCTOPUS,300,180,0 },
{ INKFISH,200,180,0 },
{ FISH,200,150,0 },
//���
{ GINESENG,50,30,0 },
{ ONION,60,40,0 },
{ POTATO,65,40,0 },
{ TOMATO,100,50,0 },
{ RADISH,200,150,0 },
//���َq
{ POTATOCHIPS,100,80,0 },
{ CHOCOLATE,100,50,0 },
{ ICE,150,50,0 },
{ RICECRACKER,100,60,0 },
//�ʕ�
{ APPLE,100,80,0 },
{ ORANGE,200,150,0 },
{ BANANA, 100,80,0 },
//���ݕ�
{ TEA,100,70,0 },
{ JUICE,150,80,0 },
{ BEER,200,100,0 },

{ MEET,0,0,0 },
{ FRUIT,0,0,0 },

};

COMBOPARAMETER foodCombo[COMBOMAX]{
{ BURIDAIKON,RARE1, FISH,RADISH,false },
{ RELISH,RARE1,BEER,VIENNESE ,false },
{ TEATIME, RARE1, TEA, RICECRACKER ,false },
{ CURRY, RARE2, POTATO, ONION, MEET,false },
{ HAMBERG, RARE2, MINCE, ONION, GINESENG ,false },
{ ASSORTEDSASHIMI, RARE2, SHRIMP, OCTOPUS, INKFISH ,false },
{ AFTERNOONREFRESHMENT,RARE2,ICE,JUICE,FRUIT,false },
{ SOUP,RARE3,VIENNESE,TOMATO,ONION ,false },
{ NIMONO,RARE3,RADISH,FISH,OCTOPUS ,false },
{ PARFAIT,RARE3,ICE,FRUIT,FRUIT,false },
};

struct COMBO_OK {
	bool one;
	bool twe;
	bool three;
};
COMBO_OK checkOk{false,false,false};
void comboCheck(int goodsId1, int goodsId2, int goodsId3 )
{
	if (foodGoods[goodsId1].haveValue)
	{
		for (int i = 0; i < COMBOMAX; i++) {
			checkOk.one = false;
			checkOk.twe = false;
			checkOk.three = false;
			//1�ڂ̃`�F�b�N
			//��ꍀ��
			if (foodGoods[goodsId1].goodsID == foodCombo[i].comboElement1 && (!checkOk.one))
			{
				checkOk.one = true; 
			}
			//��񍀖�
			else if (foodCombo[i == PARFAIT].comboElement2 == FRUIT && foodCombo[i== PARFAIT].comboElement3 == FRUIT && (!checkOk.twe))
			{
				if (foodGoods[goodsId1].goodsID == APPLE)
				{
					checkOk.twe = true; 
				}
				if (foodGoods[goodsId1].goodsID == ORANGE)
				{
					checkOk.twe = true; 
				}
				if (foodGoods[goodsId1].goodsID == BANANA)
				{
					checkOk.twe = true; 
				}
			}
			else if (foodGoods[goodsId1].goodsID == foodCombo[i].comboElement2 && (!checkOk.twe))
			{
				checkOk.twe = true; 
			}
			//��O����
			else if (foodCombo[i].comboElement3 == MEET && (!checkOk.three))
			{
				if (foodGoods[goodsId1].goodsID == BEEF)
				{
					checkOk.three = true; 
				}
				if (foodGoods[goodsId1].goodsID == PORK)
				{
					checkOk.three = true; 
				}
				if (foodGoods[goodsId1].goodsID == CHICKEN)
				{
					checkOk.three = true; 
				}

			}
			else if (foodCombo[i].comboElement3 == FRUIT && (!checkOk.three))
			{
				if (foodGoods[goodsId1].goodsID == APPLE)
				{
					checkOk.three = true; 
				}
				if (foodGoods[goodsId1].goodsID == ORANGE)
				{
					checkOk.three = true; 
				}
				if (foodGoods[goodsId1].goodsID == BANANA)
				{
					checkOk.three = true; 
				}
			}
			else if (foodGoods[goodsId1].goodsID == foodCombo[i].comboElement3 && (!checkOk.three))
			{

				checkOk.three = true; 
			}
			//2�ڂ̃`�F�b�N
			//��ꍀ��
			if (foodGoods[goodsId2].haveValue)
			{
				if (foodGoods[goodsId2].goodsID == foodCombo[i].comboElement1 && (!checkOk.one))
				{
					checkOk.one = true; 
				}
				//��񍀖�
				if (foodCombo[i == PARFAIT].comboElement2 == FRUIT && foodCombo[i == PARFAIT].comboElement3 == FRUIT && (!checkOk.twe))
				{
					if (foodGoods[goodsId2].goodsID == APPLE)
					{
						checkOk.twe = true; 
					}
					if (foodGoods[goodsId2].goodsID == ORANGE)
					{
						checkOk.twe = true; 
					}
					if (foodGoods[goodsId2].goodsID == BANANA)
					{
						checkOk.twe = true; 
					}
				}
				else if (foodGoods[goodsId2].goodsID == foodCombo[i].comboElement2 && (!checkOk.twe))
				{

					checkOk.twe = true; 
				}
				//��O����
				if (foodCombo[i].comboElement3 == MEET && (!checkOk.three))
				{
					if (foodGoods[goodsId2].goodsID == BEEF)
					{
						checkOk.three = true; 
					}
					if (foodGoods[goodsId2].goodsID == PORK)
					{
						checkOk.three = true; 
					}
					if (foodGoods[goodsId2].goodsID == CHICKEN)
					{
						checkOk.three = true; 
					}
				}
				else if (foodCombo[i].comboElement3 == FRUIT && (!checkOk.three))
				{
					if (foodGoods[goodsId2].goodsID == APPLE)
					{
						checkOk.three = true; 
					}
					if (foodGoods[goodsId2].goodsID == ORANGE)
					{
						checkOk.three = true; 
					}
					if (foodGoods[goodsId2].goodsID == BANANA)
					{
						checkOk.three = true; 
					}
				}
				else if (foodGoods[goodsId2].goodsID == foodCombo[i].comboElement3 && (!checkOk.three))
				{
					checkOk.three = true; 
				}
			}

			//3�ڂ̃`�F�b�N
			//��ꍀ��
			if (goodsId3 != BLANKGOODS && foodGoods[goodsId3].haveValue)
			{
				if (foodGoods[goodsId3].goodsID == foodCombo[i].comboElement1 && (!checkOk.one))
				{
					checkOk.one = true; 
				}
				//��񍀖�
				if (foodCombo[i == PARFAIT].comboElement2 == FRUIT && foodCombo[i == PARFAIT].comboElement3 == FRUIT && (!checkOk.twe))
				{
					if (foodGoods[goodsId3].goodsID == APPLE)
					{
						checkOk.twe = true; 
					}
					if (foodGoods[goodsId3].goodsID == ORANGE)
					{
						checkOk.twe = true; 
					}
					if (foodGoods[goodsId3].goodsID == BANANA)
					{
						checkOk.twe = true; 
					}
				}
				else if (foodGoods[goodsId3].goodsID == foodCombo[i].comboElement2 && (!checkOk.twe))
				{
					checkOk.twe = true; 
				}
				//��O����
				if (foodCombo[i].comboElement3 == MEET && (!checkOk.three))
				{
					if (foodGoods[goodsId3].goodsID == BEEF)
					{
						checkOk.three = true; 
					}
					if (foodGoods[goodsId3].goodsID == PORK)
					{
						checkOk.three = true; 
					}
					if (foodGoods[goodsId3].goodsID == CHICKEN)
					{
						checkOk.three = true; 
					}
				}
				else if (foodCombo[i].comboElement3 == FRUIT && (!checkOk.three))
				{
					if (foodGoods[goodsId3].goodsID == APPLE)
					{
						checkOk.three = true; 
					}
					if (foodGoods[goodsId3].goodsID == ORANGE)
					{
						checkOk.three = true; 
					}
					if (foodGoods[goodsId3].goodsID == BANANA)
					{
						checkOk.three = true; 
					}

				}
				else if (foodGoods[goodsId3].goodsID == foodCombo[i].comboElement3 && (!checkOk.three))
				{
					
					checkOk.three = true; 
				}
			}
			else if (goodsId3 == BLANKGOODS) {
				checkOk.three = true;
			}
			if (checkOk.one && checkOk.twe && checkOk.three)
			{
				foodCombo[i].comboSucceed = true;
				g_SoundSuccess = soundsManager.Start("SUCCESS", false) && g_SoundSuccess;
			}
			else if (!checkOk.one || !checkOk.twe || !checkOk.three) {
				g_SoundSuccess = soundsManager.Start("MISS", false) && g_SoundSuccess;
			}
		}
	}
}