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
	void fire(std::deque<Bullet*>& bullets);
	void eraseBullet(std::deque<Bullet*>& bullets);

private:
	int key;
	int oldKey;
};
