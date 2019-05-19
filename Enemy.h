#pragma once
#include "MyObject.h"
#include "Bullet.h"


class Enemy : public MyObject
{
public:
	Enemy();
	Enemy(myVector2 position);
	~Enemy();

	myVector2 getPos();

	bool isEnemy() override;
	void move() override;
	void draw() override;

private:
	myVector2 direction;
};
