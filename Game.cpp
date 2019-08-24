#include <algorithm>
#include <time.h>
#include "setup.h"
#include "Objects.h"
#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"


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


// �e�̑S����
void EraseAllBullets()
{
	for (Bullet* bul : obj::bullets) { delete bul; }
	for (Bullet* bul : obj::enBullets) { delete bul; }
	obj::bullets.clear();
	obj::enBullets.clear();
}


// �G�̒e���W������
void EraseEnemyBullets()
{
	for (Bullet* bul : obj::enBullets)
	{
		bul->setDirection(myVector2(0.0, 0.0));
		bul->setPosition(myVector2(10.0, -5.0));
	}
}


// �Q�[����ʂ̏�����
void Game_Init()
{
	// ���@�̐���
	obj::player = new Player(myVector2(mySetup::allX / 2, mySetup::Y * 7 / 8));
	// ���@�̒e����
	for (int i = 0; i < 30; i++)
	{
		Bullet* bul = new Bullet(myVector2(5.0, -5.0), myVector2(0.0, 0.0));
		bul->setRemoveFlag(true);
		bul->setIsPlaBul(true);
		obj::bullets.push_back(bul);
	}
	// �G�̒e����
	for (int i = 0; i < 50; i++)
	{
		Bullet* bul = new Bullet(myVector2(10.0, -5.0), myVector2(0.0, 0.0));
		bul->setRemoveFlag(true);
		obj::enBullets.push_back(bul);
	}
	// �G�̐���
	int rand_y;
	switch (mySetup::diff)
	{
	case easy:
		for (int i = 1; i < 6; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.push_back(new Enemy(myVector2(80.0 * i, rand_y - 140.0)));
		}
		break;
	case normal:
		for (int i = 1; i < 9; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.push_back(new Enemy(myVector2(80.0 * i, rand_y - 140.0)));
		}
		break;
	case hard:
		for (int i = 1; i < 13; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.push_back(new Enemy(myVector2(60.0 * i, rand_y - 140.0)));
		}
		break;
	case extreme:
		for (int i = 1; i < 16; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.push_back(new Enemy(myVector2(60.0 * i, rand_y - 140.0)));
		}
	default:
		break;
	}
	// �^�C�}�[�̏�����
	obj::startTime = time(NULL);
	obj::remainingTime = 60;
}


// �Q�[����ʂ̍X�V
void GameUpdate()
{
	// ���j���[��ʂɑJ��
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		delete obj::player;
		obj::player = nullptr;

		// enemy�̏���
		for (Enemy* en : obj::enemys) { delete en; }
		obj::enemys.clear();

		// bullet�̏���
		EraseAllBullets();
		
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
	if (obj::player != nullptr)
	{
		obj::player->move();
	    obj::player->fire(obj::bullets);

		// �^�C�}�[�̃J�E���g�_�E��
		obj::diffTime = time(NULL) - obj::startTime;
		if (obj::diffTime == 1)
		{
			obj::remainingTime--;
			obj::startTime = time(NULL);
		}
	}

	// enemy�̏�ԍX�V
	for (Enemy* en : obj::enemys)
	{
		en->move();
		en->fire(obj::enBullets);
	}

	// bullets�̏�ԍX�V
	for (Bullet* bul : obj::bullets)
	{
		if (!bul->getRemoveFlag())
		{
			bul->move();
			// ���������G�̏�������
			for (Enemy* en : obj::enemys)
			{
				if (bul->checkHit(*en))
				{
					en->setIsReached(true);
					en->setPosition(en->getInitPosition());
					bul->setRemoveFlag(true);
					mySetup::gameScore++;
				}
			}
			// ��ʊO�̒e�̏����t���O�𗧂Ă�
			if (bul->getPosition().x < -50 || bul->getPosition().x > mySetup::allX + 50.0
				|| bul->getPosition().y < -50 || bul->getPosition().y > mySetup::Y + 50.0)
			{
				bul->setRemoveFlag(true);
			}
		}
	}

	// enBullets�̏�ԍX�V
	for (Bullet* bul : obj::enBullets)
	{
		if (!bul->getRemoveFlag())
		{
			bul->move();
			// �v���C���[�ɓ����������̏���
			if (obj::player != nullptr)
			{
				if (bul->checkHit(*obj::player))
				{
					obj::player->setRemoveFlag(true);
					bul->setRemoveFlag(true);
				}
			}
			// ��ʊO�̒e�̏����t���O�𗧂Ă�
			if (bul->getPosition().x < -50 || bul->getPosition().x > mySetup::allX + 50.0
				|| bul->getPosition().y < -50 || bul->getPosition().y > mySetup::Y + 50.0)
			{
				bul->setRemoveFlag(true);
			}
		}
	}

	// ���@�̏���
	if (obj::player != nullptr && obj::player->getRemoveFlag())
	{
		delete obj::player;
		obj::player = nullptr;
	}

	// ���@�̒e����(���W������)
	for (Bullet* bul : obj::bullets)
	{
		if (bul->getRemoveFlag())
		{
			bul->setDirection(myVector2(0.0, 0.0));
			bul->setPosition(myVector2(5.0, -5.0));
		}
	}

	// �G�̒e����(���W������)
	for (Bullet* bul : obj::enBullets)
	{
		if (bul->getRemoveFlag())
		{
			bul->setDirection(myVector2(0.0, 0.0));
			bul->setPosition(myVector2(10.0, -5.0));
		}
	}
}


// �Q�[����ʂ̕`��
void GameDraw()
{
	DrawBox(0, 0, mySetup::allX, mySetup::Y, GetColor(0, 0, 150), 1);

	DrawString(0, 0, "q�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));
	DrawFormatString(0, 20, GetColor(255, 255, 255), "�X�R�A�F%d", mySetup::gameScore);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "remaining time: %d", obj::remainingTime);

	// player�̕`��
	if (obj::player != nullptr)
	{
		obj::player->draw();
	}
	else
	{
		DrawFormatString(mySetup::allX * 4 / 9, mySetup::Y / 2, GetColor(255, 0, 0), "Game Over");
	}

	// enemy�̕`��
	for (Enemy* en : obj::enemys) { en->draw(); }

	// bullets�̕`��
	for (Bullet* bul : obj::bullets) { bul->draw(); }

	// enBuollets�̕`��
	for (Bullet* bul : obj::enBullets) { bul->draw(); }
}
