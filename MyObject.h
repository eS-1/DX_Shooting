#pragma once
#include "MyVector2D.h"


class MyObject
{
public:
	MyObject(myVector2 position);
	~MyObject();

	myVector2 pos;

	virtual bool isPlayer();
	virtual bool isEnemy();
	virtual void move();
	virtual void draw();
};
