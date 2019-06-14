#include <algorithm>
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
	obj::bullets.clear();
}


// �Q�[����ʂ̏�����
void GameInitialize()
{
	obj::player = new Player(myVector2(230.0, 540.0));

	int enemyNum = 0;

	switch (mySetup::diff)
	{
	case easy:
		enemyNum = 3;
		break;
	case normal:
		enemyNum = 5;
		break;
	case hard:
		enemyNum = 8;
		break;
	case extreme:
		enemyNum = 10;
	default:
		break;
	}
	for (int i = 0; i < enemyNum; i++)
	{
		obj::enemys.push_back(new Enemy(myVector2(40.0 * i, 50.0)));
	}
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

	// �Q�[���N���A���ɒe��S����
	if (obj::enemys.empty())
	{
		EraseAllBullets();
	}

	// player�̏�ԍX�V
	if (obj::player != nullptr)
	{
		obj::player->move();
	    obj::player->fire(obj::bullets);
	}

	// enemy�̏�ԍX�V
	for (Enemy* en : obj::enemys)
	{
		en->move();
		en->fire(obj::bullets);
	}

	// bullets�̏�ԍX�V
	for (Bullet* bul : obj::bullets)
	{
		bul->move();
		// �v���C���[�ɓ����������̏���
		if (obj::player != nullptr)
		{
			if (bul->checkHit(*obj::player) && bul->getIsEnBul())
			{
				obj::player->setRemoveFlag(true);
				bul->setRemoveFlag(true);
			}
		}
		// ���������G�̏����t���O�𗧂Ă�
		for (Enemy* en : obj::enemys)
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

	if (obj::player != nullptr && obj::player->getRemoveFlag())
	{
		delete obj::player;
		obj::player = nullptr;
	}

	// �G�̏���
	bool isRemove;
	while (true)
	{
		isRemove = true;
		for (int i = 0; i < obj::enemys.size(); i++)
		{
			if (obj::enemys[i]->getRemoveFlag())
			{
				delete obj::enemys[i];
				obj::enemys.erase(obj::enemys.begin() + i);
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
		for (int i = 0; i < obj::bullets.size(); i++)
		{
			if (obj::bullets[i]->getRemoveFlag())
			{
				delete obj::bullets[i];
				obj::bullets.erase(obj::bullets.begin() + i);
				isRemove = false;
				break;
			}
		}
		if (isRemove) { break; }
	}
}


// �Q�[����ʂ̕`��
void GameDraw()
{
	DrawBox(0, 0, mySetup::battleX, mySetup::Y, GetColor(0, 0, 150), 1);

	DrawString(mySetup::battleX, 0, "'q'�L�[�Ń��j���[�ɖ߂�", GetColor(255, 255, 255));
	DrawFormatString(mySetup::battleX, 20, GetColor(255, 255, 255), "�X�R�A�F%d", mySetup::gameScore);

	// player�̕`��
	if (obj::player != nullptr)
	{
		obj::player->draw();

		if (obj::enemys.empty())
		{
			DrawFormatString(mySetup::battleX * 4 / 9, mySetup::Y / 2, GetColor(255, 0, 0), "Game Clear!!");
		}
	}
	else
	{
		DrawFormatString(mySetup::battleX * 3 / 7, mySetup::Y / 2, GetColor(255, 0, 0), "Game Over");
	}

	// enemy�̕`��
	for (Enemy* en : obj::enemys) { en->draw(); }

	// bullets�̕`��
	for (Bullet* bul : obj::bullets) { bul->draw(); }
}