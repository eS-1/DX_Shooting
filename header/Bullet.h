#pragma once
#include <memory>
#include "MyObject.h"


class Bullet : public MyObject
{
public:
	Bullet(const myVector2& p, const myVector2& dir);
	~Bullet() = default;

	bool isBullet() override;
	void move() override;
	void draw() override;
	bool checkHit(std::unique_ptr<MyObject>& obj) override;

	bool getIsPlaBul();
	bool getIsEnBul();
	void setIsPlaBul(bool state) override;
	void setIsEnBul(bool state) override;

private:
	bool isPlaBullet;
	bool isEnBullet;
};
