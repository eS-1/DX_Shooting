#pragma once
#include <vector>


void GameInitialize();

void GameUpdate();

void GameDraw();

void EraseAllBullets();

std::vector<unsigned int>::iterator MinItrOfVector(std::vector<unsigned int>& result);
