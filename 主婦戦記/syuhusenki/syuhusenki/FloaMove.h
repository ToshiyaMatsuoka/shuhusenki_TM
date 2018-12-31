#ifndef FLOAMOVE_H
#define FLOAMOVE_H

#include "Scene.h"

enum SALESPOSITION
{
	POS_MEET,
	POS_VEGETABLE1,
	POS_VEGETABLE2,
	POS_SEAFOOD1,
	POS_SEAFOOD2,
	POS_SWEET1,
	POS_SWEET2,
	POS_SWEET3,
	POS_DRINK1,
	POS_DRINK2,
	POS_FRUIT1,
	POS_FRUIT2,
	POS_FRUIT3,
	POS_NOTING
};

enum SCENE_NUM;
class Scene;
class TitleCursol;

class FloaMove : public Scene
{
public:
	FloaMove(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~FloaMove();
	SCENE_NUM Update();
	void Render();
	void LoadResouce();

private:


};

//enum SALESPOSITION
//{
//	POS_MEET,
//	POS_VEGETABLE1,
//	POS_VEGETABLE2,
//	POS_SEAFOOD1,
//	POS_SEAFOOD2,
//	POS_SWEET1,
//	POS_SWEET2,
//	POS_SWEET3,
//	POS_DRINK1,
//	POS_DRINK2,
//	POS_FRUIT1,
//	POS_FRUIT2,
//	POS_FRUIT3,
//	POS_NOTING
//};
//
////モブの画像頂点
//extern CUSTOMVERTEX mobFloa[4];
//extern CENTRAL_STATE mobCentralFloa[4];
//extern CENTRAL_STATE mobCentralBlowOff[5];
//
//extern CENTRAL_STATE g_PCSta;
//extern CENTRAL_STATE g_startCountSta;
//extern CENTRAL_STATE g_startSta;
//extern int effectCount;
//extern int effectIntervalPrev;
//extern int blowOffEffectIntervalPrev;
//void floaMove();

#endif // !FLOAMOVE_H