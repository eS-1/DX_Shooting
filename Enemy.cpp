#include "DxLib.h"
#include "Enemy.h"

Enemy::Enemy()
	: pos(myVector2(230.0, 50.0)), direction(myVector2(0.0, 0.0)) {}

Enemy::Enemy(myVector2 pos)
	: pos(pos), direction(myVector2(0.0, 0.0)) {}

Enemy::~Enemy()
{
	// デストラクタ
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
	if (pos.x > 460)
	{
		direction.x = 0.0;
	}
	else if (pos.x < 0)
	{
		direction.x = 0.0;
	}

	pos += direction;
}
