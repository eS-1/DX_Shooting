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

// �V�[���Ǘ��̍X�V
void SceneMgrUpdate(Player*& player, std::deque<Bullet*>& bullets, std::deque<Enemy*>& enemys);
// �V�[���Ǘ��̕`��
void SceneMgrDraw(Player*& player, std::deque<Bullet*>& bullets, std::deque<Enemy*>& enemys);
// �V�[���J�ڗp�̊֐�
void SceneMgrChange(myScene next);