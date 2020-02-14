#pragma once
#include <vector>


enum class PoseSelect
{
	restart,
	exit
};

void Game_Init();

void GameUpdate();

void GameDraw();

void EraseAllBullets();

void EraseEnemyBullets();
