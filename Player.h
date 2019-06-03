#pragma once
#include <vector>
#include "MyObject.h"
#include "Bullet.h"


class Player : public MyObject
{
public:
	Player(const myVector2& position);
	~Player();

	bool isPlayer() override;
	void move() override;
	void draw() override;
	void fire(std::vector<Bullet*>& bullets);

private:
	int key;
	int oldKey;
};
