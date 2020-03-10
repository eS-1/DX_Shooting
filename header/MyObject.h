#pragma once
#include <vector>
#include <memory>
#include "MyVector2D.h"


class MyObject
{
protected:
	myVector2 position;
	myVector2 direction;
	bool removeFlag;

public:
	MyObject(const myVector2& pos);
	virtual ~MyObject() = default;

	virtual myVector2 getPosition() const;
	virtual myVector2 getDirection() const;
	virtual myVector2 getInitPosition() const;
	virtual void setDirection(const myVector2& dir);
	virtual void setPosition(const myVector2& pos);
	virtual bool isPlayer();
	virtual bool isEnemy();
	virtual bool isBullet();
	virtual bool getRemoveFlag() const;
	virtual bool checkHit(const MyObject& obj);
	virtual void setIsReached(bool state);
	virtual void setRemoveFlag(bool state);
	virtual void setIsPlaBul(bool state);
	virtual void setIsEnBul(bool state);
	virtual void fire();
	virtual void move();
	virtual void draw();
};
