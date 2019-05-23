#pragma once
#include "Player.h"
#include "Enemy.h"

void GameInitialize(Player* &player, std::deque<Enemy*> &enemys);

void GameUpdate(Player*& player, std::deque<Bullet*> &bullets, std::deque<Enemy*> &enemys);

void GameDraw(Player* &player, std::deque<Bullet*> &bullets, std::deque<Enemy*> &enemys);