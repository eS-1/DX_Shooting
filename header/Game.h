#pragma once
#include <vector>


enum class PoseSelect
{
	restart,
	exit
};

void Game_Init();

void Game_Update();

void Game_Draw();

void EraseAllBullets();

void EraseEnemyBullets();
