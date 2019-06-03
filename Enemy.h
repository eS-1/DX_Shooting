#pragma once
#include "Bullet.h"


class Enemy : public MyObject
{
public:
	Enemy(const myVector2& position);
	~Enemy();

	bool isEnemy() override;
	void move() override;
	void draw() override;
	void fire(std::vector<Bullet*>& bullets);

private:
	int fireCount;
};
