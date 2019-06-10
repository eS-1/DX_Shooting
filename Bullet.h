#pragma once
#include "MyObject.h"


class Bullet : public MyObject
{
public:
	Bullet(const myVector2& p, const myVector2& dir);
	~Bullet();

	bool isBullet() override;
	void move() override;
	void draw() override;
	bool checkHit(MyObject& obj);

	bool getIsPlaBul();
	bool getIsEnBul();
	void setIsPlaBul(bool state);
	void setIsEnBul(bool state);

private:
	bool isPlaBullet;
	bool isEnBullet;
};
