#include "ResultScene.h"
#include "Goods.h"



ResultScene::ResultScene(DirectX* pDirectX, SoundOperater* pSoundOperater) :Scene(pDirectX, pSoundOperater)
{
	comboCheck(selectedGoods[0], selectedGoods[1], selectedGoods[2]);
	succeedCombo = comboSucceceCheck();


	if (selectedGoods[0] == selectedGoods[1] && selectedGoods[0] == selectedGoods[2]) {
		foodGoods[selectedGoods[0]].haveValue = (foodGoods[selectedGoods[0]].haveValue / 3);
	}
	else if (selectedGoods[0] == selectedGoods[1] || selectedGoods[0] == selectedGoods[2]) {
		foodGoods[selectedGoods[0]].haveValue = (foodGoods[selectedGoods[0]].haveValue / 2);
	}
	else if (selectedGoods[1] == selectedGoods[2]) {
		foodGoods[selectedGoods[1]].haveValue = (foodGoods[selectedGoods[1]].haveValue / 2);
	}

	for (int i = 0; i < 3; i++)
	{
		nomalSum += addPrice(i, 0);
		saleSale += addPrice(i, 1);
	}
	memset(apperText, false, 10);

}


ResultScene::~ResultScene()
{
	m_pDirectX->ClearTexture();
	m_pDirectX->ClearFont();

}

int ResultScene::Update()
{
	m_pXinputDevice->DeviceUpdate();
	++resultCounter;
	ApperResult(&resultCounter);

	if ((GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonA) == PadRelease))
	{

		switch (resultPage)
		{
		case PAGE1:
			m_pSoundOperater->Start("DRUM", false);
			SyncOld = timeGetTime();

			resultPage = PAGE2;
			break;
		case PAGE2:
		{
			resultPage = PAGE3;
			break;
		}
		case PAGE3:
			if (cursorResult.y < 500) {
				return  GAME_SCENE;
			}
			else return TITLE_SCENE;
			break;
		}
	}
#ifdef _DEBUG

	if (m_pDirectX->GetKeyStatus(DIK_SPACE) == KeyRelease)
	{
		//g_scene = SCENE_TITLE;
	}
#endif

	if (resultPage == PAGE3) {
		if (m_pDirectX->GetKeyStatus(DIK_W) == KeyRelease)
		{
			m_pSoundOperater->Stop("CURSOR");
			m_pSoundOperater->Start("CURSOR", false);
			cursorResult.y = 490;
		}
		if (m_pDirectX->GetKeyStatus(DIK_S) == KeyRelease)
		{
			m_pSoundOperater->Stop("CURSOR");
			m_pSoundOperater->Start("CURSOR", false);
			cursorResult.y = 560;

		}
		if (m_pXinputDevice->GetButton(ButtonUP) == PadRelease)
		{
			m_pSoundOperater->Stop("CURSOR");
			m_pSoundOperater->Start("CURSOR", false);
			cursorResult.y = 490;

		}

		if (m_pXinputDevice->GetButton(ButtonDOWN) == PadRelease)
		{
			m_pSoundOperater->Stop("CURSOR");
			m_pSoundOperater->Start("CURSOR", false);
			cursorResult.y = 560;

		}
		if (m_pXinputDevice->GetAnalogL(ANALOGDOWN))
		{
			m_pSoundOperater->Stop("CURSOR");
			m_pSoundOperater->Start("CURSOR", false);
			cursorResult.y = 490;

		}

		if (m_pXinputDevice->GetAnalogL(ANALOGUP))
		{
			m_pSoundOperater->Stop("CURSOR");
			m_pSoundOperater->Start("CURSOR", false);
			cursorResult.y = 560;

		}

	}

	return SCENE_NONE;
}

void ResultScene::KeyOperation()
{
}

void ResultScene::Render()
{
	static bool canSound = true;
	switch (resultPage)
	{
	case PAGE1:
		resultRenderOne();
		showPressA();
		break;
	case PAGE2:
	{
		SyncNow = timeGetTime();

		resultRenderOne();
		if (SyncNow - SyncOld > 3000)
		{
			resultRenderTwo();
			if (canSound)
			{
				canSound = false;
				if ((nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) < LOW_SCORE)
				{
					m_pSoundOperater->Start("LOW_SCORE", false);
				}
				if (LOW_SCORE <= (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) && (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) <= HIGH_SCORE)
				{
					m_pSoundOperater->Start("MIDLE_SCORE", false);

				}
				if (HIGH_SCORE < (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus))
				{
					m_pSoundOperater->Start("HIGH_SCORE", false);

				}
			}
		}
	}
	showPressA();
	break;
	case PAGE3:
		canSound = true;
		resultRenderOne();
		resultRenderTwo();
		resultRenderThree();
	}

}

void ResultScene::resultRenderOne(void)
{
	CUSTOMVERTEX result[4];

	CreateSquareVertex(result, DISPLAY_WIDTH, 700);
	m_pDirectX->DrawTexture("RESULT_BG_TEX", result);

	CUSTOMVERTEX resultBaseTex1[4];
	CUSTOMVERTEX resultBaseTex2[4];
	CUSTOMVERTEX resultBaseTex3[4];
	CUSTOMVERTEX resultSeleTex1[4];
	CUSTOMVERTEX resultSeleTex2[4];
	CUSTOMVERTEX resultSeleTex3[4];
	CUSTOMVERTEX resultComboTex[4];
	CUSTOMVERTEX saleTResultTex[4];
	CUSTOMVERTEX nomalTResultTex[4];
	CUSTOMVERTEX comboTResultTex[4];
	CUSTOMVERTEX comboStarResultTex[4];
	CUSTOMVERTEX comboTextResultTex[4];


	CreateSquareVertex(saleTResultTex, &saleTResult);
	CreateSquareVertex(nomalTResultTex, &nomalTResult);
	CreateSquareVertex(comboTResultTex, &comboTResult);
	CreateSquareVertex(comboStarResultTex, &comboStarResult);

	CreateSquareVertex(resultBaseTex1, &BaseTexCentral1);
	CreateSquareVertex(resultBaseTex2, &BaseTexCentral2);
	CreateSquareVertex(resultBaseTex3, &BaseTexCentral3);
	CreateSquareVertex(resultSeleTex1, &SeleTexCentral1);
	CreateSquareVertex(resultSeleTex2, &SeleTexCentral2);
	CreateSquareVertex(resultSeleTex3, &SeleTexCentral3);
	CreateSquareVertex(resultComboTex, &comboTexCentral);
	CreateSquareVertex(comboTextResultTex, &comboTextResult);

	m_pDirectX->DrawTexture("RESULT_SALE_TEX", saleTResultTex);
	m_pDirectX->DrawTexture("RESULT_NOMAL_TEX", nomalTResultTex);
	m_pDirectX->DrawTexture("RESULT_COMBO_TEX", comboTResultTex);



	char resulttantValue[32];
	if (apperText[0])
	{
		m_pDirectX->DrawTexture(foodGoods[selectedGoods[0]].textureID, resultBaseTex1);
		sprintf_s(resulttantValue, 32, "%d~%d=%d", foodGoods[selectedGoods[0]].nominalCost, foodGoods[selectedGoods[0]].haveValue, addPrice(0, 0));
		RECT resultBase1{ 160,125,600,275 };
		m_pDirectX->DrawWord( resultBase1, resulttantValue, "RESULT_FONT", DT_LEFT, BLACK);

		m_pDirectX->DrawTexture( foodGoods[selectedGoods[0]].textureID, resultSeleTex1);
		sprintf_s(resulttantValue, 32, "%d~%d=%d", foodGoods[selectedGoods[0]].selePrice, foodGoods[selectedGoods[0]].haveValue, addPrice(0, 1));
		RECT resultSele1{ 930,125,1240,275 };
		m_pDirectX->DrawWord( resultSele1, resulttantValue, "RESULT_FONT", DT_LEFT, BLACK);
	}
	if (apperText[1])
	{
		m_pDirectX->DrawTexture( foodGoods[selectedGoods[1]].textureID, resultBaseTex2);
		sprintf_s(resulttantValue, 32, "%d~%d=%d", foodGoods[selectedGoods[1]].nominalCost, foodGoods[selectedGoods[1]].haveValue, addPrice(1, 0));
		RECT resultBase2{ 160,225,600,275 };
		m_pDirectX->DrawWord( resultBase2, resulttantValue, "RESULT_FONT", DT_LEFT, BLACK);
		m_pDirectX->DrawTexture(foodGoods[selectedGoods[1]].textureID, resultSeleTex2);
		sprintf_s(resulttantValue, 32, "%d~%d=%d", foodGoods[selectedGoods[1]].selePrice, foodGoods[selectedGoods[1]].haveValue, addPrice(1, 1));
		RECT resultSele2{ 930,225,1240,275 };
		m_pDirectX->DrawWord( resultSele2, resulttantValue, "RESULT_FONT", DT_LEFT, BLACK);
	}
	if (apperText[2])
	{
		m_pDirectX->DrawTexture( foodGoods[selectedGoods[2]].textureID, resultBaseTex3);
		sprintf_s(resulttantValue, 32, "%d~%d=%d", foodGoods[selectedGoods[2]].nominalCost, foodGoods[selectedGoods[2]].haveValue, addPrice(2, 0));
		RECT resultBase3{ 160,325,600,475 };
		m_pDirectX->DrawWord( resultBase3, resulttantValue, "RESULT_FONT", DT_LEFT, BLACK);
		m_pDirectX->DrawTexture( foodGoods[selectedGoods[2]].textureID, resultSeleTex3);
		sprintf_s(resulttantValue, 32, "%d~%d=%d", foodGoods[selectedGoods[2]].selePrice, foodGoods[selectedGoods[2]].haveValue, addPrice(2, 1));
		RECT resultSele3{ 930,325,1240,475 };
		m_pDirectX->DrawWord( resultSele3, resulttantValue, "RESULT_FONT", DT_LEFT, BLACK);
	}
	if (apperText[3])
	{

		sprintf_s(resulttantValue, 32, "‡Œv%d‰~", nomalSum);
		RECT resultBaseTotal{ 160,425,440,575 };
		m_pDirectX->DrawWord( resultBaseTotal, resulttantValue, "RESULT_FONT", DT_RIGHT, BLACK);
		sprintf_s(resulttantValue, 32, "‡Œv%d‰~", saleSale);
		RECT resultSeleTotal{ 930,425,1240,575 };
		m_pDirectX->DrawWord( resultSeleTotal, resulttantValue, "RESULT_FONT", DT_RIGHT, BLACK);

	}
	if (apperText[4])
	{
		sprintf_s(resulttantValue, 32, "%d-%d=%d", nomalSum, saleSale, nomalSum - saleSale);
		RECT resultTotal{ 100,525,1180,700 };
		m_pDirectX->DrawWord( resultTotal, resulttantValue, "SCORE_FONT", DT_CENTER, BLACK);
	}
	if (apperText[5])
	{

		m_pDirectX->DrawTexture(foodCombo[succeedCombo].textureID, resultComboTex);

		switch (foodCombo[succeedCombo].comboBonus)
		{
		case RARE1:
			m_pDirectX->DrawTexture("RESULT_STAR1_TEX", comboStarResultTex);
			m_pDirectX->DrawTexture( "RESULT_COMBOTEXT1_TEX", comboTextResultTex);
			break;
		case RARE2:
			m_pDirectX->DrawTexture("RESULT_STAR2_TEX", comboStarResultTex);
			m_pDirectX->DrawTexture("RESULT_COMBOTEXT2_TEX", comboTextResultTex);
			break;
		case RARE3:
			m_pDirectX->DrawTexture("RESULT_STAR3_TEX", comboStarResultTex);
			m_pDirectX->DrawTexture("RESULT_COMBOTEXT3_TEX", comboTextResultTex);
			break;
		}

	}
}

void ResultScene::resultRenderTwo(void)
{
	CUSTOMVERTEX result[4];
	CreateSquareVertex(result,DISPLAY_WIDTH, DISPLAY_HEIGHT, HARFCLEAR);
	m_pDirectX->DrawTexture("BLANK", result);

	CreateSquareVertex(result,DISPLAY_WIDTH, DISPLAY_HEIGHT);
	m_pDirectX->DrawTexture("RESULT_POP_TEX", result);

	char resulttantValue[32];
	sprintf_s(resulttantValue, 32, "%d", nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus);
	RECT resultTotal{ 0,235,435,400 };
	m_pDirectX->DrawWord( resultTotal,resulttantValue, "LAST_SCORE_FONT", DT_RIGHT, BLACK);
	CENTRAL_STATE resultPC{ 1050,350,200,300 };
	CreateSquareVertex(result, &resultPC);
	if ((nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) < LOW_SCORE)
	{
		m_pDirectX->DrawTexture("YASUKO_EMOTION3_TEX", result);
	}
	if (LOW_SCORE <= (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) && (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus) <= HIGH_SCORE)
	{
		m_pDirectX->DrawTexture("YASUKO_EMOTION2_TEX", result);
	}
	if (HIGH_SCORE < (nomalSum - saleSale + foodCombo[comboSucceceCheck()].comboBonus))
	{
		m_pDirectX->DrawTexture("YASUKO_EMOTION1_TEX", result);
	}

}

void ResultScene::resultRenderThree(void)
{
	CUSTOMVERTEX cursor[4];
	CreateSquareVertex(cursor,50.f, 450.f, 500.f, 600.f);
	m_pDirectX->DrawTexture("RESULT_END_TEX", cursor);
	CreateSquareVertex(cursor, &cursorResult, m_Color);

	m_pDirectX->DrawTexture( "TITLEICON_TEX", cursor);
}

void ResultScene::LoadResouce()
{
	m_pDirectX->LoadTexture("Texture/button/a.png", "A_TEX");
	m_pDirectX->LoadTexture("Texture/UI/arrow.png", "TITLEICON_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/beef.png", "BEEF_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/chicken.png", "CHICKEN_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/pork.png", "PORK_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/wiener.png", "VIENNESE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/mince.png", "MINCE_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/shrimp.png", "SHRIMP_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/octopus.png", "OCTOPUS_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/squid.png", "INKFISH_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/fish.png", "FISH_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/carrot.png", "GINESENG_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/onion.png", "ONION_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/potato.png", "POTATO_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/tomato.png", "TOMATO_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/radish.png", "RADISH_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/snack.png", "POTATOCHIPS_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/choco.png", "CHOCOLATE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/ice.png", "ICE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/ricecracker.png", "RICECRACKER_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/apple.png", "APPLE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/orange.png", "ORANGE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/banana.png", "BANANA_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/tea.png", "TEA_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/juice.png", "JUICE_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/beer.png", "BEER_TEX");

	m_pDirectX->LoadTexture("Texture/result/result.png", "RESULT_BG_TEX");
	m_pDirectX->LoadTexture("Texture/result/resultLast.png", "RESULT_POP_TEX");
	m_pDirectX->LoadTexture("Texture/result/R_UI.png", "RESULT_END_TEX");
	m_pDirectX->LoadTexture("Texture/result/star1.png", "RESULT_STAR1_TEX");
	m_pDirectX->LoadTexture("Texture/result/star2.png", "RESULT_STAR2_TEX");
	m_pDirectX->LoadTexture("Texture/result/star3.png", "RESULT_STAR3_TEX");
	m_pDirectX->LoadTexture("Texture/result/point100.png", "RESULT_COMBOTEXT1_TEX");
	m_pDirectX->LoadTexture("Texture/result/point300.png", "RESULT_COMBOTEXT2_TEX");
	m_pDirectX->LoadTexture("Texture/result/point500.png", "RESULT_COMBOTEXT3_TEX");
	m_pDirectX->LoadTexture("Texture/result/bonus.png", "RESULT_COMBO_TEX");
	m_pDirectX->LoadTexture("Texture/result/SALE.png", "RESULT_SALE_TEX");
	m_pDirectX->LoadTexture("Texture/result/price.png", "RESULT_NOMAL_TEX");
	m_pDirectX->LoadTexture("Texture/yasuko_motion1.png", "YASUKO_EMOTION1_TEX");
	m_pDirectX->LoadTexture("Texture/yasuko_motion2.png", "YASUKO_EMOTION2_TEX");
	m_pDirectX->LoadTexture("Texture/yasuko_motion3.png", "YASUKO_EMOTION3_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/buridaikon.png", "BURIDAIKON_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/tsumami.png", "RELISH_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/teatime.png", "TEATIME_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/curry.png", "CURRY_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/hamberg.png", "HAMBERG_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/sashimi.png", "ASSORTEDSASHIMI_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/oyatsu.png", "AFTERNOONREFRESHMENT_TEX");

	m_pDirectX->LoadTexture("Texture/merchandise/soup.png", "SOUP_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/nimono.png", "NIMONO_TEX");
	m_pDirectX->LoadTexture("Texture/merchandise/parfait.png", "PARFAIT_TEX");

	m_pDirectX->SetFont(25, 20, "RESULT_FONT");
	m_pDirectX->SetFont(70, 50, "SCORE_FONT");
	m_pDirectX->SetFont(120, 75, "LAST_SCORE_FONT");

}

void ResultScene::PageOneKeyOperation()
{
	if (GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonA) == PadRelease)
	{
		m_pSoundOperater->Start("DRUM", false);
		SyncOld = timeGetTime();

		resultPage = PAGE2;
	}

}

void ResultScene::PageTwoKeyOperation()
{
	if (GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonA) == PadRelease)
	{
			resultPage = PAGE3;
	}

}

void ResultScene::PageThreeKeyOperation()
{
	if (GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonA) == PadRelease)
	{
			if (cursorResult.y < 500) {
				SetNextScene(GAME_SCENE);
			}
			else SetNextScene(TITLE_SCENE);
	}

	if (m_pDirectX->GetKeyStatus(DIK_W) == KeyRelease)
	{
		m_pSoundOperater->Stop("CURSOR");
		m_pSoundOperater->Start("CURSOR", false);
		cursorResult.y = 490;
	}
	if (m_pDirectX->GetKeyStatus(DIK_S) == KeyRelease)
	{
		m_pSoundOperater->Stop("CURSOR");
		m_pSoundOperater->Start("CURSOR", false);
		cursorResult.y = 560;

	}
	if (m_pXinputDevice->GetButton(ButtonUP) == PadRelease)
	{
		m_pSoundOperater->Stop("CURSOR");
		m_pSoundOperater->Start("CURSOR", false);
		cursorResult.y = 490;

	}

	if (m_pXinputDevice->GetButton(ButtonDOWN) == PadRelease)
	{
		m_pSoundOperater->Stop("CURSOR");
		m_pSoundOperater->Start("CURSOR", false);
		cursorResult.y = 560;

	}
	if (PadOn == m_pXinputDevice->GetAnalogLState(ANALOGDOWN))
	{
		m_pSoundOperater->Stop("CURSOR");
		m_pSoundOperater->Start("CURSOR", false);
		cursorResult.y = 490;

	}

	if (PadOn == m_pXinputDevice->GetAnalogLState(ANALOGUP))
	{
		m_pSoundOperater->Stop("CURSOR");
		m_pSoundOperater->Start("CURSOR", false);
		cursorResult.y = 560;

	}

}

void ResultScene::ApperResult(int* resultCounter)
{
	
	if (*resultCounter == 30) {
		apperText[0] = true;
		m_pSoundOperater->Start("COIN1", false);
	}
	if (*resultCounter == 60) {
		apperText[1] = true;
		m_pSoundOperater->Start("COIN2", false);
	}
	if (*resultCounter == 90) {
		apperText[2] = true;
		m_pSoundOperater->Start("COIN3", false);
	}
	if (*resultCounter == 120) {
		apperText[3] = true;
		m_pSoundOperater->Start("COIN4", false);
	}
	if (*resultCounter == 150) {
		apperText[4] = true;
		m_pSoundOperater->Start("CASHER", false);
	}
	if ((*resultCounter == 180) && (foodCombo[succeedCombo].comboSucceed)) {
		apperText[5] = true;
		m_pSoundOperater->Start("WIN", false);
	}

}
