#include "SubScene.h"

int SubScene::m_GameScene = FLOAMOVE;
CENTRAL_STATE SubScene::mobCentralBlowOff[5];

SubScene::SubScene(DirectX * pDirectX, SoundOperater * pSoundOperater, int turn, Yasuko* pYasuko) :Scene(pDirectX, pSoundOperater),m_Turn(turn)
{
	m_pYasuko = pYasuko;
}


SubScene::~SubScene()
{
}

void SubScene::Finalize() {
	m_GameScene = FLOAMOVE;

}


std::string SubScene::comandButtonTexture(int comand)
{
	switch (comand) {
	case ButtonA:
		return "A_TEX";
	case ButtonB:
		return"B_TEX";
	case ButtonX:
		return "X_TEX";
	case ButtonY:
		return"Y_TEX";
	case ButtonRB:
		return"R_TEX";
	case ButtonLB:
		return "L_TEX";
	default:
		return "NULL_BUTTON_TEX";
	}
}

void SubScene::ButtonSE(SoundEffect Button, int SoundNumber) {
	static int buttonKeyID = 0;
	static int prevbuttonKeyID = 1;
	if (buttonKeyID >= SoundNumber) {
		buttonKeyID = 0;
	}

	switch (buttonKeyID) {
	case 14:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE15);
			m_pSoundOperater->Start(Button.SE15, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 0;
			break;
		}
	case 13:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE14);
			m_pSoundOperater->Start(Button.SE14, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 14;
			break;
		}
	case 12:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE13);
			m_pSoundOperater->Start(Button.SE13, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 13;
			break;
		}
	case 11:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE12);
			m_pSoundOperater->Start(Button.SE12, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 12;
			break;
		}
	case 10:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE11);
			m_pSoundOperater->Start(Button.SE11, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 11;
			break;
		}

	case 9:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE10);
			m_pSoundOperater->Start(Button.SE10, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 10;
			break;
		}
	case 8:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE9);
			m_pSoundOperater->Start(Button.SE9, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 9;
			break;
		}

	case 7:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE8);
			m_pSoundOperater->Start(Button.SE8, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 8;
			break;
		}
	case 6:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE7);
			m_pSoundOperater->Start(Button.SE7, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 7;
			break;
		}
	case 5:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE6);
			m_pSoundOperater->Start(Button.SE6, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 6;
			break;
		}

	case 4:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE5);
			m_pSoundOperater->Start(Button.SE5, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 5;
			break;
		}
	case 3:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE4);
			m_pSoundOperater->Start(Button.SE4, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 4;
			break;
		}
	case 2:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE3);
			m_pSoundOperater->Start(Button.SE3, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 3;
			break;
		}
	case 1:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE2);
			m_pSoundOperater->Start(Button.SE2, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 2;
			break;
		}
	case 0:
		if (buttonKeyID != prevbuttonKeyID) {
			m_pSoundOperater->Stop(Button.SE1);
			m_pSoundOperater->Start(Button.SE1, false);
			prevbuttonKeyID = buttonKeyID;
			buttonKeyID = 1;
			break;
		}
	}
}

void SubScene::madamBlowOff() {


	mobCentralBlowOff[0].x -= rand() % 15;
	mobCentralBlowOff[0].y -= rand() % 5;

	mobCentralBlowOff[1].x += rand() % 10;
	mobCentralBlowOff[1].y -= rand() % 10;

	mobCentralBlowOff[2].x += rand() % 3;
	mobCentralBlowOff[2].y -= rand() % 10;

	mobCentralBlowOff[3].x -= rand() % 8;
	mobCentralBlowOff[3].y -= rand() % 10;

	mobCentralBlowOff[4].x += rand() % 25;
	mobCentralBlowOff[4].y -= rand() % 30;

	if (m_EffectCount > 200) {
		for (int i = 0; i < 5; i++) {
			mobCentralBlowOff[i].y += 35;
		}
	}

}

void SubScene::TurnEffectAnimation()
{
	if (m_EffectCount < 3) {
		++m_EffectCount;
	}
	else m_EffectCount = 0;
}

