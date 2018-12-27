#pragma once
#include "Scene.h"
class GameScene :
	public Scene
{
public:
	GameScene(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~GameScene();
	SCENE_NUM Update();
	void KeyOperation();

	void Render();
	void LoadResouce();

};

