#include "SubScene.h"

int SubScene::m_GameScene = FLOAMOVE;

SubScene::SubScene(DirectX * pDirectX, SoundOperater * pSoundOperater, int turn, Yasuko* pYasuko) :Scene(pDirectX, pSoundOperater),m_Turn(turn)
{
}


SubScene::~SubScene()
{
}
