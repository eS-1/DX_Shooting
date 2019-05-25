#include "setup.h"
#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"


// �Q�[����ʂ̏�����
void GameInitialize(Player* &player, std::deque<Enemy*> &enemys)
{
	player = new Player(myVector2(230.0, 540.0));

	for (int i = 1; i < 6; i++)
	{
		enemys.push_back(new Enemy(myVector2(50.0 * i, 50.0)));
	}
}


// �Q�[����ʂ̍X�V
void GameUpdate(Player* &player, std::deque<Bullet*> &bullets, std::deque<Enemy*> &enemys)
{
	// ���j���[��ʂɑJ��
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		player = nullptr;

		for (Enemy* en : enemys)
		{
			delete en;
			enemys.pop_front();
		}

		for (Bullet* bul : bullets)
		{
			delete bul;
			bullets.pop_front();
		}

		SceneMgrChange(mySceneMenu);
	}
}


// �Q�[����ʂ̕`��
void GameDraw(Player* &player, std::deque<Bullet*> &bullets, std::deque<Enemy*> &enemys)
{
	DrawBox(0, 0, mySetup::battleX, mySetup::Y, GetColor(0, 0, 150), 1);

	DrawString(mySetup::battleX, 0, "'q'�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));

	// player�̏�ԍX�V
	player->move();
	player->fire(bullets);
	player->draw();

	// enemy�̏�ԍX�V
	for (Enemy* en : enemys)
	{
		en->move();
		en->draw();
	}

	// bullets�̏�ԍX�V
	for (Bullet* bul : bullets)
	{
		bul->move();
		// ���������G�̏����t���O�𗧂Ă�
		for (Enemy* en : enemys)
		{
			if (bul->checkHit(*en))
			{
				en->setRemoveFlag(true);
				bul->setRemoveFlag(true);
			}
		}
		// ��ʊO�̒e�̏����t���O�𗧂Ă�
		if (bul->getPos().x < 0 || bul->getPos().x > mySetup::battleX
			|| bul->getPos().y < 0 || bul->getPos().y > mySetup::Y)
		{
			bul->setRemoveFlag(true);
		}
		bul->draw();
	}

	// �G�̏���
	bool isRemove;
	while (true)
	{
		isRemove = true;
		for (int i = 0; i < enemys.size(); i++)
		{
			if (enemys[i]->getRemoveFlag())
			{
				enemys.erase(enemys.begin() + i);
				isRemove = false;
				break;
			}
		}
		if (isRemove)
		{
			break;
		}
	}

	// �e�̏���
	while (true)
	{
		isRemove = true;
		for (int i = 0; i < bullets.size(); i++)
		{
			if (bullets[i]->getRemoveFlag())
			{
				bullets.erase(bullets.begin() + i);
				isRemove = false;
				break;
			}
		}
		if (isRemove)
		{
			break;
		}
	}
}