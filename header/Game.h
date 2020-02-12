#pragma once
#include <vector>


enum class PoseSelect
{
	restart,
	exit
};

namespace
{
	time_t startTime;
	time_t diffTime;
	int remainingTime;
	bool isTimeOver;
	bool isGameOver;
	bool isPose;
	bool isQuit;
	PoseSelect poseSelection;
}

void Game_Init();

void GameUpdate();

void GameDraw();

void EraseAllBullets();

void EraseEnemyBullets();
