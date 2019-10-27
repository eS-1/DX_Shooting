#include <algorithm>
#include <time.h>
#include "../header/setup.h"
#include "../header/Objects.h"
#include "../header/Game.h"
#include "../header/SceneMgr.h"
#include "DxLib.h"


// vectorの最小値のイテレータを返す関数
std::vector<unsigned int>::iterator MinItrOfVector(std::vector<unsigned int>& result)
{
	auto minItr = result.begin();
	for (auto itr = result.begin(); itr != result.end(); itr++)
	{
		if (*minItr > *itr) { minItr = itr; }
	}
	return minItr;
}


// 弾の全消去
void EraseAllBullets()
{
	for (Bullet* bul : obj::bullets) { delete bul; }
	for (Bullet* bul : obj::enBullets) { delete bul; }
	obj::bullets.clear();
	obj::enBullets.clear();
}


// 敵の弾座標初期化
void EraseEnemyBullets()
{
	for (Bullet* bul : obj::enBullets)
	{
		bul->setDirection(myVector2(0.0, 0.0));
		bul->setPosition(myVector2(10.0, -5.0));
	}
}


// ゲーム画面の初期化
void Game_Init()
{
	// 自機の生成
	obj::player = new Player(myVector2(mySetup::X / 2, mySetup::Y * 7 / 8));
	// 自機の弾生成
	for (int i = 0; i < 30; i++)
	{
		Bullet* bul = new Bullet(myVector2(5.0, -5.0), myVector2(0.0, 0.0));
		bul->setRemoveFlag(true);
		bul->setIsPlaBul(true);
		obj::bullets.push_back(bul);
	}
	// 敵の弾生成
	for (int i = 0; i < 50; i++)
	{
		Bullet* bul = new Bullet(myVector2(10.0, -5.0), myVector2(0.0, 0.0));
		bul->setRemoveFlag(true);
		obj::enBullets.push_back(bul);
	}
	// 敵の生成
	int rand_y;
	switch (mySetup::diff)
	{
	case difficulty::easy:
		for (int i = 1; i < 6; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.push_back(new Enemy(myVector2(80.0 * i, rand_y - 140.0)));
		}
		break;
	case difficulty::normal:
		for (int i = 1; i < 9; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.push_back(new Enemy(myVector2(80.0 * i, rand_y - 140.0)));
		}
		break;
	case difficulty::hard:
		for (int i = 1; i < 13; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.push_back(new Enemy(myVector2(60.0 * i, rand_y - 140.0)));
		}
		break;
	case difficulty::extreme:
		for (int i = 1; i < 16; i++)
		{
			rand_y = GetRand(100);
			obj::enemys.push_back(new Enemy(myVector2(60.0 * i, rand_y - 140.0)));
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
}


// ゲーム画面の更新
void GameUpdate()
{
	// メニュー画面に遷移
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		delete obj::player;
		obj::player = nullptr;

		// enemyの消去
		for (Enemy* en : obj::enemys) { delete en; }
		obj::enemys.clear();

		// bulletの消去
		EraseAllBullets();
		
		// リザルトスコアにゲームスコアを追加
		auto minItr = MinItrOfVector(mySetup::resultScores);
		if (mySetup::gameScore > *minItr)
		{
			*minItr = mySetup::gameScore;
			std::sort(mySetup::resultScores.begin(), mySetup::resultScores.end(),
				std::greater<std::vector<int>::value_type>());
		}

		// ゲームスコアのリセット
		mySetup::gameScore = 0;

		isGameOver = false;

		SceneMgrChange(myScene::mySceneMenu);
		return;
	}

	if (remainingTime <= 0)
	{
		isTimeOver = true;
		return;
	}

	// playerの状態更新
	if (obj::player != nullptr)
	{
		obj::player->move();
	    obj::player->fire(obj::bullets);

		// タイマーのカウントダウン
		diffTime = time(NULL) - startTime;
		if (diffTime == 1)
		{
			remainingTime--;
			startTime = time(NULL);
		}
	}

	// enemyの状態更新
	for (Enemy* en : obj::enemys)
	{
		en->move();
		en->fire(obj::enBullets);
	}

	// bulletsの状態更新
	for (Bullet* bul : obj::bullets)
	{
		if (!bul->getRemoveFlag())
		{
			bul->move();
			// 当たった敵の消去処理
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
			// 画面外の弾の消去フラグを立てる
			if (bul->getPosition().x < -50 || bul->getPosition().x > mySetup::X + 50.0
				|| bul->getPosition().y < -50 || bul->getPosition().y > mySetup::Y + 50.0)
			{
				bul->setRemoveFlag(true);
			}
		}
	}

	// enBulletsの状態更新
	for (Bullet* bul : obj::enBullets)
	{
		if (!bul->getRemoveFlag())
		{
			bul->move();
			// プレイヤーに当たった時の処理
			if (obj::player != nullptr)
			{
				if (bul->checkHit(*obj::player))
				{
					obj::player->setRemoveFlag(true);
					bul->setRemoveFlag(true);
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

	// 自機の消去
	if (obj::player != nullptr && obj::player->getRemoveFlag())
	{
		delete obj::player;
		obj::player = nullptr;
		isGameOver = true;
	}

	// 自機の弾消去(座標初期化)
	for (Bullet* bul : obj::bullets)
	{
		if (bul->getRemoveFlag())
		{
			bul->setDirection(myVector2(0.0, 0.0));
			bul->setPosition(myVector2(5.0, -5.0));
		}
	}

	// 敵の弾消去(座標初期化)
	for (Bullet* bul : obj::enBullets)
	{
		if (bul->getRemoveFlag())
		{
			bul->setDirection(myVector2(0.0, 0.0));
			bul->setPosition(myVector2(10.0, -5.0));
		}
	}
}


// ゲーム画面の描画
void GameDraw()
{
	// playerの描画
	if (obj::player != nullptr)
	{
		obj::player->draw();
	}
	
	if (isGameOver)
	{
		DrawStringToHandle(mySetup::X * 3 / 7, mySetup::Y * 3 / 7, "Game Over", GetColor(255, 0, 0), obj::fontTitle);
		DrawStringToHandle(mySetup::X * 3 / 7, mySetup::Y * 3 / 7 + 40,
			               "Press Q to back menu", GetColor(255, 255, 255), obj::fontInGame);
	}

	// enemyの描画
	for (Enemy* en : obj::enemys) { en->draw(); }

	// bulletsの描画
	for (Bullet* bul : obj::bullets) { bul->draw(); }

	// enBuolletsの描画
	for (Bullet* bul : obj::enBullets) { bul->draw(); }

	DrawFormatStringToHandle(0, 0, GetColor(255, 255, 255), obj::fontInGame, "スコア：%d", mySetup::gameScore);
	DrawFormatStringToHandle(0, 20, GetColor(255, 255, 255), obj::fontInGame, "remaining time: %d", remainingTime);

	if (isTimeOver)
	{
		DrawStringToHandle(mySetup::X * 3 / 7, mySetup::Y * 3 / 7, "Time Over", GetColor(255, 0, 0), obj::fontTitle);
		DrawStringToHandle(mySetup::X * 3 / 7, mySetup::Y * 3 / 7 + 40,
			               "Press Q to back menu", GetColor(255, 255, 255), obj::fontInGame);
	}
}
