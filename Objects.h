#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "DxLib.h"


namespace obj
{
	extern Player* player;
	extern std::vector<Bullet*> bullets;
	extern std::vector<Enemy*> enemys;
	extern std::vector<Bullet*> enBullets;
	extern int fontTitle;
}

void Objects_End();