#include "setup.h"
#include "Objects.h"
#include "SceneMgr.h"
#include "DxLib.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	ChangeWindowMode(1);

	SetGraphMode(mySetup::allX, mySetup::Y, GetColorBitDepth());

	SetMainWindowText("2Dシューティング(仮)");

	// initialize of DXLib
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	// フォント作成
	obj::fontTitle = CreateFontToHandle(NULL, 40, 3, DX_FONTTYPE_ANTIALIASING);
	obj::fontInGame = CreateFontToHandle(NULL, 20, 3, DX_FONTTYPE_ANTIALIASING);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SceneMgrUpdate();
		SceneMgrDraw();

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { break; }
	}

	// 以下終了処理

	DeleteFontToHandle(obj::fontTitle);
	DeleteFontToHandle(obj::fontInGame);

	Objects_End();

	DxLib_End();

	return 0;
}