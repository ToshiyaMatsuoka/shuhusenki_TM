#ifndef OBJECT_H
#define OBJECT_H
/**
* @file Object.h
* @brief 色々な物体の基底クラス
* @author Toshiya Matsuoka
*/

#include <vector>

#include "Scene/Scene.h"

/**
* @brief 売り子の場所ID
*/
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

/**
* @brief 衝突方向
*/
enum CONTACTDIRECTION
{
	SIDE,
	UPPER,
	UNDER
};

/**
* @brief ボタン入力
*/
enum KeyInput
{
	PUSH_NONE,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	MOVE_LEFT,
	MOVE_RIGHT,
	SPACE,
	ACTION,
};

/**
* @brief 売り子情報
*/
struct SALESMAN {
	CENTRAL_STATE popPositionCentral;
	int popPosition;
	int goodsSorting;
	int merchandise[2];
};

class Object
{
public:
	/*
	*キー入力時の内部処理関数
	*/
	virtual void KeyOperation();
	virtual void KeyOperation(KeyInput key) {};

	virtual void Update();
	virtual void Render();

	/*
	* @brief テクスチャの貼り付け
	* @param TextureKey テクスチャキー
	* @param TextureSize 貼り付け座標配列のアドレス
	*/
	void TextureRender(std::string TextureKey, CUSTOMVERTEX* TextureSize);

	Object(DirectX* pDirectX, SoundOperater* pSoundOperater);
	virtual ~Object();

	/**
	*@brief CUSTOMVERTEXにパラメータを入れる
	* @param Vertex 値を入れる配列
	* @param Central 中心座標情報
	* @param color 色
	* @param tu 切り取り画像の左端
	* @param tv 切り取り画像の上端
	* @param scaleTu 切り取り画像の右端
	* @param scaleTv 切り取り画像の下端
	*/
	void CreateSquareVertex(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, DWORD  color = 0xffffffff, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
	void CreateSquareVertex(CUSTOMVERTEX* Vertex, float x, float y, DWORD  color = 0xffffffff, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
	void CreateSquareVertex(CENTRAL_STATE Central, CUSTOMVERTEX* Vertex, DWORD  color = 0xffffffff, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
	/**
	*@brief CUSTOMVERTEXからCENTRAL_STATEを作成する
	* @param Central [out]
	* @param Vertex [in]
	* @sa CreateSquareVertex(CENTRAL_STATE Central, CUSTOMVERTEX* Vertex, DWORD  color, float tu, float tv, float scaleTu float scaleTv)
	* @details 関連するCUSTOMVERTEX作成関数の逆動作をする
	*/
	void TranslateCentral_State(CENTRAL_STATE* Central, CUSTOMVERTEX* Vertex);
	
	/**
	* @brief 売り子と指定の中心情報と当たり判定を取る
	* @param central 当たり判定を取りたい中心情報
	* @return 売り場ID
	*/
	int SalesmanToPCCollision(CENTRAL_STATE* central);

	/**
	* @brief 商品を選択する
	* @param seleChoice 売り子番号
	* @param arrayNum 選択番号
	* @return 商品ID
	*/
	int EditMerchandise(int seleChoice, int arrayNum);

	/**
	* @brief ゴンドラとの当たり判定
	* @param charctor 当たり判定を取る中心情報
	*/
	void Collision(CENTRAL_STATE * charctor);

	/**
	* @brief 指定の4座標の中に中心情報が入らないようにする
	* @param central 指定の中心情報
	* @param left 左端座標 
	* @param top 上端座標
	* @param right 右端座標
	* @param bottom 下端座標
	* @param direction 当たり判定を取る方向
	*/
	bool MoveOutToErea(CENTRAL_STATE * central, float left, float top, float right, float bottom, int direction);

	float DegToRad(float deg) {
		return deg * (D3DX_PI / 180);
	}

	SALESMAN* GetSalesman() {
		return popSales;
	}

	SALESMAN* GetSalesman(int ArrayNum) {
		return &popSales[ArrayNum];
	}

	int GetgoodsSorting(int ArrayNum) {
		return popSales[ArrayNum].goodsSorting;
	}

	/**
	* @brief 商品種別の抽選
	*/
	void DrawLotsgoodsSorting();

	virtual CENTRAL_STATE* GetCentral() {
		return &m_Center;
	}
protected:
	DirectX* m_pDirectX = NULL;
	SoundOperater* m_pSoundOperater = NULL;
	CUSTOMVERTEX Vertex[4];
	const DWORD WHITE = 0xFFFFFFFF;
	const DWORD HARFCLEAR = 0x8a000000;
	static SALESMAN popSales[3];
	CENTRAL_STATE m_Center;

	const int ANIMETION_TIME = 20;

	static const int ARRAY_LONG = 64;
	void RevolveZ(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, DWORD  color = 0xffffffff, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);

	void RevolveZEX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float 	RevolvingShaftX, float 	RevolvingShaftY, DWORD  color = 0xffffffff, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);

	bool BtoBContact(CENTRAL_STATE * central1, CENTRAL_STATE * central2);

	bool toBoxContact(CENTRAL_STATE * central1, CENTRAL_STATE * central2);

	void MoveInToErea(CENTRAL_STATE * central, float Left, float Top, float Right, float Bottom);

};
#endif
