#pragma once
#include "MyVector2D.h"


class MyObject
{
protected:
	myVector2 position;
	myVector2 direction;
	bool removeFlag;

public:
	MyObject(const myVector2& pos);
	~MyObject();

	virtual myVector2 getPosition() const;
	virtual myVector2 getDirection() const;
	virtual void setDirection(const myVector2& dir);
	virtual void setPosition(const myVector2& pos);
	virtual bool isPlayer();
	virtual bool isEnemy();
	virtual bool isBullet();
	virtual bool getRemoveFlag() const;
	virtual void setRemoveFlag(bool state);
	virtual void move();
	virtual void draw();
};
