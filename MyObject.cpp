#include "MyObject.h"

MyObject::MyObject(myVector2 position)
	: pos(position), removeFlag(false) {}

MyObject::~MyObject()
{
	// �f�X�g���N�^
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
