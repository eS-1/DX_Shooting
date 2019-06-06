#pragma once
#include "Player.h"
#include "Enemy.h"


void GameInitialize(Player*& player, std::vector<Enemy*>& enemys);

void GameUpdate(Player*& player, std::vector<Bullet*>& bullets, std::vector<Enemy*>& enemys);

void GameDraw(Player*& player, std::vector<Bullet*>& bullets, std::vector<Enemy*>& enemys);

std::vector<unsigned int>::iterator MinItrOfVector(std::vector<unsigned int>& result);
