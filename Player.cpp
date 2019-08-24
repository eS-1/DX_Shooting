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
	DrawBox(position.x - 10.0, position.y - 10.0, position.x + 10, position.y + 10, GetColor(0, 255, 0), 1);
}


void Player::move()
{
	if (CheckHitKey(KEY_INPUT_A) && position.x > 10)
	{
		direction.x -= 4.0;
	}

	if (CheckHitKey(KEY_INPUT_D) && position.x < mySetup::allX - 10)
	{
		direction.x += 4.0;
	}

	if (CheckHitKey(KEY_INPUT_W) && position.y > 10)
	{
		direction.y -= 4.0;
	}

	if (CheckHitKey(KEY_INPUT_S) && position.y < mySetup::Y - 10)
	{
		direction.y += 4.0;
	}
	position += direction;
	direction = myVector2(0, 0);
}


void Player::fire(std::vector<Bullet*>& bullets)
{
	oldKey = key;
	key = CheckHitKey(KEY_INPUT_SPACE);

	if ((key & ~oldKey) & KEY_INPUT_SPACE)
	{
		for (Bullet* bul : bullets)
		{
			if (bul->getRemoveFlag())
			{
				bul->setRemoveFlag(false);
				bul->setDirection(myVector2(0.0, -5.0));
				bul->setPosition(position);
				break;
			}
		}
	}
}
