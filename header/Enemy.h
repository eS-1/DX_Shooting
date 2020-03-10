#pragma once
#include <memory>
#include <vector>
#include "Bullet.h"
#include "Objects.h"


class Enemy : public MyObject
{
public:
	Enemy(const myVector2& pos);
	~Enemy();

	bool isEnemy() override;
	void move() override;
	void draw() override;
	void fire() override;
	myVector2 getInitPosition() const override;
	void setIsReached(bool state) override;

private:
	int fireCount;
	int img_handle;
	bool isReached;
	myVector2 initPosition;
	myVector2 destination;
};
