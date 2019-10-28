#include "../header/setup.h"
#include "../header/Player.h"
#include "DxLib.h"


Player::Player(const myVector2& position)
	: MyObject(position), key(0), oldKey(0), imgHandle(LoadGraph("images/player.png")) {}


Player::~Player()
{
	DeleteGraph(imgHandle);
}


bool Player::isPlayer()
{
	return true;
}


void Player::draw()
{
	if (imgHandle == -1)
	{
		DrawFormatString(position.x, position.y, GetColor(255, 255, 255), "F");
		return;
	}
	DrawExtendGraph(position.x - 30.0, position.y - 30.0, position.x + 30.0, position.y + 30.0, imgHandle, true);
}


void Player::move()
{
	if (CheckHitKey(KEY_INPUT_A) && position.x > 25)
	{
		direction.x -= 4.0;
	}

	if (CheckHitKey(KEY_INPUT_D) && position.x < mySetup::X - 25)
	{
		direction.x += 4.0;
	}

	if (CheckHitKey(KEY_INPUT_W) && position.y > 25)
	{
		direction.y -= 4.0;
	}

	if (CheckHitKey(KEY_INPUT_S) && position.y < mySetup::Y - 25)
	{
		direction.y += 4.0;
	}
	if (direction.length() > 4.0)
	{
		direction.normalize(4.0);
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
