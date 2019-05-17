#include "setup.h"
#include "DxLib.h"
#include "Player.h"

Player::Player()
	:pos(myVector2(230.0, 540.0)), key(0), oldKey(0) {}

Player::~Player()
{
	for (Bullet* bul : bullets)
	{
		delete bul;
	}
}

std::deque<Bullet*> Player::getBullets()
{
	return bullets;
}

void Player::draw()
{
	DrawBox(pos.x - 10.0, pos.y - 10.0, pos.x + 10, pos.y + 10, GetColor(0, 255, 0), 1);
}

void Player::move()
{
	if (CheckHitKey(KEY_INPUT_A) && pos.x > 10)
	{
		pos.x -= 3.0;
	}

	if (CheckHitKey(KEY_INPUT_D) && pos.x < mySetup::X - 10)
	{
		pos.x += 3.0;
	}

	if (CheckHitKey(KEY_INPUT_W) && pos.y > 10)
	{
		pos.y -= 3.0;
	}

	if (CheckHitKey(KEY_INPUT_S) && pos.y < mySetup::Y - 10)
	{
		pos.y += 3.0;
	}
}

void Player::fire()
{
	oldKey = key;
	key = CheckHitKey(KEY_INPUT_SPACE);

	if ((key & ~oldKey) & KEY_INPUT_SPACE)
	{
		Bullet* bul = new Bullet(pos);
		bullets.push_back(bul);
	}
}

void Player::eraseBullet()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->getPos().x < 0 || bullets[i]->getPos().x > mySetup::X
			|| bullets[i]->getPos().y < 0 || bullets[i]->getPos().y > mySetup::Y)
		{
			Bullet* bul = bullets[i];
			bullets.erase(bullets.begin() + i);
			delete bul;
		}
	}
}
