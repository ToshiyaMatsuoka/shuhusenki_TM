/**
* @file TrialLib.h
* @brief DirectX9�y��XInput�̃��C�u����
* @author Toshiya Matsuoka
* @date 2018/7/7
*/



#ifndef TRIALLIB_H
#define TRIALLIB_H

#include <Windows.h>
#include <d3dx9.h>
#include <dinput.h>
#include <D3dx9core.h>
#include <time.h>
#include <stdio.h>
#include<Xinput.h>
#include "map"



#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "dxguid.lib")
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "Xinput.lib")

/**
* @enum PADSTATE
* �{�^���̉������
*/
enum PADSTATE
{
	//! ������Ă���
	PadOn,
	//! ������Ă��Ȃ�
	PadOff,
	//! ���������Ă���
	PadPush,
	//! �����ꂽ
	PadRelease
};
/**
* @enum KEYSTATE
* �L�[�̉������
*/
enum KEYSTATE
{
	//! ������Ă��Ȃ�
	KeyOff,
	//! ������Ă���
	KeyOn,
	//! ���������Ă���
	KeyPush,
	//! �����ꂽ
	KeyRelease
};
/**
* @enum ButtonIndex
* �p�b�h�̃{�^���̗�
*/
enum ButtonIndex
{
	ButtonA,
	ButtonB,
	ButtonX,
	ButtonY,
	//! R1�{�^��
	ButtonRB,
	//! L1�{�^��
	ButtonLB,
	ButtonStart,
	ButtonBack,
	ButtonUP,
	ButtonDOWN,
	ButtonLEFT,
	ButtonRIGHT,
	ButtonLeftThumb,
	ButtonRightThumb,
	ButtomIndexMAX
};
/**
* @enum Analog
* �A�i���O�X�e�B�b�N�̌X������
*/
enum Analog
{
	ANALOGUP,
	ANALOGDOWN,
	ANALOGLEFT,
	ANALOGRIGHT,
	ANALOG_X,
	ANALOG_Y,
	ANALOGMAX
};
enum AnalogTrigger
{
	LEFTTRIGGER,
	RIGHTTRIGGER
};


typedef struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;
	DWORD	color;
	FLOAT	tu, tv;
}CUSTOMVERTEX;

struct CENTRAL_STATE
{
	float x, y, scaleX, scaleY;
};
struct CIRCLE_STATE{
	int x, y, r;//���SX���W�A���SY���W�A���a

};

extern LPDIRECT3D9 g_pDirect3D;		//	Direct3D�̃C���^�[�t�F�C�X
extern std::map<std::string, LPDIRECT3DTEXTURE9>	g_pTexture;	//	�摜�̏������Ă����ׂ̃|�C���^�z��
extern IDirect3DDevice9*	  g_pD3Device;		//	Direct3D�̃f�o�C�X
extern D3DDISPLAYMODE		  g_D3DdisplayMode;
extern D3DPRESENT_PARAMETERS g_D3dPresentParameters;
extern LPDIRECTINPUT8 g_pDinput;
extern LPDIRECTINPUTDEVICE8 g_pKeyDevice;
extern std::map<std::string, LPD3DXFONT> g_pFont;
extern PADSTATE PadState[ButtomIndexMAX];
extern PADSTATE PadOldState[ButtomIndexMAX];
extern BYTE KeyState[256];
extern BYTE KeyOldState[256];


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//DirecrtXInitialize

/**
* @brief DirecrtX��Initialize
* @param hWnd�@�E�B���h�E�n���h��
* @param pSrcFile�@�摜�t�@�C����
* @return ���������S_OK�A���s��E_FAIL
*/
HRESULT InitD3d(HWND hWnd, LPCSTR pSrcFile);
/**
* @brief �t���X�N���[���pDirecrtX��Initialize
* @param hWnd�@�E�B���h�E�n���h��
* @param pSrcFile�@�摜�t�@�C����
* @return ���������S_OK�A���s��E_FAIL
*/
HRESULT InitD3dFullscreen(HWND hWnd, LPCSTR pSrcFile, int ResolutionWidth, int ResolutionHeight);
/**
* @brief DirecrtInput��Initialize
* @param hWnd�@�E�B���h�E�n���h��
* @return ���������S_OK�A���s��E_FAIL
*/
HRESULT InitDinput(HWND hWnd);
/**
* @brief DirecrtXDevice��Initialize
* @param hWnd�@�E�B���h�E�n���h��
* @param pSrcFile�@�摜�t�@�C����
* @return ���������S_OK�A���s��E_FAIL
*/
HRESULT InitDirectX(HWND hWnd, LPCSTR pSrcFile);
/**
* @brief �t���X�N���[���pDirecrtXDevice��Initialize
* @param hWnd�@�E�B���h�E�n���h��
* @param pSrcFile�@�摜�t�@�C����
* @return ���������S_OK�A���s��E_FAIL
*/
HRESULT InitDirectXFullscreen(HWND hWnd, LPCSTR pSrcFile, int ResolutionWidth, int ResolutionHeight, int PresentationInterval=D3DPRESENT_INTERVAL_IMMEDIATE);

void FreeDx();

//WINAPI�̋�E�B���h�E����

/**
* @brief �E�B���h�E����
* @param WndName �E�B���h�E�^�C�g���y�уN���X�̖���
* @param WIDTH ��ʕ�
* @param HEIGHT ��ʍ���
* @param hInst API�C���X�^���X�̃n���h��
* @param hInstance API�C���X�^���X�̃n���h��
* @param pSrcFile�@�摜�t�@�C����
* @param  IconIDI�@Icon��ID�@�s�v�Ȃ�NULL
* @return NULL�Ԃ��ƃE�B���h�E�����
*/
int InitWindow(LPCSTR WndName, int WIDTH, int HEIGHT, HINSTANCE hInst, HINSTANCE hInstance, LPCSTR pSrcFile, int IconIDI = NULL);

/**
* @brief �E�B���h�E����
* @param WndName �E�B���h�E�^�C�g���y�уN���X�̖���
* @param hWnd�@�E�B���h�E�n���h��
* @param WIDTH ��ʕ�
* @param HEIGHT ��ʍ���
* @param hInst API�C���X�^���X�̃n���h��
* @param hInstance API�C���X�^���X�̃n���h��
* @param pSrcFile�@�摜�t�@�C����
* @param  IconIDI�@Icon��ID�@�s�v�Ȃ�NULL
* @return NULL�Ԃ��ƃE�B���h�E�����
*/
int InitWindowEx(LPCSTR WndName, HWND* hWnd, int WIDTH, int HEIGHT, HINSTANCE hInst, HINSTANCE hInstance, LPCSTR pSrcFile, int IconIDI = NULL);

/**
* @brief �t���X�N���[���p�E�B���h�E����
* @param WndName �E�B���h�E�^�C�g���y�уN���X�̖���
* @param hWnd�@�E�B���h�E�n���h��
* @param WIDTH ��ʕ�
* @param HEIGHT ��ʍ���
* @param hInst API�C���X�^���X�̃n���h��
* @param hInstance API�C���X�^���X�̃n���h��
* @param pSrcFile�@�摜�t�@�C����
* @param  int PresentationInterval ���������̐ݒ�@Default�ŃI���FD3DPRESENT_INTERVAL_IMMEDIATE�@�I�t�ɂ���Ȃ�D3DPRESENT_INTERVAL_DEFAULT�Ȃǂ�ݒ肷��
* @param  IconIDI�@Icon��ID�@�s�v�Ȃ�NULL
* @return NULL�Ԃ��ƃE�B���h�E�����
*/
int InitWindowFullscreenEx(LPCSTR WndName, HWND* hWnd, int WIDTH, int HEIGHT, HINSTANCE hInst, HINSTANCE hInstance, LPCSTR pSrcFile, int PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE, int IconIDI = NULL);

/**
* @brief �b��60�t���[�����[�v������
* @param gameroop(void) �����̍쐬�����Q�[�������֐������邱��
*		�@�A���A�߂�l�ɃE�B���h�E���b�Z�[�W��Ԃ��Ȃ���΂Ȃ�Ȃ�
* @return �v���O�����I������(int)msg.wParam
*/
int FlameRoop(unsigned int gameroop(void));

//�`��

/**
* @brief �`��J�n�֐�
* @sa EndSetTexture()
* @detail ��L�֐��ƃZ�b�g�Ŏg������
*/
void BeginSetTexture();
/**
* @brief �`��I���֐�
* @sa BeginSetTexture()
* @detail ��L�֐��ƃZ�b�g�Ŏg������
*/
void EndSetTexture();


/**
* @brief �摜�ǂݍ���
* @param pTextureName �ǂݍ��މ摜�t�@�C����
* @param TexKey �摜�̊i�[�L�[
*/
void ReadInTexture(LPCSTR pTextureName, std::string TexKey);


/**
* @brief �摜�\��
* @param Vertex �`�悷��4���_���
* @param TexKey �摜�̊i�[�L�[
* @detail CUSTOMVERTEX�ϐ��͎����ŗp�ӂ��邱��
*/
void SetUpTexture(CUSTOMVERTEX* Vertex, std::string TexKey);

void eraseTexture(std::string TexKey);

//2���_�ݒ�`��

/**
* @brief 2���_���w�肵�摜��`�悷��
* @param Left ���[
* @param Top ��[
* @param Right �E�[
* @param Bottom ���[
* @param color �F
* @param TexKey �摜�̊i�[�L�[
*/
void EasyCreateSquareVertexColor(float Left, float Top, float Right, float Bottom, std::string TexKey, DWORD color=0xffffffff);

/**
* @brief 2���_���w�肵�摜��`�悷��
* @param Left ���[
* @param Top ��[
* @param Right �E�[
* @param Bottom ���[
* @param color �F
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
* @param TexKey �摜�̊i�[�L�[
*/
void EasyCreateSquareVertex( float Left, float Top, float Right, float Bottom, std::string TexKey, DWORD  color = 0xffffffff, float tu=0, float tv=0, float scaleTu=1, float scaleTv=1);

//RECT����2���_�ݒ�`��

/**
* @brief 2���_���w�肵�摜��`�悷��
* @param Vertex RECT�\���̂Œ��_���w�肷��
* @param color �F
* @param TexKey �摜�̊i�[�L�[
*/
void EasyCreateRECTVertexColor(RECT Vertex, std::string TexKey, DWORD color = 0xffffffff);
/**
* @brief 2���_���w�肵�摜��`�悷��
* @param Vertex RECT�\���̂Œ��_���w�肷��
* @param color �F
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
* @param TexKey �摜�̊i�[�L�[
*/
void EasyCreateRECTVertex(RECT Vertex, std::string TexKey, DWORD color = 0xffffffff, float tu=0, float tv=0, float scaleTu=1, float scaleTv=1);

//4���_�ݒ�

/**
* @brief CUSTOMVERTEX�ϐ��ɒl������
* @param Vertex ���ꕨ
* @param Central ����钆�S���
* @param color �F
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
*/
void CreateSquareVertex(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, DWORD  color=0xffffffff, float tu=0, float tv=0, float scaleTu=1, float scaleTv=1);
/**
* @brief CUSTOMVERTEX�ϐ��ɒl������
* @param Vertex ���ꕨ
* @param Central ����钆�S���
* @param color �F
*/
void CreateSquareVertexColor(CUSTOMVERTEX* Vertex, CENTRAL_STATE Central, DWORD  color = 0xffffffff);


//DX�t�H���g

/**
* @brief DX�t�H���g�����ݒ�
* @param WordHeight �����̍���
* @param WordWidth �����̕�
* @param FontName �g�p����t�H���g��
* @param FontNum �\�������ݒ�̊i�[��z��ԍ�
* @param CharSet �L�����Z�b�g�i�p���Ȃ�DEFAULT_CHARSET�C�V�t�gJIS�Ȃ�SHIFTJIS_CHARSET�j
*/
void SetUpFont(int WordHeight, int WordWidth, std::string FontNum, LPCSTR FontName=NULL, int CharSet=DEFAULT_CHARSET);
/**
* @brief DX�t�H���g�`��ݒ�
* @param Texts �\�����e
* @param Vertex �\���͈�
* @param FontNum �\�������ݒ�̊i�[�L�[
* @param TextFormat �t�H�[�}�b�g
* @param color �F
*/
void WriteWord(LPCSTR Texts, RECT Vertex, std::string FontNum, int TextFormat=DT_LEFT, int color=0xff000000);

void eraseFont(std::string FontKey);

/**
* @brief ��]�A�~�^���֐�
* @param Vertex �����̒��_���̊i�[��
* @param Rad ��]�p�x�i�P�ʁFRadian�j
* @param Central ���������S���
* @param motionRadius �~�^�����a
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
*/
void RevolveAndCircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadius, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
/**
* @brief ��]�A�ȉ~�^���֐�
* @param Vertex �����̒��_���̊i�[��
* @param Rad ��]�p�x�i�P�ʁFRadian�j
* @param Central ���������S���
* @param motionRadiusX �~�^��X���a
* @param motionRadiusY �~�^��Y���a
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
*/
void RevolveAndOvalCircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadiusX, float motionRadiusY, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);


/**
* @brief Z����]
* @param Vertex �����̒��_���̊i�[��
* @param Rad ��]�p�x�i�P�ʁFRadian�j
* @param Central ���������S���
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
*/
void RevolveZ(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
/**
* @brief ��]���w��Z����]
* @param Vertex �����̒��_���̊i�[��
* @param Rad ��]�p�x�i�P�ʁFRadian�j
* @param Central ���������S���
* @param RevolvingShaftX ��]����X���W
* @param RevolvingShaftY ��]����Y���W
*/
void RevolveZEX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float 	RevolvingShaftX, float 	RevolvingShaftY, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
/**
* @brief Y����]
* @param Vertex �����̒��_���̊i�[��
* @param Rad ��]�p�x�i�P�ʁFRadian�j
* @param Central ���������S���
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
*/
void RevolveY(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
/**
* @brief ��]���w��Y����]
* @param Vertex �����̒��_���̊i�[��
* @param Rad ��]�p�x�i�P�ʁFRadian�j
* @param Central ���������S���
* @param RevolvingShaftX ��]����X���W
* @param RevolvingShaftZ ��]����Z���W
*/
void RevolveYEX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float RevolvingShaftX, float RevolvingShaftZ, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
/**
* @brief X����]
* @param Vertex �����̒��_���̊i�[��
* @param Rad ��]�p�x�i�P�ʁFRadian�j
* @param Central ���������S���
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
*/
void RevolveX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
/**
* @brief ��]���w��X����]
* @param Vertex �����̒��_���̊i�[��
* @param Rad ��]�p�x�i�P�ʁFRadian�j
* @param Central ���������S���
* @param RevolvingShaftY ��]����Y���W
* @param RevolvingShaftZ ��]����Z���W
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
*/
void RevolveXEX(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float RevolvingShaftY, float RevolvingShaftZ, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);

//�~�^��
/**
* @brief �~�^���֐�
* @param Vertex �����̒��_���̊i�[��
* @param Rad ��]�p�x�i�P�ʁFRadian�j
* @param Central ���������S���
* @param motionRadius �~�^�����a
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
*/
void CircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadius, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);
//
/**
* @brief �ȉ~�^��
* @param Vertex �����̒��_���̊i�[��
* @param Rad ��]�p�x�i�P�ʁFRadian�j
* @param Central ���������S���
* @param motionRadiusX �~�^��X���a
* @param motionRadiusY �~�^��Y���a
* @param tu �摜�؂��荶�[
* @param tv �摜�؂����[
* @param scaleTu �摜�̐؂��蕝
* @param scaleTv �摜�̐؂��荂��
*/
void OvalCircularMotion(CUSTOMVERTEX* Vertex, float Rad, CENTRAL_STATE Central, float motionRadiusX, float motionRadiusY, float tu = 0, float tv = 0, float scaleTu = 1, float scaleTv = 1);

//Dinput�L�[�{�[�h
/**
* @brief Dinput�ŃL�[�{�[�h�̓��͎擾
* @param KeyName �擾�������L�[�̔z��ԍ�
* @return ���͂���Ă����True�A�����łȂ����False
*/
bool InputKEY(int KeyName);
/**
* @brief Dinput�ŃL�[�{�[�h�̏�Ԏ擾
* @param KeyName �擾�������L�[�̔z��ԍ�
* @sa enum KEYSTATE
* @detail �g�p���ɂ́@KeyState[KeyName]�@�̒��g���m�F���邱��
*/
void CheckKeyState(int KeyName);
//XInput
bool InputKEY(int KeyName);
/**
* @brief Xinput�ŃQ�[���p�b�h�f�o�C�X�̎擾
* @param GamePadNumber �p�b�h�ԍ��i0�x�[�X�j
*/
void GetControl(int GamePadNumber = 0);
/**
* @brief Xinput�ŃQ�[���p�b�h�̓��͎擾
* @param index �擾�������{�^���̔z��ԍ�
* @return PADSTATE�^�̒l
*/
PADSTATE GetButton(ButtonIndex index);
/**
* @brief Xinput�ŃQ�[���p�b�h�̍��A�i���O�X�e�B�b�N���͎擾
* @param �g���K�[�̍��E�F���ԍ��@0or1
* @return 0�`255�̒l�A�����ĂȂ����0
* @sa enum AnalogTrigger
*/
int GetAnalogTrigger(int Trigger);
/**
* @brief Xinput�ŃQ�[���p�b�h�̍��A�i���O�X�e�B�b�N���͎擾
* @param Analogstate �X�e�B�b�N�̕�������ԍ�
* @return �X���Ă����True�A�����łȂ����False
* @sa enum Analog
* @detail �ȉ��̂悤�Ɏg�p�\
* if(GetAnalogL(ANALOGRIGHT)){
* for (int i = 0; i < 4; i++){
* �����@
* }
* }
*/
bool GetAnalogL(Analog Analogstate);
/**
* @brief  Xinput�ŃQ�[���p�b�h�̉E�A�i���O�X�e�B�b�N���͎擾
* @param Analogstate �X�e�B�b�N�̕�������ԍ�
* @return �X���Ă����True�A�����łȂ����False
* @sa enum Analog
* @detail �ȉ��̂悤�Ɏg�p�\
* if(GetAnalogL(ANALOGRIGHT)){
* for (int i = 0; i < 4; i++){
* �����@
* }
* }
*/
bool GetAnalogR(Analog AnalogState);
/**
* @brief  Xinput�ŃQ�[���p�b�h�̍��A�i���O�X�e�B�b�N���͎擾
* @param Analogstate �X�e�B�b�N�̕�������ԍ�
* @return �X����̐��l�@MAX��32767�@MIN��-32768
* @sa enum Analog
*/
int GetAnalogLValue(Analog AnalogState);
/**
* @brief  Xinput�ŃQ�[���p�b�h�̉E�A�i���O�X�e�B�b�N���͎擾
* @param Analogstate �X�e�B�b�N�̕�������ԍ�
* @return �X����̐��l�@MAX��32767�@MIN��-32768
* @sa enum Analog
*/
int GetAnalogRValue(Analog AnalogState);
/**
* @brief Dinput�ŃL�[�{�[�h�̏�Ԏ擾
* @param ButtomID �擾������XInput�{�^���ԍ�
* @param ButtomIndex �擾�������{�^���̔z��ԍ�
* @sa enum ButtonIndex
* @detail �g�p���ɂ́@PadState[KeyName]�@�̒��g���m�F���邱��
*/
void CheckButtonState(WORD ButtomID, ButtonIndex ButtomIndex);
/**
* @brief CheckButtonState��Z�߂čs��
* @sa CheckButtonState(WORD ButtomID, int ButtomIndex)
*/
void BottonCheck();
//�����蔻��


/**
* @brief �~�Ɖ~�̓����蔻��
* @param PosX1 1�ڂ̉~��X���W
* @param PosY1 1�ڂ̉~��Y���W
* @param Radius1 1�ڂ̉~�̔��a
* @param PosX2 2�ڂ̉~��X���W
* @param PosY2 2�ڂ̉~��Y���W
* @param Radius2 2�ڂ̉~�̔��a
* @return �������Ă����True
*/
bool CtoCContact(float PosX1, float PosY1, float Radius1, float PosX2, float PosY2, float Radius2);
/**
* @brief CIRCLE_STATE���g�p���ĉ~�Ɖ~�̓����蔻��
* @param CircleA 1�ڂ̉~
* @param CircleB 2�ڂ̉~
* @return �������Ă����True
*/
bool CtoCContact(CIRCLE_STATE* CircleA, CIRCLE_STATE* CircleB);


/**
* @brief ��`�Ƌ�`�̓����蔻��
* @param central1 1�ڂ̋�`
* @param central2 2�ڂ̋�`
* @return �������Ă����True
*/
bool BtoBContact(CENTRAL_STATE* central1, CENTRAL_STATE* central2);


/**
* @brief ��`���w��͈͊O�ɏo�Ȃ��悤�ɂ���
* @param central �g�p���钆�S���
* @param Left �w��͈͂̍��[
* @param Top �w��͈͂̏�[
* @param Right �w��͈͂̉E�[
* @param Bottom �w��͈͂̉��[
*/
void MoveInToErea(CENTRAL_STATE* central, float Left, float Top, float Right, float Bottom);

#endif TRIALLIB_H