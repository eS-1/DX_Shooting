#pragma once
#include "Player.h"
#include "Enemy.h"


typedef enum
{
	mySceneMenu,
	mySceneGame,
	mySceneConfig,
} myScene;

// �X�V
void SceneMgrUpdate(Player* &player, std::deque<Bullet*> &bullets, std::deque<Enemy*> &enemys);
// �`��
void SceneMgrDraw(Player* &player, std::deque<Bullet*> &bullets, std::deque<Enemy*> &enemys);
// �V�[���J��
void SceneMgrChange(myScene next);