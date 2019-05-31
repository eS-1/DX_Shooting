#include <algorithm>
#include "setup.h"
#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"


// array�̍ŏ��l��Ԃ��֐�
unsigned int MinOfArray(std::array<unsigned int, 5> result)
{
	if (!result.empty())
	{
		unsigned int mini = UINT_MAX;
		for (auto num : result)
		{
			if (num < mini) { mini = num; }
		}
		return mini;
	}
	return 0;
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
		player = nullptr;

		// enemy�̏���
		for (Enemy* en : enemys) { delete en; }
		enemys.clear();

		// bullet�̏���
		for (Bullet* bul : bullets) { delete bul; }
		bullets.clear();

		// ���U���g�X�R�A�ɃQ�[���X�R�A��ǉ�
		if (mySetup::gameScore > MinOfArray(mySetup::resultScores))
		{
			mySetup::resultScores[0] = mySetup::gameScore;
			std::sort(mySetup::resultScores.begin(), mySetup::resultScores.end());
		}

		// �Q�[���X�R�A�̃��Z�b�g
		mySetup::gameScore = 0;

		SceneMgrChange(mySceneMenu);
		return;
	}

	// player�̏�ԍX�V
	player->move();
	player->fire(bullets);

	// enemy�̏�ԍX�V
	for (Enemy* en : enemys) { en->move(); }

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
	player->draw();

	// enemy�̕`��
	for (Enemy* en : enemys) { en->draw(); }

	// bullets�̕`��
	for (Bullet* bul : bullets) { bul->draw(); }
}