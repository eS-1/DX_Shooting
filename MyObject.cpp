#include "MyObject.h"


MyObject::MyObject(myVector2 position)
	: pos(position) {}

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

void MyObject::move() {}

void MyObject::draw() {}
