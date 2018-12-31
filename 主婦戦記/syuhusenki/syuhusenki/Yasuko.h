#pragma once
#include "Object.h"
#include "Goods.h"

class Yasuko :
	public Object
{
public:
	bool MoveOutToErea(CENTRAL_STATE * central, float Left, float Top, float Right, float Bottom, int direction);
	int salesmanToPCCollision(CENTRAL_STATE central, SALESMAN* popSales);
	void collision(CENTRAL_STATE * charctor);
	void leachedGondolaCheck(int * leschgondola, SALESMAN* popSales, int whergondola);

	Yasuko(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~Yasuko();
	void FloaMoveControl(KeyInput vec);

	void FloaMoveLeft(int * onceSound);

	void FloaMoveRight(int * onceSound);

	void FloaMoveUp(int * onceSound);

	void FloaMoveDown(int * onceSound);


private:
	CENTRAL_STATE g_PCSta = { 900.f, 580.f, 32.f, 53.f };
	float g_PCSpeed = 2.f;
	bool isRight = false;
	int animeCount = 0;
	int salesChoice;
	int PCtu = 0;
	int PCtv = 0;
	const int ANIMETION_TIME = 20;
};

