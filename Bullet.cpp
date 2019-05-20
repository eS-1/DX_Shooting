#include "DxLib.h"
#include "Bullet.h"


Bullet::Bullet(double bx, double by)
	: pos(myVector2(bx, by)), moveDirection(myVector2(0.0, -5.0)), removeFlag(false) {}

Bullet::Bullet(const myVector2& p)
	: pos(p), moveDirection(myVector2(0.0, -5.0)), removeFlag(false) {}

Bullet::~Bullet()
{
	// デストラクタ
}

myVector2 Bullet::getPos() const
{
	return pos;
}

bool Bullet::getRemoveFlag() const
{
	return removeFlag;
}

void Bullet::setRemoveFlag(bool state)
{
	removeFlag = state;
}

void Bullet::move()
{
	pos += moveDirection;
}

void Bullet::draw()
{
	DrawBox(pos.x - 5.0, pos.y - 5.0, pos.x + 5.0, pos.y + 5.0, GetColor(255, 0, 0), 1);
}

bool Bullet::checkHit(MyObject& obj)
{
	return obj.isEnemy() && pos.distanceFrom(obj.pos) <= 15;
}