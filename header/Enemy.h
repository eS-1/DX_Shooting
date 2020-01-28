#pragma once
#include <memory>
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
	void fire(std::vector<std::unique_ptr<Bullet>>& bullets);
	myVector2 getInitPosition() const override;
	void setIsReached(bool state) override;

private:
	int fireCount;
	int imgHandle;
	bool isReached;
	myVector2 initPosition;
	myVector2 destination;
};
