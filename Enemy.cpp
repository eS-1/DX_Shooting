#include "setup.h"
#include "DxLib.h"
#include "Enemy.h"


Enemy::Enemy()
	: MyObject(myVector2(230.0, 50.0)), direction(myVector2(0.0, 0.0)) {}

Enemy::Enemy(myVector2 pos)
	: MyObject(pos), direction(myVector2(2.0, 0.0)) {}

Enemy::~Enemy()
{
	// デストラクタ
}

bool Enemy::isEnemy()
{
	return true;
}

myVector2 Enemy::getPos()
{
	return pos;
}

void Enemy::draw()
{
	DrawBox(pos.x - 10, pos.y - 10, pos.x + 10, pos.y + 10, GetColor(255, 255, 255), 1);
}

void Enemy::move()
{
	if (pos.x + 10 > mySetup::battleX)
	{
		direction.x = -2.0;
	}
	else if (pos.x - 10 < 0)
	{
		direction.x = 2.0;
	}

	pos += direction;
}
