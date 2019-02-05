﻿
#include "FloaMove.h"

FloaMove::FloaMove(DirectX * pDirectX, SoundOperater * pSoundOperater,int turn, Yasuko* pYasuko) :SubScene(pDirectX, pSoundOperater,turn,pYasuko)
{
	m_pYasuko->Initialize();
	m_pSalesman = new Salesman(pDirectX, pSoundOperater);
	m_pFloaMob = new FloaMob(pDirectX, pSoundOperater,turn);
	m_pYasuko->DrawLotsgoodsSorting();
	m_pYasuko->DrawLotsgoodsSorting();
	m_pYasuko->DrawLotsgoodsSorting();
	m_pGoods->selectGoods(m_pYasuko->GetSalesman(0));
	m_pGoods->selectGoods(m_pYasuko->GetSalesman(1));
	m_pGoods->selectGoods(m_pYasuko->GetSalesman(2));
	m_pSalesman->Update();

}

FloaMove::~FloaMove()
{
	delete m_pSalesman;
	m_pSalesman = NULL;
	delete m_pFloaMob;
	m_pFloaMob = NULL;
}

int FloaMove::Update()
{
	if (m_pDirectX->GetKeyStatus(DIK_RIGHT) || m_pDirectX->GetKeyStatus(DIK_D) || m_pXinputDevice->GetButton(ButtonRIGHT) || m_pXinputDevice->GetAnalogL(ANALOGRIGHT)){
		m_pYasuko->KeyOperation(RIGHT);
	}
	if (m_pDirectX->GetKeyStatus(DIK_LEFT) || m_pDirectX->GetKeyStatus(DIK_A) || m_pXinputDevice->GetButton(ButtonLEFT) || m_pXinputDevice->GetAnalogL(ANALOGLEFT)){
		m_pYasuko->KeyOperation(LEFT);
	}
	if (m_pDirectX->GetKeyStatus(DIK_UP) || m_pDirectX->GetKeyStatus(DIK_W) || m_pXinputDevice->GetButton(ButtonUP) || m_pXinputDevice->GetAnalogL(ANALOGUP)) {
		m_pYasuko->KeyOperation(UP);
	}
	if (m_pDirectX->GetKeyStatus(DIK_DOWN) || m_pDirectX->GetKeyStatus(DIK_S) || m_pXinputDevice->GetButton(ButtonDOWN) || m_pXinputDevice->GetAnalogL(ANALOGDOWN)) {
		m_pYasuko->KeyOperation(DOWN);
	}
	if (GetPushedRETURN() || m_pXinputDevice->GetButton(ButtonA)) {
		leachedGondolaCheck(&m_SalesChoice, m_pSalesman->GetSalesman(), m_pYasuko->salesmanToPCCollision(m_pYasuko->GetCentral()));
	}

	m_pYasuko->FloaUpdate();
	m_pFloaMob->Update();
	m_pYasuko->mobToPCContact(m_pFloaMob->GetCentral());

	return m_GameScene;
}

void FloaMove::Render()
{
	CUSTOMVERTEX Vertex[4];
	RECT Background = { 0,100,DISPLAY_WIDTH ,700 };
	CreateSquareVertex(Vertex, Background);
	m_pDirectX->DrawTexture("FLOAMOVE_BG_TEX", Vertex);

	CUSTOMVERTEX startCount[4];
	CUSTOMVERTEX start[4];
	CUSTOMVERTEX m_EffectVertex[4];
	m_pFloaMob->Render();
	m_pSalesman->Render();
	m_pYasuko->FloaRender();

}


void FloaMove::LoadResouce()
{
}

void FloaMove::DebugAction()
{
	m_pYasuko->DrawLotsgoodsSorting();//フロア移動で決めたものを入れる
	m_pGoods->selectGoods(m_pYasuko->GetSalesman(0));
	m_pGoods->selectGoods(m_pYasuko->GetSalesman(1));
	m_pGoods->selectGoods(m_pYasuko->GetSalesman(2));
	m_pSalesman->Update();
}

void FloaMove::leachedGondolaCheck(int* leschgondola, SALESMAN* popSales, int whergondola)
{
	for (int i = 0; i < 3; i++)
	{
		if (popSales[i].popPosition == whergondola)
		{
			*leschgondola = i;
			SetGameScene(CHOSEGOODS);
		}
	}
}


