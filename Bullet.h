#pragma once
#include "MyVector2D.h"

class Bullet
{
public:
	// �f�t�H���g�R���X�g���N�^
	Bullet();
	// double�^�ŏ�����
	Bullet(double bx, double by);
	// vector�ŏ�����
	Bullet(const myVector2 &p);
	// �f�X�g���N�^
	~Bullet();

	// ���W�̃Q�b�^
	myVector2 getPos() const;

	void move();
	void draw();

private:
	// ���W
	myVector2 pos;
	// ���x
	myVector2 moveDirection;
};
