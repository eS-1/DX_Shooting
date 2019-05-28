#pragma once
#include "Player.h"
#include "Enemy.h"


typedef enum
{
	mySceneMenu,
	mySceneGame,
	mySceneConfig,
	mySceneResult
} myScene;

// シーン管理の更新
void SceneMgrUpdate(Player*& player, std::deque<Bullet*>& bullets, std::deque<Enemy*>& enemys);
// シーン管理の描画
void SceneMgrDraw(Player*& player, std::deque<Bullet*>& bullets, std::deque<Enemy*>& enemys);
// シーン遷移用の関数
void SceneMgrChange(myScene next);