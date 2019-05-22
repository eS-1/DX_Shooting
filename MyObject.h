#pragma once
#include "MyVector2D.h"


class MyObject
{
protected:
	bool removeFlag;

public:
	MyObject(myVector2 position);
	~MyObject();

	myVector2 pos;

	virtual bool isPlayer();
	virtual bool isEnemy();
	virtual bool getRemoveFlag() const;
	virtual void setRemoveFlag(bool state);
	virtual void move();
	virtual void draw();
};
