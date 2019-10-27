#include "../header/Enemy.h"
#include "../header/setup.h"
#include "DxLib.h"


Enemy::Enemy(const myVector2& pos) : MyObject(pos), fireCount(0), isReached(true), initPosition(pos),
                                     destination(myVector2(pos.x, pos.y + 200.0)),
	                                 imgHandle(LoadGraph("images/enemy.png"))
{
	direction = myVector2(0.0, 3.0);
}

Enemy::~Enemy()
{
	DeleteGraph(imgHandle);
}

bool Enemy::isEnemy()
{
	return true;
}

void Enemy::draw()
{
	if (imgHandle == -1)
	{
		DrawFormatString(position.x, position.y, GetColor(255, 255, 255), "F");
		return;
	}
	DrawExtendGraph(position.x - 30.0, position.y - 30.0, position.x + 30.0, position.y + 30.0, imgHandle, true);
}

void Enemy::move()
{
	if (isReached)
	{
		direction = myVector2(0.0, 3.0);
		if (position.y > destination.y)
		{
			direction = myVector2(2.0, 0.0);
			isReached = false;
		}
	}

	if (position.x > mySetup::X)
	{
		direction = myVector2(-2.0, 0.0);
	}
	else if (position.x < 0)
	{
		direction = myVector2(2.0, 0.0);
	}

	position += direction;
}

void Enemy::fire(std::vector<Bullet*>& bullets)
{
	fireCount++;
	if (fireCount == 60)
	{
		for (Bullet* bul : bullets)
		{
			if (bul->getRemoveFlag())
			{
				bul->setRemoveFlag(false);
				bul->setDirection(myVector2(0.0, 5.0));
				bul->setPosition(position);
				break;
			}
		}
		fireCount = 0;
	}
}

myVector2 Enemy::getInitPosition()
{
	return initPosition;
}

void Enemy::setIsReached(bool state)
{
	isReached = state;
}