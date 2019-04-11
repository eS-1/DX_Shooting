#include "setup.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	SetGraphMode(mySetup::X, mySetup::Y, GetColorBitDepth());

	// DXLib初期化
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	Player* player = new Player;
	Enemy* enemy = new Enemy;

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		// playerの状態更新
		player->move();
		player->fire();
		player->draw();

		// bulletsの状態更新
		for (int i = 0; i < player->getBullets().size(); i++)
		{
			player->getBullets()[i]->move();
			if (enemy != nullptr && player->getBullets()[i]->getPos().distanceFrom(enemy->getPos()) <= 10)
			{
				delete enemy;
				enemy = nullptr;

				
				/* ここで敵に当たった弾を消したい
				Bullet* bul = player->getBullets()[i];
				player->getBullets().erase(player->getBullets().begin() + i);
				delete bul;
				
				continue;
				*/
			}
			player->getBullets()[i]->draw();
		}

		// 画面外の弾を消す
		player->eraseBullet();

		// enemyの状態更新
		if (enemy != nullptr)
		{
			enemy->move();
			enemy->draw();
		}

		ScreenFlip();
	}

	delete player;
	delete enemy;

	DxLib_End();

	return 0;
}