#include <algorithm>
#include <time.h>
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/Game.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


// �e�̑S����
void EraseAllBullets()
{
	obj::bullets.clear();
	obj::bullets.shrink_to_fit();
	obj::enBullets.clear();
	obj::enBullets.shrink_to_fit();
}


// �G�̒e���W������
void EraseEnemyBullets()
{
	for (const auto& enBul : obj::enBullets)
	{
		enBul->setDirection(myVector2(0.0, 0.0));
		enBul->setPosition(myVector2(5000.0, 5000.0));
	}
}


// �Q�[����ʂ̏�����
void Game_Init()
{
	// ���@�̐���
	obj::player.reset(new Player(myVector2(mySetup::X / 2, mySetup::Y * 7 / 8)));

	// ���@�̒e����
	for (int i = 0; i < 30; i++)
	{
		std::unique_ptr<MyObject> bul(new Bullet(myVector2(5000.0, 5000.0), myVector2(0.0, 0.0)));
		bul->setRemoveFlag(true);
		bul->setIsPlaBul(true);
		obj::bullets.push_back(std::move(bul));
	}

	// �G�̒e����
	for (int i = 0; i < 50; i++)
	{
		std::unique_ptr<MyObject> bul(new Bullet(myVector2(5000.0, 5000.0), myVector2(0.0, 0.0)));
		bul->setRemoveFlag(true);
		obj::enBullets.push_back(std::move(bul));
	}

	// �G�̐���
	int rand_y;
	switch (mySetup::diff)
	{
	case difficulty::easy:
		for (int i = 1; i < 6; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.emplace_back(new Enemy(myVector2(260.0 * i + 20, rand_y - 140.0)));
		}
		break;
	case difficulty::normal:
		for (int i = 1; i < 8; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.emplace_back(new Enemy(myVector2(200.0 * i, rand_y - 140.0)));
		}
		break;
	case difficulty::hard:
		for (int i = 1; i < 13; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.emplace_back(new Enemy(myVector2(130.0 * i - 50, rand_y - 140.0)));
		}
		break;
	case difficulty::extreme:
		for (int i = 1; i < 16; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.emplace_back(new Enemy(myVector2(100.0 * i - 50, rand_y - 140.0)));
		}
	default:
		break;
	}

	// �^�C�}�[�̏�����
	startTime = time(NULL);
	remainingTime = 60;

	// �^�C���I�[�o�[�t���O�̏�����
	isTimeOver = false;

	// �Q�[���I�[�o�[�t���O�̏�����
	isGameOver = false;

	// �|�[�Y�t���O�̏�����
	isPose = false;

	// ���j���[��ʂɖ߂�t���O�̏�����
	isQuit = false;
}


// �Q�[����ʂ̍X�V
void GameUpdate()
{
	setup::KeyInput();

	if (isGameOver || isTimeOver)
	{
		if ((keyInput::Q & ~keyInput::old_Q) || ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_10))
		{
			isQuit = true;
		}
	}
	else
	{
		if (!isPose && (keyInput::Q || (keyInput::pad & PAD_INPUT_10)))
		{
			// �|�[�Y��ʂ̃t���O�����Ă�
			isPose = true;
			return;
		}

		if (isPose)
		{
			if ((keyInput::E & ~keyInput::old_E) || ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_2))
			{
				isPose = false;
			}
			else if ((keyInput::Q & ~keyInput::old_Q) || ((keyInput::pad & ~keyInput::old_pad) & PAD_INPUT_3))
			{
				isQuit = true;
			}
			else
			{
				return;
			}
		}
	}

	// ���j���[��ʂɑJ��
	if (isQuit)
	{
		bool SaveNameFlag = false;

		obj::player = nullptr;

		// enemy�̏���
		obj::enemys.clear();
		obj::enemys.shrink_to_fit();

		// bullet�̏���
		EraseAllBullets();
		
		// ���U���g�X�R�A�ɃQ�[���X�R�A��ǉ�
		auto minItr = setup::MinItrOfVector(mySetup::resultScores);
		if (mySetup::gameScore > minItr->first)
		{
			SaveNameFlag = true;
		}

		isGameOver = false;
		isPose = false;

		if (SaveNameFlag)
		{
			SceneMgrChange(myScene::mySceneSaveName);
		}
		else
		{
			mySetup::gameScore = 0;
			SceneMgrChange(myScene::mySceneMenu);
		}

		return;
	}

	if (remainingTime <= 0)
	{
		isTimeOver = true;
		return;
	}

	// player�̏�ԍX�V
	if (!(obj::player->getRemoveFlag()))
	{
		obj::player->move();
	    obj::player->fire();

		// �^�C�}�[�̃J�E���g�_�E��
		diffTime = time(NULL) - startTime;
		if (diffTime >= 1)
		{
			remainingTime--;
			startTime = time(NULL);
		}
	}

	// enemy�̏�ԍX�V
	for (const auto& en : obj::enemys)
	{
		en->move();
		en->fire();
	}

	// bullets�̏�ԍX�V
	for (const auto& bul : obj::bullets)
	{
		if (!(bul->getRemoveFlag()))
		{
			bul->move();
			// ���������G�̏�������
			for (const auto& en : obj::enemys)
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
			if (bul->getPosition().x < -50 || bul->getPosition().x > mySetup::X + 50.0
				|| bul->getPosition().y < -50 || bul->getPosition().y > mySetup::Y + 50.0)
			{
				bul->setRemoveFlag(true);
			}
		}
	}

	// enBullets�̏�ԍX�V
	for (const auto& enBul : obj::enBullets)
	{
		if (!(enBul->getRemoveFlag()))
		{
			enBul->move();
			// �v���C���[�ɓ����������̏���
			if (!(obj::player->getRemoveFlag()))
			{
				if (enBul->checkHit(*obj::player))
				{
					obj::player->setRemoveFlag(true);
					enBul->setRemoveFlag(true);
				}
			}
			// ��ʊO�̒e�̏����t���O�𗧂Ă�
			if (enBul->getPosition().x < -50 || enBul->getPosition().x > mySetup::X + 50.0
				|| enBul->getPosition().y < -50 || enBul->getPosition().y > mySetup::Y + 50.0)
			{
				enBul->setRemoveFlag(true);
			}
		}
	}

	// ���@�̏���
	if (obj::player->getRemoveFlag())
	{
		obj::player->setPosition(myVector2(6000.0, 6000.0));
		isGameOver = true;
	}

	// ���@�̒e����(���W������)
	for (const auto& bul : obj::bullets)
	{
		if (bul->getRemoveFlag())
		{
			bul->setDirection(myVector2(0.0, 0.0));
			bul->setPosition(myVector2(5000.0, 5000.0));
		}
	}

	// �G�̒e����(���W������)
	for (const auto& enBul : obj::enBullets)
	{
		if (enBul->getRemoveFlag())
		{
			enBul->setDirection(myVector2(0.0, 0.0));
			enBul->setPosition(myVector2(5000.0, 5000.0));
		}
	}
}


// �Q�[����ʂ̕`��
void GameDraw()
{
	// player�̕`��
	if (obj::player != nullptr && !(obj::player->getRemoveFlag())) { obj::player->draw(); }

	// enemy�̕`��
	for (const auto& en : obj::enemys)
	{
		if (!(en->getRemoveFlag()))
		{
			en->draw();
		}
	}

	// bullets�̕`��
	for (const auto& bul : obj::bullets)
	{
		if (!(bul->getRemoveFlag()))
		{
			bul->draw();
		}
	}

	// enBullets�̕`��
	for (const auto& enBul : obj::enBullets)
	{
		if (!(enBul->getRemoveFlag()))
		{
			enBul->draw();
		}
	}

	DrawFormatStringToHandle(0, 0, GetColor(255, 255, 255), obj::fontInGame, "score�F%d", mySetup::gameScore);
	DrawFormatStringToHandle(0, 30, GetColor(255, 255, 255), obj::fontInGame, "remaining time: %d", remainingTime);

	if (isGameOver)
	{
		DrawStringToHandle(mySetup::X * 3 / 8, mySetup::Y * 3 / 7, "Game Over", GetColor(255, 0, 0), obj::fontTitle);
		DrawStringToHandle(mySetup::X * 3 / 8 + 30, mySetup::Y * 3 / 7 + 80,
			"Press Q to back menu", GetColor(255, 255, 255), obj::fontInGame);
		return;
	}

	if (isTimeOver)
	{
		DrawStringToHandle(mySetup::X * 3 / 8, mySetup::Y * 3 / 7, "Time Over", GetColor(0, 255, 0), obj::fontTitle);
		DrawStringToHandle(mySetup::X * 3 / 8 + 30, mySetup::Y * 3 / 7 + 80,
			               "Press Q to back menu", GetColor(255, 255, 255), obj::fontInGame);
		return;
	}

	if (isPose)
	{
		DrawBox(mySetup::X / 4, mySetup::Y / 4, mySetup::X * 3 / 4, mySetup::Y * 3 / 4, GetColor(128, 128, 128), true);
		DrawFormatStringToHandle(mySetup::X * 3 / 7, mySetup::Y / 4, GetColor(255, 255, 255), obj::fontInGame, "Pose Menu");
		DrawFormatStringToHandle(mySetup::X / 3, mySetup::Y * 3 / 7,
			GetColor(255, 255, 255), obj::fontInGame, "Q: back to main menu");
		DrawFormatStringToHandle(mySetup::X / 3, mySetup::Y * 3 / 7 + 40,
			GetColor(255, 255, 255), obj::fontInGame, "E: continue");
	}
}
