#include <algorithm>
#include <time.h>
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/Game.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


// 弾の全消去
void EraseAllBullets()
{
	obj::bullets.clear();
	obj::bullets.shrink_to_fit();
	obj::enBullets.clear();
	obj::enBullets.shrink_to_fit();
}


// 敵の弾座標初期化
void EraseEnemyBullets()
{
	for (const auto& enBul : obj::enBullets)
	{
		enBul->setDirection(myVector2(0.0, 0.0));
		enBul->setPosition(myVector2(5000.0, 5000.0));
	}
}


// ゲーム画面の初期化
void Game_Init()
{
	// 自機の生成
	obj::player.reset(new Player(myVector2(mySetup::X / 2, mySetup::Y * 7 / 8)));

	// 自機の弾生成
	for (int i = 0; i < 30; i++)
	{
		std::unique_ptr<MyObject> bul(new Bullet(myVector2(5000.0, 5000.0), myVector2(0.0, 0.0)));
		bul->setRemoveFlag(true);
		bul->setIsPlaBul(true);
		obj::bullets.push_back(std::move(bul));
	}

	// 敵の弾生成
	for (int i = 0; i < 50; i++)
	{
		std::unique_ptr<MyObject> bul(new Bullet(myVector2(5000.0, 5000.0), myVector2(0.0, 0.0)));
		bul->setRemoveFlag(true);
		obj::enBullets.push_back(std::move(bul));
	}

	// 敵の生成
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

	// タイマーの初期化
	startTime = time(NULL);
	remainingTime = 60;

	// タイムオーバーフラグの初期化
	isTimeOver = false;

	// ゲームオーバーフラグの初期化
	isGameOver = false;

	// ポーズフラグの初期化
	isPose = false;

	// メニュー画面に戻るフラグの初期化
	isQuit = false;
}


// ゲーム画面の更新
void GameUpdate()
{
	setup::KeyInput();

	if (isGameOver || isTimeOver)
	{
		if (keyInput::Q != 0 && (keyInput::Q & ~keyInput::oldQ)) { isQuit = true; }
	}
	else
	{
		if (!isPose && keyInput::Q != 0)
		{
			// ポーズ画面のフラグを建てる
			isPose = true;
			return;
		}

		if (isPose)
		{
			if (keyInput::E != 0 && (keyInput::E & ~keyInput::oldE)) { isPose = false; }
			else if (keyInput::Q != 0 && (keyInput::Q & ~keyInput::oldQ)) { isQuit = true; }
			else { return; }
		}
	}

	// メニュー画面に遷移
	if (isQuit)
	{
		bool SaveNameFlag = false;

		obj::player = nullptr;

		// enemyの消去
		obj::enemys.clear();
		obj::enemys.shrink_to_fit();

		// bulletの消去
		EraseAllBullets();
		
		// リザルトスコアにゲームスコアを追加
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

	// playerの状態更新
	if (!(obj::player->getRemoveFlag()))
	{
		obj::player->move();
	    obj::player->fire();

		// タイマーのカウントダウン
		diffTime = time(NULL) - startTime;
		if (diffTime >= 1)
		{
			remainingTime--;
			startTime = time(NULL);
		}
	}

	// enemyの状態更新
	for (const auto& en : obj::enemys)
	{
		en->move();
		en->fire();
	}

	// bulletsの状態更新
	for (const auto& bul : obj::bullets)
	{
		if (!(bul->getRemoveFlag()))
		{
			bul->move();
			// 当たった敵の消去処理
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
			// 画面外の弾の消去フラグを立てる
			if (bul->getPosition().x < -50 || bul->getPosition().x > mySetup::X + 50.0
				|| bul->getPosition().y < -50 || bul->getPosition().y > mySetup::Y + 50.0)
			{
				bul->setRemoveFlag(true);
			}
		}
	}

	// enBulletsの状態更新
	for (const auto& enBul : obj::enBullets)
	{
		if (!(enBul->getRemoveFlag()))
		{
			enBul->move();
			// プレイヤーに当たった時の処理
			if (!(obj::player->getRemoveFlag()))
			{
				if (enBul->checkHit(*obj::player))
				{
					obj::player->setRemoveFlag(true);
					enBul->setRemoveFlag(true);
				}
			}
			// 画面外の弾の消去フラグを立てる
			if (enBul->getPosition().x < -50 || enBul->getPosition().x > mySetup::X + 50.0
				|| enBul->getPosition().y < -50 || enBul->getPosition().y > mySetup::Y + 50.0)
			{
				enBul->setRemoveFlag(true);
			}
		}
	}

	// 自機の消去
	if (obj::player->getRemoveFlag())
	{
		obj::player->setPosition(myVector2(6000.0, 6000.0));
		isGameOver = true;
	}

	// 自機の弾消去(座標初期化)
	for (const auto& bul : obj::bullets)
	{
		if (bul->getRemoveFlag())
		{
			bul->setDirection(myVector2(0.0, 0.0));
			bul->setPosition(myVector2(5000.0, 5000.0));
		}
	}

	// 敵の弾消去(座標初期化)
	for (const auto& enBul : obj::enBullets)
	{
		if (enBul->getRemoveFlag())
		{
			enBul->setDirection(myVector2(0.0, 0.0));
			enBul->setPosition(myVector2(5000.0, 5000.0));
		}
	}
}


// ゲーム画面の描画
void GameDraw()
{
	// playerの描画
	if (obj::player != nullptr && !(obj::player->getRemoveFlag())) { obj::player->draw(); }

	// enemyの描画
	for (const auto& en : obj::enemys)
	{
		if (!(en->getRemoveFlag()))
		{
			en->draw();
		}
	}

	// bulletsの描画
	for (const auto& bul : obj::bullets)
	{
		if (!(bul->getRemoveFlag()))
		{
			bul->draw();
		}
	}

	// enBulletsの描画
	for (const auto& enBul : obj::enBullets)
	{
		if (!(enBul->getRemoveFlag()))
		{
			enBul->draw();
		}
	}

	DrawFormatStringToHandle(0, 0, GetColor(255, 255, 255), obj::fontInGame, "score：%d", mySetup::gameScore);
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
