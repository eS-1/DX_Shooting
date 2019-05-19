#pragma once
#include <deque>
#include "MyObject.h"
#include "Bullet.h"


class Player : public MyObject
{
public:
	Player(myVector2 position);
	~Player();

	bool isPlayer() override;
	void move() override;
	void draw() override;
	void fire();
	void eraseBullet();
	std::deque<Bullet*> getBullets();

private:
	std::deque<Bullet*> bullets;
	int key;
	int oldKey;
};
