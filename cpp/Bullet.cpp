#include "DxLib.h"
#include "../header/Bullet.h"


Bullet::Bullet(const myVector2& p, const myVector2& dir)
	: MyObject(p), isPlaBullet(false), isEnBullet(false)
{
	direction = dir;
}

Bullet::~Bullet()
{
	// デストラクタ
}

bool Bullet::isBullet()
{
	return true;
}

bool Bullet::getIsPlaBul()
{
	return isPlaBullet;
}

bool Bullet::getIsEnBul()
{
	return isEnBullet;
}

void Bullet::setIsPlaBul(bool state)
{
	isPlaBullet = state;
}

void Bullet::setIsEnBul(bool state)
{
	isEnBullet = state;
}

void Bullet::move()
{
	position += direction;
}

void Bullet::draw()
{
	unsigned int color;
	if (isPlaBullet)
	{
		color = GetColor(255, 0, 0);
	}
	else
	{
		color = GetColor(255, 0, 255);
	}
	DrawBox(position.x - 5.0, position.y - 5.0, position.x + 5.0, position.y + 5.0, color, 1);
}

bool Bullet::checkHit(MyObject& obj)
{
	return position.distanceFrom(obj.getPosition()) <= 20;
}
