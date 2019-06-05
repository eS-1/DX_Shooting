#include "setup.h"
#include "DxLib.h"
#include "Enemy.h"


Enemy::Enemy(const myVector2& pos) : MyObject(pos), fireCount(0)
{
	direction = myVector2(2.0, 0.0);
}

Enemy::~Enemy()
{
	// デストラクタ
}

bool Enemy::isEnemy()
{
	return true;
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

void Enemy::fire(std::vector<Bullet*>& bullets)
{
	fireCount++;
	if (fireCount == 50)
	{
		Bullet* bul = new Bullet(pos, 4.0);
		bul->setIsEnBul(true);
		bullets.push_back(bul);
		fireCount = 0;
	}
}
