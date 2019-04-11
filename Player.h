#pragma once
#include <deque>
#include "Bullet.h"

class Player
{
public:
	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	std::deque<Bullet*> getBullets();

	void move();
	void draw();
	void fire();
	void eraseBullet();

private:
	//座標
	myVector2 pos;
	// 弾を保管する配列
	std::deque<Bullet*> bullets;
	// キー入力状態
	int key;
	// 前フレームのキー入力状態
	int oldKey;
};
