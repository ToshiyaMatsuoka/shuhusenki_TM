#ifndef FLOAMOVE_H
#define FLOAMOVE_H

#include "Scene/GameScene/SubScene/SubScene.h"
#include "Scene/GameScene/Salesman.h"
#include "Scene/GameScene/FloaMob.h"



class FloaMove : public SubScene
{
public:
	FloaMove(DirectX* pDirectX, SoundOperater* pSoundOperater,int turn ,Yasuko* pYasuko);
	~FloaMove();
	int Update();
	void Render();
	void LoadResouce();
	void DebugAction();
private:
	Object* m_pSalesman;
	Object* m_pFloaMob;
	void LeachedGondolaCheck(int * leschgondola, SALESMAN * popSales, int whergondola);
	

};

#endif // !FLOAMOVE_H