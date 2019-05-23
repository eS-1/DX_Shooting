#pragma once
#include "Player.h"
#include "Enemy.h"


typedef enum
{
	mySceneMenu,
	mySceneGame,
	mySceneConfig,
} myScene;

// 更新
void SceneMgrUpdate(Player* &player, std::deque<Bullet*> &bullets, std::deque<Enemy*> &enemys);
// 描画
void SceneMgrDraw(Player* &player, std::deque<Bullet*> &bullets, std::deque<Enemy*> &enemys);
// シーン遷移
void SceneMgrChange(myScene next);