#pragma once
#include "MyVector2D.h"
#include "MyObject.h"


class Bullet
{
public:
	// double型で初期化
	Bullet(double bx, double by);
	// vectorで初期化
	Bullet(const myVector2& p);
	// デストラクタ
	~Bullet();

	// 座標のゲッタ
	myVector2 getPos() const;
	bool getRemoveFlag() const;

	void setRemoveFlag(bool state);

	void move();
	void draw();
	bool checkHit(MyObject& obj);

private:
	// 座標
	myVector2 pos;
	// 速度
	myVector2 moveDirection;
	//削除フラグ
	bool removeFlag;
};
