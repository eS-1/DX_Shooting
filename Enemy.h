#pragma once
#include "Bullet.h"

class Enemy
{
public:
	// コンストラクタ
	Enemy();
	// コンストラクタ
	Enemy(myVector2 pos);
	// デストラクタ
	~Enemy();

	myVector2 getPos();

	void move();
	void draw();

private:
	// 座標
	myVector2 pos;
	// 進行方向
	myVector2 direction;
};
