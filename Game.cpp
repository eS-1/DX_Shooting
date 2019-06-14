#include <algorithm>
#include "setup.h"
#include "Objects.h"
#include "Game.h"
#include "SceneMgr.h"
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
	obj::bullets.clear();
}


// ゲーム画面の初期化
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

		SceneMgrChange(mySceneMenu);
		return;
	}

	// ゲームクリア時に弾を全消去
	if (obj::enemys.empty())
	{
		EraseAllBullets();
	}

	// playerの状態更新
	if (obj::player != nullptr)
	{
		obj::player->move();
	    obj::player->fire(obj::bullets);
	}

	// enemyの状態更新
	for (Enemy* en : obj::enemys)
	{
		en->move();
		en->fire(obj::bullets);
	}

	// bulletsの状態更新
	for (Bullet* bul : obj::bullets)
	{
		bul->move();
		// プレイヤーに当たった時の処理
		if (obj::player != nullptr)
		{
			if (bul->checkHit(*obj::player) && bul->getIsEnBul())
			{
				obj::player->setRemoveFlag(true);
				bul->setRemoveFlag(true);
			}
		}
		// 当たった敵の消去フラグを立てる
		for (Enemy* en : obj::enemys)
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

	if (obj::player != nullptr && obj::player->getRemoveFlag())
	{
		delete obj::player;
		obj::player = nullptr;
	}

	// 敵の消去
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

	// 弾の消去
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


// ゲーム画面の描画
void GameDraw()
{
	DrawBox(0, 0, mySetup::battleX, mySetup::Y, GetColor(0, 0, 150), 1);

	DrawString(mySetup::battleX, 0, "'q'キーでメニューに戻る", GetColor(255, 255, 255));
	DrawFormatString(mySetup::battleX, 20, GetColor(255, 255, 255), "スコア：%d", mySetup::gameScore);

	// playerの描画
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

	// enemyの描画
	for (Enemy* en : obj::enemys) { en->draw(); }

	// bulletsの描画
	for (Bullet* bul : obj::bullets) { bul->draw(); }
}