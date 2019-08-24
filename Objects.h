#pragma once
#include "Bullet.h"
#include "Enemy.h"
#include "Player.h"
#include "DxLib.h"


namespace obj
{
	static Player* player;
	static std::vector<Bullet*> bullets;
	static std::vector<Enemy*> enemys;
	static std::vector<Bullet*> enBullets;
	static time_t startTime;
	static time_t diffTime;
	static int remainingTime;
	static int fontTitle;
}

void Objects_End();