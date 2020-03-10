#include <algorithm>
#include <time.h>
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/Game.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


namespace
{
	time_t startTime;
	time_t diffTime;
	int remainingTime;
	bool isTimeOver;
	bool isGameOver;
	bool isPose;
	bool isQuit;
	PoseSelect poseSelection;
}

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
	int enemySpawn = 0;
	double xInitPos = 0.0;
	switch (mySetup::diff)
	{
	case difficulty::easy:
		enemySpawn = 6;
		xInitPos = 260.0;
		break;
	case difficulty::normal:
		enemySpawn = 8;
		xInitPos = 200.0;
		break;
	case difficulty::hard:
		enemySpawn = 13;
		xInitPos = 130.0;
		break;
	case difficulty::extreme:
		enemySpawn = 16;
		xInitPos = 100.0;
	default:
		break;
	}
	for (int i = 1; i < enemySpawn; i++)
	{
		int rand_y = GetRand(100);
		obj::enemys.emplace_back(new Enemy(myVector2(xInitPos * i + 20, rand_y - 140.0)));
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
		if ((Input::Q & ~Input::old_Q) || ((Input::pad & ~Input::old_pad) & PAD_INPUT_10))
		{
			isQuit = true;
		}
	}
	else
	{
		if (!isPose && (Input::Q || (Input::pad & PAD_INPUT_10)))
		{
			// �|�[�Y��ʂ̃t���O�����Ă�
			isPose = true;
			return;
		}

		if (isPose)
		{
			if (((Input::W & ~Input::old_W) ||
				((Input::pad & ~Input::old_pad) & PAD_INPUT_UP)) &&
				poseSelection > PoseSelect::restart)
			{
				int current = static_cast<int>(poseSelection);
				poseSelection = static_cast<PoseSelect>(current - 1);
				return;
			}
			else if (((Input::S & ~Input::old_S) ||
				((Input::pad & ~Input::old_pad) & PAD_INPUT_DOWN)) &&
				poseSelection < PoseSelect::exit)
			{
				int current = static_cast<int>(poseSelection);
				poseSelection = static_cast<PoseSelect>(current + 1);
				return;
			}
			else if ((Input::space & ~Input::old_space) ||
				     (Input::pad & ~Input::old_pad) & PAD_INPUT_3)
			{
				switch (poseSelection)
				{
				case PoseSelect::restart:
					isPose = false;
					return;
				case PoseSelect::exit:
					isQuit = true;
					break;
				default:
					break;
				}
				poseSelection = PoseSelect::restart;
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
		std::vector<scorePair>::iterator minItr = setup::MinItrOfVector(mySetup::resultScores);
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
	using namespace mySetup;

	// player�̕`��
	if (obj::player != nullptr && !(obj::player->getRemoveFlag()))
	{
		obj::player->draw();
	}

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

	DrawFormatStringToHandle(0, 0, GetColor(255, 255, 255), obj::fontInGame, "score�F%d", gameScore);
	DrawFormatStringToHandle(0, 30, GetColor(255, 255, 255), obj::fontInGame, "remaining time: %d", remainingTime);

	if (isGameOver)
	{
		DrawStringToHandle(X * 3 / 8, Y * 3 / 7, "Game Over", GetColor(255, 0, 0), obj::fontTitle);
		DrawStringToHandle(X * 3 / 8 + 30, Y * 3 / 7 + 80, "Press Q to back menu", GetColor(255, 255, 255), obj::fontInGame);
		return;
	}

	if (isTimeOver)
	{
		DrawStringToHandle(X * 3 / 8, Y * 3 / 7, "Time Over", GetColor(0, 255, 0), obj::fontTitle);
		DrawStringToHandle(X * 3 / 8 + 30, Y * 3 / 7 + 80, "Press Q to back menu", GetColor(255, 255, 255), obj::fontInGame);
		return;
	}

	if (isPose)
	{
		int stateSelect = static_cast<int>(poseSelection);
		DrawBox(X / 4, Y / 4, X * 3 / 4, Y * 3 / 4, GetColor(128, 128, 128), true);
		DrawFormatStringToHandle(X * 3 / 7, Y / 4, GetColor(255, 255, 255), obj::fontInGame, "Pose Menu");
		DrawFormatStringToHandle(X / 3, Y * 3 / 7, GetColor(255, 255, 255), obj::fontInGame, "Continue");
		DrawFormatStringToHandle(X / 3, Y * 3 / 7 + 40, GetColor(255, 255, 255), obj::fontInGame, "Back to Main Menu");
		setup::drawCursor(X / 3 - 5, Y * 3 / 7 + 15 + (stateSelect * 40), GetColor(255, 255, 255), 1, 0);
	}
}
