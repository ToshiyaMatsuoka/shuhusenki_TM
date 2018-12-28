//#include "Main.h"
//#include "GameMain.h"
//#include "Title.h"
//#include "Result.h"
//#include "Goods.h"
//#include "Timer.h"
//#include "resource.h"
//
//SoundLib::SoundsManager soundsManager;
//
//bool g_SoundSuccess = false;
//
//RECT testWord = { 50,200,1200,500 };
//unsigned int gameRoop();
//void soundLoad();
//int g_titleScene = TITLE;
//int g_scene = SCENE_TEAMLOGO;
////int g_scene = SCENE_MAIN;
//void teamlogoRender(void);//仮
//void teamlogoControl(void);//仮
//HANDLE threadHandle;
//DWORD threadResult;
//bool LoadConpleate[3] = { false };
//void LoadTexture();
//void LoadFont();
//static HWND hWnd = NULL;
////フルスクリーン関連
//D3DPRESENT_PARAMETERS d3dppWin, d3dppFull;
//RECT WinRect;			//Window Mode での位置大きさ
//bool WinMode = true;	//true:Window　false:Full
//bool DeviceLost = false;
//
//DWORD g_cursolColor = 0xffffffff;
//DWORD WINAPI Thread(LPVOID *data)
//{
//	LoadTexture();
//	LoadFont();
//	if (g_scene == SCENE_TEAMLOGO) {
//		soundLoad();
//	}
//	ExitThread(0);
//}
//void ChangeDisplayMode(void)
//{
//	HRESULT hr = NULL;
//	WinMode = !WinMode;
//	//画面の消去
//	g_pD3Device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0x00, 0x00, 0x00), 1.0, 0);
//	//描画の終了
//	g_pD3Device->EndScene();
//	//表示
//	g_pD3Device->Present(NULL, NULL, NULL, NULL);
//
//	if (WinMode) {
//		g_D3dPresentParameters = d3dppWin;
//	}
//	else {
//		g_D3dPresentParameters = d3dppFull;
//		GetWindowRect(hWnd, &WinRect);
//	}
//	hr = g_pD3Device->Reset(&g_D3dPresentParameters);
//	FreeDx();
//	if (WinMode) {
//		InitDirectX(hWnd, "Texture/Yasuko.png");
//	}
//	else {
//		InitDirectXFullscreen(hWnd, "Texture/Yasuko.png", WIDTH, HEIGHT, D3DPRESENT_INTERVAL_DEFAULT);
//	}
//	//ファイルの引用
//	ReadInTexture("Texture/nowloading.png", "LOAD_TEX");
//	LoadTexture();
//	LoadFont();
//	if (FAILED(hr)) {
//		if (hr == D3DERR_DEVICELOST) {
//			DeviceLost = true;
//		}
//		if (hr == D3DERR_DRIVERINTERNALERROR) {
//			DestroyWindow(hWnd);
//		}
//		return;
//	}
//
//	if (WinMode) {
//		SetWindowLong(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE);
//		SetWindowPos(hWnd, HWND_NOTOPMOST,
//			WinRect.left, WinRect.top,
//			WinRect.right - WinRect.left,
//			WinRect.bottom - WinRect.top,
//			SWP_SHOWWINDOW);
//	}
//	else {
//		SetWindowLong(hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
//	}
//}
//// ウインドウ・サイズの変更
//HRESULT ChangeWindowSize(void)
//{
//	// ウインドウのクライアント領域に合わせる
//
//	HRESULT hr = g_pD3Device->Reset(&g_D3dPresentParameters);
//	if (FAILED(hr)) {
//		if (hr == D3DERR_DEVICELOST) {
//			DeviceLost = true;
//		}
//	}
//	else {
//		DestroyWindow(hWnd);
//	}
//
//	// ビューポートの設定
//	D3DVIEWPORT9 vp;
//	vp.X = 0;
//	vp.Y = 0;
//	vp.Width = g_D3dPresentParameters.BackBufferWidth;
//	vp.Height = g_D3dPresentParameters.BackBufferHeight;
//	vp.MinZ = 0.0f;
//	vp.MaxZ = 1.0f;
//	hr = g_pD3Device->SetViewport(&vp);
//	if (FAILED(hr)) {
//		DestroyWindow(hWnd);
//	}
//	return hr;
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
//{
//	switch (msg)
//	{
//	case WM_DESTROY:
//		PostQuitMessage(0);
//		return 0;
//	case WM_SYSKEYDOWN:     // Alt + 特殊キーの処理に使う
//		switch (wp) {
//		case VK_RETURN:     // Alt + Enterを押すと切り替え
//			ChangeDisplayMode();
//			return 0;
//		case VK_F4:
//			PostMessage(hWnd, WM_CLOSE, 0, 0);
//			return 0;
//		default:
//			return 0;
//		}
//		return 0;
//	}
//	return DefWindowProc(hWnd, msg, wp, lp);
//}
//
//INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE hInstance, LPSTR szStr, INT iCmdShow) {
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	//_CrtSetBreakAlloc(1854);
//
//#ifdef _DEBUG
//	InitWindowEx("☆主婦戦記☆", &hWnd, WIDTH, HEIGHT, hInst, hInstance, "Texture/Yasuko.png", IDI_ICON1);
//#else
//	InitWindowFullscreenEx("☆主婦戦記☆", &hWnd, WIDTH, HEIGHT, hInst, hInstance, "Texture/Yasuko.png", D3DPRESENT_INTERVAL_DEFAULT, IDI_ICON1);
//#endif
//	g_SoundSuccess = soundsManager.Initialize() && g_SoundSuccess;
//	ReadInTexture("Texture/nowloading.png", "LOAD_TEX");
//	g_SoundSuccess = soundsManager.AddFile("Sound/loadEnd.mp3", "LOAD") && g_SoundSuccess;
//	threadHandle = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thread, NULL, 0, NULL);
//
//	FlameRoop(gameRoop);
//		
//
//}
//
//unsigned int gameRoop() {
//	static bool isFirst = true;
//#ifdef _DEBUG
//	CheckKeyState(DIK_F4);
//	if (KeyState[DIK_F4] == KeyRelease && InputKEY(DIK_LSHIFT))
//	{
//		g_SoundSuccess = soundsManager.Stop("FOOD") && g_SoundSuccess;
//		g_SoundSuccess = soundsManager.Stop("HURRY_UP") && g_SoundSuccess;
//		g_SoundSuccess = soundsManager.SetVolume("HURRY_UP", 100) && g_SoundSuccess;
//
//		g_SoundSuccess = soundsManager.Stop("TIME_LIMIT") && g_SoundSuccess;
//
//		g_timeDeadline = false;
//
//		selectedGoods[0] = POTATO;
//		selectedGoods[1] = BEEF;
//		selectedGoods[2] = ONION;
//		for (int i = 0; i < 3; i++) {
//			foodGoods[selectedGoods[i]].haveValue += 300;
//		}
//		g_scene = SCENE_RESULT;
//	}
//#endif
//	if (!LoadConpleate[0]) {
//		ResumeThread(threadHandle);
//		static DWORD LodingColor = 0xffffffff;
//		setNowLoading(LodingColor);
//		if (LodingColor < 0xffffff) {
//			LodingColor = 0xffffffff;
//		}
//		LodingColor = colorDecrease(LodingColor);
//		GetExitCodeThread(threadHandle, &threadResult);
//		if (threadResult != STILL_ACTIVE) {
//			LoadConpleate[0] = true;
//			g_SoundSuccess = soundsManager.Start("LOAD", false) && g_SoundSuccess;
//			CloseHandle(threadHandle);
//
//		}
//	}
//
//	else if (LoadConpleate[0]) {
//		static bool clearCursol = false;
//		if (!clearCursol) {
//			g_cursolColor -= 2 << 24;
//		}
//		if (clearCursol) {
//			g_cursolColor += 2 << 24;
//		}
//
//		if (g_cursolColor == (0xffffffff))
//		{
//			clearCursol = true;
//		}
//		if (g_cursolColor <= (0xffffff))
//		{
//			clearCursol = false;
//		}
//
//		switch (g_scene) {
//		case SCENE_TEAMLOGO:
//			if (isFirst) {
//
//				g_SoundSuccess = soundsManager.Start("LOGO", false) && g_SoundSuccess;
//
//				isFirst = false;
//			}
//			g_SoundSuccess = soundsManager.SetVolume("FOOD", 25) && g_SoundSuccess;
//			teamlogoControl();
//			teamlogoRender();
//			break;
//		case SCENE_TITLE:
//			switch (g_titleScene)
//			{
//			case TITLE:
//				titleControl();
//				titleRender();
//				break;
//			case WISDOM:
//				wisdomControl();
//				wisdomRender();
//				break;
//			}
//			break;
//		case SCENE_MAIN:
//			if (g_isTimeUp)
//			{
//				g_isFirst = true;
//				g_isTimeUp = false;
//				g_timerCount = 0;
//				g_gameScene = FLOAMOVE;
//				switch (g_turn)
//				{
//
//				case 0:
//					g_turn = 1;
//					break;
//				case 1:
//					g_turn = 2;
//					break;
//				case 2:
//					g_turn = 0;
//
//					g_scene = SCENE_RESULT;
//					break;
//				}
//				Sleep(3000);
//
//			}
//			gameMain();
//			break;
//		case SCENE_RESULT:
//			result();
//			break;
//		}
//		CheckKeyState(DIK_ESCAPE);
//		if (KeyState[DIK_ESCAPE] == KeyRelease)
//		{
//			return WM_QUIT;
//		}
//		return WM_NULL;
//	}
//}
//
//void teamlogoControl(void) {
//	
//	static DWORD SyncOld = timeGetTime();
//	DWORD SyncNow = timeGetTime();
//	CheckKeyState(DIK_RETURN);
//	CheckKeyState(DIK_NUMPADENTER);
//	if (SyncNow - SyncOld > 4500)
//	{
//		g_scene = SCENE_TITLE;
//	}
//	if (KeyState[DIK_RETURN] == KeyRelease || KeyState[DIK_NUMPADENTER] == KeyRelease)
//	{
//			g_scene = SCENE_TITLE;
//	}
//	GetControl(0);
//	BottonCheck();
//	if (PadState[ButtonA] == PadRelease)
//	{
//		g_scene = SCENE_TITLE;
//	}
//
//}
//
//void teamlogoRender(void) {
//	CUSTOMVERTEX teamlogo[4];
//	CENTRAL_STATE logo{ 640,320,400,400 };
//	static DWORD logoColor = 0x00ffffff;
//	static bool canCleared = false;
//	if (!canCleared) {
//		logoColor += 2 << 24;
//	}
//	if (canCleared && (logoColor > 0xfffffff)) {
//		logoColor -= 2 << 24;
//	}
//	if (canCleared && (logoColor > 0xffffff)) {
//		logoColor -= 1 << 24;
//	}
//
//	if (logoColor == (0xfeffffff))
//	{
//		canCleared = true;
//	}
//
//	BeginSetTexture();
//	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT,"BLANK");
//
//	CreateSquareVertexColor(teamlogo, logo, logoColor);
//	SetUpTexture(teamlogo, "TEAMLOGO_TEX");
//
//	EndSetTexture();
//
//}
//
//void soundLoad() {
//	g_SoundSuccess = soundsManager.AddFile("Sound/foodbgm.mp3", "FOOD") && g_SoundSuccess;
//
//	g_SoundSuccess = soundsManager.AddFile("Sound/bottun.mp3", "BUTTON1") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/bottun.mp3", "BUTTON2") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/bottun.mp3", "BUTTON3") && g_SoundSuccess;
//
//	g_SoundSuccess = soundsManager.AddFile("Sound/Welcome.mp3", "GREETING") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/thankyou.mp3", "BOW") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/correct answer.mp3", "SUCCESS") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/mistake.mp3", "MISS") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/explosion.mp3", "ATTACK") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/timer.mp3", "TIME_LIMIT") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/salebgm.mp3", "HURRY_UP") && g_SoundSuccess;
//
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK1") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK2") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK3") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK4") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK5") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK6") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK7") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK8") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK9") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK10") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK11") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK12") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK13") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK14") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/shopping.mp3", "PICK15") && g_SoundSuccess;
//
//	g_SoundSuccess = soundsManager.AddFile("Sound/selectBGM.mp3", "SELECT") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/cursor.mp3", "CURSOR") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/gong.mp3", "GONG") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/whistle1.mp3", "WHISYLE") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/newop.mp3", "OP_BGM") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/select.mp3", "SELECT_BGM") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/clothBreak.mp3", "BREAK") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/stupid3.mp3", "LOSE") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/trumpet1.mp3", "WIN") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/select.mp3", "SELECT_BGM") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/clothBreak.mp3", "BREAK") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/stupid3.mp3", "LOSE") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/trumpet1.mp3", "WIN") && g_SoundSuccess;
//
//	g_SoundSuccess = soundsManager.AddFile("Sound/money.mp3", "COIN1") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/money.mp3", "COIN2") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/money.mp3", "COIN3") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/money.mp3", "COIN4") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/money.mp3", "COIN5") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/money.mp3", "COIN6") && g_SoundSuccess;
//
//	g_SoundSuccess = soundsManager.AddFile("Sound/madam.mp3", "WISDOM") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/cutin.mp3", "CUTIN") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/tin1.mp3", "LOW_SCORE") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/people.mp3", "MIDLE_SCORE") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/people2.mp3", "HIGH_SCORE") && g_SoundSuccess;
//
//	g_SoundSuccess = soundsManager.AddFile("Sound/sound.mp3", "LOGO") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/cash.mp3", "CASHER") && g_SoundSuccess;
//	g_SoundSuccess = soundsManager.AddFile("Sound/drum roll.mp3", "DRUM") && g_SoundSuccess;
//	//g_SoundSuccess = soundsManager.AddFile("Sound/.mp3", "") && g_SoundSuccess;
//
//}
//
//void setNowLoading(DWORD color)
//{
//	BeginSetTexture();
//	EasyCreateSquareVertex(0, 0, WIDTH, HEIGHT, "LOAD_TEX",color);
//	EndSetTexture();
//}
//
//void LoadTexture() {
//	switch (g_scene) {
//	case SCENE_TEAMLOGO:
//		ReadInTexture("Texture/Blank.jpg", "BLANK");
//		ReadInTexture("Texture/Yasuko.png", "YASUKO_TEX");
//		ReadInTexture("Texture/title.jpg", "TITLE_BG_TEX");
//		ReadInTexture("Texture/title_select.png", "TITLE_UI_TEX");
//		ReadInTexture("Texture/UI/pressA.png", "PRESS_TEX");
//
//		ReadInTexture("Texture/mob.png", "MOB_TEX");
//		ReadInTexture("Texture/team_logo.png", "TEAMLOGO_TEX");
//
//		ReadInTexture("Texture/Mituko.png", "MITUKO_TEX");
//		ReadInTexture("Texture/Isoko.png", "ISOKO_TEX");
//		ReadInTexture("Texture/UI/arrow.png", "TITLEICON_TEX");
//		ReadInTexture("Texture/wisdomP1.png", "WISDOM1_TEX");
//		ReadInTexture("Texture/wisdomP2.png", "WISDOM2_TEX");
//		ReadInTexture("Texture/wisdomP3.png", "WISDOM3_TEX");
//
//		ReadInTexture("Texture/button/a.png", "A_TEX");
//
//		break;
//	case SCENE_TITLE:
//		break;
//	case SCENE_MAIN:
//		ReadInTexture("Texture/UI/frame_goods.png", "FRAME_TEX");
//		ReadInTexture("Texture/effect.png", "YASUKO_EFFECT_TEX");
//
//		ReadInTexture("Texture/FoodSection.png", "FOOD_STAGE_TEX");
//		ReadInTexture("Texture/maxresdefault.png", "CUTIN_TEX");
//		ReadInTexture("Texture/bakuhuhathu.png", "EXPLOSION_TEX");
//		ReadInTexture("Texture/yasukoCutin.png", "CUTIN_YASUKO_TEX");
//		ReadInTexture("Texture/UI/durabilityBar.jpg", "DURABILITY_TEX");
//		ReadInTexture("Texture/smoke.png", "SMOKE_TEX");
//		ReadInTexture("Texture/boy.png", "BOY_TEX");
//		ReadInTexture("Texture/salesclerk.png", "SALESMAN_TEX");
//
//		ReadInTexture("Texture/UI/timerFrame.png", "TIMER_FRAME_TEX");
//		ReadInTexture("Texture/UI/timerHand.png", "TIMER_HAND_TEX");
//		ReadInTexture("Texture/UI/startCount3.png", "STARTCOUNT_3_TEX");
//		ReadInTexture("Texture/UI/startCount2.png", "STARTCOUNT_2_TEX");
//		ReadInTexture("Texture/UI/startCount1.png", "STARTCOUNT_1_TEX");
//		ReadInTexture("Texture/UI/salerogo.png", "START_TEX");
//		ReadInTexture("Texture/pauseMenu.png", "PAUSE_TEX");
//		ReadInTexture("Texture/UI/end.png", "TIMEUP_TEX");
//		ReadInTexture("Texture/stage.png", "FLOAMOVE_BG_TEX");
//
//		ReadInTexture("Texture/scoretext/s50e.png", "FIFTY_TEX");
//		ReadInTexture("Texture/scoretext/s60e.png", "SIXTY_TEX");
//		ReadInTexture("Texture/scoretext/s65e.png", "SIXTYFIVE_TEX");
//		ReadInTexture("Texture/scoretext/s100e.png", "HUNDRED_TEX");
//		ReadInTexture("Texture/scoretext/s150e.png", "HUNDREDFIFTY_TEX");
//		ReadInTexture("Texture/scoretext/s200e.png", "TWEHANDRED_TEX");
//		ReadInTexture("Texture/scoretext/s250e.png", "TWEHANDREDFIFTY_TEX");
//		ReadInTexture("Texture/scoretext/s300e.png", "THREEHANDRED_TEX");
//		ReadInTexture("Texture/scoretext/ss30e.png", "S_THRTY_TEX");
//		ReadInTexture("Texture/scoretext/ss40e.png", "S_FOURTY_TEX");
//		ReadInTexture("Texture/scoretext/ss50e.png", "S_FIFTY_TEX");
//		ReadInTexture("Texture/scoretext/ss60e.png", "S_SIXTY_TEX");
//		ReadInTexture("Texture/scoretext/ss70e.png", "S_SEVENTY_TEX");
//		ReadInTexture("Texture/scoretext/ss80e.png", "S_EIGHTY_TEX");
//		ReadInTexture("Texture/scoretext/ss100e.png", "S_HUNDRED_TEX");
//		ReadInTexture("Texture/scoretext/ss150e.png", "S_HUNDREDFIFTY_TEX");
//		ReadInTexture("Texture/scoretext/ss180e.png", "S_HUNDREDEIGHTY_TEX");
//		ReadInTexture("Texture/scoretext/ss200e.png", "S_TWEHUNDRED_TEX");
//
//		ReadInTexture("Texture/scoretext/t1.png", "T_1");
//		ReadInTexture("Texture/scoretext/t2.png", "T_2");
//		ReadInTexture("Texture/scoretext/t3.png", "T_3");
//		ReadInTexture("Texture/scoretext/t4.png", "T_4");
//		ReadInTexture("Texture/scoretext/t5.png", "T_5");
//
//		ReadInTexture("Texture/button/b.png", "B_TEX");
//		ReadInTexture("Texture/button/x.png", "X_TEX");
//		ReadInTexture("Texture/button/y.png", "Y_TEX");
//		ReadInTexture("Texture/button/r.png", "R_TEX");
//		ReadInTexture("Texture/button/l.png", "L_TEX");
//		ReadInTexture("Texture/button/button.png", "NULL_BUTTON_TEX");
//
//		ReadInTexture("Texture/merchandise/beef.png", "BEEF_TEX");
//		ReadInTexture("Texture/merchandise/chicken.png", "CHICKEN_TEX");
//		ReadInTexture("Texture/merchandise/pork.png", "PORK_TEX");
//		ReadInTexture("Texture/merchandise/wiener.png", "VIENNESE_TEX");
//		ReadInTexture("Texture/merchandise/mince.png", "MINCE_TEX");
//
//		ReadInTexture("Texture/merchandise/shrimp.png", "SHRIMP_TEX");
//		ReadInTexture("Texture/merchandise/octopus.png", "OCTOPUS_TEX");
//		ReadInTexture("Texture/merchandise/squid.png", "INKFISH_TEX");
//		ReadInTexture("Texture/merchandise/fish.png", "FISH_TEX");
//
//		ReadInTexture("Texture/merchandise/carrot.png", "GINESENG_TEX");
//		ReadInTexture("Texture/merchandise/onion.png", "ONION_TEX");
//		ReadInTexture("Texture/merchandise/potato.png", "POTATO_TEX");
//		ReadInTexture("Texture/merchandise/tomato.png", "TOMATO_TEX");
//		ReadInTexture("Texture/merchandise/radish.png", "RADISH_TEX");
//
//		ReadInTexture("Texture/merchandise/snack.png", "POTATOCHIPS_TEX");
//		ReadInTexture("Texture/merchandise/choco.png", "CHOCOLATE_TEX");
//		ReadInTexture("Texture/merchandise/ice.png", "ICE_TEX");
//		ReadInTexture("Texture/merchandise/ricecracker.png", "RICECRACKER_TEX");
//
//		ReadInTexture("Texture/merchandise/apple.png", "APPLE_TEX");
//		ReadInTexture("Texture/merchandise/orange.png", "ORANGE_TEX");
//		ReadInTexture("Texture/merchandise/banana.png", "BANANA_TEX");
//
//		ReadInTexture("Texture/merchandise/tea.png", "TEA_TEX");
//		ReadInTexture("Texture/merchandise/juice.png", "JUICE_TEX");
//		ReadInTexture("Texture/merchandise/beer.png", "BEER_TEX");
//
//		break;
//	case SCENE_RESULT:
//		ReadInTexture("Texture/result/result.png", "RESULT_BG_TEX");
//		ReadInTexture("Texture/result/resultLast.png", "RESULT_POP_TEX");
//		ReadInTexture("Texture/result/R_UI.png", "RESULT_END_TEX");
//		ReadInTexture("Texture/result/star1.png", "RESULT_STAR1_TEX");
//		ReadInTexture("Texture/result/star2.png", "RESULT_STAR2_TEX");
//		ReadInTexture("Texture/result/star3.png", "RESULT_STAR3_TEX");
//		ReadInTexture("Texture/result/point100.png", "RESULT_COMBOTEXT1_TEX");
//		ReadInTexture("Texture/result/point300.png", "RESULT_COMBOTEXT2_TEX");
//		ReadInTexture("Texture/result/point500.png", "RESULT_COMBOTEXT3_TEX");
//		ReadInTexture("Texture/result/bonus.png", "RESULT_COMBO_TEX");
//		ReadInTexture("Texture/result/SALE.png", "RESULT_SALE_TEX");
//		ReadInTexture("Texture/result/price.png", "RESULT_NOMAL_TEX");
//		ReadInTexture("Texture/yasuko_motion1.png", "YASUKO_EMOTION1_TEX");
//		ReadInTexture("Texture/yasuko_motion2.png", "YASUKO_EMOTION2_TEX");
//		ReadInTexture("Texture/yasuko_motion3.png", "YASUKO_EMOTION3_TEX");
//
//		ReadInTexture("Texture/merchandise/buridaikon.png", "BURIDAIKON_TEX");
//		ReadInTexture("Texture/merchandise/tsumami.png", "RELISH_TEX");
//		ReadInTexture("Texture/merchandise/teatime.png", "TEATIME_TEX");
//
//		ReadInTexture("Texture/merchandise/curry.png", "CURRY_TEX");
//		ReadInTexture("Texture/merchandise/hamberg.png", "HAMBERG_TEX");
//		ReadInTexture("Texture/merchandise/sashimi.png", "ASSORTEDSASHIMI_TEX");
//		ReadInTexture("Texture/merchandise/oyatsu.png", "AFTERNOONREFRESHMENT_TEX");
//
//		ReadInTexture("Texture/merchandise/soup.png", "SOUP_TEX");
//		ReadInTexture("Texture/merchandise/nimono.png", "NIMONO_TEX");
//		ReadInTexture("Texture/merchandise/parfait.png", "PARFAIT_TEX");
//
//		break;
//	}
//
//}
//void LoadFont() {
//	switch (g_scene) {
//	case SCENE_TEAMLOGO:
//	SetUpFont(100, 70, "HOGE_FONT", NULL);
//	SetUpFont(25, 25, "DEBUG_FONT", NULL);
//	SetUpFont(70, 50, "HAVEGOODS_FONT", NULL);
//	break;
//	case SCENE_RESULT:
//	SetUpFont(25, 20, "RESULT_FONT", NULL);
//	SetUpFont(70, 50, "SCORE_FONT", NULL);
//	SetUpFont(120, 75, "LAST_SCORE_FONT", NULL);
//	break;
//	}
//}