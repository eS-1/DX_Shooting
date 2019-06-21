#include "setup.h"
#include "Player.h"
#include "DxLib.h"


Player::Player(const myVector2& position)
	: MyObject(position), key(0), oldKey(0) {}

Player::~Player()
{
	// デストラクタ
}

bool Player::isPlayer()
{
	return true;
}

void Player::draw()
{
	DrawBox(pos.x - 10.0, pos.y - 10.0, pos.x + 10, pos.y + 10, GetColor(0, 255, 0), 1);
}

void Player::move()
{
	if (CheckHitKey(KEY_INPUT_A) && pos.x > 10)
	{
		direction.x -= 4.0;
	}

	if (CheckHitKey(KEY_INPUT_D) && pos.x < mySetup::allX - 10)
	{
		direction.x += 4.0;
	}

	if (CheckHitKey(KEY_INPUT_W) && pos.y > 10)
	{
		direction.y -= 4.0;
	}

	if (CheckHitKey(KEY_INPUT_S) && pos.y < mySetup::Y - 10)
	{
		direction.y += 4.0;
	}
	pos += direction;
	direction = myVector2(0, 0);
}

void Player::fire(std::vector<Bullet*>& bullets)
{
	oldKey = key;
	key = CheckHitKey(KEY_INPUT_SPACE);

	if ((key & ~oldKey) & KEY_INPUT_SPACE)
	{
		Bullet* bul = new Bullet(pos, myVector2(0.0, -5.0));
		bul->setIsPlaBul(true);
		bullets.push_back(bul);
	}
}

