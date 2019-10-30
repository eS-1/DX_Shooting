#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/SceneMgr.h"
#include "../header/Menu.h"
#include "DxLib.h"
#include "../resource1.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	ChangeWindowMode(1);

	SetGraphMode(mySetup::X, mySetup::Y, GetColorBitDepth());

	SetMainWindowText("Simple Shooter 2D");

	SetWindowIconID(IDI_ICON1);

	// initialize of DXLib
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	// フォント作成
	obj::fontTitle = CreateFontToHandle(NULL, 60, 3, DX_FONTTYPE_ANTIALIASING);
	obj::fontInGame = CreateFontToHandle(NULL, 30, 3, DX_FONTTYPE_ANTIALIASING);

	// ゲーム終了フラグの初期化
	Menu::exitFlag = false;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SceneMgrUpdate();
		SceneMgrDraw();

		if (Menu::exitFlag) { break; }
	}

	// 以下終了処理

	DeleteFontToHandle(obj::fontTitle);
	DeleteFontToHandle(obj::fontInGame);

	Objects_End();

	DxLib_End();

	return 0;
}