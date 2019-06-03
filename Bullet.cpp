#include "DxLib.h"
#include "Bullet.h"


Bullet::Bullet(const myVector2& p, double dy)
	: MyObject(p), isPlaBullet(false), isEnBullet(false)
{
	direction = myVector2(0.0, dy);
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
	pos += direction;
}

void Bullet::draw()
{
	DrawBox(pos.x - 5.0, pos.y - 5.0, pos.x + 5.0, pos.y + 5.0, GetColor(255, 0, 0), 1);
}

bool Bullet::checkHit(MyObject& obj)
{
	return pos.distanceFrom(obj.getPos()) <= 15;
}