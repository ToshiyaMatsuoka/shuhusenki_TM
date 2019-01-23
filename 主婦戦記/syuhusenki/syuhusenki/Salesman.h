#pragma once
#include "Object.h"
#include "Salesman.h"

class Salesman :
	public Object
{
public:
	Salesman(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~Salesman();
	void Render();
	void Update();
private:

	const float  SALE_TU = (480.f / 2048.f);
	const float  SALE_TV = (785.f / 2048.f);

};

