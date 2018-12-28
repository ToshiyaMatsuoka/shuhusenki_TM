#include "GameScene.h"



GameScene::GameScene(DirectX* pDirectX, SoundOperater* pSoundOperater) :Scene(pDirectX, pSoundOperater)
{

}

GameScene::~GameScene()
{
	m_pDirectX->ClearTexture();
	m_pDirectX->ClearFont();
}

SCENE_NUM GameScene::Update()
{
	return SCENE_NONE;
}

void GameScene::KeyOperation()
{
}

void GameScene::Render()
{
}

void GameScene::LoadResouce()
{
	m_pDirectX->LoadTexture("Texture/Blank.jpg", "BLANK");
	m_pDirectX->LoadTexture("Texture/Yasuko.png", "YASUKO_TEX");
	m_pDirectX->LoadTexture("Texture/Mituko.png", "MITUKO_TEX");
	m_pDirectX->LoadTexture("Texture/Isoko.png", "ISOKO_TEX");
	m_pDirectX->LoadTexture("Texture/mob.png", "MOB_TEX");

	m_pDirectX->LoadTexture("Texture/UI/frame_goods.png", "FRAME_TEX");
	m_pDirectX->LoadTexture("Texture/effect.png", "YASUKO_EFFECT_TEX");

	m_pDirectX->LoadTexture("Texture/FoodSection.png", "FOOD_STAGE_TEX");
	m_pDirectX->LoadTexture("Texture/maxresdefault.png", "CUTIN_TEX");
	m_pDirectX->LoadTexture("Texture/bakuhuhathu.png", "EXPLOSION_TEX");
	m_pDirectX->LoadTexture("Texture/yasukoCutin.png", "CUTIN_YASUKO_TEX");
	m_pDirectX->LoadTexture("Texture/UI/durabilityBar.jpg", "DURABILITY_TEX");
	m_pDirectX->LoadTexture("Texture/smoke.png", "SMOKE_TEX");
	m_pDirectX->LoadTexture("Texture/boy.png", "BOY_TEX");
	m_pDirectX->LoadTexture("Texture/salesclerk.png", "SALESMAN_TEX");

	m_pDirectX->LoadTexture("Texture/UI/timerFrame.png", "TIMER_FRAME_TEX");
	m_pDirectX->LoadTexture("Texture/UI/timerHand.png", "TIMER_HAND_TEX");
	m_pDirectX->LoadTexture("Texture/UI/startCount3.png", "STARTCOUNT_3_TEX");
	m_pDirectX->LoadTexture("Texture/UI/startCount2.png", "STARTCOUNT_2_TEX");
	m_pDirectX->LoadTexture("Texture/UI/startCount1.png", "STARTCOUNT_1_TEX");
	m_pDirectX->LoadTexture("Texture/UI/salerogo.png", "START_TEX");
	m_pDirectX->LoadTexture("Texture/pauseMenu.png", "PAUSE_TEX");
	m_pDirectX->LoadTexture("Texture/UI/end.png", "TIMEUP_TEX");
	m_pDirectX->LoadTexture("Texture/stage.png", "FLOAMOVE_BG_TEX");

	m_pDirectX->LoadTexture("Texture/scoretext/s50e.png", "FIFTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s60e.png", "SIXTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s65e.png", "SIXTYFIVE_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s100e.png", "HUNDRED_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s150e.png", "HUNDREDFIFTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s200e.png", "TWEHANDRED_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s250e.png", "TWEHANDREDFIFTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/s300e.png", "THREEHANDRED_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss30e.png", "S_THRTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss40e.png", "S_FOURTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss50e.png", "S_FIFTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss60e.png", "S_SIXTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss70e.png", "S_SEVENTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss80e.png", "S_EIGHTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss100e.png", "S_HUNDRED_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss150e.png", "S_HUNDREDFIFTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss180e.png", "S_HUNDREDEIGHTY_TEX");
	m_pDirectX->LoadTexture("Texture/scoretext/ss200e.png", "S_TWEHUNDRED_TEX");

	m_pDirectX->LoadTexture("Texture/scoretext/t1.png", "T_1");
	m_pDirectX->LoadTexture("Texture/scoretext/t2.png", "T_2");
	m_pDirectX->LoadTexture("Texture/scoretext/t3.png", "T_3");
	m_pDirectX->LoadTexture("Texture/scoretext/t4.png", "T_4");
	m_pDirectX->LoadTexture("Texture/scoretext/t5.png", "T_5");

	m_pDirectX->LoadTexture("Texture/button/a.png", "A_TEX");
	m_pDirectX->LoadTexture("Texture/button/b.png", "B_TEX");
	m_pDirectX->LoadTexture("Texture/button/x.png", "X_TEX");
	m_pDirectX->LoadTexture("Texture/button/y.png", "Y_TEX");
	m_pDirectX->LoadTexture("Texture/button/r.png", "R_TEX");
	m_pDirectX->LoadTexture("Texture/button/l.png", "L_TEX");
	m_pDirectX->LoadTexture("Texture/button/button.png", "NULL_BUTTON_TEX");

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

}
