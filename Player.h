#pragma once
#include <deque>
#include "Bullet.h"

class Player
{
public:
	// �R���X�g���N�^
	Player();
	// �f�X�g���N�^
	~Player();

	std::deque<Bullet*> getBullets();

	void move();
	void draw();
	void fire();
	void eraseBullet();

private:
	//���W
	myVector2 pos;
	// �e��ۊǂ���z��
	std::deque<Bullet*> bullets;
	// �L�[���͏��
	int key;
	// �O�t���[���̃L�[���͏��
	int oldKey;
};
