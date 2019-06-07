#include <algorithm>
#include "setup.h"
#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"


// vector�̍ŏ��l�̃C�e���[�^��Ԃ��֐�
std::vector<unsigned int>::iterator MinItrOfVector(std::vector<unsigned int>& result)
{
	auto minItr = result.begin();
	for (auto itr = result.begin(); itr != result.end(); itr++)
	{
		if (*minItr > *itr) { minItr = itr; }
	}
	return minItr;
}


// �Q�[����ʂ̏�����
void GameInitialize(Player*& player, std::vector<Enemy*>& enemys)
{
	player = new Player(myVector2(230.0, 540.0));

	for (int i = 1; i < 6; i++)
	{
		enemys.push_back(new Enemy(myVector2(50.0 * i, 50.0)));
	}
}


// �Q�[����ʂ̍X�V
void GameUpdate(Player*& player, std::vector<Bullet*>& bullets, std::vector<Enemy*>& enemys)
{
	// ���j���[��ʂɑJ��
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		delete player;
		player = nullptr;

		// enemy�̏���
		for (Enemy* en : enemys) { delete en; }
		enemys.clear();

		// bullet�̏���
		for (Bullet* bul : bullets) { delete bul; }
		bullets.clear();
		
		// ���U���g�X�R�A�ɃQ�[���X�R�A��ǉ�
		auto minItr = MinItrOfVector(mySetup::resultScores);
		if (mySetup::gameScore > *minItr)
		{
			*minItr = mySetup::gameScore;
			std::sort(mySetup::resultScores.begin(), mySetup::resultScores.end(),
				std::greater<std::vector<int>::value_type>());
		}

		// �Q�[���X�R�A�̃��Z�b�g
		mySetup::gameScore = 0;

		SceneMgrChange(mySceneMenu);
		return;
	}

	// player�̏�ԍX�V
	if (player != nullptr)
	{
		player->move();
	    player->fire(bullets);
	}

	// enemy�̏�ԍX�V
	for (Enemy* en : enemys)
	{
		en->move();
		en->fire(bullets);
	}

	// bullets�̏�ԍX�V
	for (Bullet* bul : bullets)
	{
		bul->move();
		// �v���C���[�ɓ����������̏���
		if (player != nullptr)
		{
			if (bul->checkHit(*player) && bul->getIsEnBul())
			{
				player->setRemoveFlag(true);
			}
		}
		// ���������G�̏����t���O�𗧂Ă�
		for (Enemy* en : enemys)
		{
			if (bul->checkHit(*en) && bul->getIsPlaBul())
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
	}

	if (player != nullptr)
	{
		if (player->getRemoveFlag())
		{
			delete player;
			player = nullptr;
		}
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
				delete enemys[i];
				enemys.erase(enemys.begin() + i);
				mySetup::gameScore++;
				isRemove = false;
				break;
			}
		}
		if (isRemove) { break; }
	}

	// �e�̏���
	while (true)
	{
		isRemove = true;
		for (int i = 0; i < bullets.size(); i++)
		{
			if (bullets[i]->getRemoveFlag())
			{
				delete bullets[i];
				bullets.erase(bullets.begin() + i);
				isRemove = false;
				break;
			}
		}
		if (isRemove) { break; }
	}
}


// �Q�[����ʂ̕`��
void GameDraw(Player*& player, std::vector<Bullet*>& bullets, std::vector<Enemy*>& enemys)
{
	DrawBox(0, 0, mySetup::battleX, mySetup::Y, GetColor(0, 0, 150), 1);

	DrawString(mySetup::battleX, 0, "'q'�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));
	DrawFormatString(mySetup::battleX, 20, GetColor(255, 255, 255), "�X�R�A�F%d", mySetup::gameScore);

	// player�̕`��
	if (player != nullptr)
	{
		player->draw();

		if (enemys.empty())
		{
			DrawFormatString(mySetup::battleX * 3 / 7, mySetup::Y / 2, GetColor(255, 0, 0), "Game Clear!!");
		}
	}
	else
	{
		DrawFormatString(mySetup::battleX * 3 / 7, mySetup::Y / 2, GetColor(255, 0, 0), "Game Over");
	}

	// enemy�̕`��
	for (Enemy* en : enemys) { en->draw(); }

	// bullets�̕`��
	for (Bullet* bul : bullets) { bul->draw(); }
}