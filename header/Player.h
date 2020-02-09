#pragma once
#include <vector>
#include <memory>
#include "Bullet.h"
#include "Objects.h"


class Player : public MyObject
{
public:
	Player(const myVector2& position);
	~Player();

	bool isPlayer() override;
	void move() override;
	void draw() override;
	void fire() override;

private:
	int img_handle;
};
