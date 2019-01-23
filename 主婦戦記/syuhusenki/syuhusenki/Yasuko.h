#pragma once
#include "Object.h"

class Yasuko :
	public Object
{
public:
	Yasuko(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~Yasuko();
	bool MoveOutToErea(CENTRAL_STATE * central, float Left, float Top, float Right, float Bottom, int direction);
	void collision(CENTRAL_STATE * charctor);
	void Update();
	void Render();
	void KeyOperation(KeyInput key);
	void FloaMoveUpdate();

	void FloaMoveLeft();

	void FloaMoveRight();

	void FloaMoveUp();

	void FloaMoveDown();

private:

	const float MOVE_SPEED = 2.f;
	bool m_isRight = false;
	int m_AnimeCount = 0;
	int salesChoice;
	int m_TurningAnimetion = 0;
	int m_ChangeAnimetion = 0;
	const float YASUKO_TU = (350.f / 2048.f);
	const float YASUKO_TV = (679.f / 2048.f);
};

