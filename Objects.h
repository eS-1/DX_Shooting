#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"


namespace obj
{
	extern Player* player;
	extern std::vector<Bullet*> bullets;
	extern std::vector<Enemy*> enemys;
	extern std::vector<Bullet*> enBullets;
	extern int fontTitle;
	extern int fontInGame;
}

void Objects_End();