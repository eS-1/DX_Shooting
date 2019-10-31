#pragma once
#include <vector>


namespace
{
	time_t startTime;
	time_t diffTime;
	int remainingTime;
	bool isTimeOver;
	bool isGameOver;
	bool isPose;
	bool isQuit;
}

void Game_Init();

void GameUpdate();

void GameDraw();

void EraseAllBullets();

void EraseEnemyBullets();

std::vector<unsigned int>::iterator MinItrOfVector(std::vector<unsigned int>& result);
