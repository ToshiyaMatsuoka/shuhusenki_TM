#pragma once
#include "Object.h"

class Yasuko :
	public Object
{
public:
	Yasuko();
	~Yasuko();
	void FloaMoveControl(int * onceSound);

	void FloaMoveLeft(int * onceSound);

	void FloaMoveRight(int * onceSound);

	void FloaMoveUp(int * onceSound);

	void FloaMoveDown(int * onceSound);


private:
	CENTRAL_STATE g_PCSta = { 900.f, 580.f, 32.f, 53.f };
	float g_PCSpeed = 2.f;
	bool isRight = false;

	int PCtu = 0;
	int PCtv = 0;

};

