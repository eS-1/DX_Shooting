#pragma once
#include "MyVector2D.h"


class MyObject
{
protected:
	myVector2 pos;
	myVector2 direction;
	bool removeFlag;

public:
	MyObject(myVector2 position);
	~MyObject();

	virtual myVector2 getPos() const;
	virtual bool isPlayer();
	virtual bool isEnemy();
	virtual bool isBullet();
	virtual bool getRemoveFlag() const;
	virtual void setRemoveFlag(bool state);
	virtual void move();
	virtual void draw();
};
