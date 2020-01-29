#include "../header/MyObject.h"


MyObject::MyObject(const myVector2& pos)
	: position(pos), direction(myVector2(0, 0)), removeFlag(false) {}

myVector2 MyObject::getPosition() const
{
	return position;
}

myVector2 MyObject::getDirection() const
{
	return direction;
}

myVector2 MyObject::getInitPosition() const
{
	return position;
}

void MyObject::setDirection(const myVector2& dir)
{
	direction = dir;
}

void MyObject::setPosition(const myVector2& pos)
{
	position = pos;
}

bool MyObject::isPlayer()
{
	return false;
}

bool MyObject::isEnemy()
{
	return false;
}

bool MyObject::isBullet()
{
	return false;
}

bool MyObject::getRemoveFlag() const
{
	return removeFlag;
}

bool MyObject::checkHit(const MyObject& obj)
{
	return false;
}

void MyObject::setIsReached(bool state) {}

void MyObject::setRemoveFlag(bool state)
{
	removeFlag = state;
}

void MyObject::setIsEnBul(bool state) {}

void MyObject::setIsPlaBul(bool state) {}

void MyObject::fire() {}

void MyObject::move() {}

void MyObject::draw() {}
