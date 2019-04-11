#pragma once
#include "MyVector2D.h"

class Bullet
{
public:
	// デフォルトコンストラクタ
	Bullet();
	// double型で初期化
	Bullet(double bx, double by);
	// vectorで初期化
	Bullet(const myVector2 &p);
	// デストラクタ
	~Bullet();

	// 座標のゲッタ
	myVector2 getPos() const;

	void move();
	void draw();

private:
	// 座標
	myVector2 pos;
	// 速度
	myVector2 moveDirection;
};
