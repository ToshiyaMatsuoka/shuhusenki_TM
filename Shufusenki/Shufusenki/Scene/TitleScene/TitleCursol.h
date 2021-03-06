﻿#ifndef TITLECURSOL_H
#define TITLECURSOL_H
/**
* @file TitleCursol.h
* @brief タイトルのカーソル処理
* @author Toshiya Matsuoka
*/

#include "Scene/GameScene/Object.h"

namespace Cursol {
	enum CursolPosition {
		START,
		OPTION,
		END
	};
};

class TitleCursol :public Object
{
public:
	TitleCursol(DirectX* pDirectX, SoundOperater* pSoundOperater);
	~TitleCursol();
	void KeyOperation(KeyInput vec);
	void Update();
	void Render();
	Cursol::CursolPosition GetCursolPosition(){
		return m_CursolPos;
	}
private:
	CENTRAL_STATE m_Cursol = { 480,0,40,30 };
	Cursol::CursolPosition m_CursolPos = Cursol::START;
	void MoveUp();
	void MoveDown();
};
#endif
