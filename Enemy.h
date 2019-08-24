#pragma once
#include <vector>
#include "Bullet.h"


class Enemy : public MyObject
{
public:
	Enemy(const myVector2& pos);
	~Enemy();

	bool isEnemy() override;
	void move() override;
	void draw() override;
	void fire(std::vector<Bullet*>& bullets);
	myVector2 getInitPosition();
	void setIsReached(bool state);

private:
	int fireCount;
	bool isReached;
	myVector2 initPosition;
	myVector2 destination;
};
