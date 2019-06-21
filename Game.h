#pragma once
#include <vector>


void Game_Init();

void GameUpdate();

void GameDraw();

void EraseAllBullets();

void EraseEnemyBullets();

std::vector<unsigned int>::iterator MinItrOfVector(std::vector<unsigned int>& result);
