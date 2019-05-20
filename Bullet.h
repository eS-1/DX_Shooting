#pragma once
#include "MyVector2D.h"
#include "MyObject.h"


class Bullet
{
public:
	// double�^�ŏ�����
	Bullet(double bx, double by);
	// vector�ŏ�����
	Bullet(const myVector2& p);
	// �f�X�g���N�^
	~Bullet();

	// ���W�̃Q�b�^
	myVector2 getPos() const;
	bool getRemoveFlag() const;

	void setRemoveFlag(bool state);

	void move();
	void draw();
	bool checkHit(MyObject& obj);

private:
	// ���W
	myVector2 pos;
	// ���x
	myVector2 moveDirection;
	//�폜�t���O
	bool removeFlag;
};
