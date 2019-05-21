#include "setup.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"


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

	Player* player = new Player(myVector2(230.0, 540.0));
	std::deque<Bullet*> bullets;
	std::deque<Enemy*> enemys;
	
	for (int i = 1; i < 6; i++)
	{
		enemys.push_back(new Enemy(myVector2(50.0 * i, 50.0)));
	}


	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		DrawBox(0, 0, mySetup::battleX, mySetup::Y, GetColor(0, 0, 150), 1);

		// playerの状態更新
		player->move();
		player->fire(bullets);
		player->draw();

		// bulletsの状態更新
		for (Bullet* bul : bullets)
		{
			bul->move();
			// 当たった敵の消去フラグを立てる
			int j = 0;
			for (Enemy* en : enemys)
			{
				if (bul->checkHit(*en))
				{
					enemys.erase(enemys.begin() + j);
					bul->setRemoveFlag(true);
				}
				j++;
			}
			// 画面外の弾の消去フラグを立てる
			if (bul->getPos().x < 0 || bul->getPos().x > mySetup::battleX
				|| bul->getPos().y < 0 || bul->getPos().y > mySetup::Y)
			{
				bul->setRemoveFlag(true);
			}
			bul->draw();
		}

		// 弾の消去
		int itr = 0;
		for (Bullet* bul : bullets)
		{
			if (bul->getRemoveFlag())
			{
				bullets.erase(bullets.begin() + itr);
			}
			itr++;
		}

		// enemyの状態更新
		for (Enemy* en : enemys)
		{
			en->move();
			en->draw();
		}

		ScreenFlip();
	}

	// 以下終了処理

	delete player;

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