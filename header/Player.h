#pragma once
#include <vector>
#include <memory>
#include "Bullet.h"


class Player : public MyObject
{
public:
	Player(const myVector2& position);
	~Player();

	bool isPlayer() override;
	void move() override;
	void draw() override;
	void fire(std::vector<std::unique_ptr<MyObject>>& bullets) override;

private:
	int key;
	int oldKey;
	int imgHandle;
};
