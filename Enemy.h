#pragma once
#include "Bullet.h"

class Enemy
{
public:
	// �R���X�g���N�^
	Enemy();
	// �f�X�g���N�^
	~Enemy();

	myVector2 getPos();

	void move();
	void draw();

private:
	// ���W
	myVector2 pos;
	// �i�s����
	myVector2 direction;
};
