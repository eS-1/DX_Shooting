#include "MyObject.h"


MyObject::MyObject(myVector2 position)
	: pos(position), direction(myVector2(0, 0)), removeFlag(false) {}

MyObject::~MyObject()
{
	// デストラクタ
}

myVector2 MyObject::getPos() const
{
	return pos;
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

void MyObject::setRemoveFlag(bool state)
{
	removeFlag = state;
}

void MyObject::move() {}

void MyObject::draw() {}
