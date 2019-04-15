#include "setup.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	SetGraphMode(mySetup::X, mySetup::Y, GetColorBitDepth());

	// DXLib������
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	Player* player = new Player;
	std::deque<Enemy*> enemys;
	
	for (int i = 1; i < 6; i++)
	{
		enemys.push_back(new Enemy(myVector2(50.0 * i, 50.0)));
	}

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();

		// player�̏�ԍX�V
		player->move();
		player->fire();
		player->draw();

		// bullets�̏�ԍX�V
		for (int i = 0; i < player->getBullets().size(); i++)
		{
			player->getBullets()[i]->move();
			for (int j = 0; j < enemys.size(); j++)
			{
				if (player->getBullets()[i]->getPos().distanceFrom(enemys[j]->getPos()) <= 15)
				{
					Enemy* en = enemys[j];
					enemys.erase(enemys.begin() + j);
					delete en;
				}
			}
			player->getBullets()[i]->draw();
		}

		// ��ʊO�̒e������
		player->eraseBullet();

		// enemy�̏�ԍX�V
		for (Enemy* en : enemys)
		{
			en->move();
			en->draw();
		}

		ScreenFlip();
	}

	delete player;

	for (Enemy* en : enemys)
	{
		delete en;
	}

	DxLib_End();

	return 0;
}