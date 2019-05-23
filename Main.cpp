#include "setup.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"
#include "SceneMgr.h"


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	ChangeWindowMode(TRUE);

	SetGraphMode(mySetup::battleX + mySetup::subX, mySetup::Y, GetColorBitDepth());

	// initialize of DXLib
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	static Player* player;
	static std::deque<Bullet*> bullets;
	static std::deque<Enemy*> enemys;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
	{
		SceneMgrUpdate(player, bullets, enemys);
		SceneMgrDraw(player, bullets, enemys);

		if (CheckHitKey(KEY_INPUT_ESCAPE) != 0)
		{
			break;
		}
	}

	// à»â∫èIóπèàóù

	if (player != nullptr)
	{
		delete player;
	}

	for (Enemy* en : enemys)
	{
		delete en;
	}

	for (Bullet* bul : bullets)
	{
		delete bul;
	}


	DxLib_End();
	return 0;
}