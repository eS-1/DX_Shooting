#include "MyObject.h"


MyObject::MyObject(myVector2 position)
	: pos(position), removeFlag(false) {}

MyObject::~MyObject()
{
	// デストラクタ
}

bool MyObject::isPlayer()
{
	return false;
}

bool MyObject::isEnemy()
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
