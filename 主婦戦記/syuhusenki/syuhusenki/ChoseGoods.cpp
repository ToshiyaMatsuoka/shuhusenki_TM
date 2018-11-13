#include "Main.h"
#include "FloaMove.h"
#include "GameMain.h"
#include "Goods.h"
#include "Timer.h"
#include "ChoseGoods.h"


int salesChoice;

void choseGoods() {
	if (g_isGameStart)
	{
		choseGoodsControl();
	}
	choseGoodsReader();
}
void choseGoodsControl() {

	timerControl();

	CheckKeyState(DIK_RETURN);
	CheckKeyState(DIK_NUMPADENTER);
	CheckKeyState(DIK_Q);
	CheckKeyState(DIK_E);
	if (KeyState[DIK_Q] == KeyRelease)
	{
		selectedGoods[g_turn] = popSales[salesChoice].merchandise[0];
		g_gameScene = PUSHENEMY;
	}
	if (KeyState[DIK_E] == KeyRelease)
	{
		selectedGoods[g_turn] = popSales[salesChoice].merchandise[1];
		g_gameScene = PUSHENEMY;
	}

	GetControl(0);
	BottonCheck();
	if (PadState[ButtonA] == PadRelease)
	{

	}
	if (PadState[ButtonB] == PadRelease)
	{
		selectedGoods[g_turn] = popSales[salesChoice].merchandise[1];
		g_gameScene = PUSHENEMY;
	}
	if (PadState[ButtonX] == PadRelease)
	{
		selectedGoods[g_turn] = popSales[salesChoice].merchandise[0];
		g_gameScene = PUSHENEMY;
	}

}
void choseGoodsReader() {

	CUSTOMVERTEX effectPC[4];
	CENTRAL_STATE effectCentral = { playerCentralHit.x - 2,playerCentralHit.y - 14,playerCentralHit.scaleX*2.03f,playerCentralHit.scaleY*1.4f };

	BeginSetTexture();
	CreateSquareVertex(playerHit, playerCentralHit, WHITE, 0, 0, YASUKO_TU, YASUKO_TV);
	CreateSquareVertex(effectPC, effectCentral, WHITE, (effectCount * EFFECT_TU), 0, EFFECT_TU, EFFECT_TV);

	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, "FLOAMOVE_BG_TEX");

	EasyCreateSquareVertexColor(0, 0, WIDTH, HEIGHT, "BLANK", HARFCLEAR);

	for (int i = 0; i < 5; i++) {
		CreateSquareVertex(mobFloa, mobCentralBlowOff[i],0, 0, MOB_TU, MOB_TV);
		SetUpTexture(mobFloa, mobTexNum);
	}

	SetUpTexture(effectPC, "YASUKO_EFFECT_TEX");
	SetUpTexture(playerHit, texturePC);
	EasyCreateSquareVertex(350, 150, 600, 400, foodGoods[popSales[salesChoice].merchandise[0]].textureID);
	EasyCreateSquareVertex(660, 150, 910, 400, foodGoods[popSales[salesChoice].merchandise[1]].textureID);
	EasyCreateSquareVertex(350, 350, 600, 500, "X_TEX");
	EasyCreateSquareVertex(660, 350, 910, 500, "B_TEX");

	goodsScoreShow();
	timerRender();
	EndSetTexture();

}
