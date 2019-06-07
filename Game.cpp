#include <algorithm>
#include "setup.h"
#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include "Player.h"
#include "Enemy.h"


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


// ゲーム画面の初期化
void GameInitialize(Player*& player, std::vector<Enemy*>& enemys)
{
	player = new Player(myVector2(230.0, 540.0));

	for (int i = 1; i < 6; i++)
	{
		enemys.push_back(new Enemy(myVector2(50.0 * i, 50.0)));
	}
}


// ゲーム画面の更新
void GameUpdate(Player*& player, std::vector<Bullet*>& bullets, std::vector<Enemy*>& enemys)
{
	// メニュー画面に遷移
	if (CheckHitKey(KEY_INPUT_Q) != 0)
	{
		delete player;
		player = nullptr;

		// enemyの消去
		for (Enemy* en : enemys) { delete en; }
		enemys.clear();

		// bulletの消去
		for (Bullet* bul : bullets) { delete bul; }
		bullets.clear();
		
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

		SceneMgrChange(mySceneMenu);
		return;
	}

	// playerの状態更新
	if (player != nullptr)
	{
		player->move();
	    player->fire(bullets);
	}

	// enemyの状態更新
	for (Enemy* en : enemys)
	{
		en->move();
		en->fire(bullets);
	}

	// bulletsの状態更新
	for (Bullet* bul : bullets)
	{
		bul->move();
		// プレイヤーに当たった時の処理
		if (player != nullptr)
		{
			if (bul->checkHit(*player) && bul->getIsEnBul())
			{
				player->setRemoveFlag(true);
			}
		}
		// 当たった敵の消去フラグを立てる
		for (Enemy* en : enemys)
		{
			if (bul->checkHit(*en) && bul->getIsPlaBul())
			{
				en->setRemoveFlag(true);
				bul->setRemoveFlag(true);
			}
		}
		// 画面外の弾の消去フラグを立てる
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

	// 敵の消去
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

	// 弾の消去
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


// ゲーム画面の描画
void GameDraw(Player*& player, std::vector<Bullet*>& bullets, std::vector<Enemy*>& enemys)
{
	DrawBox(0, 0, mySetup::battleX, mySetup::Y, GetColor(0, 0, 150), 1);

	DrawString(mySetup::battleX, 0, "'q'キーでメニューに戻る", GetColor(255, 255, 255));
	DrawFormatString(mySetup::battleX, 20, GetColor(255, 255, 255), "スコア：%d", mySetup::gameScore);

	// playerの描画
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

	// enemyの描画
	for (Enemy* en : enemys) { en->draw(); }

	// bulletsの描画
	for (Bullet* bul : bullets) { bul->draw(); }
}